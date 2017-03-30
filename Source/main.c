/*------------------------------------------------------------------------------
 * 
 * LED��ʾ�����ƿ���Ŀ
 * 
 * 2016-08-06
 *------------------------------------------------------------------------------
 * Name:    main.c
 * Purpose: main
 *----------------------------------------------------------------------------*/

#include <stdio.h>
#include "cmsis_os.h"                   /* ARM::CMSIS:RTOS:Keil RTX */
#include "rl_net.h"                     /* Network definitions                */

#include "rl_net_lib.h"

#include "flash_SPI.h"
#include "usartX.h"
#include "esp8266.h"
#include "Board_LED.h"
#include "LED_Display.h"
#include "rtc.h"
#include "water.h"

struct_time water_time;       //����ʱ��
struct rtc_time system_time;  //ϵͳʱ��
uint16_t water_last_second;    //����ʱ������Ϊ��λ
bool water_flag;              //������ʼ��־��true--����

/*----------------------------------------------------------------------------
  Main Thread 'main': ���ƿ��������ʼ��
 *---------------------------------------------------------------------------*/
int main (void) {
	
		FLASH_SPI_initialize();
		water_stop();     //ϵͳ����ʱ���رս�����Դ
		USARTx_Config();	
		
		RTC_check();           //����Ƿ���Ҫ����RTC
		RTC_AlarmSet();				 //RTC��������
	
		netInitialize ();    		//������ĳ�ʼ��
		netSLIP_Listen();      //��ʼSLIP����
		osDelay(500);

		netHTTPs_LoginOnOff (false);
	
		Board_LED_GPIO_Config(); 

		LED_display_init();      //��ʾ����ʼ��
		LED_display_start();     //���ƿ����������LED��ʾ����ʼ��ʾ
	
		ESP8266_init();      //��ʼ������EPS8266�õ���PGIO����
		//ESP8266_ENABLE();   //��WIFI
		ESP8266_rst();

		water_stop();     //ϵͳ����ʱ���رս�����Դ
				
		printf("\nLED CtrlCard is running...\n");

		while(1){
			if(water_flag){
				water_start(water_last_second);
				water_flag=false;
			}

			Board_LED(ON);
			osDelay(1000);
			Board_LED(OFF);
			osDelay(1000);
			
		}
}
