/*********************************************************************
	Rhapsody in C	: 7.5.3 
	Login		: limdo
	Component	: StopwatchTest 
	Configuration 	: Arm_Cortex
	Model Element	: PushSwitch
//!	Generated Date	: Sun, 22, May 2022  
	File Path	: StopwatchTest/Arm_Cortex/PushSwitch.h
*********************************************************************/

#ifndef PushSwitch_H
#define PushSwitch_H

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
#define PushSwitch_Timeout_ReadSwitch_id 1
/*#]*/

/*## package StopwatchPkg */

/*## class TopLevel::PushSwitch */
struct PushSwitch_t {
    RiCReactive ric_reactive;
    struct Button_t* itsButton;		/*## link itsButton */
    /*#[ ignore */
    unsigned char rootState_subState;
    unsigned char rootState_active;
    /*#]*/
};

/***    User implicit entries    ***/


/* Constructors and destructors:*/

/*## auto_generated */
void PushSwitch_Init(struct PushSwitch_t* const me, RiCTask * p_task);

/*## auto_generated */
void PushSwitch_Cleanup(struct PushSwitch_t* const me);

/*## auto_generated */
struct Button_t* PushSwitch_getItsButton(const struct PushSwitch_t* const me);

/*## auto_generated */
void PushSwitch_setItsButton(struct PushSwitch_t* const me, struct Button_t* p_Button);

/*## auto_generated */
RiCBoolean PushSwitch_startBehavior(struct PushSwitch_t* const me);

/***    Framework entries    ***/

/* rootState: */
/*## statechart_method */
#define PushSwitch_rootState_IN(me)    \
    (1)

/* ReadSwitch: */
/*## statechart_method */
#define PushSwitch_ReadSwitch_IN(me)    \
    ((me)->rootState_subState == PushSwitch_ReadSwitch)

/*#[ ignore */
enum PushSwitch_Enum {
    PushSwitch_RiCNonState = 0,
    PushSwitch_ReadSwitch = 1
};
/*#]*/

#endif
/*********************************************************************
	File Path	: StopwatchTest/Arm_Cortex/PushSwitch.h
*********************************************************************/
