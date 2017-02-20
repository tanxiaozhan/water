#include "Board_LED.h"


void Board_LED_GPIO_Config ( void )
{
	/*����һ��GPIO_InitTypeDef���͵Ľṹ��*/
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;   //��������ģʽΪͨ���������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;  //������������Ϊ50MHz    

	//����STB����
	Board_LED_GPIO_APBxClock_FUN ( Board_LED_GPIO_CLK, ENABLE );  //����GPIOB������ʱ��
	GPIO_InitStructure.GPIO_Pin = Board_LED_GPIO_PIN;	                //ѡ��Ҫ���Ƶ�GPIOB����	
	GPIO_Init ( Board_LED_GPIO_PORT, & GPIO_InitStructure );	        //���ÿ⺯������ʼ��GPIO
}

