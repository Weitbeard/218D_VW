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
	//Passive Patterns - self-contained patterns
void HueTest(uint16_t *, uint8_t *, uint32_t *, uint8_t, uint8_t, void *);            //moving rainbow test (default starting/TEST pattern)
void FullPulseHold(uint16_t *, uint8_t *, uint32_t *, uint8_t, uint8_t, void *);      //single full mirror pulse then hold (default WELCOME)
void CenterBreathe(uint16_t *, uint8_t *, uint32_t *, uint8_t, uint8_t, void *);      //breathing pulse in center bottom (default IDLE)
void SingleFadedLoop(uint16_t *, uint8_t *, uint32_t *, uint8_t, uint8_t, void *);    //single faded bar looping mirror (default THINKING)
void DoubleFadedLoop(uint16_t *, uint8_t *, uint32_t *, uint8_t, uint8_t, void *);    //two faded bars looping mirror (default Pattern 7)
void DoubleBrokenLoop(uint16_t *, uint8_t *, uint32_t *, uint8_t, uint8_t, void *);   //same as previous, but terminates halfway through loop
void BrokenPinwheel(uint16_t *, uint8_t *, uint32_t *, uint8_t, uint8_t, void *);     //broken loop expanded to 8 bars (default Pattern 8)
void MirroredQuadrants(uint16_t *, uint8_t *, uint32_t *, uint8_t, uint8_t, void *);  //faded bar mirrored across both axis (default Pattern 6)
	//Active Patterns - require pointer to ?focus? analog value
void SingleFocusPulse(uint16_t *, uint8_t *, uint32_t *, uint8_t, uint8_t, void *);   //short pulse, centered on "focus" location
void SingleFocusBreathe(uint16_t *, uint8_t *, uint32_t *, uint8_t, uint8_t, void *); //shortened CenterBreathe on "focus" (default LISTENING)

//void TemplatePattern(uint16_t *, uint8_t *, uint32_t *, uint8_t, uint8_t, void *);

#endif /* Pattern_PtrnFunctions_H */
