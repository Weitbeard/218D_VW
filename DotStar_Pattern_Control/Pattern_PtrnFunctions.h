/****************************************************************************
 Module
     Pattern_PtrnFunctions.h
 Description
     header file for pattern function collection
 Notes

 History
 When           Who     What/Why
 -------------- ---     --------
 10/28/16 02:00 lxw      first pass
*****************************************************************************/

#ifndef Pattern_PtrnFunctions_H
#define Pattern_PtrnFunctions_H

 //the common headers for C99 types 
#include "ES_Types.h"

 //function prototypes for sample patterns
	//Passive Patterns
void HueTest(uint16_t *, uint8_t *, uint32_t *, uint8_t, uint8_t, void *);
void FullPulseHold(uint16_t *, uint8_t *, uint32_t *, uint8_t, uint8_t, void *);
void CenterBreathe(uint16_t *, uint8_t *, uint32_t *, uint8_t, uint8_t, void *);
void SingleFadedLoop(uint16_t *, uint8_t *, uint32_t *, uint8_t, uint8_t, void *);
void DoubleFadedLoop(uint16_t *, uint8_t *, uint32_t *, uint8_t, uint8_t, void *);
void DoubleBrokenLoop(uint16_t *, uint8_t *, uint32_t *, uint8_t, uint8_t, void *);
void BrokenPinwheel(uint16_t *, uint8_t *, uint32_t *, uint8_t, uint8_t, void *);
void MirroredQuadrants(uint16_t *, uint8_t *, uint32_t *, uint8_t, uint8_t, void *);
	//Active Patterns
void SingleFocusPulse(uint16_t *, uint8_t *, uint32_t *, uint8_t, uint8_t, void *);

#endif /* Pattern_PtrnFunctions_H */
