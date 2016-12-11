/*----------------------------- Include Files -----------------------------*/
/* include header files for this state machine as well as any machines at the
   next lower level in the hierarchy that are sub-machines to this machine
*/
#include "ES_Configure.h"
#include "ES_Framework.h"
#include "AnalogService.h"
#include "Can_XmitService.h"

/*----------------------------- Module Defines ----------------------------*/
#define ONE_SEC 50
#define ACQUISITION_TIME 5
#define BRIGHTNESS_CHANNEL 0x00
#define LOCATION_CHANNEL 0x01

/*----------------------------- Module Variables ----------------------------*/
static uint8_t Brightness;
static uint8_t Location;
static uint8_t MyPriority;

/*---------------------------- Module Functions ---------------------------*/
/* prototypes for private functions for this service.They should be functions
   relevant to the behavior of this service
 * 
*/
static void InitAnalogHW(void);

/*------------------------------ Module Code ------------------------------*/


bool InitAnalogService( uint8_t Priority ) 
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

bool PostAnalogService( ES_Event ThisEvent )
{
    return ES_PostToService( MyPriority, ThisEvent);
}

ES_Event RunAnalogService( ES_Event ThisEvent )
{
    ES_Event ReturnEvent;
    if(ThisEvent.EventType == ES_INIT) {
        InitAnalogHW();
        ADCON0bits.CHS = BRIGHTNESS_CHANNEL; //start sampling brightness first
        ES_Timer_InitTimer(ANALOG_TIMER, ACQUISITION_TIME);
    }
    if(ThisEvent.EventType == ES_TIMEOUT && ThisEvent.EventParam == ANALOG_TIMER) {
        ADCON0bits.GO = 1;      // start the conversion
    }
    ReturnEvent.EventType = ES_NO_EVENT; // assume no errors
    return ReturnEvent;
}

uint8_t GetBrightness(void)
{
    return Brightness;
}

uint8_t GetLocation(void)
{
    return Location;
}

void AnalogISR(void) 
{
    if (!ADCON0bits.DONE) { //Make sure conversion is finished
        if (ADCON0bits.CHS == BRIGHTNESS_CHANNEL) {
            Brightness = ((ADRESH<<8)|ADRESL) >> 2; // scale to 8-bit number
            ADCON0bits.CHS = LOCATION_CHANNEL; //sample location channel
            ADCON0bits.GO = 1;
        } else if (ADCON0bits.CHS == LOCATION_CHANNEL) {
            Location = ((ADRESH<<8)|ADRESL) >> 2;
            ADCON0bits.CHS = BRIGHTNESS_CHANNEL; //sample brightness channel
            ES_Event Event2Post;
            Event2Post.EventType = XMIT_EVENT;
            PostCan_XmitService(Event2Post);
            ES_Timer_InitTimer(ANALOG_TIMER, ACQUISITION_TIME);
        }
    }
}
/*----------------------------- Module Functions ----------------------------*/
static void InitAnalogHW(void)
{
    PORTA = 0x00; // Clear portA
    LATA = 0x00; // Clear Data Latches
    TRISAbits.TRISA0 = 1; // Set RA0 as input
    TRISAbits.TRISA1 = 1; // Set RA1 as input
    
    ADCON1bits.VCFG1 = 0; // set v+ reference to Vdd
    ADCON1bits.VCFG0 = 0;  // set v- reference to GND
    
    ADCON2bits.ADFM = 1;  // right justify the output
    ADCON2bits.ACQT = 0b100; // 8 TAD
    ADCON2bits.ADCS = 0b001; // use Fosc/8 for clock source
    
    ADCON0bits.ADON = 1;  // turn on the ADC
    ADIF = 0;             // Start with flag equal to zero
    ADIE = 1;            //Enable Analog Converter Interrupt
}