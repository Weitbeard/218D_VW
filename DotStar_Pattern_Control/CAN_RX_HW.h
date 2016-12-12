/* 
 * File:   CAN_RX_HW.h
 * Author: jeannywang
 *
 * Created on November 23, 2016, 11:44 PM
 * Modified 12/10 by lw for conversion of service to module
 */

#ifndef CAN_RX_HW_H
#define	CAN_RX_HW_H

 //the common headers for C99 types 
#include "ES_Types.h"

 //function prototypes
void CAN_Init(void);
void CAN_XmitResponse(void); 
void CAN_ReceiveResponse(void);
void CAN_ErrorResponse(void);
void CAN_BusErrorResponse(void);

//uint8_t CAN_GetCurrentPattern(void);
//uint8_t CAN_GetListLoc(void);
//uint8_t CAN_GetBrightness(void);

#endif	/* CAN_RX_HW_H */
