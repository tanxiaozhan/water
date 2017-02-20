#include "stm32f10x_gpio.h"

#ifndef  __BOARD_LED_H
#define	 __BOARD_LED_H


//LED״̬�����ӹܽŶ���
#define Board_LED_GPIO_APBxClock_FUN  RCC_APB2PeriphClockCmd   // ����GPIO������ʱ��
#define Board_LED_GPIO_PORT    	GPIOC			                     // GPIO�˿� 
#define Board_LED_GPIO_CLK 	    RCC_APB2Periph_GPIOC	  	     // GPIO�˿�ʱ��  
#define Board_LED_GPIO_PIN		    GPIO_Pin_11			               // ���ӵ�SCLʱ���ߵ�GPIO 


/** ����ܽ������ƽ
  * 1 - ����ߵ�ƽ
  * 0 - ����͵�ƽ
  */
#define ON  1
#define OFF 0

/* ���κ꣬��������������һ��ʹ�� */
#define Board_LED(x)	if (x)	\
					GPIO_SetBits(Board_LED_GPIO_PORT,Board_LED_GPIO_PIN);\
					else		\
					GPIO_ResetBits(Board_LED_GPIO_PORT,Board_LED_GPIO_PIN)

void Board_LED_GPIO_Config ( void );

#endif
