/*********************************************************************
	Rhapsody in C	: 7.5.3 
	Login		: limdo
	Component	: StopwatchTest 
	Configuration 	: Microsoft
	Model Element	: Button
//!	Generated Date	: Sun, 22, May 2022  
	File Path	: StopwatchTest\Microsoft\Button.c
*********************************************************************/

/*## auto_generated */
#include <oxf\RiCTask.h>
/*## auto_generated */
#include "Button.h"
/*## link itsTimer */
#include "Timer.h"
/*## package StopwatchPkg */

/*## class TopLevel::Button */
/*## auto_generated */
static void initStatechart(struct Button_t* const me);

/*## auto_generated */
static void cleanUpRelations(struct Button_t* const me);

/*## statechart_method */
static void rootState_entDef(void * const void_me);

/*## statechart_method */
static RiCTakeEventStatus rootState_dispatchEvent(void * const void_me, short id);

/*## statechart_method */
static void held_entDef(struct Button_t* const me);

/*#[ ignore */
static void FreeInstance(struct Button_t* const me);
/*#]*/

void Button_Init(struct Button_t* const me, RiCTask * p_task) {
    /* Virtual tables Initialization */
    static const RiCReactive_Vtbl Button_reactiveVtbl = {
        rootState_dispatchEvent,
        rootState_entDef,
        NULL,
        (RiCObjectDestroyMethod) Button_Destroy,
        NULL,
        NULL,
        NULL,
        (RiCObjectCleanupMethod) Button_Cleanup,
        (RiCObjectFreeMethod) FreeInstance
    };
    RiCReactive_init(&(me->ric_reactive), (void*)me, p_task, &Button_reactiveVtbl);
    RiCReactive_setActive(&(me->ric_reactive), RiCFALSE);
    me->itsTimer = NULL;
    initStatechart(me);
}

void Button_Cleanup(struct Button_t* const me) {
    RiCReactive_cleanup(&(me->ric_reactive));
    cleanUpRelations(me);
}

struct Button_t * Button_Create(RiCTask * p_task) {
    struct Button_t* me = (struct Button_t *) malloc(sizeof(struct Button_t));
    if(me!=NULL)
        {
            Button_Init(me, p_task);
        }
    DYNAMICALLY_ALLOCATED(me);
    return me;
}

void Button_Destroy(struct Button_t* const me) {
    if(me!=NULL)
        {
            Button_Cleanup(me);
        }
    free(me);
}

RiCBoolean Button_startBehavior(struct Button_t* const me) {
    RiCBoolean done = RiCFALSE;
    done = RiCReactive_startBehavior(&(me->ric_reactive));
    return done;
}

static void initStatechart(struct Button_t* const me) {
    me->rootState_subState = Button_RiCNonState;
    me->rootState_active = Button_RiCNonState;
    me->held_subState = Button_RiCNonState;
}

static void cleanUpRelations(struct Button_t* const me) {
    if(me->itsTimer != NULL)
        {
            me->itsTimer = NULL;
        }
}

struct Timer_t* Button_getItsTimer(const struct Button_t* const me) {
    return (struct Timer_t*)me->itsTimer;
}

void Button_setItsTimer(struct Button_t* const me, struct Timer_t* p_Timer) {
    me->itsTimer = p_Timer;
}

int Button_rootState_IN(const struct Button_t* const me) {
    return 1;
}

int Button_idle_IN(const struct Button_t* const me) {
    return me->rootState_subState == Button_idle;
}

int Button_held_IN(const struct Button_t* const me) {
    return me->rootState_subState == Button_held;
}

void Button_held_exit(struct Button_t* const me) {
    if(me->held_subState == Button_pressed)
        {
            RiCTask_unschedTm(me->ric_reactive.myTask, Button_Timeout_pressed_id, &(me->ric_reactive));
        }
    me->held_subState = Button_RiCNonState;
    RiCTask_unschedTm(me->ric_reactive.myTask, Button_Timeout_held_id, &(me->ric_reactive));
}

RiCTakeEventStatus Button_held_takeEvent(struct Button_t* const me, short id) {
    RiCTakeEventStatus res = eventNotConsumed;
    if(id == Timeout_id)
        {
            if(RiCTimeout_getTimeoutId((RiCTimeout*) me->ric_reactive.current_event) == Button_Timeout_held_id)
                {
                    Button_held_exit(me);
                    {
                        /*#[ transition 3 */
                        
                        CGEN(me->itsTimer, evReset());
                        /*#]*/
                    }
                    me->rootState_subState = Button_idle;
                    me->rootState_active = Button_idle;
                    res = eventConsumed;
                }
        }
    return res;
}

int Button_pressed_IN(const struct Button_t* const me) {
    return me->held_subState == Button_pressed;
}

static void rootState_entDef(void * const void_me) {
    
    struct Button_t * const me = (struct Button_t *)void_me;
    {
        me->rootState_subState = Button_idle;
        me->rootState_active = Button_idle;
    }
}

static RiCTakeEventStatus rootState_dispatchEvent(void * const void_me, short id) {
    
    struct Button_t * const me = (struct Button_t *)void_me;
    RiCTakeEventStatus res = eventNotConsumed;
    switch (me->rootState_active) {
        case Button_idle:
        {
            if(id == evPress_StopwatchPkg_id)
                {
                    {
                        /*#[ transition 0 */
                        
                        CGEN(me->itsTimer, evStartStop());
                        /*#]*/
                    }
                    held_entDef(me);
                    res = eventConsumed;
                }
        }
        break;
        case Button_pressed:
        {
            switch (id) {
                case Timeout_id:
                {
                    if(RiCTimeout_getTimeoutId((RiCTimeout*) me->ric_reactive.current_event) == Button_Timeout_pressed_id)
                        {
                            RiCTask_unschedTm(me->ric_reactive.myTask, Button_Timeout_pressed_id, &(me->ric_reactive));
                            me->held_subState = Button_pressed;
                            me->rootState_active = Button_pressed;
                            RiCTask_schedTm(me->ric_reactive.myTask, 30, Button_Timeout_pressed_id, &(me->ric_reactive), NULL);
                            res = eventConsumed;
                        }
                }
                break;
                case evRealse_StopwatchPkg_id:
                {
                    Button_held_exit(me);
                    me->rootState_subState = Button_idle;
                    me->rootState_active = Button_idle;
                    res = eventConsumed;
                }
                break;
                default:
                    break;
            }
            if(res == eventNotConsumed)
                {
                    res = Button_held_takeEvent(me, id);
                }
        }
        break;
        default:
            break;
    }
    return res;
}

static void held_entDef(struct Button_t* const me) {
    me->rootState_subState = Button_held;
    RiCTask_schedTm(me->ric_reactive.myTask, 3000, Button_Timeout_held_id, &(me->ric_reactive), NULL);
    me->held_subState = Button_pressed;
    me->rootState_active = Button_pressed;
    RiCTask_schedTm(me->ric_reactive.myTask, 30, Button_Timeout_pressed_id, &(me->ric_reactive), NULL);
}

/*#[ ignore */
static void FreeInstance(struct Button_t* const me) {
    free(me);
}
/*#]*/

/*********************************************************************
	File Path	: StopwatchTest\Microsoft\Button.c
*********************************************************************/
