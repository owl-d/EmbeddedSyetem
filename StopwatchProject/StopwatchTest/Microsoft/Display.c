/*********************************************************************
	Rhapsody in C	: 7.5.3 
	Login		: limdo
	Component	: StopwatchTest 
	Configuration 	: Microsoft
	Model Element	: Display
//!	Generated Date	: Sun, 22, May 2022  
	File Path	: StopwatchTest\Microsoft\Display.c
*********************************************************************/

/*## auto_generated */
#include "Display.h"
/*## package StopwatchPkg */

/*## class TopLevel::Display */
void Display_Init(struct Display_t* const me) {
}

void Display_Cleanup(struct Display_t* const me) {
}

/*## operation print(int,int) */
void Display_print(struct Display_t* const me, int min, int sec) {
    /*#[ operation print(int,int) */
    printf("%d:%d\r\n",min,sec);
    /*#]*/
}

struct Display_t * Display_Create(void) {
    struct Display_t* me = (struct Display_t *) malloc(sizeof(struct Display_t));
    if(me!=NULL)
        {
            Display_Init(me);
        }
    return me;
}

void Display_Destroy(struct Display_t* const me) {
    if(me!=NULL)
        {
            Display_Cleanup(me);
        }
    free(me);
}

/*********************************************************************
	File Path	: StopwatchTest\Microsoft\Display.c
*********************************************************************/
