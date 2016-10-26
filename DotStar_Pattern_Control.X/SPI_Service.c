/****************************************************************************
 Module
   SPI_Service.c

****************************************************************************/
/*----------------------------- Include Files -----------------------------*/
/* include header files for this state machine as well as any machines at the
   next lower level in the hierarchy that are sub-machines to this machine
*/
#include "ES_Configure.h"
#include "ES_Framework.h"
#include "SPI_Service.h"
#include "ES_Types.h"


/*----------------------------- Module Defines ----------------------------*/
#define ONE_SEC 50
#define NUM_LEDS 11
#define OVERHEAD_BYTES 8
#define TOT_BYTES OVERHEAD_BYTES + NUM_LEDS*4 //just for now

/*---------------------------- Module Functions ---------------------------*/
static void InitSPI(void);
static void FormPacket(void);
static void SetBGR(uint8_t B, uint8_t G, uint8_t R);

/*---------------------------- Module Variables ---------------------------*/
// everybody needs a state variable, though if the top level state machine
// is just a single state container for orthogonal regions, you could get
// away without it
// with the introduction of Gen2, we need a module level Priority var as well
static uint8_t MyPriority;
static uint8_t BytesToSend[TOT_BYTES]; //for testing
static uint8_t BGR[3];
static uint8_t NumBytesLeft;
static bool FirstSend; 
static SPIState_t CurrentState;
static uint8_t LEDColor;

/*------------------------------ Module Code ------------------------------*/

/****************************************************************************
 Function
     InitSPI_Service

 Parameters
     uint8_t : the priorty of this service

 Returns
     boolean, False if error in initialization, True otherwise

 Description
     Saves away the priority and starts the top level state machine

****************************************************************************/
bool InitSPI_Service (uint8_t Priority)
{

  MyPriority = Priority;  // save our priority
  FirstSend = true;
  LEDColor = 0;
  SetBGR(0x00, 0xFF, 0x00);
  CurrentState = Waiting2Send;
  InitSPI();
  ES_Timer_InitTimer(SPI_TEST_TIMER, ONE_SEC*3); //set timer to trigger
  return true;
}



/****************************************************************************
 Function
     PostSPI_Service

 Parameters
     ES_Event ThisEvent , the event to post to the queue

 Returns
     boolean False if the post operation failed, True otherwise

****************************************************************************/
bool PostSPI_Service(ES_Event ThisEvent)
{
  return ES_PostToService( MyPriority, ThisEvent);
}

/****************************************************************************
 Function
    RunSPI

 Parameters
   ES_Event: the event to process

 Returns
   ES_Event: an event to return

****************************************************************************/
ES_Event RunSPI_Service( ES_Event ThisEvent )
{
    ES_Event ReturnEvent;
    if (ThisEvent.EventType == ES_TIMEOUT) {
        if (ThisEvent.EventParam == SPI_TEST_TIMER){
            if (RA0 == 1) //toggle LED to test
            {
                RA0 = 0;
            } else {
                RA0 = 1;
            }
            if (LEDColor == 0) { //Rotate between 3 colors for now
                SetBGR(0x00, 0xFF, 0x00);
                LEDColor = 1;
            } else if (LEDColor ==1) {
                SetBGR(0x00, 0x00, 0xFF);
                LEDColor = 2;
            } else {
                SetBGR(0xFF, 0x00, 0x00);
                LEDColor = 0;
            }
            //sendByte(0xAA); //replace with actual Data
            ES_Event ThisEvent;
            ThisEvent.EventType = SEND_TRIGGER; //use button later
            PostSPI_Service(ThisEvent);
            
        }
    }
    if (CurrentState == Waiting2Send) {
        if (ThisEvent.EventType == SEND_TRIGGER) {   
            CurrentState = Sending;
            NumBytesLeft--;
            FormPacket();
            sendByte(BytesToSend[0]);
        }   
    } else if (CurrentState == Sending) {
        if (ThisEvent.EventType == BYTE_SENT) {
            if (NumBytesLeft == 0) {
                NumBytesLeft = TOT_BYTES;
                FirstSend = true;
                ES_Timer_InitTimer(SPI_TEST_TIMER, ONE_SEC); //restart timer to trigger for testing
                CurrentState = Waiting2Send;
            } else {
                NumBytesLeft--;
                sendByte(BytesToSend[TOT_BYTES - NumBytesLeft - 1]); //send another byte for testing
            }
        } else if(ThisEvent.EventType == BUF_NOT_READY) {
            sendByte(BytesToSend[TOT_BYTES - NumBytesLeft - 1]); //send again
        }
    }
    
    ReturnEvent.EventType = ES_NO_EVENT;
    return(ReturnEvent);
}
/****************************************************************************
 Function
 SendByte

 Parameters
   uint8_t: Data

 Returns
    None
 
  Description
    Writes to the SSBUF register to transmit data. If the buffer is not done sending,
 keep trying to send again until the buffer is full

****************************************************************************/

void sendByte(uint8_t Data) {
    if (FirstSend == true) { //BF will be 0 at start
        FirstSend = false;
        SSPBUF = Data;
    } else if (SSPSTATbits.BF != 0) { //If all bits have been sent
        uint8_t dummy = SSPBUF;//read from buffer and discard data (resets BF))
        SSPBUF = Data; //Set Buffer to Data
    } else { // try sending again
//        ES_Timer_InitTimer(SPI_TEST_TIMER, ONE_SEC);
        ES_Event ThisEvent;
        ThisEvent.EventType = BUF_NOT_READY;
        PostSPI_Service(ThisEvent);
    }
}

void EOTResponse(void) { //Interrupt response
    ES_Event ThisEvent;
    ThisEvent.EventType = BYTE_SENT;
    PostSPI_Service(ThisEvent);
//      ES_Timer_InitTimer(SPI_TEST_TIMER, ONE_SEC/2);
}

/*----------------------------- Module Functions -----------------------------*/
static void InitSPI(void){ 
    //Page 13 for pins
    // RC5 for Data output
    // RC3 for CLK as output
    PORTC = 0x00; // Clear portC
    LATC = 0x00; // Clear Data Latches
    ANSELC = 0x00; //Set all pins as digital
    TRISC = 0x00; //(0 = output))
    
    SSPIE = 1; // Enable MSSP interrupt
    // To reconfigure SPI: clear SSPEN, reinitialize SSPCONx, set SSPEN
	//Set SSP Enable Bit and SSPEN of SSPCON1 register
    //Configure SDI, SDO, SCK, SS as serial
    SSPCON1 = 0x00; //Clear SSPCON1
    SSPSTAT = 0b01000000; //XMit occurs from active to idle clk state (CKE, 6))
    SSPADD = 0xFF;
    SSPCON1 = 0b00111010; //Set idle high (CKP, 4) and enable on (SSPEN 5))
    NumBytesLeft = TOT_BYTES;
    FormPacket();
//    sendByte(0xAA);
}

static void FormPacket(void) {
    for (uint8_t i=0; i < 4; i++) {
        BytesToSend[i] = 0x00; // starting bytes (0-3)
    }
    for (uint8_t ledNum=0; ledNum < NUM_LEDS; ledNum++) {
        for (uint8_t j=0; j < 4; j++) {           
            if (j==0) {
                BytesToSend[4+4*ledNum+j] = 0xFF; //global
            } else if (j==1) {
                BytesToSend[4+4*ledNum+j] = BGR[0]; //Blue
            } else if (j==2) {
                BytesToSend[4+4*ledNum+j] = BGR[1]; //Green
            } else {
                BytesToSend[4+4*ledNum+j] = BGR[2]; //Red
            }
        }
    }
    for (uint8_t i=0; i < 4; i++) {
        BytesToSend[4+NUM_LEDS*4 + i] = 0x00; 
    }
}

static void SetBGR(uint8_t B, uint8_t G, uint8_t R) {
    BGR[0] = B;
    BGR[1] = G;
    BGR[2] = R;
}
