/****************************************************************************
 Module
   Pattern_HSVPtrnFunctions.c

 Revision
   1.0.1 

 Description
   Module to hold the HSV-encoded pattern-generating functions
   
 Notes
   
   
 History
 When            Who     What/Why
 --------------- ---     --------
 10/028/16 01:30 lxw     first pass
****************************************************************************/

#include "ES_Types.h"
#include "stdlib.h"

#include "ES_Configure.h"
#include "ES_Framework.h"

#include "Pattern_Defs.h"

 /*		Passive Patterns (no position control)		*/
void HueTest(uint16_t * ptrnPointer, uint8_t  * ptrnStepCounter, uint32_t * cycleCounter, uint8_t base_hue, uint8_t base_sat, void*){
	
    #ifdef HSV_PATTERNS
    for(uint8_t i=0;i<STRIP_LENGTH;i++){
        ptrnPointer[i] = (((uint16_t)(i+*ptrnStepCounter)*255/STRIP_LENGTH)<<8) | (base_sat<<4) | FULL_VAL;
    }
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
 
void FullPulseHold(uint16_t * ptrnPointer, uint8_t * ptrnStepCounter, uint32_t * cycleCounter, uint8_t base_hue, uint8_t base_sat, void*){
	static bool rising = true;
    uint8_t val;
    
     //scale value according to stepCount
    val = (*ptrnStepCounter>>4);
    for(uint8_t i=0;i<STRIP_LENGTH;i++){
        ptrnPointer[i] = ((uint16_t)base_hue<<8) | (base_sat<<4) | val;
    }
    if(*ptrnStepCounter == 255){
        rising = false;
        *cycleCounter = *cycleCounter+1;
    }
    else if(*ptrnStepCounter == 0){
        rising = true;
        *cycleCounter = *cycleCounter+1;
    }
    if(*cycleCounter < 4){
        *ptrnStepCounter = (rising ? *ptrnStepCounter+15 : *ptrnStepCounter-15);
    }
}

void CenterBreathe(uint16_t * ptrnPointer, uint8_t * ptrnStepCounter, uint32_t * cycleCounter, uint8_t base_hue, uint8_t base_sat, void*){
	static bool rising = true;
    uint8_t fade_thresh = 10;
    uint8_t val, x, pulseWidth;
    
    pulseWidth = 15;
    for(uint8_t i=0;i<STRIP_LENGTH;i++){
         //scale value according to stepCount
        x = min((STRIP_LENGTH+i-CENTER_PIXEL)%STRIP_LENGTH,(STRIP_LENGTH+CENTER_PIXEL-i)%STRIP_LENGTH);
        val = (x < fade_thresh ? (ptrnPointer[i]>>4) : (x < pulseWidth ? (*ptrnStepCounter-*ptrnStepCounter*x/pulseWidth)>>4 : 0x00));
        ptrnPointer[i] = ((uint16_t)base_hue<<8) | (base_sat<<4) | val;
    }
    if(*ptrnStepCounter == 255){
        rising = false;
    }
    else if(*ptrnStepCounter == 0){
        rising = true;
    }
    *ptrnStepCounter = (rising ? *ptrnStepCounter+15 : *ptrnStepCounter-15);
	
}

void SingleFadedLoop(uint16_t * ptrnPointer, uint8_t * ptrnStepCounter, uint32_t * cycleCounter, uint8_t base_hue, uint8_t base_sat, void*){
    uint8_t val, x;
    
    for(uint8_t i=0;i<STRIP_LENGTH;i++){
         //scale fade according to minimum distance from head (stepCount)
        x = min((STRIP_LENGTH+i-*ptrnStepCounter)%STRIP_LENGTH,(STRIP_LENGTH+*ptrnStepCounter-i)%STRIP_LENGTH);
        val = (x < FADE_LENGTH ? 0x0F-x*0x0F/FADE_LENGTH : 0x00);
        ptrnPointer[i] = ((uint16_t)base_hue<<8) | (base_sat<<4) | val;
    }
    *ptrnStepCounter = (*ptrnStepCounter+1)%STRIP_LENGTH;
}

void DoubleFadedLoop(uint16_t * ptrnPointer, uint8_t * ptrnStepCounter, uint32_t * cycleCounter, uint8_t base_hue, uint8_t base_sat, void*){
    uint8_t val, x;
    
    for(uint8_t i=0;i<STRIP_LENGTH;i++){
         //scale fade according to minimum distance from head (stepCount)
        x = min((STRIP_LENGTH+i-*ptrnStepCounter)%STRIP_LENGTH,(STRIP_LENGTH+*ptrnStepCounter-i)%STRIP_LENGTH,
                (STRIP_LENGTH+i-(*ptrnStepCounter+CENTER_PIXEL))%STRIP_LENGTH,(STRIP_LENGTH+(*ptrnStepCounter+CENTER_PIXEL)-i)%STRIP_LENGTH);
        val = (x < FADE_LENGTH ? 0x0F-x*0x0F/FADE_LENGTH : 0x00);
        ptrnPointer[i] = ((uint16_t)base_hue<<8) | (base_sat<<4) | val;
    }
    *ptrnStepCounter = (*ptrnStepCounter+1)%STRIP_LENGTH;
}

 /*		Active Patterns (active position control)		*/
void SingleFocusPulse(uint16_t * ptrnPointer, uint8_t * ptrnStepCounter, uint32_t * cycleCounter, uint8_t base_hue, uint8_t base_sat, void * focus){
    uint8_t val, x, head;
    head = *(uint8_t*)focus;
    
    for(uint8_t i=0;i<STRIP_LENGTH;i++){
         //scale fade according to minimum distance from head (stepCount)
        x = min((STRIP_LENGTH+i-head)%STRIP_LENGTH,(STRIP_LENGTH+head)%STRIP_LENGTH);
        val = (x < FADE_LENGTH ? 0x0F-x*0x0F/FADE_LENGTH : 0x00);
        ptrnPointer[i] = ((uint16_t)base_hue<<8) | (base_sat<<4) | val;
    }
    *ptrnStepCounter = *ptrnStepCounter+50;
}

void DoubleFocusPulse(uint16_t * ptrnPointer, uint8_t * ptrnStepCounter, uint32_t * cycleCounter, uint8_t base_hue, uint8_t base_sat, void * focus){
	
}
