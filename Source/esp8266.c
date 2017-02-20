#include "esp8266.h"
#include "cmsis_os.h"                   /* ARM::CMSIS:RTOS:Keil RTX */




/*
 * ��������ESP8266_rst
 * ����  ������WF-ESP8266ģ��
 * ����  ����
 * ����  : ��
 * ����  ���� main() ����
 */
void ESP8266_rst ( void )
{
	 ESP8266_RST_LOW_LEVEL();    
	 osDelay ( 500 ); 
	 ESP8266_RST_HIGH_LEVEL();

}

/**
  * @brief  ESP8266��ʼ������
  * @param  ��
  * @retval ��
  */
void ESP8266_init ( void )
{
	ESP8266_GPIO_Config (); 
	ESP8266_RST_HIGH_LEVEL();
	ESP8266_DISABLE();    //�ر�WIFI��ESP8266��7�ܽŸߵ�ƽʹ�ܣ��͵�ƽ��������

}


/**
  * @brief  ��ʼ��ESP8266�õ���GPIO����
  * @param  ��
  * @retval ��
  */
static void ESP8266_GPIO_Config ( void )
{
	/*����һ��GPIO_InitTypeDef���͵Ľṹ��*/
	GPIO_InitTypeDef GPIO_InitStructure;

	/* ���� ENABLE ����*/
	ESP8266_CH_PD_APBxClock_FUN ( ESP8266_CH_PD_CLK, ENABLE ); 
	GPIO_InitStructure.GPIO_Pin = ESP8266_CH_PD_PIN;	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;   
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
	GPIO_Init ( ESP8266_CH_PD_PORT, & GPIO_InitStructure );	 
	
	/* ���� RST ����*/
	ESP8266_RST_APBxClock_FUN ( ESP8266_RST_CLK, ENABLE ); 
	GPIO_InitStructure.GPIO_Pin = ESP8266_RST_PIN;	
	GPIO_Init ( ESP8266_RST_PORT, & GPIO_InitStructure );	 
}
