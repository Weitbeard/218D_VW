/****************************************************************************
 
  Header file for the DotStar SPI32 Control Service
  based on the Gen2 Events and Services Framework

 ****************************************************************************/

#ifndef SPI32_ControlService_H
#define SPI32_ControlService_H

// Event Definitions
#include "ES_Configure.h" /* gets us event definitions */
#include "ES_Types.h"     /* gets bool type for returns */

// typedefs for the states
// State definitions for use with the query function
typedef enum { SPI32_Startup,
               SPI32_Waiting4Send,
               SPI32_Transmitting
              } SPI32State_t ;
              
// Service function prototypes
bool InitSPI32ControlService( uint8_t Priority );
bool PostSPI32ControlService( ES_Event ThisEvent );
ES_Event RunSPI32ControlService( ES_Event ThisEvent );

// Other public functions
void SPI32_TransmitFrames(uint32_t *framePointer, uint8_t numFrames);

#endif /* SPI32_ControlService_H */
