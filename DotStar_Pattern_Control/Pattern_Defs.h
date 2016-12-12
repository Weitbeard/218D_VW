#ifndef Pattern_Defs_H
#define	Pattern_Defs_H

 //PATTERN_TEST define for debugging
#define PATTERN_TEST
#define TEST_SATURATION 0x0F
#define TEST_VALUE      0x0F

 //Defines for using 16-bit HSV or RGB patterns
#define HSV_PATTERNS
//#define RGB_PATTERNS

 //Memory location offset for image buffers
#define BANK_0_GPR  0x060
#define BANK_2_GPR  0x200

 //Pattern defines
#define SINGLE_FADE_LOOP    1
#define DOUBLE_FADE_LOOP    2
#define SINGLE_REBOUND      3
#define DOUBLE_REBOUND      4
#define FULL_PULSE          5
#define TOP_PULSE           6

 //Pattern color defines
#define WELCOME_HUE     135
#define WELCOME_SAT     4

#define IDLE_HUE        135
#define IDLE_SAT        4

#define LISTENING_HUE   85
#define THINKING_HUE    32
#define SPEAKING_HUE    170

 //General LED strip defines
#define STRIP_LENGTH        76
#define MAX_STRIP_LENGTH    76
#define CENTER_PIXEL        37

 //LED pattern configuration array defines
#define NUM_CONFIGS 5
#define	POWER_STATE	0
#define	CUR_PATTERN	1
#define	BRIGHTNESS	2
#define	CUR_PROFILE	3
#define	CYC_SPEED	4

 //LED status defines
#define ON	1
#define	OFF	0
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
#define DEFAULT_PROFILE	0
 //Pattern cycle speed defines
#define	DEFAULT_SPEED	1
#define HZ60            15
 //Pattern fade tail length define
#define FADE_LENGTH     5

#endif