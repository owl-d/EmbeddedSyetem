/*********************************************************************
	Rhapsody in C	: 7.5.3 
	Login		: limdo
	Component	: StopwatchTest 
	Configuration 	: Microsoft
	Model Element	: Timer
//!	Generated Date	: Sun, 22, May 2022  
	File Path	: StopwatchTest\Microsoft\Timer.h
*********************************************************************/

#ifndef Timer_H
#define Timer_H

/*## auto_generated */
#include <oxf\Ric.h>
/*## auto_generated */
#include "stdio.h"
/*## auto_generated */
#include "StopwatchPkg.h"
/*## auto_generated */
#include <oxf\RiCReactive.h>
/*## auto_generated */
#include <oxf\RiCEvent.h>
/*#[ ignore */
#define Timer_Timeout_on_id 1
/*#]*/

/*## link itsDisplay */
struct Display_t;

/*## package StopwatchPkg */

/*## class TopLevel::Timer */
struct Timer_t {
    RiCReactive ric_reactive;
    int minutes;		/*## attribute minutes */
    int seconds;		/*## attribute seconds */
    struct Display_t* itsDisplay;		/*## link itsDisplay */
    /*#[ ignore */
    int rootState_subState;
    int rootState_active;
    int running_subState;
    /*#]*/
};

/***    Framework entries    ***/

/***    User implicit entries    ***/

/* Constructors and destructors:*/

/*## auto_generated */
void Timer_Init(struct Timer_t* const me, RiCTask * p_task);

/*## auto_generated */
void Timer_Cleanup(struct Timer_t* const me);

/*## auto_generated */
struct Display_t* Timer_getItsDisplay(const struct Timer_t* const me);

/*## auto_generated */
void Timer_setItsDisplay(struct Timer_t* const me, struct Display_t* p_Display);

/*## auto_generated */
struct Timer_t * Timer_Create(RiCTask * p_task);

/*## auto_generated */
void Timer_Destroy(struct Timer_t* const me);

/*## auto_generated */
RiCBoolean Timer_startBehavior(struct Timer_t* const me);

/* rootState: */
/*## statechart_method */
int Timer_rootState_IN(const struct Timer_t* const me);

/* running: */
/*## statechart_method */
int Timer_running_IN(const struct Timer_t* const me);

/*## statechart_method */
RiCTakeEventStatus Timer_running_takeEvent(struct Timer_t* const me, short id);

/* on: */
/*## statechart_method */
int Timer_on_IN(const struct Timer_t* const me);

/* off: */
/*## statechart_method */
int Timer_off_IN(const struct Timer_t* const me);

/*#[ ignore */
enum Timer_Enum {
    Timer_RiCNonState = 0,
    Timer_running = 1,
    Timer_on = 2,
    Timer_off = 3
};
/*#]*/

#endif
/*********************************************************************
	File Path	: StopwatchTest\Microsoft\Timer.h
*********************************************************************/
