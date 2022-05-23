/*********************************************************************
	Rhapsody in C	: 7.5.3 
	Login		: limdo
	Component	: StopwatchTest 
	Configuration 	: Microsoft
	Model Element	: Button
//!	Generated Date	: Sun, 22, May 2022  
	File Path	: StopwatchTest\Microsoft\Button.h
*********************************************************************/

#ifndef Button_H
#define Button_H

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
#define Button_Timeout_pressed_id 2

#define Button_Timeout_held_id 1
/*#]*/

/*## link itsTimer */
struct Timer_t;

/*## package StopwatchPkg */

/*## class TopLevel::Button */
struct Button_t {
    RiCReactive ric_reactive;
    struct Timer_t* itsTimer;		/*## link itsTimer */
    /*#[ ignore */
    int rootState_subState;
    int rootState_active;
    int held_subState;
    /*#]*/
};

/***    Framework entries    ***/

/***    User implicit entries    ***/

/* Constructors and destructors:*/

/*## auto_generated */
void Button_Init(struct Button_t* const me, RiCTask * p_task);

/*## auto_generated */
void Button_Cleanup(struct Button_t* const me);

/*## auto_generated */
struct Button_t * Button_Create(RiCTask * p_task);

/*## auto_generated */
void Button_Destroy(struct Button_t* const me);

/*## auto_generated */
RiCBoolean Button_startBehavior(struct Button_t* const me);

/*## auto_generated */
struct Timer_t* Button_getItsTimer(const struct Button_t* const me);

/*## auto_generated */
void Button_setItsTimer(struct Button_t* const me, struct Timer_t* p_Timer);

/* rootState: */
/*## statechart_method */
int Button_rootState_IN(const struct Button_t* const me);

/* idle: */
/*## statechart_method */
int Button_idle_IN(const struct Button_t* const me);

/* held: */
/*## statechart_method */
int Button_held_IN(const struct Button_t* const me);

/*## statechart_method */
void Button_held_exit(struct Button_t* const me);

/*## statechart_method */
RiCTakeEventStatus Button_held_takeEvent(struct Button_t* const me, short id);

/* pressed: */
/*## statechart_method */
int Button_pressed_IN(const struct Button_t* const me);

/*#[ ignore */
enum Button_Enum {
    Button_RiCNonState = 0,
    Button_idle = 1,
    Button_held = 2,
    Button_pressed = 3
};
/*#]*/

#endif
/*********************************************************************
	File Path	: StopwatchTest\Microsoft\Button.h
*********************************************************************/
