/****************************************************************************
 Module
   Pattern_HSV_Convert.c

 Revision
   1.0.1 

 Description
   16 bit HSV to 32 bit RGB conversion module.

 Notes
   
   
 History
 When            Who     What/Why
 --------------- ---     --------
 11/14/16 02:00 lxw     first pass
****************************************************************************/

/*----------------------------- Include Files -----------------------------*/
/* include header files for this state machine as well as any machines at the
   next lower level in the hierarchy that are sub-machines to this machine
*/
//standard c libraries
#include "ES_Types.h"

//framework headers
#include "ES_Configure.h"
#include "ES_Framework.h"

//module includes
#include "Pattern_HSV_Convert.h"
#include "Pattern_Defs.h"

/*----------------------------- Module Defines ----------------------------*/

#define SAT_MASK    0xF0
#define VAL_MASK    0x0F

/*---------------------------- Module Functions ---------------------------*/
/* prototypes for private functions for this machine.They should be functions
   relevant to the behavior of this state machine
*/

/*---------------------------- Module Variables ---------------------------*/

/*------------------------------ Module Code ------------------------------*/

void HSV_to_RGB(uint32_t * HSV_Value){
    uint16_t r, g, b, h, s, v, region, fpart, p, q, t;    
    
    h = *HSV_Value >> 8;
    s = *HSV_Value & SAT_MASK;
    s += s >> 4;                    //scale to 8-bit value
    v = *HSV_Value & VAL_MASK;
    v += v << 4;                    //scale to 8-bit value
    
    if(s == 0) {
        /* color is grayscale */
        r = g = b = v;
    }
    
    else{
        /* make hue 0-5 */
        region = h / 43;
        /* find remainder part, make it from 0-255 */
        fpart = (h - (region * 43)) * 6;

        /* calculate temp vars, doing integer multiplication */ //************TODO********** convert to 4-bit saturation and value
        p = (v * (255 - s)) >> 8;
        q = (v * (255 - ((s * fpart) >> 8))) >> 8;
        t = (v * (255 - ((s * (255 - fpart)) >> 8))) >> 8;

        /* assign temp vars based on color cone region */
        switch(region) {
            case 0:
                r = v; g = t; b = p; break;
            case 1:
                r = q; g = v; b = p; break;
            case 2:
                r = p; g = v; b = t; break;
            case 3:
                r = p; g = q; b = v; break;
            case 4:
                r = t; g = p; b = v; break;
            default:
                r = v; g = p; b = q; break;
        }
    }
    
    //preserve brightness value and set new RGB value (in order B - G - R)
    *HSV_Value = (*HSV_Value & 0xFF000000) | ((uint32_t)b << 16) | ((uint32_t)g << 8) | ((uint32_t)r);
    
    return;
}
