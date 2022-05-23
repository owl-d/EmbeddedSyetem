/*********************************************************************
	Rhapsody in C	: 7.5.3 
	Login		: limdo
	Component	: StopwatchTest 
	Configuration 	: Microsoft
	Model Element	: Display
//!	Generated Date	: Sun, 22, May 2022  
	File Path	: StopwatchTest\Microsoft\Display.h
*********************************************************************/

#ifndef Display_H
#define Display_H

/*## auto_generated */
#include <oxf\Ric.h>
/*## auto_generated */
#include "stdio.h"
/*## auto_generated */
#include "StopwatchPkg.h"
/*## package StopwatchPkg */

/*## class TopLevel::Display */
struct Display_t {
    RIC_EMPTY_STRUCT
};

/***    User implicit entries    ***/

/* Constructors and destructors:*/

/*## auto_generated */
void Display_Init(struct Display_t* const me);

/*## auto_generated */
void Display_Cleanup(struct Display_t* const me);

/***    User explicit entries    ***/

/* Operations */

/*## operation print(int,int) */
void Display_print(struct Display_t* const me, int min, int sec);

/*## auto_generated */
struct Display_t * Display_Create(void);

/*## auto_generated */
void Display_Destroy(struct Display_t* const me);

#endif
/*********************************************************************
	File Path	: StopwatchTest\Microsoft\Display.h
*********************************************************************/
