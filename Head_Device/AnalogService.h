/****************************************************************************
 Module
     AnalogService.h
 Description
     header file for pattern control of a RGB LED strip
 Notes

*****************************************************************************/

#ifndef ANALOGSERVICE_H
#define ANALOGSERVICE_H

 //the common headers for C99 types 
#include "ES_Types.h"

 //function prototypes
bool InitAnalogService( uint8_t Priority );
bool PostAnalogService( ES_Event ThisEvent );
ES_Event RunAnalogService( ES_Event ThisEvent );
uint16_t GetBrightness(void);
uint16_t GetLocation(void);
void AnalogISR(void); 


#endif /* ANALOGSERVICE_H */
