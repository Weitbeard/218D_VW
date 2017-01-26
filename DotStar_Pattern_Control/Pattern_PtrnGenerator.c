/****************************************************************************
 Module
   Pattern_PtrnGenerator.c

 Revision
   1.0.1 

 Description
   Pattern generator for circular LED strip

 Notes
   
   
 History
 When            Who     What/Why
 --------------- ---     --------
 10/28/16 02:00 lxw     first pass
****************************************************************************/

/*----------------------------- Include Files -----------------------------*/
/* include header files for this state machine as well as any machines at the
   next lower level in the hierarchy that are sub-machines to this machine
*/
//standard c libraries
#include "ES_Types.h"
#include "stdlib.h"

//framework headers
#include "ES_Configure.h"
#include "ES_Framework.h"

//module includes
#include "Pattern_PtrnGenerator.h"
#include "Pattern_PtrnFunctions.h"
#include "Pattern_Defs.h"

/*----------------------------- Module Defines ----------------------------*/

#define PIXEL_OFF   0x0

/*---------------------------- Module Functions ---------------------------*/
/* prototypes for private functions for this machine.They should be functions
   relevant to the behavior of this state machine
*/

/*---------------------------- Module Variables ---------------------------*/
static	uint16_t PixelPattern[STRIP_LENGTH];
static  uint8_t* PatternID;
static  uint8_t* ListeningFocus;
static  uint8_t  PatternStepCounter = 0;
static  uint32_t CycleCounter = 0;

/*****  Scrapped example for better modularity with function pointers: ********/
/*        (commented out/removed to save data space on uC)                    */
/*
 //typedef for pattern generation function pointers
typedef void(*ptrnFunc)(uint16_t*, uint8_t*, uint32_t*, uint8_t, uint8_t, void*);
    //linked pattern-generating functions
static ptrnFunc TestPattern = HueTest;
static ptrnFunc WelcomePattern = FullPulseHold;
static ptrnFunc IdlePattern = CenterBreathe;
static ptrnFunc ThinkingPattern = SingleFadedLoop;
static ptrnFunc ListeningPattern = SingleFocusPulse;
static ptrnFunc SpeakingPattern = SingleFocusPulse;
static ptrnFunc CustomPattern = DoubleFadedLoop;
*/
/********************************* End Example ********************************/

/*------------------------------ Module Code ------------------------------*/

/****************************************************************************
 Function
    SetupPattern

 Parameters
    uint8_t *: pointer to pattern ID configuration
    uint8_t *: pointer to analog value for the listening focus position

 Returns
    void

 Description
    stores required configurations for later use
 Notes
   
 Author
    lxw, 10/28/16, 02:00
****************************************************************************/
void SetupPattern(uint8_t *patternIDPointer, uint8_t *listeningFocusPointer){
     //store pattern ID and listening focus pointers
    PatternID = patternIDPointer;
    ListeningFocus = listeningFocusPointer;
}

/****************************************************************************
 Function
    SetupPattern

 Parameters
    void
 
 Returns
    void

 Description
    resets variables used to calculate repeating (or step-based) patterns
 
 Notes
   
 Author
    lxw, 10/28/16, 02:00
****************************************************************************/
void ResetPattern(void){
     //reset pattern step counter
    PatternStepCounter = 0;
     //reset cycle counter
    CycleCounter = 0;
}

/****************************************************************************
 Function
    PatternOff

 Parameters
    void

 Returns
    uint16_t *: pointer to populated image array (buffer)

 Description
    turns pixels off by populating image buffer with 0 values

 Notes
   
 Author
    lxw, 10/28/16, 02:00
****************************************************************************/
uint16_t * PatternOff(void){
    for(uint8_t i=0;i<STRIP_LENGTH;i++){
        PixelPattern[i] = PIXEL_OFF;
    }
    return PixelPattern;
}

/****************************************************************************
 Function
    UpdatePattern

 Parameters
    void

 Returns
    uint16_t *: pointer to populated image array (buffer)

 Description
    populates the image buffer with a new image based on the configured pattern ID

 Notes
   
 Author
    lxw, 10/28/16, 02:00
****************************************************************************/
uint16_t * UpdatePattern(void){    
     //based on the current pattern ID...
    switch(*PatternID){
        
        case NO_PATTERN:
             //populate pattern array with image of all pixels OFF
            for(uint8_t i=0;i<STRIP_LENGTH;i++){
                PixelPattern[i] = PIXEL_OFF;
            }
        break;
                
        case WELCOME_PATTERN:
             //populate pattern array with image for when in the Welcome State
            FullPulseHold(PixelPattern, &PatternStepCounter, &CycleCounter, WELCOME_HUE, WELCOME_SAT, 0);
        break;
        
        case IDLE_PATTERN:
             //populate pattern array with image for when in the Idle State
            CenterBreathe(PixelPattern, &PatternStepCounter, &CycleCounter, IDLE_HUE, IDLE_SAT, 0);
        break;
        
        case THINKING_PATTERN:
             //populate pattern array with image for when in the Thinking State
            SingleFadedLoop(PixelPattern, &PatternStepCounter, &CycleCounter, THINKING_HUE, THINKING_SAT, 0);
        break;
        
        case SPEAKING_PATTERN:
             //populate pattern array with image for when in the Speaking State
            SingleFocusBreathe(PixelPattern, &PatternStepCounter, &CycleCounter, SPEAKING_HUE, SPEAKING_SAT, ListeningFocus);  
        break;
        
        case LISTENING_PATTERN:
             //populate pattern array with image for when in the Listening State
            SingleFocusBreathe(PixelPattern, &PatternStepCounter, &CycleCounter, LISTENING_HUE, LISTENING_SAT, ListeningFocus);
        break;
        
         /********************** ADD NEW CUSTOM STATES & PATTERNS HERE *************************/
        
        case CUSTOM1_PATTERN:
            MirroredQuadrants(PixelPattern, &PatternStepCounter, &CycleCounter, CUSTOM1_HUE, CUSTOM1_SAT, 0);
        break;
        
        case CUSTOM2_PATTERN:
            DoubleFadedLoop(PixelPattern, &PatternStepCounter, &CycleCounter, (255*PatternStepCounter/STRIP_LENGTH), CUSTOM2_SAT, 0);
        break;
        
        case CUSTOM3_PATTERN:
            BrokenPinwheel(PixelPattern, &PatternStepCounter, &CycleCounter, (255*PatternStepCounter/(STRIP_LENGTH/3)), CUSTOM3_SAT, 0);
        break;
        
        /*
         case TEMPLATE_PATTERN:
            TemplatePattern(PixelPattern, &PatternStepCounter, &CycleCounter, TEMPLATE_HUE, TEMPLATE_SAT, genericPointer);
         break;
        */
        
         /***************************************  END  ****************************************/
        
        #ifdef PATTERN_TEST_ENABLE
        case TEST_PATTERN:
            HueTest(PixelPattern, &PatternStepCounter, &CycleCounter, TEST_HUE, TEST_SAT, 0);
        break;
        #endif
        
        default:
            for(uint8_t i=0;i<STRIP_LENGTH;i++){
                PixelPattern[i] = PIXEL_OFF;
            }
        break;
    } //end switch
    
    return PixelPattern;
}
