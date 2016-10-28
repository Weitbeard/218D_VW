/****************************************************************************
 
  Header file for the DotStar Pattern Control Service
  based on the Gen2 Events and Services Framework

 ****************************************************************************/

#ifndef PatternControlService_H
#define PatternControlService_H

// Event Definitions
#include "ES_Configure.h" /* gets us event definitions */
#include "ES_Types.h"     /* gets bool type for returns */

// typedefs for the states
// State definitions for use with the query function
typedef enum { Pattern_Startup, Pattern_Idle, Pattern_Running, Pattern_Paused } PatternControlState_t ;


// Public Function Prototypes
bool InitPatternControlService ( uint8_t Priority );
bool PostPatternControlService( ES_Event ThisEvent );
ES_Event RunPatternControlService( ES_Event ThisEvent );
TemplateState_t QueryTemplateSM ( void );


#endif /* PatternControlService_H */

