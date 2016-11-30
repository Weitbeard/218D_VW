/****************************************************************************
 Module
   Pattern_RGBPatterns.c

 Revision
   1.0.1 

 Description
   Pattern control of a RGB LED strip

 Notes
   
   
 History
 When            Who     What/Why
 --------------- ---     --------
 10/028/16 02:00 lxw     first pass
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
#include "Pattern_RGBPatterns.h"
#include "Pattern_Defs.h"

/*----------------------------- Module Defines ----------------------------*/

#define PIXEL_OFF   0x0

/*---------------------------- Module Functions ---------------------------*/
/* prototypes for private functions for this machine.They should be functions
   relevant to the behavior of this state machine
*/

static uint16_t ThinkingPattern(uint8_t pattern, uint8_t pixel,uint8_t stepCount);

/*---------------------------- Module Variables ---------------------------*/
static	uint16_t PixelPattern[MAX_STRIP_LENGTH];// @ (BANK_2_GPR);
static  uint8_t* PatternConfigs;
static  uint8_t  Length;
static  uint8_t  PatternStepCounter = 0;

#ifdef PATTERN_TEST
static  uint16_t TestHue = 0;
//#define NUM_COLORS  13
//static  uint16_t GenColors[NUM_COLORS]={
//    RED,
//    ORANGE,
//    YELLOW,
//    OLIVE,
//    LIME,
//    GREEN,
//    AQUA,
//    TEAL,
//    BLUE,
//    NAVY,
//    FUSCHIA,
//    PURPLE,
//    MAROON
//};
#endif
/*------------------------------ Module Code ------------------------------*/

void SetupPattern(uint8_t *configs, uint8_t numPixels){
     //store pattern configuration pointer
    PatternConfigs = configs;
     //store pixel strip length
    Length = numPixels;
}

uint16_t * PatternOff(void){
    for(uint8_t i=0;i<Length;i++){
        PixelPattern[i] = PIXEL_OFF;
    }
    return PixelPattern;
}


uint16_t * UpdatePattern(void){
     //gather configurations
    uint8_t patternID = PatternConfigs[CUR_PATTERN];
    
     //based on the current pattern ID...
    switch(patternID){
        
        case NO_PATTERN:
            
        break;
        
        case IDLE_PATTERN:
            //for(uint8_t i=0;i<Length;i++){
            //    PixelPattern[i] = TestHue | TEST_SATURATION | TEST_VALUE; //(uint32_t)(i == PatternStepCounter ? (GenColors[TestColor]|0x1f000000) : 0x0));
            //}
        break;
        
        case THINKING_PATTERN:
            for(uint8_t i=0;i<Length;i++){
                PixelPattern[i] = ThinkingPattern(SINGLE_FADE_LOOP,i,PatternStepCounter);
            }
            PatternStepCounter = (PatternStepCounter+1)%Length;
        break;
        
        case SPEAKING_PATTERN:
            
        break;
        
        case LISTENING_PATTERN:
            
        break;
        
        #ifdef PATTERN_TEST
        case TEST_PATTERN:
        {
            #ifdef RGB_PATTERNS
            uint8_t r, g, b;
            switch(PatternStepCounter/43){
                case 0:
                    r = 0x0F;
                    g = (PatternStepCounter%43)*15/43;
                    b = 0;
                    break;
                case 1:
                    r = 0x0F-(PatternStepCounter%43)*15/43;
                    g = 0x0F;
                    b = 0x0;
                    break;
                case 2:
                    r = 0;
                    g = 0x0F;
                    b = (PatternStepCounter%43)*15/43;
                    break;
                case 3:
                    r = 0;
                    g = 0x0F-(PatternStepCounter%43)*15/43;
                    b = 0x0F;
                    break;
                case 4:
                    r = (PatternStepCounter%43)*15/43;
                    g = 0;
                    b = 0x0F;
                    break;
                default:
                    r = 0x0F;
                    g = 0;
                    b = 0x0F-(PatternStepCounter%43)*15/43;
                    break;
            }
            for(uint8_t i=0;i<Length;i++){
                PixelPattern[i] = ((uint16_t)r<<8) | ((uint16_t)g<<4) | (uint16_t)(b);
            }
            PatternStepCounter=PatternStepCounter+1;
            #endif

            #ifdef HSV_PATTERNS
            for(uint8_t i=0;i<Length;i++){
                PixelPattern[i] = (((uint16_t)(i+PatternStepCounter)*255/Length)<<8) | (TEST_SATURATION<<4) | TEST_VALUE; //(uint32_t)(i == PatternStepCounter ? (GenColors[TestColor]|0x1f000000) : 0x0));
            }
            PatternStepCounter = (PatternStepCounter+1)%Length;
            #endif
        }
        break;
        #endif
    }
    
    return PixelPattern;
}

void ResetPattern(void){
     //reset pattern step counter
    PatternStepCounter=0;
}

static uint16_t ThinkingPattern(uint8_t pattern, uint8_t pixel, uint8_t stepCount){
    uint8_t head = stepCount;
    uint16_t pixelHSV;
    uint8_t sat, val, hue, x;
    
    switch(pattern){
        default:
            hue = THINKING_HUE;
            sat = 0x0F;
             //scale fade according to minimum distance from head (stepCount)
            x = min((Length+pixel-head)%Length,(Length+head-pixel)%Length);
            val = (x < FADE_LENGTH ? 0x0F-x*0x0F/FADE_LENGTH : 0x00);
        break;
    }
            
    pixelHSV = ((uint16_t)THINKING_HUE<<8) | (sat<<4) | val;
    
    return pixelHSV;
}

//Length - (stepCount-pixel)