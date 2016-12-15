/****************************************************************************
 Module
   Can_TransmitService.c

 Revision
   1.0.1

 Description
   ES Framework service for can control

 Notes

 History
 When           Who     What/Why
 -------------- ---     --------
 11/10/16 06:49 jw       started implementation of can service
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
#include "Can_XmitService.h"
#include "AnalogService.h"

/*----------------------------- Module Defines ----------------------------*/
#define ONE_SEC 50

#define START 0x0E
#define STOP 0x0D
#define RESET 0x0B
#define NEXT 0x07

//Pins to Light Up Buttons
#define START_PIN LATA2
#define STOP_PIN LATA3
#define RESET_PIN LATA4
#define NEXT_PIN LATA5

#define START_DATA 0x00
#define STOP_DATA 0x01
#define RESET_DATA 0x02
#define NEXT_DATA 0x03

#define NUM_BYTES 0x03
/*---------------------------- Module Functions ---------------------------*/
/* prototypes for private functions for this machine.They should be functions
   relevant to the behavior of this state machine
*/
static void InitCanHardware(void);
static void InitPins(void);
static void XmitData(uint8_t DataByte);

/*---------------------------- Module Variables ---------------------------*/
static uint8_t MyPriority;


/*------------------------------ Module Code ------------------------------*/
/****************************************************************************
 Function
     InitCan_XmitService

 Parameters
     uint8_t : the priority of this service

 Returns
     bool, false if error in initialization, true otherwise

 Description
     Saves away the priority, sets up the initial transition and does any
     other required initialization for this state machine

****************************************************************************/
bool InitCan_XmitService( uint8_t Priority )
{
  ES_Event ThisEvent;

  MyPriority = Priority;

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
     Post_CanTransmitService

 Parameters
     EF_Event ThisEvent , the event to post to the queue

 Returns
     boolean False if the Enqueue operation failed, True otherwise

 Description
     Posts an event to this state machine's queue
 
****************************************************************************/
bool PostCan_XmitService( ES_Event ThisEvent )
{
  return ES_PostToService( MyPriority, ThisEvent);
}


/****************************************************************************
 Function
    RunCan_TransmitService

 Parameters
   ES_Event : the event to process

 Returns
   ES_Event, ES_NO_EVENT if no error ES_ERROR otherwise

 Description
   add your description here
 
****************************************************************************/
ES_Event RunCan_XmitService( ES_Event ThisEvent )
{
  ES_Event ReturnEvent;

  if (ThisEvent.EventType == ES_INIT) {
     InitPins();
     InitCanHardware();
     START_PIN = 1;
  } else if (ThisEvent.EventType == DBButtonDown) {
      switch(ThisEvent.EventParam){
          case START:
              START_PIN = 1;
              STOP_PIN = 0;
              RESET_PIN = 0;
              NEXT_PIN = 0;
              XmitData(START_DATA);
              break;
          case STOP:
              START_PIN = 0;
              STOP_PIN = 1;
              RESET_PIN = 0;
              NEXT_PIN = 0;
              XmitData(STOP_DATA);
              break;
          case RESET:
              START_PIN = 0;
              STOP_PIN = 0;
              RESET_PIN = 1;
              NEXT_PIN = 0;
              XmitData(RESET_DATA);
              break;
          case NEXT:
              START_PIN = 0;
              STOP_PIN = 0;
              RESET_PIN = 0;
              NEXT_PIN = 1;
              XmitData(NEXT_DATA);
              break; 
        }
    } else if (ThisEvent.EventType == XMIT_EVENT) {
        XmitData(0xFF);        
    }
  ReturnEvent.EventType = ES_NO_EVENT; // assume no errors
  return ReturnEvent;
}

void CanXmitResponse(void) 
{
    TXB0CONbits.TXREQ = 0;
}

void CanRCVResponse(void)
{
    if (RXB0CONbits.RXFUL == 1) {
        RXB0CONbits.RXFUL = 0; //clear buffer
    }
}

void CanErrorResponse(void) 
{
    // For debugging
}

void BusErrorResponse(void)
{
//    For debugging
}

/***************************************************************************
 private functions
 ***************************************************************************/
static void InitCanHardware(void)
{
	// 2. Ensure that the ECAN module is in Configuration
	// mode.
	CANCON = 0x80; //Request Configuration Mode p. 282
	// 3. Select ECAN Operational mode.
    while (CANSTATbits.OPMODE2 != 1);
    CIOCON = 0x20;
	// 4. Set up the Baud Rate registers.
    //256 kbps
    BRGCON2bits.SEG2PHTS = 1; //freely programmable SEG2PH
    
    BRGCON1bits.BRP0 = 1; //BRP = 1;
    BRGCON1bits.BRP1 = 0;
    BRGCON2bits.PRSEG0 = 0; // 7 Tq
    BRGCON2bits.PRSEG1 = 1;
    BRGCON2bits.PRSEG2 = 1;
    BRGCON2bits.SEG1PH0 = 1; // 6 Tq
    BRGCON2bits.SEG1PH1 = 0; 
    BRGCON2bits.SEG1PH2 = 1; 
    BRGCON3bits.SEG2PH0 = 1; //2 Tq
    BRGCON1bits.SJW0 = 1; //2 Tq
    
	// 5. Set up the Filter and Mask registers.
    
    RXB0CONbits.RXB0DBEN = 0; //No Receive Buffer 0 overflow to Receive Buffer 1 
    RXB0CONbits.RXM0 = 0; //Receive all messages Standard or EID
    RXB0CONbits.RXM1 = 0;
    RXF0SIDH = 0x00;
    RXF0SIDL = 0x08;
    RXF0EIDH = 0x00;
    RXF0EIDL = 0x01;
        
    RXM0SIDH = 0x00; 
    RXM0SIDL = 0x00; 
    RXM0EIDH = 0x00;
    RXM0EIDL = 0x01;
    
    // 6. Set the ECAN module to normal mode or any
	// other mode required by the application logic.
    ECANCON = 0x00; // Set in MODE 0 (should be default already)
	  CANCON = 0b00010000; //Return to normal request mode
    while (CANSTATbits.OPMODE2 != 0); // wait to return to normal mode
    
    // Enable Interrupts
    RXB0IE = 1; //enable interrupt
    ERRIE = 1; // Can module error
    IRXIE = 1; // CAN Bus error
    
    
	// Clear TXREQ to get buffer ready for transmission
    RXB0IF = 0;
    ERRIF = 0;
    IRXIF = 0;
    TXB0IE = 1; //enable interrupt
    TXB0IF = 0; //clear flag
    TXB0CONbits.TXREQ = 0;
    RXB0CONbits.RXFUL = 0; //make sure buffer is cleared
}

static void InitPins(void) 
{
 // 1. Initial LAT and TRIS bits for RX (RB3)and TX (RB2) CAN.
  PORTB = 0x00; // Clear portB
  LATB = 0x00; // Clear Data Latches
  TRISBbits.TRISB2 = 0; // Set RB2 as output
  TRISBbits.TRISB3 = 1; // Set RB3 as input
  
  //For LED pins
  PORTA = 0x00;
  LATA &= 0b11111100;
  TRISA &= 0b00000011;
  
}


static void XmitData(uint8_t DataByte) {
    TXB0CONbits.TXREQ = 0;
    
    // Set Data Length and RTR pg. 291
    TXB0DLC = NUM_BYTES; //w RTR Cleared (5 bytes w/ RTR cleared)
    TXB0D0 = DataByte;
    TXB0D1 = GetBrightness();
    TXB0D2 = GetLocation();
    // Load message identifier
    //Extended Message Identifer
    TXB0SIDH = 0x00;
    TXB0SIDL = 0x08; //EXIDE set
    TXB0EIDH = 0x00;
    TXB0EIDL = 0x01;
    
    TXB0CONbits.TXPRI0 = 1; //highest priority level
    TXB0CONbits.TXPRI1 = 1;
    // Mark ready for transmission
    TXB0CONbits.TXREQ = 1;
}
