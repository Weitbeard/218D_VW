/****************************************************************************
 Module
   Pattern_DotStarLED.c

 Revision
   1.0.1 

 Description
   Hardware and pattern control for DotStar LED strip.

 Notes
   
   
 History
 When            Who     What/Why
 --------------- ---     --------
 10/028/16 01:30 lxw     first pass
****************************************************************************/

#include "ES_Types.h"
#include "string.h"

#include "ES_Configure.h"
#include "ES_Framework.h"

#include "Pattern_DotStarLED.h"
#include "Pattern_HSV_Convert.h"
#include "Pattern_Defs.h"
#include "SPI32_ControlService.h"

#define FIRST_PIXEL 1
#define HEAD        0
#define HEAD_FRAME  0x0
#define TAIL        Length+1
#define TAIL_FRAME  0xffffffff
#define PIXEL_HEADER    0xe0000000

#define R_MASK      0x0F00
#define G_MASK      0x00F0
#define B_MASK      0x000F

static uint8_t Length;
static uint8_t Brightness;
static uint32_t PixelFrames[MAX_STRIP_LENGTH+3];// @ (BANK_0_GPR);

static void Expand_RGB(uint32_t *);

void DotStar_Init(uint8_t numPixels, uint8_t brightness){
    /*
     insert error checking for numPixels = 0 || numPixels >= MAX_STRIP_LENGTH
      and pre-established SPI communication ********************* TODO
    */
    
	 //initialize SPI hardware registers
	//SPI32_Init(); //****already done by SPI service... there might be a better way to do this
     //set number of pixels
    Length = numPixels;
     //set strip brightness
    Brightness = brightness;
     //setup PatternFrames
    PixelFrames[HEAD] = HEAD_FRAME;
    PixelFrames[TAIL] = TAIL_FRAME;
    PixelFrames[TAIL+1] = TAIL_FRAME;
}

uint8_t DotStar_GetLength(void){
    return Length;
}

void DotStar_SetBrightness(uint8_t brightness){
    if(brightness <= FULL_BRIGHT){
        Brightness = brightness;
    }
}

void DotStar_Show(uint16_t *patternPointer){
    for(uint8_t i=1; i<=Length; i++){
         //add pixelPointer's values to PixelFrames with brightness
        PixelFrames[i] = (PIXEL_HEADER | ((uint32_t)Brightness<<24) | *(patternPointer+(i-1)));
        
        #ifdef HSV_PATTERNS
             //convert values from HSV to RGB
            HSV_to_RGB(PixelFrames+i);
        #endif

        #ifdef RGB_PATTERNS
             //expand 4-bit RGB values to 8-bit
            Expand_RGB(PixelFrames+i);
        #endif
    }
    
     //start SPI transmission of PixelFrames
    SPI32_TransmitFrames(PixelFrames,Length+3);
}

static void Expand_RGB(uint32_t * RGBval){
    uint16_t r, g, b;
    
    r = *RGBval & R_MASK;
    r += r<<4;
    g = *RGBval & G_MASK;
    g += g<<4;
    b = *RGBval & B_MASK;
    b += b<<4;
    
    *RGBval = 0xff000000 | ((uint32_t)r>>8) | ((uint32_t)g<<4) | ((uint32_t)b<<16);
}