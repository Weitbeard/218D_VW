#ifndef CAN_Defs_H
#define	CAN_Defs_H

// Data Identifiers
#define START_MESSAGE 0x00
#define STOP_MESSAGE 0x01
#define RESET_MESSAGE 0x02
#define NEXT_PATTERN_MESSAGE 0x03
#define NO_NEW_INPUT 0xFF

//Pins to Toggle for Debugging
#define IDLE_PIN LATA0
#define LOADING_PIN LATA1
#define SPEAKING_PIN LATA2
#define LISTENING_PIN LATA3

//Identifiers
#define SIDH 0x00
#define SIDL 0x18
#define EIDH 0x00
#define EIDL 0x01

#endif