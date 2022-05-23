/*********************************************************************
	Rhapsody in C	: 7.5.3 
	Login		: limdo
	Component	: StopwatchTest 
	Configuration 	: Arm_Cortex
	Model Element	: Display
//!	Generated Date	: Sun, 22, May 2022  
	File Path	: StopwatchTest/Arm_Cortex/Display.c
*********************************************************************/

/*## auto_generated */
#include "Display.h"
/*## dependency ssd1306 */
#include "ssd1306.h"
/*## dependency fonts */
#include "fonts.h"
/*## package StopwatchPkg */

/*## class TopLevel::Display */

extern void ssd1306_UpdateScreen(void); extern uint8_t ssd1306_Init(void); extern char ssd1306_WriteString(char* str, FontDef Font, SSD1306_COLOR color); extern void ssd1306_SetCursor(uint8_t x, uint8_t y);

void Display_Init(struct Display_t* const me) {
}

void Display_Cleanup(struct Display_t* const me) {
}

/*## operation print(int,int) */
void Display_print(struct Display_t* const me, int min, int sec) {
    /*#[ operation print(int,int) */
    printf("%d:%d\r\n",min,sec);      
    
    char string[10];
    ssd1306_Fill(Black);
    ssd1306_SetCursor(40, 20);
    sprintf(string, "%d:%d", min,sec);
    ssd1306_WriteString(string, Font_16x26, White);
    ssd1306_UpdateScreen();
    HAL_Delay(10);
    /*#]*/
}

/*********************************************************************
	File Path	: StopwatchTest/Arm_Cortex/Display.c
*********************************************************************/
