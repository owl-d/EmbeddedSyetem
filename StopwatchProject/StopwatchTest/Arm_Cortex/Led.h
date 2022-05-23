/*********************************************************************
	Rhapsody in C	: 7.5.3 
	Login		: limdo
	Component	: StopwatchTest 
	Configuration 	: Arm_Cortex
	Model Element	: Led
//!	Generated Date	: Sun, 22, May 2022  
	File Path	: StopwatchTest/Arm_Cortex/Led.h
*********************************************************************/

#ifndef Led_H
#define Led_H

/*## auto_generated */
#include <oxf/Ric.h>
/*## auto_generated */
#include "RiC_IdfP.h"
/*## auto_generated */
#include "StopwatchPkg.h"
/*## auto_generated */
#include <oxf/RiCReactive.h>
/*## auto_generated */
#include <oxf/RiCEvent.h>
/*#[ ignore */
#define Led_Timeout_Off_id 2

#define Led_Timeout_On_id 1
/*#]*/

/*## package StopwatchPkg */

/*## class TopLevel::Led */
struct Led_t {
    RiCReactive ric_reactive;
    /*#[ ignore */
    unsigned char rootState_subState;
    unsigned char rootState_active;
    /*#]*/
};

/***    User implicit entries    ***/


/* Constructors and destructors:*/

/*## auto_generated */
void Led_Init(struct Led_t* const me, RiCTask * p_task);

/*## auto_generated */
void Led_Cleanup(struct Led_t* const me);

/*## auto_generated */
RiCBoolean Led_startBehavior(struct Led_t* const me);

/***    Framework entries    ***/

/* rootState: */
/*## statechart_method */
#define Led_rootState_IN(me)    \
    (1)

/* On: */
/*## statechart_method */
#define Led_On_IN(me)    \
    ((me)->rootState_subState == Led_On)

/* Off: */
/*## statechart_method */
#define Led_Off_IN(me)    \
    ((me)->rootState_subState == Led_Off)

/*#[ ignore */
enum Led_Enum {
    Led_RiCNonState = 0,
    Led_On = 1,
    Led_Off = 2
};
/*#]*/

#endif
/*********************************************************************
	File Path	: StopwatchTest/Arm_Cortex/Led.h
*********************************************************************/
