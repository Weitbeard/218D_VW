#ifndef Pattern_Defs_H
#define	Pattern_Defs_H
#include "Pattern_PtrnFunctions.h"

 //PATTERN_TEST define for debugging
#define PATTERN_TEST_ENABLE

 //Defines for using 16-bit HSV or RGB patterns (choose one to enable)
#define HSV_PATTERNS
//#define RGB_PATTERNS //!!! RGB MODE NOT FULLY SUPPORTED !!!

/*********** Pattern selection & behavior configurations ***************/
#define NUM_PATTERNS        9 //number of patterns excluding TEST_PATTERN
#define	NO_PATTERN          0 //index for default blank pattern

    //Test pattern configuration
#define TEST_PATTERN        0xFF
#define TEST_HUE            0
#define TEST_SAT            0x0F

    //Welcome pattern configuration
#define WELCOME_PATTERN     1   //pattern index
#define WELCOME_HUE         135 //base color hue for the pattern
#define WELCOME_SAT         4   //base color saturation for the pattern

    //Idle pattern configuration
#define	IDLE_PATTERN        2
#define IDLE_HUE            135
#define IDLE_SAT            4

    //Listening pattern configuration
#define LISTENING_PATTERN   3
#define LISTENING_HUE       85
#define LISTENING_SAT       0x0F

    //Thinking pattern configuration
#define THINKING_PATTERN    4
#define THINKING_HUE        32
#define THINKING_SAT        0x0F

    //Speaking pattern configuration
#define SPEAKING_PATTERN    5
#define SPEAKING_HUE        170
#define SPEAKING_SAT        0x0F

    /**** DEFINE NEW CUSTOM PATTERN CONFIGURATIONS HERE ****/

    //Custom (demo) pattern configuration 1
#define CUSTOM1_PATTERN     6
#define CUSTOM1_HUE         WELCOME_HUE
#define CUSTOM1_SAT         0x04

    //Custom (demo) pattern configuration 2
#define CUSTOM2_PATTERN     7
#define CUSTOM2_HUE         0
#define CUSTOM2_SAT         0x0F

    //Custom (demo) pattern configuration 3
#define CUSTOM3_PATTERN     8
#define CUSTOM3_HUE         0
#define CUSTOM3_SAT         0x0F

/*
 #define TEMPLATE_PATTERN   9
 #define TEMPLATE_HUE       0
 #define TEMPLATE_SAT       0x0F
*/

    /**********************  END  **************************/

/************************************************************************/

 //General LED strip defines
#define STRIP_LENGTH        76  //76 is appropriate value for the supplied prototype
#define MAX_STRIP_LENGTH    76  //Max strip length limited by available memory space for image buffers
#define CENTER_PIXEL        (STRIP_LENGTH%2 ? STRIP_LENGTH/2-1: (STRIP_LENGTH-1)/2)

 //LED pattern configs array defines
#define NUM_CONFIGS     4
#define	CUR_PATTERN     0
#define	BRIGHTNESS      1
#define	LISTEN_FOCUS	2
#define	CYC_SPEED       3
 //LED brightness defines
#define FULL_BRIGHT		0x1F
#define	MID_BRIGHT		0x0F
#define TEST_BRIGHT     0x1F
 //Pattern profile defines
#define DEFAULT_FOCUS   CENTER_PIXEL
 //Pattern cycle speed defines
#define	DEFAULT_SPEED	1 //1 is max update & display speed for the provided framework/hardware
 //Misc. pattern defines
#define FULL_SAT        0x0F
#define FULL_VAL        0x0F
#define FADE_LENGTH     5

#endif
