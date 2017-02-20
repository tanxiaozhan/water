//ESP8266 WIFIģ��

#include "stm32f10x_gpio.h"

#ifndef  __ESP8266_H
#define	 __ESP8266_H

/******************************** ESP8266 �������Ŷ��� ***********************************/
#define      ESP8266_CH_PD_APBxClock_FUN                   RCC_APB2PeriphClockCmd
#define      ESP8266_CH_PD_CLK                             RCC_APB2Periph_GPIOB  
#define      ESP8266_CH_PD_PORT                            GPIOB
#define      ESP8266_CH_PD_PIN                             GPIO_Pin_4

#define      ESP8266_RST_APBxClock_FUN                     RCC_APB2PeriphClockCmd
#define      ESP8266_RST_CLK                               RCC_APB2Periph_GPIOB
#define      ESP8266_RST_PORT                              GPIOB
#define      ESP8266_RST_PIN                               GPIO_Pin_5


#define     ESP8266_ENABLE()                 GPIO_SetBits ( ESP8266_CH_PD_PORT, ESP8266_CH_PD_PIN )
#define     ESP8266_DISABLE()                GPIO_ResetBits ( ESP8266_CH_PD_PORT, ESP8266_CH_PD_PIN )

#define     ESP8266_RST_HIGH_LEVEL()            GPIO_SetBits ( ESP8266_RST_PORT, ESP8266_RST_PIN )
#define     ESP8266_RST_LOW_LEVEL()             GPIO_ResetBits ( ESP8266_RST_PORT, ESP8266_RST_PIN )

/*
 * ��������ESP8266_Rst
 * ����  ������WF-ESP8266ģ��
 * ����  ����
 * ����  : ��
 * ����  ���� ESP8266_AT_Test ����
 */
void ESP8266_rst ( void );
static void ESP8266_GPIO_Config ( void );
void ESP8266_init( void );

#endif
