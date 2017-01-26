/****************************************************************************
 Module
   Pattern_PtrnFunctions.c

 Revision
   1.0.1 

 Description
   Module to hold the HSV-encoded pattern-generating functions
   
 Notes
   
   
 History
 When            Who     What/Why
 --------------- ---     --------
   1/10/16 01:30 lxw     first pass
****************************************************************************/

#include "ES_Types.h"
#include "stdlib.h"

#include "ES_Configure.h"
#include "ES_Framework.h"

#include "Pattern_Defs.h"

/****************************************************************************
 Function
    *Standard pattern function format*

 Parameters
    uint16_t *  ptrnPointer:	 pointer to pattern image buffer
    uint8_t *   ptrnStepCounter: pointer to an incremental counter variable
    uint32_t *  cycleCounter:    additional incremental counter variable
    uint8_t     base_hue:		 base color hue for pattern (8-bit)
    uint8_t     base_sat:		 base color saturation for pattern (4-bit)
    void *      genericPointer:  general-use pointer for referencing external data
                                  (e.g. an analog value or an array of constants)
 Returns
    void

 Description
    fills an image buffer with HSV-encoded colors based on step-based calculations 
 Notes
   
 Author
    lxw, 1/10/16, 01:30
****************************************************************************/

 /*		Passive Patterns (no position control)		*/
 //moving rainbow test (default starting/TEST pattern)
void HueTest(uint16_t * ptrnPointer, uint8_t  * ptrnStepCounter, uint32_t * cycleCounter, uint8_t base_hue, uint8_t base_sat, void*){
	
    #ifdef HSV_PATTERNS
     //for each pixel in the LED strip
    for(uint8_t i=0;i<STRIP_LENGTH;i++){
         //set it to a HSV color with changing hue, based on its position and pattern step counter
        ptrnPointer[i] = (((uint16_t)(i+*ptrnStepCounter)*255/STRIP_LENGTH)<<8) | (base_sat<<4) | FULL_VAL;
    }
     //increment pattern step coounter
    *ptrnStepCounter = (*ptrnStepCounter+1)%STRIP_LENGTH;
    #endif

    #ifdef RGB_PATTERNS
    uint8_t r, g, b;
    switch(*ptrnStepCounter/43){
        case 0:
            r = 0x0F;
            g = (*ptrnStepCounter%43)*15/43;
            b = 0;
            break;
        case 1:
            r = 0x0F-(*ptrnStepCounter%43)*15/43;
            g = 0x0F;
            b = 0x0;
            break;
        case 2:
            r = 0;
            g = 0x0F;
            b = (*ptrnStepCounter%43)*15/43;
            break;
        case 3:
            r = 0;
            g = 0x0F-(*ptrnStepCounter%43)*15/43;
            b = 0x0F;
            break;
        case 4:
            r = (*ptrnStepCounter%43)*15/43;
            g = 0;
            b = 0x0F;
            break;
        default:
            r = 0x0F;
            g = 0;
            b = 0x0F-(*ptrnStepCounter%43)*15/43;
            break;
    }
    for(uint8_t i=0;i<STRIP_LENGTH;i++){
        ptrnPointer[i] = ((uint16_t)r<<8) | ((uint16_t)g<<4) | (uint16_t)(b);
    }
    *ptrnStepCounter=*ptrnStepCounter+1;
    #endif
	
} 

 //single full mirror pulse then hold (default WELCOME)
void FullPulseHold(uint16_t * ptrnPointer, uint8_t * ptrnStepCounter, uint32_t * cycleCounter, uint8_t base_hue, uint8_t base_sat, void*){
	static bool rising = true;
    uint8_t val;
    
     //scale value according to stepCount
    val = (*ptrnStepCounter>>4);
    for(uint8_t i=0;i<STRIP_LENGTH;i++){
         //set HSV color to each pixel
        ptrnPointer[i] = ((uint16_t)base_hue<<8) | (base_sat<<4) | val;
    }
     //check if pattern is at max value or min value
    if(*ptrnStepCounter == 255){
        rising = false;
        *cycleCounter = *cycleCounter+1;
    }
    else if(*ptrnStepCounter == 0){
        rising = true;
        *cycleCounter = *cycleCounter+1;
    }
     //increment pattern step counter based on cycle count and waning/waxing status
    if(*cycleCounter < 4){
        *ptrnStepCounter = (rising ? *ptrnStepCounter+15 : *ptrnStepCounter-15);
    }
}

 //"breathing" pulse in center bottom (default IDLE)
void CenterBreathe(uint16_t * ptrnPointer, uint8_t * ptrnStepCounter, uint32_t * cycleCounter, uint8_t base_hue, uint8_t base_sat, void*){
	static bool rising = true;
    uint8_t fade_thresh = 10;
    uint8_t val, x, pulseWidth;
    
    pulseWidth = 15;
    for(uint8_t i=0;i<STRIP_LENGTH;i++){
        x = min((STRIP_LENGTH+i-CENTER_PIXEL)%STRIP_LENGTH,(STRIP_LENGTH+CENTER_PIXEL-i)%STRIP_LENGTH);
        val = (x < fade_thresh ? (*ptrnStepCounter>>4) : (x < pulseWidth ? (*ptrnStepCounter-*ptrnStepCounter*x/pulseWidth)>>4 : 0x00));
        ptrnPointer[i] = ((uint16_t)base_hue<<8) | (base_sat<<4) | val;
    }
    if(*ptrnStepCounter >= 241){
        rising = false;
    }
    else if(*ptrnStepCounter <= 60){
        rising = true;
    }
    *ptrnStepCounter = (rising ? *ptrnStepCounter+15 : *ptrnStepCounter-15);
	
}

 //single faded bar looping mirror (default THINKING)
void SingleFadedLoop(uint16_t * ptrnPointer, uint8_t * ptrnStepCounter, uint32_t * cycleCounter, uint8_t base_hue, uint8_t base_sat, void*){
    uint8_t val, x;
    
    for(uint8_t i=0;i<STRIP_LENGTH;i++){
         //scale fade according to minimum distance from head (stepCount)
        x = min((STRIP_LENGTH+i-*ptrnStepCounter)%STRIP_LENGTH,(STRIP_LENGTH+*ptrnStepCounter-i)%STRIP_LENGTH);
        val = (x < FADE_LENGTH ? FULL_VAL-x*FULL_VAL/FADE_LENGTH : 0x00);
         //set HSV value to the current pixel index
        ptrnPointer[i] = ((uint16_t)base_hue<<8) | (base_sat<<4) | val;
    }
     //increment pattern step counter
    *ptrnStepCounter = (*ptrnStepCounter+1)%STRIP_LENGTH;
}

 //two faded bars looping mirror (default Pattern 7)
void DoubleFadedLoop(uint16_t * ptrnPointer, uint8_t * ptrnStepCounter, uint32_t * cycleCounter, uint8_t base_hue, uint8_t base_sat, void*){
    uint8_t val, x;
    
    for(uint8_t i=0;i<STRIP_LENGTH/4;i++){
        x = min((STRIP_LENGTH+i)%STRIP_LENGTH,(STRIP_LENGTH-i)%STRIP_LENGTH);
        val = (x < FADE_LENGTH ? FULL_VAL-x*FULL_VAL/FADE_LENGTH : 0x00);
        ptrnPointer[(i+*ptrnStepCounter)%STRIP_LENGTH] = ((uint16_t)base_hue<<8) | (base_sat<<4) | val;
        ptrnPointer[(i+STRIP_LENGTH/2+*ptrnStepCounter)%STRIP_LENGTH] = ((uint16_t)base_hue<<8) | (base_sat<<4) | val;
    }
    for(uint8_t i=STRIP_LENGTH*3/4;i<STRIP_LENGTH;i++){
        x = min((STRIP_LENGTH+i)%STRIP_LENGTH,(STRIP_LENGTH-i)%STRIP_LENGTH);
        val = (x < FADE_LENGTH ? FULL_VAL-x*FULL_VAL/FADE_LENGTH : 0x00);
        ptrnPointer[(i+*ptrnStepCounter)%STRIP_LENGTH] = ((uint16_t)base_hue<<8) | (base_sat<<4) | val;
        ptrnPointer[(i-STRIP_LENGTH/2+*ptrnStepCounter)%STRIP_LENGTH] = ((uint16_t)base_hue<<8) | (base_sat<<4) | val;
    }
    *ptrnStepCounter = (*ptrnStepCounter+1)%STRIP_LENGTH;
}

 //same as previous (DoubleFadedLoop), but terminates halfway through loop
void DoubleBrokenLoop(uint16_t * ptrnPointer, uint8_t * ptrnStepCounter, uint32_t * cycleCounter, uint8_t base_hue, uint8_t base_sat, void*){
    uint8_t val, x;
    
    for(uint8_t i=0;i<STRIP_LENGTH/2;i++){
        x = min((STRIP_LENGTH+i-*ptrnStepCounter)%STRIP_LENGTH,(STRIP_LENGTH+*ptrnStepCounter-i)%STRIP_LENGTH);
        val = (x < FADE_LENGTH ? FULL_VAL-x*FULL_VAL/FADE_LENGTH : 0x00);
        ptrnPointer[i] = ((uint16_t)base_hue<<8) | (base_sat<<4) | val;
        ptrnPointer[i+STRIP_LENGTH/2] = ((uint16_t)base_hue<<8) | (base_sat<<4) | val;
    }
    *ptrnStepCounter = (*ptrnStepCounter+1)%STRIP_LENGTH;
}

 //broken loop expanded to 8 bars (default Pattern 8)
void BrokenPinwheel(uint16_t * ptrnPointer, uint8_t * ptrnStepCounter, uint32_t * cycleCounter, uint8_t base_hue, uint8_t base_sat, void*){
    uint8_t val, x;
    uint8_t fade = 2;
    
    for(uint8_t i=0;i<STRIP_LENGTH/8;i++){
        x = min((STRIP_LENGTH+i-*ptrnStepCounter)%STRIP_LENGTH,(STRIP_LENGTH+*ptrnStepCounter-i)%STRIP_LENGTH);
        val = (x < fade ? FULL_VAL-x*FULL_VAL/fade : 0x00);
        ptrnPointer[i] = ((uint16_t)base_hue<<8) | (base_sat<<4) | val;
        ptrnPointer[i+STRIP_LENGTH/8] = ((uint16_t)base_hue<<8) | (base_sat<<4) | val;
        ptrnPointer[i+STRIP_LENGTH/4] = ((uint16_t)base_hue<<8) | (base_sat<<4) | val;
        ptrnPointer[i+STRIP_LENGTH*3/8] = ((uint16_t)base_hue<<8) | (base_sat<<4) | val;
        ptrnPointer[i+STRIP_LENGTH/2] = ((uint16_t)base_hue<<8) | (base_sat<<4) | val;
        ptrnPointer[i+STRIP_LENGTH*5/8] = ((uint16_t)base_hue<<8) | (base_sat<<4) | val;
        ptrnPointer[i+STRIP_LENGTH*3/4] = ((uint16_t)base_hue<<8) | (base_sat<<4) | val;
        ptrnPointer[i+STRIP_LENGTH*7/8] = ((uint16_t)base_hue<<8) | (base_sat<<4) | val;
    }
    *ptrnStepCounter = (*ptrnStepCounter+1)%(STRIP_LENGTH/4);
}

 //faded bar mirrored across both axis (default Pattern 6)
void MirroredQuadrants(uint16_t * ptrnPointer, uint8_t * ptrnStepCounter, uint32_t * cycleCounter, uint8_t base_hue, uint8_t base_sat, void*){
    uint8_t val, x;
    
    for(uint8_t i=0;i<STRIP_LENGTH/4;i++){
        x = min((STRIP_LENGTH+i-*ptrnStepCounter)%STRIP_LENGTH,(STRIP_LENGTH+*ptrnStepCounter-i)%STRIP_LENGTH);
        val = (x < FADE_LENGTH ? FULL_VAL-x*FULL_VAL/FADE_LENGTH : 0x00);
        ptrnPointer[i] = ((uint16_t)base_hue<<8) | (base_sat<<4) | val;
        ptrnPointer[STRIP_LENGTH/2-1-i] = ((uint16_t)base_hue<<8) | (base_sat<<4) | val;
        ptrnPointer[i+STRIP_LENGTH/2] = ((uint16_t)base_hue<<8) | (base_sat<<4) | val;
        ptrnPointer[STRIP_LENGTH-1-i] = ((uint16_t)base_hue<<8) | (base_sat<<4) | val;
    }
    *ptrnStepCounter = (*ptrnStepCounter+1)%(STRIP_LENGTH/2);
}

 /*		Active Patterns (active position control)		*/
 //short pulse, centered on "focus" location
void SingleFocusPulse(uint16_t * ptrnPointer, uint8_t * ptrnStepCounter, uint32_t * cycleCounter, uint8_t base_hue, uint8_t base_sat, void * focus){
    uint8_t val, x, y, head;
    head = *(uint8_t*)focus;
    
    for(uint8_t i=0;i<STRIP_LENGTH;i++){
        y = (FADE_LENGTH-*ptrnStepCounter%4);
        x = min((STRIP_LENGTH+i-head)%STRIP_LENGTH,(STRIP_LENGTH+head-i)%STRIP_LENGTH);
        val = (x < y ? 0x0F-x*0x0F/y : 0x00);
        ptrnPointer[i] = ((uint16_t)base_hue<<8) | (base_sat<<4) | val;
    }
    *ptrnStepCounter = (*ptrnStepCounter+1)%STRIP_LENGTH;
}

 //shortened CenterBreathe on "focus" (default LISTENING)
void SingleFocusBreathe(uint16_t * ptrnPointer, uint8_t * ptrnStepCounter, uint32_t * cycleCounter, uint8_t base_hue, uint8_t base_sat, void * focus){
    static bool rising = true;
    uint8_t fade_thresh = 8;
    uint8_t val, x, pulseWidth;
    uint8_t head = *(uint8_t*)focus;
    
    pulseWidth = 8;
    for(uint8_t i=0;i<STRIP_LENGTH;i++){
         //scale value according to stepCount
        x = min((STRIP_LENGTH+i-head)%STRIP_LENGTH,(STRIP_LENGTH+head-i)%STRIP_LENGTH);
        val = (x < fade_thresh ? (*ptrnStepCounter>>4) : (x < pulseWidth ? (*ptrnStepCounter-*ptrnStepCounter*x/pulseWidth)>>4 : 0x00));
        ptrnPointer[i] = ((uint16_t)base_hue<<8) | (base_sat<<4) | val;
    }
    if(*ptrnStepCounter >= 216){
        rising = false;
    }
    else if(*ptrnStepCounter <= 80){
        rising = true;
    }
    *ptrnStepCounter = (rising ? *ptrnStepCounter+40 : *ptrnStepCounter-40);
}

/*  Template pattern function example
void TemplatePattern(uint16_t * ptrnPointer, uint8_t * ptrnStepCounter, uint32_t * cycleCounter, uint8_t base_hue, uint8_t base_sat, void * genericPointer){
    uint8_t val;
    
     //iterate through the pixels in the strip
    for(uint8_t i=0;i<STRIP_LENGTH;i++){
         //modify the val somehow
        val = i*FULL_VAL/STRIP_LENGTH; //scale the LEDs value according to its 
                                       // position in the strip
         
            //the use of the ptrnStepCounter, cycleCounter, and genericPointer 
            //are not necessary, but can help make more dynamic patterns
   
         //add a cyclical pulse
        val = val*(*ptrnStepCounter)/STRIP_LENGTH;
         //write the HSV to the Pixel
        ptrnPointer[i] = ((uint16_t)base_hue<<8) | (base_sat<<4) | val;
    }
     //increment the ptrnStepCounter
    *ptrnStepCounter = *ptrnStepCounter + 1;
     //if ptrnStepCounter is rolling over, increment the cycleCounter
    *cycleCounter = (*ptrnStepCounter == 0 ?  *cycleCounter + 1 : *cycleCounter);
}
*/
