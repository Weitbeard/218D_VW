/****************************************************************************
 Module
     Pattern_PtrnGenerator.h
 Description
     header file for pattern generator for a circular LED strip
 Notes

 History
 When           Who     What/Why
 -------------- ---     --------
 10/28/16 02:00 lxw      first pass
*****************************************************************************/

#ifndef Pattern_PtrnGenerator_H
#define Pattern_PtrnGenerator_H

 //the common headers for C99 types 
#include "ES_Types.h"

 //function prototypes
void SetupPattern(uint8_t *patternIDPointer, uint8_t *listeningFocusPointer);
uint16_t * PatternOff(void);
uint16_t * UpdatePattern(void);
void ResetPattern(void);

#endif /* Pattern_PtrnGenerator_H */
