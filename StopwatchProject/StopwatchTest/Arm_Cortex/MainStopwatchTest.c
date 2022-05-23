/*********************************************************************
	Rhapsody in C	: 7.5.3 
	Login		: limdo
	Component	: StopwatchTest 
	Configuration 	: Arm_Cortex
	Model Element	: Arm_Cortex
//!	Generated Date	: Sun, 22, May 2022  
	File Path	: StopwatchTest/Arm_Cortex/MainStopwatchTest.c
*********************************************************************/

/*## auto_generated */
#include "MainStopwatchTest.h"
/*## auto_generated */
#include "StopwatchPkg.h"
void StopwatchTest_Init(void) {
    StopwatchPkg_initRelations();
    StopwatchPkg_startBehavior();
}

void StopwatchTest_Cleanup(void) {
    StopwatchPkg_OMInitializer_Cleanup();
}

int Cortex_main(int argc, char* argv[]) {
    int status = 0;
    if(RiCOXFInit(argc, argv, 6423, "", 0, 0, RiCTRUE))
        {
            StopwatchTest_Init();
            /*#[ configuration StopwatchTest::Arm_Cortex */
            /*#]*/
            RiCOXFStart(FALSE);
            StopwatchTest_Cleanup();
            status = 0;
        }
    else
        {
            status = 1;
        }
    return status;
}

/*********************************************************************
	File Path	: StopwatchTest/Arm_Cortex/MainStopwatchTest.c
*********************************************************************/
