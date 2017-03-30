/*------------------------------------------------------------------------------
 * 
 * LED显示屏控制卡项目
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

struct_time water_time;       //浇花时间
struct rtc_time system_time;  //系统时间
uint16_t water_last_second;    //浇花时长，秒为单位
bool water_flag;              //浇花开始标志，true--浇花

/*----------------------------------------------------------------------------
  Main Thread 'main': 控制卡、网络初始化
 *---------------------------------------------------------------------------*/
int main (void) {
	
		FLASH_SPI_initialize();
		water_stop();     //系统启动时，关闭浇花电源
		USARTx_Config();	
		
		RTC_check();           //检测是否需要配置RTC
		RTC_AlarmSet();				 //RTC闹钟设置
	
		netInitialize ();    		//网络核心初始化
		netSLIP_Listen();      //开始SLIP监听
		osDelay(500);

		netHTTPs_LoginOnOff (false);
	
		Board_LED_GPIO_Config(); 

		LED_display_init();      //显示屏初始化
		LED_display_start();     //控制卡输出启动，LED显示屏开始显示
	
		ESP8266_init();      //初始化控制EPS8266用到的PGIO引脚
		//ESP8266_ENABLE();   //打开WIFI
		ESP8266_rst();

		water_stop();     //系统启动时，关闭浇花电源
				
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
