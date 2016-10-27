/* 
 * File:   SPI_Service.h
 *
 * Created on October 19, 2016, 2:20 PM
 */

#ifndef SPI_SERVICE_H
#define	SPI_SERVICE_H

#include "ES_Types.h"

typedef enum { Sending, Waiting2Send} SPIState_t ;
// Public Function Prototypes

bool InitSPI_Service ( uint8_t Priority );
bool PostSPI_Service( ES_Event ThisEvent );
ES_Event RunSPI_Service( ES_Event ThisEvent );
void EOTResponse(void);
void sendByte(uint8_t Data);

#endif	/* SPI_SERVICE_H */
