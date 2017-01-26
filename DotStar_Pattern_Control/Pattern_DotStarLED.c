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
#include "stdlib.h"

#include "ES_Configure.h"
#include "ES_Framework.h"

#include "Pattern_DotStarLED.h"
#include "Pattern_HSV_Convert.h"
#include "Pattern_Defs.h"
#include "SPI32_ControlService.h"

 //DotStar LED-specific defines
#define FIRST_PIXEL 1
#define HEAD        0
#define HEAD_FRAME  0x0
#define TAIL        STRIP_LENGTH+1
#define TAIL_FRAME  0xffffffff
#define PIXEL_HEADER    0xe0000000
#define R_MASK      0x0F00
#define G_MASK      0x00F0
#define B_MASK      0x000F

 //module variables
static uint8_t* Brightness;     //pointer to LED brightness configuration
static uint32_t PixelFrames[STRIP_LENGTH+3]; //external RGB image buffer

#ifdef RGB_PATTERNS
static void Expand_RGB(uint32_t *);
#endif


/****************************************************************************
 Function
    DotStar_Init

 Parameters
    uint8_t *: pointer to LED brightness configuration  value

 Returns
    void

 Description
    stores LED brightness configuration & sets mandatory image frame values

 Notes
   
 Author
    lxw, 11/14/16, 02:00
****************************************************************************/
void DotStar_Init(uint8_t *brightnessPointer){
     //set strip brightness pointer
    Brightness = brightnessPointer;
     //setup PatternFrames
    PixelFrames[HEAD] = HEAD_FRAME;
    PixelFrames[TAIL] = TAIL_FRAME;
    #if STRIP_LENGTH > 64
    PixelFrames[TAIL+1] = TAIL_FRAME;
    #endif
}

/****************************************************************************
 Function
    DotStar_Show

 Parameters
    uint16_t *: 16-bit HSV image buffer

 Returns
    void

 Description
    displays the provided HSV image buffer at the LED strip

 Notes
   
 Author
    lxw, 11/14/16, 02:00
****************************************************************************/
void DotStar_Show(uint16_t *patternPointer){
    for(uint8_t i=1; i<=STRIP_LENGTH; i++){
         //add pixelPointer's values to PixelFrames with brightness
        PixelFrames[i] = (PIXEL_HEADER | ((uint32_t)*Brightness<<24) | *(patternPointer+(i-1)));
        
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
    SPI32_TransmitFrames(PixelFrames,STRIP_LENGTH+3);
}

#ifdef RGB_PATTERNS
 //expand 16-bit RGB to 24-bit RGB
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
#endif