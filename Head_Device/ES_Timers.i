#line 1 "ES_Timers.c"
#line 1 "ES_Timers.c"

#line 41 "ES_Timers.c"
 

 
#line 1 "./ES_Configure.h"

#line 19 "./ES_Configure.h"
 


#line 23 "./ES_Configure.h"

 



#line 29 "./ES_Configure.h"

 


#line 34 "./ES_Configure.h"

 





#line 42 "./ES_Configure.h"

#line 44 "./ES_Configure.h"

#line 46 "./ES_Configure.h"

#line 48 "./ES_Configure.h"

 



 

#line 56 "./ES_Configure.h"

#line 58 "./ES_Configure.h"

#line 60 "./ES_Configure.h"

#line 62 "./ES_Configure.h"

#line 64 "./ES_Configure.h"
#line 65 "./ES_Configure.h"

 

#line 69 "./ES_Configure.h"
#line 78 "./ES_Configure.h"

 

#line 82 "./ES_Configure.h"
#line 91 "./ES_Configure.h"

 

#line 95 "./ES_Configure.h"
#line 104 "./ES_Configure.h"

 

#line 108 "./ES_Configure.h"
#line 117 "./ES_Configure.h"

 

#line 121 "./ES_Configure.h"
#line 130 "./ES_Configure.h"

 

#line 134 "./ES_Configure.h"
#line 143 "./ES_Configure.h"

 

#line 147 "./ES_Configure.h"
#line 156 "./ES_Configure.h"

 

#line 160 "./ES_Configure.h"
#line 169 "./ES_Configure.h"

 

#line 173 "./ES_Configure.h"
#line 182 "./ES_Configure.h"

 

#line 186 "./ES_Configure.h"
#line 195 "./ES_Configure.h"

 

#line 199 "./ES_Configure.h"
#line 208 "./ES_Configure.h"

 

#line 212 "./ES_Configure.h"
#line 221 "./ES_Configure.h"

 

#line 225 "./ES_Configure.h"
#line 234 "./ES_Configure.h"

 

#line 238 "./ES_Configure.h"
#line 247 "./ES_Configure.h"


 


typedef enum {   
                ES_NO_EVENT = 0,
                ES_ERROR,   
                ES_INIT,    
                ES_TIMEOUT,  
                ES_SHORT_TIMEOUT,  
                 
                PATTERN_START,
                PATTERN_END,
                PATTERN_PAUSE,
                PATTERN_UNPAUSE,
                 
                SPI32_TRANSMIT
            } ES_EventTyp_t;

 



#line 272 "./ES_Configure.h"
#line 273 "./ES_Configure.h"
#line 275 "./ES_Configure.h"
#line 276 "./ES_Configure.h"
#line 278 "./ES_Configure.h"
#line 279 "./ES_Configure.h"
#line 281 "./ES_Configure.h"
#line 282 "./ES_Configure.h"
#line 284 "./ES_Configure.h"
#line 285 "./ES_Configure.h"
#line 287 "./ES_Configure.h"
#line 288 "./ES_Configure.h"
#line 290 "./ES_Configure.h"
#line 291 "./ES_Configure.h"
#line 293 "./ES_Configure.h"
#line 294 "./ES_Configure.h"
#line 296 "./ES_Configure.h"

 

#line 300 "./ES_Configure.h"

 

#line 304 "./ES_Configure.h"

 





#line 312 "./ES_Configure.h"
#line 313 "./ES_Configure.h"
#line 314 "./ES_Configure.h"
#line 315 "./ES_Configure.h"
#line 316 "./ES_Configure.h"
#line 317 "./ES_Configure.h"
#line 318 "./ES_Configure.h"
#line 319 "./ES_Configure.h"
#line 320 "./ES_Configure.h"
#line 321 "./ES_Configure.h"
#line 322 "./ES_Configure.h"
#line 323 "./ES_Configure.h"
#line 324 "./ES_Configure.h"
#line 325 "./ES_Configure.h"
#line 326 "./ES_Configure.h"
#line 327 "./ES_Configure.h"
#line 328 "./ES_Configure.h"

 






#line 337 "./ES_Configure.h"
#line 338 "./ES_Configure.h"
#line 339 "./ES_Configure.h"
#line 44 "ES_Timers.c"

#line 1 "./ES_Framework.h"

#line 14 "./ES_Framework.h"
 


#line 18 "./ES_Framework.h"

#line 1 "./ES_Port.h"

#line 20 "./ES_Port.h"
 

#line 23 "./ES_Port.h"



#line 1 "C:/Program Files (x86)/Microchip/mplabc18/v3.47/bin/../h/stdio.h"

#line 3 "C:/Program Files (x86)/Microchip/mplabc18/v3.47/bin/../h/stdio.h"

#line 1 "C:/Program Files (x86)/Microchip/mplabc18/v3.47/bin/../h/stdarg.h"
 


#line 5 "C:/Program Files (x86)/Microchip/mplabc18/v3.47/bin/../h/stdarg.h"

typedef void* va_list;
#line 8 "C:/Program Files (x86)/Microchip/mplabc18/v3.47/bin/../h/stdarg.h"
#line 9 "C:/Program Files (x86)/Microchip/mplabc18/v3.47/bin/../h/stdarg.h"
#line 10 "C:/Program Files (x86)/Microchip/mplabc18/v3.47/bin/../h/stdarg.h"
#line 11 "C:/Program Files (x86)/Microchip/mplabc18/v3.47/bin/../h/stdarg.h"
#line 12 "C:/Program Files (x86)/Microchip/mplabc18/v3.47/bin/../h/stdarg.h"
#line 4 "C:/Program Files (x86)/Microchip/mplabc18/v3.47/bin/../h/stdio.h"

#line 1 "C:/Program Files (x86)/Microchip/mplabc18/v3.47/bin/../h/stddef.h"
 

#line 4 "C:/Program Files (x86)/Microchip/mplabc18/v3.47/bin/../h/stddef.h"

typedef unsigned char wchar_t;


#line 10 "C:/Program Files (x86)/Microchip/mplabc18/v3.47/bin/../h/stddef.h"
 
typedef signed short int ptrdiff_t;
typedef signed short int ptrdiffram_t;
typedef signed short long int ptrdiffrom_t;


#line 20 "C:/Program Files (x86)/Microchip/mplabc18/v3.47/bin/../h/stddef.h"
 
typedef unsigned short int size_t;
typedef unsigned short int sizeram_t;
typedef unsigned short long int sizerom_t;


#line 34 "C:/Program Files (x86)/Microchip/mplabc18/v3.47/bin/../h/stddef.h"
 
#line 36 "C:/Program Files (x86)/Microchip/mplabc18/v3.47/bin/../h/stddef.h"


#line 41 "C:/Program Files (x86)/Microchip/mplabc18/v3.47/bin/../h/stddef.h"
 
#line 43 "C:/Program Files (x86)/Microchip/mplabc18/v3.47/bin/../h/stddef.h"

#line 45 "C:/Program Files (x86)/Microchip/mplabc18/v3.47/bin/../h/stddef.h"
#line 5 "C:/Program Files (x86)/Microchip/mplabc18/v3.47/bin/../h/stdio.h"



#line 9 "C:/Program Files (x86)/Microchip/mplabc18/v3.47/bin/../h/stdio.h"
 
#line 11 "C:/Program Files (x86)/Microchip/mplabc18/v3.47/bin/../h/stdio.h"

#line 13 "C:/Program Files (x86)/Microchip/mplabc18/v3.47/bin/../h/stdio.h"


typedef unsigned char FILE;

 
#line 19 "C:/Program Files (x86)/Microchip/mplabc18/v3.47/bin/../h/stdio.h"
#line 20 "C:/Program Files (x86)/Microchip/mplabc18/v3.47/bin/../h/stdio.h"

extern FILE *stderr;
extern FILE *stdout;


int putc (auto char c, auto FILE *f);
int vsprintf (auto char *buf, auto const far  rom char *fmt, auto va_list ap);
int vprintf (auto const far  rom char *fmt, auto va_list ap);
int sprintf (auto char *buf, auto const far  rom char *fmt, ...);
int printf (auto const far  rom char *fmt, ...);
int fprintf (auto FILE *f, auto const far  rom char *fmt, ...);
int vfprintf (auto FILE *f, auto const far  rom char *fmt, auto va_list ap);
int puts (auto const far  rom char *s);
int fputs (auto const far  rom char *s, auto FILE *f);

#line 36 "C:/Program Files (x86)/Microchip/mplabc18/v3.47/bin/../h/stdio.h"
#line 26 "./ES_Port.h"



#line 1 "./BITDEFS.H"

#line 3 "./BITDEFS.H"
 

 

#line 8 "./BITDEFS.H"

#line 10 "./BITDEFS.H"
#line 11 "./BITDEFS.H"
#line 12 "./BITDEFS.H"
#line 13 "./BITDEFS.H"
#line 14 "./BITDEFS.H"
#line 15 "./BITDEFS.H"
#line 16 "./BITDEFS.H"
#line 17 "./BITDEFS.H"
#line 18 "./BITDEFS.H"
#line 19 "./BITDEFS.H"
#line 20 "./BITDEFS.H"
#line 21 "./BITDEFS.H"
#line 22 "./BITDEFS.H"
#line 23 "./BITDEFS.H"
#line 24 "./BITDEFS.H"
#line 25 "./BITDEFS.H"
#line 26 "./BITDEFS.H"
#line 27 "./BITDEFS.H"
#line 28 "./BITDEFS.H"
#line 29 "./BITDEFS.H"
#line 30 "./BITDEFS.H"
#line 31 "./BITDEFS.H"
#line 32 "./BITDEFS.H"
#line 33 "./BITDEFS.H"
#line 34 "./BITDEFS.H"
#line 35 "./BITDEFS.H"
#line 36 "./BITDEFS.H"
#line 37 "./BITDEFS.H"
#line 38 "./BITDEFS.H"
#line 39 "./BITDEFS.H"
#line 40 "./BITDEFS.H"
#line 41 "./BITDEFS.H"

#line 43 "./BITDEFS.H"
#line 44 "./BITDEFS.H"
#line 45 "./BITDEFS.H"
#line 46 "./BITDEFS.H"
#line 47 "./BITDEFS.H"
#line 48 "./BITDEFS.H"
#line 49 "./BITDEFS.H"
#line 50 "./BITDEFS.H"
#line 51 "./BITDEFS.H"
#line 52 "./BITDEFS.H"
#line 53 "./BITDEFS.H"
#line 54 "./BITDEFS.H"
#line 55 "./BITDEFS.H"
#line 56 "./BITDEFS.H"
#line 57 "./BITDEFS.H"
#line 58 "./BITDEFS.H"
#line 59 "./BITDEFS.H"
#line 60 "./BITDEFS.H"
#line 61 "./BITDEFS.H"
#line 62 "./BITDEFS.H"
#line 63 "./BITDEFS.H"
#line 64 "./BITDEFS.H"
#line 65 "./BITDEFS.H"
#line 66 "./BITDEFS.H"
#line 67 "./BITDEFS.H"
#line 68 "./BITDEFS.H"
#line 69 "./BITDEFS.H"
#line 70 "./BITDEFS.H"
#line 71 "./BITDEFS.H"
#line 72 "./BITDEFS.H"
#line 73 "./BITDEFS.H"
#line 74 "./BITDEFS.H"

#line 76 "./BITDEFS.H"

#line 29 "./ES_Port.h"
        
#line 1 "./Bin_Const.h"

#line 3 "./Bin_Const.h"


#line 6 "./Bin_Const.h"
 

 

 


#line 15 "./Bin_Const.h"
 

#line 18 "./Bin_Const.h"

 

#line 27 "./Bin_Const.h"
#line 28 "./Bin_Const.h"

 
 

#line 33 "./Bin_Const.h"

 


#line 37 "./Bin_Const.h"
#line 38 "./Bin_Const.h"

 


#line 44 "./Bin_Const.h"
#line 45 "./Bin_Const.h"

#line 47 "./Bin_Const.h"


#line 52 "./Bin_Const.h"
 
#line 30 "./ES_Port.h"
      
#line 1 "./ES_Types.h"

#line 17 "./ES_Types.h"
 

#line 20 "./ES_Types.h"

 
#line 25 "./ES_Types.h"

#line 27 "./ES_Types.h"


 
 
#line 34 "./ES_Types.h"

#line 36 "./ES_Types.h"


#line 39 "./ES_Types.h"
#line 31 "./ES_Port.h"

























 
#line 58 "./ES_Port.h"
 
#line 60 "./ES_Port.h"



#line 70 "./ES_Port.h"
 
typedef enum {	ES_Timer_RATE_OFF  	=   (0),
				ES_Timer_RATE_100uS = 4000-1,
				ES_Timer_RATE_500uS = 20000-1,
				ES_Timer_RATE_1mS	= 40000-1,
				ES_Timer_RATE_2mS	= 80000-1,
				ES_Timer_RATE_4mS	= 160000-1,
				ES_Timer_RATE_5mS	= 200000-1,
				ES_Timer_RATE_8mS	= 320000-1,
				ES_Timer_RATE_10mS	= 400000-1,
				ES_Timer_RATE_16mS	= 640000-1,
				ES_Timer_RATE_32mS	= 1280000-1
} TimerRate_t;




#line 88 "./ES_Port.h"
#line 89 "./ES_Port.h"

#line 91 "./ES_Port.h"
#line 92 "./ES_Port.h"


void _HW_Timer_Init(TimerRate_t Rate);
bool _HW_Process_Pending_Ints( void );
uint16_t _HW_GetTickCount(void);




#line 102 "./ES_Port.h"
#line 19 "./ES_Framework.h"

#line 1 "./ES_Types.h"

#line 17 "./ES_Types.h"
 
#line 25 "./ES_Types.h"
#line 27 "./ES_Types.h"
#line 34 "./ES_Types.h"
#line 36 "./ES_Types.h"
#line 39 "./ES_Types.h"
#line 20 "./ES_Framework.h"

#line 1 "./ES_General.h"

#line 3 "./ES_General.h"

#line 5 "./ES_General.h"

#line 7 "./ES_General.h"
#line 8 "./ES_General.h"

#line 10 "./ES_General.h"
#line 21 "./ES_Framework.h"

#line 1 "./ES_CheckEvents.h"

#line 15 "./ES_CheckEvents.h"
 


#line 19 "./ES_CheckEvents.h"

#line 1 "./ES_Types.h"

#line 17 "./ES_Types.h"
 
#line 25 "./ES_Types.h"
#line 27 "./ES_Types.h"
#line 34 "./ES_Types.h"
#line 36 "./ES_Types.h"
#line 39 "./ES_Types.h"
#line 20 "./ES_CheckEvents.h"


typedef bool CheckFunc( void );

typedef CheckFunc (*pCheckFunc);

bool ES_CheckUserEvents( void );


#line 30 "./ES_CheckEvents.h"
#line 22 "./ES_Framework.h"

#line 1 "./ES_PostList.h"

#line 15 "./ES_PostList.h"
 

#line 18 "./ES_PostList.h"

#line 1 "./ES_Types.h"

#line 17 "./ES_Types.h"
 
#line 25 "./ES_Types.h"
#line 27 "./ES_Types.h"
#line 34 "./ES_Types.h"
#line 36 "./ES_Types.h"
#line 39 "./ES_Types.h"
#line 19 "./ES_PostList.h"

#line 1 "./ES_Events.h"

#line 16 "./ES_Events.h"
 


#line 20 "./ES_Events.h"

#line 1 "./ES_Types.h"

#line 17 "./ES_Types.h"
 
#line 25 "./ES_Types.h"
#line 27 "./ES_Types.h"
#line 34 "./ES_Types.h"
#line 36 "./ES_Types.h"
#line 39 "./ES_Types.h"
#line 21 "./ES_Events.h"

#line 1 "./ES_Configure.h"

#line 19 "./ES_Configure.h"
 

#line 56 "./ES_Configure.h"
#line 65 "./ES_Configure.h"
#line 69 "./ES_Configure.h"
#line 78 "./ES_Configure.h"
#line 82 "./ES_Configure.h"
#line 91 "./ES_Configure.h"
#line 95 "./ES_Configure.h"
#line 104 "./ES_Configure.h"
#line 108 "./ES_Configure.h"
#line 117 "./ES_Configure.h"
#line 121 "./ES_Configure.h"
#line 130 "./ES_Configure.h"
#line 134 "./ES_Configure.h"
#line 143 "./ES_Configure.h"
#line 147 "./ES_Configure.h"
#line 156 "./ES_Configure.h"
#line 160 "./ES_Configure.h"
#line 169 "./ES_Configure.h"
#line 173 "./ES_Configure.h"
#line 182 "./ES_Configure.h"
#line 186 "./ES_Configure.h"
#line 195 "./ES_Configure.h"
#line 199 "./ES_Configure.h"
#line 208 "./ES_Configure.h"
#line 212 "./ES_Configure.h"
#line 221 "./ES_Configure.h"
#line 225 "./ES_Configure.h"
#line 234 "./ES_Configure.h"
#line 238 "./ES_Configure.h"
#line 247 "./ES_Configure.h"
#line 273 "./ES_Configure.h"
#line 275 "./ES_Configure.h"
#line 276 "./ES_Configure.h"
#line 278 "./ES_Configure.h"
#line 279 "./ES_Configure.h"
#line 281 "./ES_Configure.h"
#line 282 "./ES_Configure.h"
#line 284 "./ES_Configure.h"
#line 285 "./ES_Configure.h"
#line 287 "./ES_Configure.h"
#line 288 "./ES_Configure.h"
#line 290 "./ES_Configure.h"
#line 291 "./ES_Configure.h"
#line 293 "./ES_Configure.h"
#line 294 "./ES_Configure.h"
#line 296 "./ES_Configure.h"
#line 339 "./ES_Configure.h"
#line 22 "./ES_Events.h"


typedef struct ES_Event_t {
    ES_EventTyp_t EventType;    
    uint16_t   EventParam;      
}ES_Event;


#line 31 "./ES_Events.h"
#line 20 "./ES_PostList.h"


typedef bool PostFunc_t( ES_Event );

typedef PostFunc_t (*pPostFunc);

bool ES_PostList00( ES_Event);
bool ES_PostList01( ES_Event);
bool ES_PostList02( ES_Event);
bool ES_PostList03( ES_Event);
bool ES_PostList04( ES_Event);
bool ES_PostList05( ES_Event);
bool ES_PostList06( ES_Event);
bool ES_PostList07( ES_Event);

#line 36 "./ES_PostList.h"
#line 23 "./ES_Framework.h"

#line 1 "./ES_Events.h"

#line 16 "./ES_Events.h"
 

#line 31 "./ES_Events.h"
#line 24 "./ES_Framework.h"

#line 1 "./ES_Timers.h"

#line 29 "./ES_Timers.h"
 


#line 33 "./ES_Timers.h"

#line 1 "./ES_Port.h"

#line 20 "./ES_Port.h"
 

#line 70 "./ES_Port.h"
#line 102 "./ES_Port.h"
#line 34 "./ES_Timers.h"

#line 1 "./ES_Types.h"

#line 17 "./ES_Types.h"
 
#line 25 "./ES_Types.h"
#line 27 "./ES_Types.h"
#line 34 "./ES_Types.h"
#line 36 "./ES_Types.h"
#line 39 "./ES_Types.h"
#line 35 "./ES_Timers.h"



typedef enum { ES_Timer_ERR           = -1,
               ES_Timer_ACTIVE        =  1,
               ES_Timer_OK            =  0,
               ES_Timer_NOT_ACTIVE    =  0
} ES_TimerReturn_t;

void             ES_Timer_Init(TimerRate_t Rate);
void             ES_Timer_Tick_Resp(void);
ES_TimerReturn_t ES_Timer_InitTimer(uint8_t Num, uint16_t NewTime);
ES_TimerReturn_t ES_Timer_SetTimer(uint8_t Num, uint16_t NewTime);
ES_TimerReturn_t ES_Timer_StartTimer(uint8_t Num);
ES_TimerReturn_t ES_Timer_StopTimer(uint8_t Num);
uint16_t         ES_Timer_GetTime(void);

#line 53 "./ES_Timers.h"
 


#line 25 "./ES_Framework.h"


typedef enum {
              Success = 0,
              FailedPost = 1,
              FailedRun,
              FailedPointer,
              FailedIndex,
              FailedInit
} ES_Return_t;

ES_Return_t ES_Initialize( TimerRate_t NewRate  );
ES_Return_t ES_Run( void );
bool ES_PostAll( ES_Event ThisEvent );
bool ES_PostToService( uint8_t WhichService, ES_Event ThisEvent);
bool ES_PostToServiceLIFO( uint8_t WhichService, ES_Event TheEvent);

#line 43 "./ES_Framework.h"
#line 45 "ES_Timers.c"

#line 1 "./ES_ServiceHeaders.h"

#line 11 "./ES_ServiceHeaders.h"
 

#line 1 "./ES_Configure.h"

#line 19 "./ES_Configure.h"
 

#line 56 "./ES_Configure.h"
#line 65 "./ES_Configure.h"
#line 69 "./ES_Configure.h"
#line 78 "./ES_Configure.h"
#line 82 "./ES_Configure.h"
#line 91 "./ES_Configure.h"
#line 95 "./ES_Configure.h"
#line 104 "./ES_Configure.h"
#line 108 "./ES_Configure.h"
#line 117 "./ES_Configure.h"
#line 121 "./ES_Configure.h"
#line 130 "./ES_Configure.h"
#line 134 "./ES_Configure.h"
#line 143 "./ES_Configure.h"
#line 147 "./ES_Configure.h"
#line 156 "./ES_Configure.h"
#line 160 "./ES_Configure.h"
#line 169 "./ES_Configure.h"
#line 173 "./ES_Configure.h"
#line 182 "./ES_Configure.h"
#line 186 "./ES_Configure.h"
#line 195 "./ES_Configure.h"
#line 199 "./ES_Configure.h"
#line 208 "./ES_Configure.h"
#line 212 "./ES_Configure.h"
#line 221 "./ES_Configure.h"
#line 225 "./ES_Configure.h"
#line 234 "./ES_Configure.h"
#line 238 "./ES_Configure.h"
#line 247 "./ES_Configure.h"
#line 273 "./ES_Configure.h"
#line 275 "./ES_Configure.h"
#line 276 "./ES_Configure.h"
#line 278 "./ES_Configure.h"
#line 279 "./ES_Configure.h"
#line 281 "./ES_Configure.h"
#line 282 "./ES_Configure.h"
#line 284 "./ES_Configure.h"
#line 285 "./ES_Configure.h"
#line 287 "./ES_Configure.h"
#line 288 "./ES_Configure.h"
#line 290 "./ES_Configure.h"
#line 291 "./ES_Configure.h"
#line 293 "./ES_Configure.h"
#line 294 "./ES_Configure.h"
#line 296 "./ES_Configure.h"
#line 339 "./ES_Configure.h"
#line 13 "./ES_ServiceHeaders.h"


Pattern_ControlService

#line 18 "./ES_ServiceHeaders.h"
#line 1 "./SPI32_ControlService.h"

#line 6 "./SPI32_ControlService.h"
 


#line 10 "./SPI32_ControlService.h"


#line 1 "./ES_Configure.h"

#line 19 "./ES_Configure.h"
 

#line 56 "./ES_Configure.h"
#line 65 "./ES_Configure.h"
#line 69 "./ES_Configure.h"
#line 78 "./ES_Configure.h"
#line 82 "./ES_Configure.h"
#line 91 "./ES_Configure.h"
#line 95 "./ES_Configure.h"
#line 104 "./ES_Configure.h"
#line 108 "./ES_Configure.h"
#line 117 "./ES_Configure.h"
#line 121 "./ES_Configure.h"
#line 130 "./ES_Configure.h"
#line 134 "./ES_Configure.h"
#line 143 "./ES_Configure.h"
#line 147 "./ES_Configure.h"
#line 156 "./ES_Configure.h"
#line 160 "./ES_Configure.h"
#line 169 "./ES_Configure.h"
#line 173 "./ES_Configure.h"
#line 182 "./ES_Configure.h"
#line 186 "./ES_Configure.h"
#line 195 "./ES_Configure.h"
#line 199 "./ES_Configure.h"
#line 208 "./ES_Configure.h"
#line 212 "./ES_Configure.h"
#line 221 "./ES_Configure.h"
#line 225 "./ES_Configure.h"
#line 234 "./ES_Configure.h"
#line 238 "./ES_Configure.h"
#line 247 "./ES_Configure.h"
#line 273 "./ES_Configure.h"
#line 275 "./ES_Configure.h"
#line 276 "./ES_Configure.h"
#line 278 "./ES_Configure.h"
#line 279 "./ES_Configure.h"
#line 281 "./ES_Configure.h"
#line 282 "./ES_Configure.h"
#line 284 "./ES_Configure.h"
#line 285 "./ES_Configure.h"
#line 287 "./ES_Configure.h"
#line 288 "./ES_Configure.h"
#line 290 "./ES_Configure.h"
#line 291 "./ES_Configure.h"
#line 293 "./ES_Configure.h"
#line 294 "./ES_Configure.h"
#line 296 "./ES_Configure.h"
#line 339 "./ES_Configure.h"
#line 12 "./SPI32_ControlService.h"
  
#line 1 "./ES_Types.h"

#line 17 "./ES_Types.h"
 
#line 25 "./ES_Types.h"
#line 27 "./ES_Types.h"
#line 34 "./ES_Types.h"
#line 36 "./ES_Types.h"
#line 39 "./ES_Types.h"
#line 13 "./SPI32_ControlService.h"
      



typedef enum { SPI32_Startup,
               SPI32_Waiting4Send,
               SPI32_SendingByte1,
               SPI32_SendingByte2,
               SPI32_SendingByte3,
               SPI32_SendingByte4
              } SPI32State_t;
              

bool InitSPI32ControlService( uint8_t Priority );
bool PostSPI32ControlService( ES_Event ThisEvent );
ES_Event RunSPI32ControlService( ES_Event ThisEvent );

void SPI32_TransmitFrames(uint32_t *framePointer, uint8_t numFrames);

#line 33 "./SPI32_ControlService.h"
#line 19 "./ES_ServiceHeaders.h"
 
#line 20 "./ES_ServiceHeaders.h"

#line 22 "./ES_ServiceHeaders.h"
#line 24 "./ES_ServiceHeaders.h"

#line 26 "./ES_ServiceHeaders.h"
#line 28 "./ES_ServiceHeaders.h"

#line 30 "./ES_ServiceHeaders.h"
#line 32 "./ES_ServiceHeaders.h"

#line 34 "./ES_ServiceHeaders.h"
#line 36 "./ES_ServiceHeaders.h"

#line 38 "./ES_ServiceHeaders.h"
#line 40 "./ES_ServiceHeaders.h"

#line 42 "./ES_ServiceHeaders.h"
#line 44 "./ES_ServiceHeaders.h"

#line 46 "./ES_ServiceHeaders.h"
#line 48 "./ES_ServiceHeaders.h"

#line 50 "./ES_ServiceHeaders.h"
#line 52 "./ES_ServiceHeaders.h"

#line 54 "./ES_ServiceHeaders.h"
#line 56 "./ES_ServiceHeaders.h"

#line 58 "./ES_ServiceHeaders.h"
#line 60 "./ES_ServiceHeaders.h"

#line 62 "./ES_ServiceHeaders.h"
#line 64 "./ES_ServiceHeaders.h"

#line 66 "./ES_ServiceHeaders.h"
#line 68 "./ES_ServiceHeaders.h"

#line 70 "./ES_ServiceHeaders.h"
#line 72 "./ES_ServiceHeaders.h"

#line 74 "./ES_ServiceHeaders.h"
#line 76 "./ES_ServiceHeaders.h"
#line 46 "ES_Timers.c"

#line 1 "./ES_General.h"
#line 10 "./ES_General.h"
#line 47 "ES_Timers.c"

#line 1 "./ES_Events.h"

#line 16 "./ES_Events.h"
 

#line 31 "./ES_Events.h"
#line 48 "ES_Timers.c"

#line 1 "./ES_PostList.h"

#line 15 "./ES_PostList.h"
 
#line 36 "./ES_PostList.h"
#line 49 "ES_Timers.c"

#line 1 "./ES_LookupTables.h"

#line 25 "./ES_LookupTables.h"
 
#line 1 "./ES_Types.h"

#line 17 "./ES_Types.h"
 
#line 25 "./ES_Types.h"
#line 27 "./ES_Types.h"
#line 34 "./ES_Types.h"
#line 36 "./ES_Types.h"
#line 39 "./ES_Types.h"
#line 26 "./ES_LookupTables.h"


#line 31 "./ES_LookupTables.h"
 
#line 33 "./ES_LookupTables.h"


#line 37 "./ES_LookupTables.h"
 
extern uint16_t const BitNum2SetMask[];


#line 46 "./ES_LookupTables.h"
 
extern uint8_t const Nybble2MSBitNum[15];


#line 62 "./ES_LookupTables.h"
 
uint8_t ES_GetMSBitSet( uint16_t Val2Check);
#line 50 "ES_Timers.c"

#line 1 "./ES_Timers.h"

#line 29 "./ES_Timers.h"
 

#line 53 "./ES_Timers.h"
 


#line 51 "ES_Timers.c"

#line 1 "./ES_Port.h"

#line 20 "./ES_Port.h"
 

#line 70 "./ES_Port.h"
#line 102 "./ES_Port.h"
#line 52 "ES_Timers.c"

 

 

 


#line 63 "ES_Timers.c"
 

typedef uint16_t Tflag_t;

typedef uint16_t Timer_t; 


 

 
static Timer_t TMR_TimerArray[sizeof(Tflag_t)*8 ]=
                                            { 0x0,
                                              0x0,
                                              0x0,
                                              0x0,
                                              0x0,
                                              0x0,
                                              0x0,
                                              0x0, 
                                              0x0,
                                              0x0,
                                              0x0,
                                              0x0,
                                              0x0,
                                              0x0,
                                              0x0,
                                              0x0 };

static Tflag_t TMR_ActiveFlags;

static pPostFunc const Timer2PostFunc[sizeof(Tflag_t)*8 ] = 
                                            { PostPatternControlService ,
                                              PostSPI32ControlService ,
                                              ((pPostFunc)0)  ,
                                              ((pPostFunc)0)  ,
                                              ((pPostFunc)0)  ,
                                              ((pPostFunc)0)  ,
                                              ((pPostFunc)0)  ,
                                              ((pPostFunc)0)  , 
                                              ((pPostFunc)0)  ,
                                              ((pPostFunc)0)  ,
                                              ((pPostFunc)0)  ,
                                              ((pPostFunc)0)  ,
                                              ((pPostFunc)0)  ,
                                              ((pPostFunc)0)  ,
                                              ((pPostFunc)0)  ,
                                              ((pPostFunc)0)  
                                              };
  

 

#line 129 "ES_Timers.c"
 
void ES_Timer_Init(TimerRate_t Rate)
{
   
   _HW_Timer_Init(Rate);
}


#line 151 "ES_Timers.c"
 
ES_TimerReturn_t ES_Timer_SetTimer(uint8_t Num, uint16_t NewTime)
{
    
   if( (Num >= (sizeof(TMR_TimerArray)/sizeof(TMR_TimerArray[0])) ) ||
    
       (Timer2PostFunc[Num] == ((pPostFunc)0) ) ||
       (NewTime == 0) )  
      return ES_Timer_ERR;  
   TMR_TimerArray[Num] = NewTime;
   return ES_Timer_OK;
}


#line 178 "ES_Timers.c"
 
ES_TimerReturn_t ES_Timer_StartTimer(uint8_t Num)
{
    
   if( (Num >= (sizeof(TMR_TimerArray)/sizeof(TMR_TimerArray[0])) ) ||
        
       (TMR_TimerArray[Num] == 0) )
      return ES_Timer_ERR;  
   TMR_ActiveFlags |= BitNum2SetMask[Num];  
   return ES_Timer_OK;
}


#line 204 "ES_Timers.c"
 
ES_TimerReturn_t ES_Timer_StopTimer(uint8_t Num)
{
   if( Num >= (sizeof(TMR_TimerArray)/sizeof(TMR_TimerArray[0]))  )
      return ES_Timer_ERR;   
   TMR_ActiveFlags &= ~BitNum2SetMask [Num];  
   return ES_Timer_OK;
}


#line 228 "ES_Timers.c"
 
ES_TimerReturn_t ES_Timer_InitTimer(uint8_t Num, uint16_t NewTime)
{
    
   if( (Num >= (sizeof(TMR_TimerArray)/sizeof(TMR_TimerArray[0])) ) ||
    
       (Timer2PostFunc[Num] == ((pPostFunc)0) ) ||
        
       (NewTime == 0) )
      return ES_Timer_ERR;  
   TMR_TimerArray[Num] = NewTime;
   TMR_ActiveFlags |= BitNum2SetMask[Num];  
   return ES_Timer_OK;
}



#line 259 "ES_Timers.c"
 
uint16_t ES_Timer_GetTime(void)
{
   return (_HW_GetTickCount());
}


#line 283 "ES_Timers.c"
 
void ES_Timer_Tick_Resp(void)
{
	static Tflag_t NeedsProcessing;
	static uint8_t NextTimer2Process;
	static ES_Event NewEvent;

	if (TMR_ActiveFlags != 0)  
	{
		
		NeedsProcessing = TMR_ActiveFlags;
		do{
			
			NextTimer2Process = ES_GetMSBitSet(NeedsProcessing);
			 
			if(--TMR_TimerArray[NextTimer2Process] == 0)
			{
				NewEvent.EventType = ES_TIMEOUT;
				NewEvent.EventParam = NextTimer2Process;
				 
				Timer2PostFunc[NextTimer2Process](NewEvent);
				 
				TMR_ActiveFlags &= ~BitNum2SetMask [NextTimer2Process];
			}
			
			NeedsProcessing &= ~BitNum2SetMask [NextTimer2Process];
		}while(NeedsProcessing != 0);
      
	}
}
 
 

