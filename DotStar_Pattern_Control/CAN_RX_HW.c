
/****************************************************************************
 Module
   CAN_RX_HW.c

 Revision
   1.1.1

 Description
   CAN receive control module

 Notes

 History
 When           Who     What/Why
 -------------- ---     --------
 12/10/16 07;15 lw		 converted from service to HW module, feeding master mirror service
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
#include "CAN_RX_HW.h"
#include "CAN_Defs.h"
#include "Pattern_ControlService.h"
#include "Pattern_Defs.h"

/*----------------------------- Module Defines ----------------------------*/
#define ONE_SEC 50

/*---------------------------- Module Functions ---------------------------*/
/* prototypes for private functions for this machine.They should be functions
   relevant to the behavior of this state machine
*/
static void InitCanHardware(void);
static void InitPins(void);
static void ProcessReceive(void);

/*---------------------------- Module Variables ---------------------------*/
static uint8_t MyPriority;

static uint8_t CurrentPattern = 0;
static uint8_t ListLoc = 0;
static uint8_t Brightness = 0;

/*------------------------------ Module Code ------------------------------*/

void CAN_Init(void){
    InitPins();
	InitCanHardware();
}

void CAN_XmitResponse(void) 
{
    TXB0CONbits.TXREQ = 0;
}

void CAN_RCVResponse(void)
{
    if (RXB0CONbits.RXFUL == 1) {
        ProcessReceive();
        RXB0CONbits.RXFUL = 0; //clear buffer
        
    }
}

void CAN_ErrorResponse(void) 
{
    // For debugging
}

void CAN_BusErrorResponse(void)
{
//    For debugging
}

//uint8_t CAN_GetCurrentPattern(void){
//    return CurrentPattern;
//}
//
//uint8_t CAN_GetListLoc(void){
//    return ListLoc;
//}
//
//uint8_t CAN_GetBrightness(void){
//    return Brightness;
//}

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
    //256 kbs baud rate
    BRGCON2bits.SEG2PHTS = 1; //freely programmable SEG2PH

    BRGCON1bits.BRP0 = 1;
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
  
  // To test functionality
  PORTA = 0x00; // Clear portA
  LATA = 0x00; // Clear Data Latches
  TRISA = 0x00; //set as output
}

static void ProcessReceive(void)
{
    static uint8_t LastButton = NO_NEW_INPUT;
    // Check if Identifiers match
    if (RXB0SIDH == SIDH && RXB0SIDL == SIDL && RXB0EIDH == EIDH && RXB0EIDL == EIDL)  {
        ES_Event Event2Post;
        if(RXB0D0 != NO_NEW_INPUT){
            switch(RXB0D0) { //Read First Data Byte
                case START_MESSAGE:
                    Event2Post.EventType = PATTERN_START;
                    break;
                case STOP_MESSAGE:
                    Event2Post.EventType = (LastButton == STOP_MESSAGE ? PATTERN_END : PATTERN_PAUSE);
                    break;
                case RESET_MESSAGE:
                    #ifdef PATTERN_TEST
                        SetPattern(TEST_PATTERN);
                        Event2Post.EventType = PATTERN_START;
                    #else 
                        SetPattern(NO_PATTERN);
                        Event2Post.EventType = PATTERN_END;
                    #endif
                    break;
                case NEXT_PATTERN_MESSAGE:
                    SetPattern(CurrentPattern);
                    CurrentPattern = (CurrentPattern+1)%NUM_PATTERNS;
                    break;
            }
             //store last button pushed
            LastButton = RXB0D0;
        }
		 //set pattern brightness based off second byte
        SetBrightness(RXB0D1);
		 //set analog listening location based off third byte
        SetListLoc(RXB0D2);
         //post new event to Pattern Control Service
        PostPatternControlService(Event2Post);
    }
}