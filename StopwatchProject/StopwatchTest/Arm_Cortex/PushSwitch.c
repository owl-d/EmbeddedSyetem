/*********************************************************************
	Rhapsody in C	: 7.5.3 
	Login		: limdo
	Component	: StopwatchTest 
	Configuration 	: Arm_Cortex
	Model Element	: PushSwitch
//!	Generated Date	: Sun, 22, May 2022  
	File Path	: StopwatchTest/Arm_Cortex/PushSwitch.c
*********************************************************************/

/*## auto_generated */
#include <oxf/RiCTask.h>
/*## auto_generated */
#include "PushSwitch.h"
/*## link itsButton */
#include "Button.h"
/*## package StopwatchPkg */

/*## class TopLevel::PushSwitch */
/*## auto_generated */
static void initStatechart(struct PushSwitch_t* const me);

/*## auto_generated */
static void cleanUpRelations(struct PushSwitch_t* const me);

/*## statechart_method */
static void rootState_entDef(void * const void_me);

/*## statechart_method */
static RiCTakeEventStatus rootState_dispatchEvent(void * const void_me, short id);

void PushSwitch_Init(struct PushSwitch_t* const me, RiCTask * p_task) {
    /* Virtual tables Initialization */
    static const RiCReactive_Vtbl PushSwitch_reactiveVtbl = {
        rootState_dispatchEvent,
        rootState_entDef,
        NULL
    };
    RiCReactive_init(&(me->ric_reactive), (void*)me, p_task, &PushSwitch_reactiveVtbl);
    RiCReactive_setActive(&(me->ric_reactive), RiCFALSE);
    me->itsButton = NULL;
    initStatechart(me);
}

void PushSwitch_Cleanup(struct PushSwitch_t* const me) {
    RiCReactive_cleanup(&(me->ric_reactive));
    cleanUpRelations(me);
}

struct Button_t* PushSwitch_getItsButton(const struct PushSwitch_t* const me) {
    return (struct Button_t*)me->itsButton;
}

void PushSwitch_setItsButton(struct PushSwitch_t* const me, struct Button_t* p_Button) {
    me->itsButton = p_Button;
}

RiCBoolean PushSwitch_startBehavior(struct PushSwitch_t* const me) {
    RiCBoolean done = RiCFALSE;
    done = RiCReactive_startBehavior(&(me->ric_reactive));
    return done;
}

static void initStatechart(struct PushSwitch_t* const me) {
    me->rootState_subState = PushSwitch_RiCNonState;
    me->rootState_active = PushSwitch_RiCNonState;
}

static void cleanUpRelations(struct PushSwitch_t* const me) {
    if(me->itsButton != NULL)
        {
            me->itsButton = NULL;
        }
}

static void rootState_entDef(void * const void_me) {
    
    struct PushSwitch_t * const me = (struct PushSwitch_t *)void_me;
    {
        me->rootState_subState = PushSwitch_ReadSwitch;
        me->rootState_active = PushSwitch_ReadSwitch;
        {
            /*#[ state ROOT.ReadSwitch.(Entry) */
            if(ReadButton()) CGEN(me->itsButton, evPress());
            /*#]*/
        }
        RiCTask_schedTm(me->ric_reactive.myTask, 30, PushSwitch_Timeout_ReadSwitch_id, &(me->ric_reactive), NULL);
    }
}

static RiCTakeEventStatus rootState_dispatchEvent(void * const void_me, short id) {
    
    struct PushSwitch_t * const me = (struct PushSwitch_t *)void_me;
    RiCTakeEventStatus res = eventNotConsumed;
    if(me->rootState_active == PushSwitch_ReadSwitch)
        {
            if(id == Timeout_id)
                {
                    if(RiCTimeout_getTimeoutId((RiCTimeout*) me->ric_reactive.current_event) == PushSwitch_Timeout_ReadSwitch_id)
                        {
                            RiCTask_unschedTm(me->ric_reactive.myTask, PushSwitch_Timeout_ReadSwitch_id, &(me->ric_reactive));
                            me->rootState_subState = PushSwitch_ReadSwitch;
                            me->rootState_active = PushSwitch_ReadSwitch;
                            {
                                /*#[ state ROOT.ReadSwitch.(Entry) */
                                if(ReadButton()) CGEN(me->itsButton, evPress());
                                /*#]*/
                            }
                            RiCTask_schedTm(me->ric_reactive.myTask, 30, PushSwitch_Timeout_ReadSwitch_id, &(me->ric_reactive), NULL);
                            res = eventConsumed;
                        }
                }
        }
    return res;
}

/*********************************************************************
	File Path	: StopwatchTest/Arm_Cortex/PushSwitch.c
*********************************************************************/
