/****************************************************************************
 Module
     Pattern_HSV_Convert.h
 Description
     header file for 16-bit HSV -> 24-bit RGB color conversion
 Notes

 History
 When           Who     What/Why
 -------------- ---     --------
 10/28/16 02:00 lxw      first pass
*****************************************************************************/

#ifndef Pattern_HSV_Convert_H
#define Pattern_HSV_Convert_H

 //the common headers for C99 types 
#include "ES_Types.h"

 //function prototypes
void HSV_to_RGB(uint32_t *);

#endif /* Pattern_HSV_Convert_H */
