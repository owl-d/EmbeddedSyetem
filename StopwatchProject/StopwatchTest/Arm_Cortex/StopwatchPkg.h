/*********************************************************************
	Rhapsody in C	: 7.5.3 
	Login		: limdo
	Component	: StopwatchTest 
	Configuration 	: Arm_Cortex
	Model Element	: StopwatchPkg
//!	Generated Date	: Sun, 22, May 2022  
	File Path	: StopwatchTest/Arm_Cortex/StopwatchPkg.h
*********************************************************************/

#ifndef StopwatchPkg_H
#define StopwatchPkg_H

/*## auto_generated */
#include <oxf/Ric.h>
/*## auto_generated */
#include "RiC_IdfP.h"
/*## auto_generated */
#include <oxf/MemAlloc.h>
/*## auto_generated */
#include <oxf/RiCEvent.h>
/*#[ ignore */
#define evPress_StopwatchPkg_id 10401

#define evRealse_StopwatchPkg_id 10402

#define evStartStop_StopwatchPkg_id 10403

#define evReset_StopwatchPkg_id 10404

#define evRelease_StopwatchPkg_id 10405
/*#]*/

/*## package StopwatchPkg */


/*## classInstance Button */
extern struct Button_t Button;

/*## classInstance Display */
extern struct Display_t Display;

/*## classInstance PushSwitch */
extern struct PushSwitch_t PushSwitch;

/*## classInstance Timer */
extern struct Timer_t Timer;

/*## auto_generated */
void StopwatchPkg_OMInitializer_Init(void);

/*## auto_generated */
void StopwatchPkg_OMInitializer_Cleanup(void);

/*## auto_generated */
void StopwatchPkg_initRelations(void);

/*## auto_generated */
RiCBoolean StopwatchPkg_startBehavior(void);

typedef struct evPress evPress;
/*## event evPress() */
struct evPress {
    RiCEvent ric_event;
    RIC_DECLARE_MEMORY_ALLOCATOR_MEMBER(evPress)
};

/*## auto_generated */
void evPress_Init(evPress* const me);

/*## auto_generated */
void evPress_Cleanup(evPress* const me);

/*#[ ignore */
evPress * RiC_Create_evPress(void);

void RiC_Destroy_evPress(evPress* const me);
/*#]*/

RIC_DECLARE_MEMORY_ALLOCATOR(evPress)

typedef struct evRealse evRealse;
/*## event evRealse() */
struct evRealse {
    RiCEvent ric_event;
    RIC_DECLARE_MEMORY_ALLOCATOR_MEMBER(evRealse)
};

/*## auto_generated */
void evRealse_Init(evRealse* const me);

/*## auto_generated */
void evRealse_Cleanup(evRealse* const me);

/*#[ ignore */
evRealse * RiC_Create_evRealse(void);

void RiC_Destroy_evRealse(evRealse* const me);
/*#]*/

RIC_DECLARE_MEMORY_ALLOCATOR(evRealse)

typedef struct evStartStop evStartStop;
/*## event evStartStop() */
struct evStartStop {
    RiCEvent ric_event;
    RIC_DECLARE_MEMORY_ALLOCATOR_MEMBER(evStartStop)
};

/*## auto_generated */
void evStartStop_Init(evStartStop* const me);

/*## auto_generated */
void evStartStop_Cleanup(evStartStop* const me);

/*#[ ignore */
evStartStop * RiC_Create_evStartStop(void);

void RiC_Destroy_evStartStop(evStartStop* const me);
/*#]*/

RIC_DECLARE_MEMORY_ALLOCATOR(evStartStop)

typedef struct evReset evReset;
/*## event evReset() */
struct evReset {
    RiCEvent ric_event;
    RIC_DECLARE_MEMORY_ALLOCATOR_MEMBER(evReset)
};

/*## auto_generated */
void evReset_Init(evReset* const me);

/*## auto_generated */
void evReset_Cleanup(evReset* const me);

/*#[ ignore */
evReset * RiC_Create_evReset(void);

void RiC_Destroy_evReset(evReset* const me);
/*#]*/

RIC_DECLARE_MEMORY_ALLOCATOR(evReset)

typedef struct evRelease evRelease;
/*## event evRelease() */
struct evRelease {
    RiCEvent ric_event;
    RIC_DECLARE_MEMORY_ALLOCATOR_MEMBER(evRelease)
};

/*## auto_generated */
void evRelease_Init(evRelease* const me);

/*## auto_generated */
void evRelease_Cleanup(evRelease* const me);

/*#[ ignore */
evRelease * RiC_Create_evRelease(void);

void RiC_Destroy_evRelease(evRelease* const me);
/*#]*/

RIC_DECLARE_MEMORY_ALLOCATOR(evRelease)

#endif
/*********************************************************************
	File Path	: StopwatchTest/Arm_Cortex/StopwatchPkg.h
*********************************************************************/
