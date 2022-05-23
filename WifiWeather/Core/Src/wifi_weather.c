#include "stm32f4xx_hal.h"
#include "string.h"
#include "stdio.h"
extern UART_HandleTypeDef huart2;
extern UART_HandleTypeDef huart3;
void PrintString(uint8_t * string);

void my_itoa(uint32_t val, uint8_t* str, uint8_t len)
{
	uint8_t i;

	for (i = 1; i <= len; i++)
	{
		str[len - i] = (uint8_t)((val % 10UL) + '0');
		val /= 10;
	}
	str[i - 1] = '\0';
}
void WifiSetup(void)
{
	uint8_t  string[200];
	uint8_t  buffer[200];
	int length;
	
	for (int i = 0; i < 200; i++)buffer[i] = ' ';	
	strcpy((char *)string, "AT+CWMODE=3");
	length = strlen((char *)string);
	string[length] = 0x0D;
	string[length + 1] = 0x0A;
	string[length + 2] = 0;
	HAL_UART_Transmit(&huart3, (uint8_t *)string, length + 2, 0xFFFF);	
	HAL_UART_Receive(&huart3, (uint8_t *)buffer, 100, 1000);  
	HAL_UART_Transmit(&huart2, (uint8_t *)buffer, 100, 0xFFFF);	
	string[0] = 0x0D;
	string[1] = 0x0A;
	HAL_UART_Transmit(&huart2, (uint8_t *)string, 2, 0xFFFF);	
	
	strcpy((char *)string, (char *)"AT+CWJAP=\"HY-DORM5-1107\",\"residence1107\"");
	length = strlen((char *)string);
	string[length] = 0x0D;
	string[length + 1] = 0x0A;
	string[length + 2] = 0;
	HAL_UART_Transmit(&huart3, (uint8_t *)string, length + 2, 0xFFFF);	
	HAL_UART_Receive(&huart3, (uint8_t *)buffer, 100, 4000); 
	HAL_UART_Transmit(&huart2, (uint8_t *)buffer, 100, 0xFFFF);	
	string[0] = 0x0D;
	string[1] = 0x0A;
	HAL_UART_Transmit(&huart2, (uint8_t *)string, 2, 0xFFFF);
}
void OpenWeather(void)
{
	uint8_t  string[200];
	uint8_t  buffer[200];
	int length;
	int ret;
	
	do
	{
		for (int i = 0; i < 200; i++)buffer[i] = ' ';
		strcpy((char *)string, (char *)"AT+CIPSTART=\"TCP\",\"www.kma.go.kr\",80");
		length = strlen((char *)string);
		string[length] = 0x0D;
		string[length + 1] = 0x0A;
		string[length + 2] = 0;
		HAL_UART_Transmit(&huart3, (uint8_t *)string, length + 2, 0xFFFF);	
		HAL_UART_Receive(&huart3, (uint8_t *)buffer, 100, 4000); 
		HAL_UART_Transmit(&huart2, (uint8_t *)buffer, 100, 0xFFFF);
		string[0] = 0x0D;
		string[1] = 0x0A;
		HAL_UART_Transmit(&huart2, (uint8_t *)string, 2, 0xFFFF);
		ret = (int)strstr((char *)buffer, (char *)"CONNECT");
	} while (ret == 0);
}
void WifiWeather(void)
{
	uint8_t  string[200];
	uint8_t  buffer[2000];
	uint8_t  query[500];
	uint8_t queryLength;
	uint8_t queryLengthString[5];
	int length;
	
	OpenWeather();
	for (;;)
	{    
		sprintf((char *)query, "GET /wid/queryDFSRSS.jsp?zone=4127152500 HTTP/1.1\r\nHost: www.kma.go.kr\r\nConnection: keep-alive\r\n\r\n");
		queryLength = strlen((char *)query);
		
		for (int i = 0; i < 50; i++)buffer[i] = ' ';
		my_itoa(queryLength, queryLengthString, 3);
		sprintf((char *)string, "AT+CIPSEND=%s", queryLengthString);
		length = strlen((char *)string);
		string[length] = 0x0D;
		string[length + 1] = 0x0A;
		string[length + 2] = 0;
		HAL_UART_Transmit(&huart3, (uint8_t *)string, length + 2, 0xFFFF);	
		HAL_UART_Receive(&huart3, (uint8_t *)buffer, 23, 4000);	
		
		for (int i = 0; i < 2000; i++)buffer[i] = ' ';
		HAL_Delay(1);
		HAL_UART_Transmit(&huart3, (uint8_t *)(query), queryLength, 0xFFFF);
		HAL_UART_Receive(&huart3, (uint8_t *)buffer, 2000, 4000);
		//HAL_UART_Transmit(&huart2, (uint8_t *)buffer, 2000, 0xFFFF);
		string[0] = 0x0D;
		string[1] = 0x0A;
		HAL_UART_Transmit(&huart2, (uint8_t *)string, 2, 0xFFFF);
		
		int ret1,ret2;
		
		ret1 = (int)strstr((char *)buffer, (char *)"ERROR");
		if (ret1 != 0) break;
		
		ret1 = (int)strstr((char *)buffer, (char *)"GMT");
		HAL_UART_Transmit(&huart2, (uint8_t *)(ret1 -9), 12, 0xFFFF);
		
		ret1 = (int)strstr((char *)buffer, (char *)"<hour>");
		ret2 = (int)strstr((char *)buffer, (char *)"</hour>");
		HAL_UART_Transmit(&huart2, (uint8_t *)(ret1), ret2 - ret1, 0xFFFF);
		
		ret1 = (int)strstr((char *)buffer, (char *)"<temp>");
		ret2 = (int)strstr((char *)buffer, (char *)"</temp>");
		HAL_UART_Transmit(&huart2, (uint8_t *)(ret1), ret2 - ret1, 0xFFFF);
		
		ret1 = (int)strstr((char *)buffer, (char *)"<wfEn>");
		ret2 = (int)strstr((char *)buffer, (char *)"</wfEn>");
		HAL_UART_Transmit(&huart2, (uint8_t *)(ret1), ret2 - ret1, 0xFFFF);
		
		string[0] = 0x0D;
		string[1] = 0x0A;
		HAL_UART_Transmit(&huart2, (uint8_t *)string, 2, 0xFFFF);
        /* wait for a while to slow down */    
		HAL_Delay(2000);
	}	
	PrintString((uint8_t *)"ERROR: Connection Closed. Restart the program.\r\n");
}
