#line 1 "ES_LookupTables.c"
#line 1 "ES_LookupTables.c"


#line 30 "ES_LookupTables.c"
 
 

#line 1 "./ES_Types.h"

#line 17 "./ES_Types.h"
 

#line 20 "./ES_Types.h"

 
#line 25 "./ES_Types.h"

#line 27 "./ES_Types.h"


 
 
#line 34 "./ES_Types.h"

#line 36 "./ES_Types.h"


#line 39 "./ES_Types.h"
#line 33 "ES_LookupTables.c"

#line 1 "./ES_General.h"

#line 3 "./ES_General.h"

#line 5 "./ES_General.h"

#line 7 "./ES_General.h"
#line 8 "./ES_General.h"

#line 10 "./ES_General.h"
#line 34 "ES_LookupTables.c"

#line 1 "./ES_Timers.h"

#line 29 "./ES_Timers.h"
 


#line 33 "./ES_Timers.h"

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
 


#line 35 "ES_LookupTables.c"

#line 1 "./bitdefs.h"

#line 3 "./bitdefs.h"
 

 
#line 76 "./bitdefs.h"

#line 36 "ES_LookupTables.c"


 
#line 40 "ES_LookupTables.c"

 

 


#line 56 "ES_LookupTables.c"
 


#line 61 "ES_LookupTables.c"
 
uint16_t const BitNum2SetMask[] = {
  0x00000001 , 0x00000002 , 0x00000004 , 0x00000008 , 0x00000010 , 0x00000020 , 0x00000040 , 0x00000080 , 0x00000100 , 0x00000200 ,
  0x00000400 , 0x00000800 , 0x00001000 , 0x00002000 , 0x00004000 , 0x00008000 
};


#line 73 "ES_LookupTables.c"
 
uint8_t const Nybble2MSBitNum[15] = {
    0U, 1U, 1U, 2U, 2U, 2U, 2U, 3U, 3U, 3U, 3U, 3U, 3U, 3U, 3U
};

 
uint8_t ES_GetMSBitSet( uint16_t Val2Check) {

  int8_t LoopCntr;
  uint8_t Nybble2Test; 
  uint8_t ReturnVal = 128; 

  
  for( LoopCntr = sizeof(Val2Check) * (8 /4 )-1;
       LoopCntr >= 0; LoopCntr--) {
    
    Nybble2Test = (uint8_t)
                  ((Val2Check >> (uint8_t)(LoopCntr * 4 )) & 
                          0x0F );
    if ( Nybble2Test != 0){
      
      ReturnVal = Nybble2MSBitNum[Nybble2Test-1] + 
                  (LoopCntr * 4 );
      break;     
    }
  }
  return ReturnVal;  
}


#line 104 "ES_LookupTables.c"
 
#line 125 "ES_LookupTables.c"
 
