/****************************************************************************
 Module
     Pattern_DotStarLED.h
 Description
     header file for the hardware control of a DotStar LED strip
 Notes

 History
 When           Who     What/Why
 -------------- ---     --------
 10/28/16 01:20 lxw      first pass
*****************************************************************************/

#ifndef Pattern_DotStarLED_H
#define Pattern_DotStarLED_H

 //the common headers for C99 types 
#include "ES_Configure.h"
#include "ES_Types.h"

 //function prototypes
void DotStar_Init(uint8_t numPixels, uint8_t brightness);
void DotStar_Show(uint16_t *pixelPointer);
uint8_t DotStar_GetLength(void);
void DotStar_SetBrightness(uint8_t brightness);

#endif /* Pattern_DotStarLED_H */
