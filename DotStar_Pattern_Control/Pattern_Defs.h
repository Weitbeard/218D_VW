#ifndef Pattern_Defs_H
#define	Pattern_Defs_H
#include "Pattern_PtrnFunctions.h"

 //PATTERN_TEST define for debugging
#define PATTERN_TEST_ENABLE

 //Defines for using 16-bit HSV or RGB patterns (choose one to enable)
#define HSV_PATTERNS
//#define RGB_PATTERNS //!!! RGB MODE NOT FULLY SUPPORTED !!!

 //Pattern fade tail length define
#define FADE_LENGTH     5

 //Pattern selection & behavior configurations
    //Test pattern configuration
#define TEST_PTRN       HueTest
#define TEST_HUE        0
#define TEST_SAT        0x0F

    //Welcome pattern configuration
#define WELCOME_PTRN    FullPulseHold
#define WELCOME_HUE     135
#define WELCOME_SAT     4

    //Idle pattern configuration
#define IDLE_PTRN       TopPulse
#define IDLE_HUE        135
#define IDLE_SAT        4

    //Listening pattern configuration
#define LISTENING_PTRN  SingleFocusPulse
#define LISTENING_HUE   85
#define LISTENING_SAT   0x0F

    //Listening2 (demo) pattern configuration
#define LISTENING2_PTRN DoubleFocusPulse
#define LISTENING2_HUE  85
#define LISTENING2_SAT  0x0F

    //Thinking pattern configuration
#define THINKING_PTRN   SingleFadedLoop
#define THINKING_HUE    32
#define THINKING_SAT    0x0F

    //Speaking pattern configuration
#define SPEAKING_PTRN   SingleFocusPulse
#define SPEAKING_HUE    170
#define SPEAKING_SAT    0x0F

 //General LED strip defines
#define STRIP_LENGTH        76  //76 is appropriate value for the supplied prototype
#define MAX_STRIP_LENGTH    76  //Max strip length limited by available memory space for image buffers
#define CENTER_PIXEL        (STRIP_LENGTH%2 ? STRIP_LENGTH/2-1: (STRIP_LENGTH-1)/2)

 //LED pattern configuration array defines
#define NUM_CONFIGS     4
#define	CUR_PATTERN     0
#define	BRIGHTNESS      1
#define	LISTEN_FOCUS	2
#define	CYC_SPEED       3

 //Pattern ID defines
#define NUM_PATTERNS        6
#define	NO_PATTERN          0
#define WELCOME_PATTERN     1 
#define	IDLE_PATTERN        2
#define	LISTENING_PATTERN   3
#define	THINKING_PATTERN    4
#define	SPEAKING_PATTERN    5
#define	TEST_PATTERN        0xFF
 //LED brightness defines
#define FULL_BRIGHT		0x1F
#define	MID_BRIGHT		0x0F
#define TEST_BRIGHT     0x1F
 //Pattern profile defines
#define DEFAULT_FOCUS   CENTER_PIXEL
 //Pattern cycle speed defines
#define	DEFAULT_SPEED	1
 //Misc. pattern defines
#define FULL_SAT        0x0F
#define FULL_VAL        0x0F

#endif