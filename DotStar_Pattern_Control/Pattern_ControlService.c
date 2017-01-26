/****************************************************************************
 Module
   Pattern_ControlService.c

 Revision
   1.0.1

 Description
   ES Framework service for control of patterns displayed on a DotStar LED
   strip.

 Notes

 History
 When           Who     What/Why
 -------------- ---     --------
 10/27/16 04:20 lxw      started implementation of pattern control service
 01/15/12 11:12 jec      revisions for Gen2 framework
 11/07/11 11:26 jec      made the queue static
 10/30/11 17:59 jec      fixed references to CurrentEvent in RunTemplateSM()
 10/23/11 18:20 jec      began conversion from SMTemplate.c (02/20/07 rev)
****************************************************************************/
/*----------------------------- Include Files -----------------------------*/
/* include header files for this state machine as well as any machines at the
   next lower level in the hierarchy that are sub-machines to this machine
*/
//std c libraries
#include "ES_Types.h"

//framework headers
#include "ES_Configure.h"
#include "ES_Framework.h"

//module includes
#include "Pattern_ControlService.h"
#include "Pattern_DotStarLED.h"
#include "Pattern_PtrnGenerator.h"
#include "Pattern_Defs.h"
#include "CAN_RX_HW.h"

/*----------------------------- Module Defines ----------------------------*/

/*---------------------------- Module Functions ---------------------------*/
/* prototypes for private functions for this machine.They should be functions
   relevant to the behavior of this state machine
*/
static void ShowPattern(void);
static void StopPattern(void);
static void PausePattern(void);

/*---------------------------- Module Variables ---------------------------*/
// everybody needs a state variable, you may need others as well.
// type of state variable should match that of enum in header file
static PatternState_t CurrentState;

// with the introduction of Gen2, we need a module level Priority var as well
static uint8_t MyPriority;//module-level variables

#ifdef PATTERN_TEST_ENABLE
static	uint8_t	PatternConfigs[4] = {
	TEST_PATTERN,
	TEST_BRIGHT,
	DEFAULT_FOCUS,
	DEFAULT_SPEED };
#else
static	uint8_t	PatternConfigs[4] = {
	NO_PATTERN,
	FULL_BRIGHT,
	DEFAULT_FOCUS,
	DEFAULT_SPEED };
#endif

static uint8_t MaxBrightness = FULL_BRIGHT; //maximum allowed LED brightness
                                 /*could be interesting to implement a function to
                                  * adjust this value based on external environment
                                  * (i.e. daytime -> brighter) */


/*------------------------------ Module Code ------------------------------*/
/****************************************************************************
 Function
     InitPatternControlService

 Parameters
     uint8_t : the priority of this service

 Returns
     bool, false if error in initialization, true otherwise

 Description
     Saves away the priority, sets up the initial transition and does any
     other required initialization for this state machine
 Notes

 Author
    lxw - revised for pattern control service
     J. Edward Carryer, 10/23/11, 18:55
****************************************************************************/
bool InitPatternControlService( uint8_t Priority )
{
  ES_Event ThisEvent;

  MyPriority = Priority;
   //initialize DotStar LED strip
  DotStar_Init(&PatternConfigs[BRIGHTNESS]);
  SetupPattern(&PatternConfigs[CUR_PATTERN], &PatternConfigs[LISTEN_FOCUS]);
   //initialize CAN
  CAN_Init();
   //set initial state
  CurrentState = Pattern_Startup;
   //post the initial transition event
  ThisEvent.EventType = ES_INIT;
  if (ES_PostToService( MyPriority, ThisEvent) == true)
  {
      return true;
  }else
  {
      return false;
  }
}

/****************************************************************************
 Function
     PostPatternControlService

 Parameters
     EF_Event ThisEvent , the event to post to the queue

 Returns
     boolean False if the Enqueue operation failed, True otherwise

 Description
     Posts an event to this state machine's queue
 Notes

 Author
    lxw - revised for pattern control service
    J. Edward Carryer, 10/23/11, 19:25
****************************************************************************/
bool PostPatternControlService( ES_Event ThisEvent )
{
  return ES_PostToService( MyPriority, ThisEvent);
}

/****************************************************************************
 Function
    RunPatternControlService

 Parameters
   ES_Event : the event to process

 Returns
   ES_Event, ES_NO_EVENT if no error ES_ERROR otherwise

 Description
   add your description here
 Notes
   uses nested switch/case to implement the machine.
 Author
    lxw - revised for pattern control service
    J. Edward Carryer, 01/15/12, 15:23
****************************************************************************/
ES_Event RunPatternControlService( ES_Event ThisEvent )
{
  ES_Event ReturnEvent;
  ReturnEvent.EventType = ES_NO_EVENT; // assume no errors
   
   //based upon the current state...
  switch(CurrentState){
		case Pattern_Startup:
             //if receiving an initial event
            if(ThisEvent.EventType == ES_INIT){
                 //Add any debug functions or self-checks here
                /*												*/
                 //clear the LED strip
				StopPattern();
                 //change state to Pattern_Off
                CurrentState = Pattern_Off;
                
                #ifdef PATTERN_TEST_ENABLE
                ES_Event testEvent;
                testEvent.EventType = PATTERN_START;
                PostPatternControlService(testEvent);
                #endif
            }
		break;
		
		case Pattern_Off:
			 //if receiving a START event
			if(ThisEvent.EventType == PATTERN_START){
				 //begin the pattern
				ShowPattern();
				 //change state to Pattern_Running
				CurrentState = Pattern_Running;
			}
		break;
		
		case Pattern_Running:
			 //if receiving a TIMEOUT event
			if(ThisEvent.EventType == ES_TIMEOUT){
				 //continue the pattern
				ShowPattern();
			}
			 //else if receiving an END event
			else if(ThisEvent.EventType == PATTERN_END){
				 //end the pattern
				StopPattern();
				 //change state to Pattern_Off
				CurrentState = Pattern_Off;
			}
			 //else if receiving a PAUSE event
			else if(ThisEvent.EventType == PATTERN_PAUSE){
				 //pause the pattern
				PausePattern();
				 //change state to Pattern_Paused
				CurrentState = Pattern_Paused;
			}
		break;
		
		case Pattern_Paused:
			 //if receiving an UNPAUSE event
			if(ThisEvent.EventType == PATTERN_START){
				 //unpause the pattern
				ShowPattern();
				 //change state to Pattern_Running
				CurrentState = Pattern_Running;
			}
			 //else if receiving an END event
			else if(ThisEvent.EventType == PATTERN_END){
				 //end the pattern
				StopPattern();
				 //change state to Pattern_Off
				CurrentState = Pattern_Off;
			}
		break;
  }                                   // end switch on Current State
  return ReturnEvent;
}

// Set a new LED display pattern
void SetPattern(uint8_t PatternID){
	PatternConfigs[CUR_PATTERN] = PatternID;
     //reset pattern step counter
    ResetPattern();
}

// Set brightness of the LED pattern
void SetBrightness(uint8_t brightness){
    uint16_t newBrightness = brightness*MaxBrightness/255;
	PatternConfigs[BRIGHTNESS] = newBrightness;
}

// Set LED color and pattern profile (based on car model)
void SetListenFocus(uint8_t listFocus){
	PatternConfigs[LISTEN_FOCUS] = listFocus*STRIP_LENGTH/255;
}

// Set pattern cycle speed
void SetPatternSpeed(uint8_t speed){
	PatternConfigs[CYC_SPEED] = speed;
}

/***************************************************************************
 private functions
 ***************************************************************************/

// Push the LED pattern to the DotStar strip
static void ShowPattern(void){
	 //start pattern update timer
	ES_Timer_InitTimer(PATTERN_UPDATE_TIMER,PatternConfigs[CYC_SPEED]);
	 //call pattern update function based on current profile and pattern ID
	DotStar_Show(UpdatePattern());
}

// Stop the pattern and turn off the LEDs
static void StopPattern(void){
	 //stop the pattern update timer
	ES_Timer_StopTimer(PATTERN_UPDATE_TIMER);
	 //turn off LEDs
	DotStar_Show(PatternOff());
	 //reset pattern
	ResetPattern();
}

// Pause the pattern but leave the LEDs on
static void PausePattern(void){
	 //pause the pattern update timer
	ES_Timer_StopTimer(PATTERN_UPDATE_TIMER);
}
