/*********************************************************************
	Rhapsody in C	: 7.5.3 
	Login		: limdo
	Component	: StopwatchTest 
	Configuration 	: Arm_Cortex
	Model Element	: Led
//!	Generated Date	: Sun, 22, May 2022  
	File Path	: StopwatchTest/Arm_Cortex/Led.c
*********************************************************************/

/*## auto_generated */
#include <oxf/RiCTask.h>
/*## auto_generated */
#include "Led.h"
/*## package StopwatchPkg */

/*## class TopLevel::Led */

exterm void LedOn(); exterm void LedOff();

/*## auto_generated */
static void initStatechart(struct Led_t* const me);

/*## statechart_method */
static void rootState_entDef(void * const void_me);

/*## statechart_method */
static RiCTakeEventStatus rootState_dispatchEvent(void * const void_me, short id);

void Led_Init(struct Led_t* const me, RiCTask * p_task) {
    /* Virtual tables Initialization */
    static const RiCReactive_Vtbl Led_reactiveVtbl = {
        rootState_dispatchEvent,
        rootState_entDef,
        NULL
    };
    RiCReactive_init(&(me->ric_reactive), (void*)me, p_task, &Led_reactiveVtbl);
    RiCReactive_setActive(&(me->ric_reactive), RiCFALSE);
    initStatechart(me);
}

void Led_Cleanup(struct Led_t* const me) {
    RiCReactive_cleanup(&(me->ric_reactive));
}

RiCBoolean Led_startBehavior(struct Led_t* const me) {
    RiCBoolean done = RiCFALSE;
    done = RiCReactive_startBehavior(&(me->ric_reactive));
    return done;
}

static void initStatechart(struct Led_t* const me) {
    me->rootState_subState = Led_RiCNonState;
    me->rootState_active = Led_RiCNonState;
}

static void rootState_entDef(void * const void_me) {
    
    struct Led_t * const me = (struct Led_t *)void_me;
    {
        me->rootState_subState = Led_On;
        me->rootState_active = Led_On;
        {
            /*#[ state ROOT.On.(Entry) */
            printf("On\n\r");
            /*#]*/
        }
        RiCTask_schedTm(me->ric_reactive.myTask, 500, Led_Timeout_On_id, &(me->ric_reactive), NULL);
    }
}

static RiCTakeEventStatus rootState_dispatchEvent(void * const void_me, short id) {
    
    struct Led_t * const me = (struct Led_t *)void_me;
    RiCTakeEventStatus res = eventNotConsumed;
    switch (me->rootState_active) {
        case Led_On:
        {
            if(id == Timeout_id)
                {
                    if(RiCTimeout_getTimeoutId((RiCTimeout*) me->ric_reactive.current_event) == Led_Timeout_On_id)
                        {
                            RiCTask_unschedTm(me->ric_reactive.myTask, Led_Timeout_On_id, &(me->ric_reactive));
                            me->rootState_subState = Led_Off;
                            me->rootState_active = Led_Off;
                            {
                                /*#[ state ROOT.Off.(Entry) */
                                printf("Off\n\r");
                                /*#]*/
                            }
                            RiCTask_schedTm(me->ric_reactive.myTask, 500, Led_Timeout_Off_id, &(me->ric_reactive), NULL);
                            res = eventConsumed;
                        }
                }
        }
        break;
        case Led_Off:
        {
            if(id == Timeout_id)
                {
                    if(RiCTimeout_getTimeoutId((RiCTimeout*) me->ric_reactive.current_event) == Led_Timeout_Off_id)
                        {
                            RiCTask_unschedTm(me->ric_reactive.myTask, Led_Timeout_Off_id, &(me->ric_reactive));
                            me->rootState_subState = Led_On;
                            me->rootState_active = Led_On;
                            {
                                /*#[ state ROOT.On.(Entry) */
                                printf("On\n\r");
                                /*#]*/
                            }
                            RiCTask_schedTm(me->ric_reactive.myTask, 500, Led_Timeout_On_id, &(me->ric_reactive), NULL);
                            res = eventConsumed;
                        }
                }
        }
        break;
        default:
            break;
    }
    return res;
}

/*********************************************************************
	File Path	: StopwatchTest/Arm_Cortex/Led.c
*********************************************************************/
