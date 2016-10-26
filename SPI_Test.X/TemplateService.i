#line 1 "TemplateService.c"
#line 1 "TemplateService.c"

#line 18 "TemplateService.c"
 
 

#line 22 "TemplateService.c"
 
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


 


typedef enum {  ES_NO_EVENT = 0,
                ES_ERROR,   
                ES_INIT,    
                ES_TIMEOUT,  
                ES_SHORT_TIMEOUT,  
                 
                BYTE_SENT,
                DBButtonUp,
                DBButtonDown,
                SEND_TRIGGER,
                BUF_NOT_READY,
                
                ES_NEW_KEY,  
                ES_LOCK,
                ES_UNLOCK} ES_EventTyp_t;

 



#line 273 "./ES_Configure.h"
#line 274 "./ES_Configure.h"
#line 275 "./ES_Configure.h"
#line 276 "./ES_Configure.h"
#line 277 "./ES_Configure.h"
#line 279 "./ES_Configure.h"
#line 280 "./ES_Configure.h"
#line 282 "./ES_Configure.h"
#line 283 "./ES_Configure.h"
#line 285 "./ES_Configure.h"
#line 286 "./ES_Configure.h"
#line 288 "./ES_Configure.h"
#line 289 "./ES_Configure.h"
#line 291 "./ES_Configure.h"
#line 292 "./ES_Configure.h"
#line 294 "./ES_Configure.h"
#line 295 "./ES_Configure.h"
#line 297 "./ES_Configure.h"

 

#line 301 "./ES_Configure.h"

 

#line 305 "./ES_Configure.h"

 





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
#line 329 "./ES_Configure.h"

 






#line 338 "./ES_Configure.h"
#line 339 "./ES_Configure.h"
#line 340 "./ES_Configure.h"
#line 341 "./ES_Configure.h"
#line 342 "./ES_Configure.h"
#line 23 "TemplateService.c"

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



#line 1 "./bitdefs.h"

#line 3 "./bitdefs.h"
 

 

#line 8 "./bitdefs.h"

#line 10 "./bitdefs.h"
#line 11 "./bitdefs.h"
#line 12 "./bitdefs.h"
#line 13 "./bitdefs.h"
#line 14 "./bitdefs.h"
#line 15 "./bitdefs.h"
#line 16 "./bitdefs.h"
#line 17 "./bitdefs.h"
#line 18 "./bitdefs.h"
#line 19 "./bitdefs.h"
#line 20 "./bitdefs.h"
#line 21 "./bitdefs.h"
#line 22 "./bitdefs.h"
#line 23 "./bitdefs.h"
#line 24 "./bitdefs.h"
#line 25 "./bitdefs.h"
#line 26 "./bitdefs.h"
#line 27 "./bitdefs.h"
#line 28 "./bitdefs.h"
#line 29 "./bitdefs.h"
#line 30 "./bitdefs.h"
#line 31 "./bitdefs.h"
#line 32 "./bitdefs.h"
#line 33 "./bitdefs.h"
#line 34 "./bitdefs.h"
#line 35 "./bitdefs.h"
#line 36 "./bitdefs.h"
#line 37 "./bitdefs.h"
#line 38 "./bitdefs.h"
#line 39 "./bitdefs.h"
#line 40 "./bitdefs.h"
#line 41 "./bitdefs.h"

#line 43 "./bitdefs.h"
#line 44 "./bitdefs.h"
#line 45 "./bitdefs.h"
#line 46 "./bitdefs.h"
#line 47 "./bitdefs.h"
#line 48 "./bitdefs.h"
#line 49 "./bitdefs.h"
#line 50 "./bitdefs.h"
#line 51 "./bitdefs.h"
#line 52 "./bitdefs.h"
#line 53 "./bitdefs.h"
#line 54 "./bitdefs.h"
#line 55 "./bitdefs.h"
#line 56 "./bitdefs.h"
#line 57 "./bitdefs.h"
#line 58 "./bitdefs.h"
#line 59 "./bitdefs.h"
#line 60 "./bitdefs.h"
#line 61 "./bitdefs.h"
#line 62 "./bitdefs.h"
#line 63 "./bitdefs.h"
#line 64 "./bitdefs.h"
#line 65 "./bitdefs.h"
#line 66 "./bitdefs.h"
#line 67 "./bitdefs.h"
#line 68 "./bitdefs.h"
#line 69 "./bitdefs.h"
#line 70 "./bitdefs.h"
#line 71 "./bitdefs.h"
#line 72 "./bitdefs.h"
#line 73 "./bitdefs.h"
#line 74 "./bitdefs.h"

#line 76 "./bitdefs.h"

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
#line 274 "./ES_Configure.h"
#line 276 "./ES_Configure.h"
#line 277 "./ES_Configure.h"
#line 279 "./ES_Configure.h"
#line 280 "./ES_Configure.h"
#line 282 "./ES_Configure.h"
#line 283 "./ES_Configure.h"
#line 285 "./ES_Configure.h"
#line 286 "./ES_Configure.h"
#line 288 "./ES_Configure.h"
#line 289 "./ES_Configure.h"
#line 291 "./ES_Configure.h"
#line 292 "./ES_Configure.h"
#line 294 "./ES_Configure.h"
#line 295 "./ES_Configure.h"
#line 297 "./ES_Configure.h"
#line 342 "./ES_Configure.h"
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
#line 24 "TemplateService.c"

#line 1 "./TemplateService.h"

#line 6 "./TemplateService.h"
 


#line 10 "./TemplateService.h"

#line 1 "./ES_Types.h"

#line 17 "./ES_Types.h"
 
#line 25 "./ES_Types.h"
#line 27 "./ES_Types.h"
#line 34 "./ES_Types.h"
#line 36 "./ES_Types.h"
#line 39 "./ES_Types.h"
#line 11 "./TemplateService.h"




bool InitTemplateService ( uint8_t Priority );
bool PostTemplateService( ES_Event ThisEvent );
ES_Event RunTemplateService( ES_Event ThisEvent );


#line 21 "./TemplateService.h"

#line 25 "TemplateService.c"


 

 

#line 32 "TemplateService.c"
 

 

static uint8_t MyPriority;


 

#line 57 "TemplateService.c"
 
bool InitTemplateService ( uint8_t Priority )
{
  ES_Event ThisEvent;

  MyPriority = Priority;
  
#line 65 "TemplateService.c"
 
  
  ThisEvent.EventType = ES_INIT;
  if (ES_PostToService( MyPriority, ThisEvent) == true)
  {
      return true;
  }else
  {
      return false;
  }
}


#line 93 "TemplateService.c"
 
bool PostTemplateService( ES_Event ThisEvent )
{
  return ES_PostToService( MyPriority, ThisEvent);
}


#line 115 "TemplateService.c"
 
ES_Event RunTemplateService( ES_Event ThisEvent )
{
  ES_Event ReturnEvent;
  ReturnEvent.EventType = ES_NO_EVENT; 
  
#line 122 "TemplateService.c"
 
  return ReturnEvent;
}


#line 128 "TemplateService.c"
 

 
 

