/*
**********************************************************
*
* ���ƿ�08��12����ӿڶ���
* 
* �������ڣ�2016.09.11
*
**********************************************************
*/

#include "stm32f10x_gpio.h"

#ifndef  __PORT_08_12_H
#define	 __PORT_08_12_H


//���ƿ�08��12�ӿڹ����ܽŶ���
#define PORT_08_12_STB_GPIO_APBxClock_FUN  RCC_APB2PeriphClockCmd   // ����GPIO������ʱ��
#define PORT_08_12_STB_GPIO_PORT    	GPIOC			                     // GPIO�˿� 
#define PORT_08_12_STB_GPIO_CLK 	    RCC_APB2Periph_GPIOC	  	     // GPIO�˿�ʱ��  
#define PORT_08_12_STB_GPIO_PIN		    GPIO_Pin_2			               // ���ӵ�SCLʱ���ߵ�GPIO 

#define PORT_08_12_SCK_GPIO_APBxClock_FUN  RCC_APB2PeriphClockCmd   
#define PORT_08_12_SCK_GPIO_PORT    	GPIOC			              
#define PORT_08_12_SCK_GPIO_CLK 	    RCC_APB2Periph_GPIOC		
#define PORT_08_12_SCK_GPIO_PIN		    GPIO_Pin_1			        

#define PORT_08_12_EN_GPIO_APBxClock_FUN  RCC_APB2PeriphClockCmd   
#define PORT_08_12_EN_GPIO_PORT    	  GPIOC			           
#define PORT_08_12_EN_GPIO_CLK 	      RCC_APB2Periph_GPIOC	
#define PORT_08_12_EN_GPIO_PIN		 	  GPIO_Pin_0			        

#define PORT_08_12_A_GPIO_APBxClock_FUN  RCC_APB2PeriphClockCmd  
#define PORT_08_12_A_GPIO_PORT    	  GPIOB			           
#define PORT_08_12_A_GPIO_CLK 	      RCC_APB2Periph_GPIOB
#define PORT_08_12_A_GPIO_PIN		 		  GPIO_Pin_13			        

#define PORT_08_12_B_GPIO_APBxClock_FUN  RCC_APB2PeriphClockCmd   
#define PORT_08_12_B_GPIO_PORT    	  GPIOC			           
#define PORT_08_12_B_GPIO_CLK 	      RCC_APB2Periph_GPIOC	
#define PORT_08_12_B_GPIO_PIN		 		  GPIO_Pin_5			        

#define PORT_08_12_C_GPIO_APBxClock_FUN  RCC_APB2PeriphClockCmd   
#define PORT_08_12_C_GPIO_PORT    	  GPIOC			           
#define PORT_08_12_C_GPIO_CLK 	      RCC_APB2Periph_GPIOC	
#define PORT_08_12_C_GPIO_PIN		 		  GPIO_Pin_4			        

#define PORT_08_12_D_GPIO_APBxClock_FUN  RCC_APB2PeriphClockCmd   
#define PORT_08_12_D_GPIO_PORT    	  GPIOC			           
#define PORT_08_12_D_GPIO_CLK 	      RCC_APB2Periph_GPIOC	
#define PORT_08_12_D_GPIO_PIN		 		  GPIO_Pin_3			        


//���ƿ�08-1�ӿڹܽŶ���

#define PORT_08_1_R1_GPIO_APBxClock_FUN  RCC_APB2PeriphClockCmd   
#define PORT_08_1_R1_GPIO_PORT    	GPIOB			           
#define PORT_08_1_R1_GPIO_CLK 	    RCC_APB2Periph_GPIOB	
#define PORT_08_1_R1_GPIO_PIN		 		GPIO_Pin_14			        

#define PORT_08_1_G1_GPIO_APBxClock_FUN  RCC_APB2PeriphClockCmd  
#define PORT_08_1_G1_GPIO_PORT    	GPIOC			           
#define PORT_08_1_G1_GPIO_CLK 	    RCC_APB2Periph_GPIOC	
#define PORT_08_1_G1_GPIO_PIN		 		GPIO_Pin_6			        

#define PORT_08_1_R2_GPIO_APBxClock_FUN  RCC_APB2PeriphClockCmd  
#define PORT_08_1_R2_GPIO_PORT    	GPIOB			           
#define PORT_08_1_R2_GPIO_CLK 	    RCC_APB2Periph_GPIOB	
#define PORT_08_1_R2_GPIO_PIN		 		GPIO_Pin_15			        

#define PORT_08_1_G2_GPIO_APBxClock_FUN  RCC_APB2PeriphClockCmd   
#define PORT_08_1_G2_GPIO_PORT    	GPIOC			           
#define PORT_08_1_G2_GPIO_CLK 	    RCC_APB2Periph_GPIOC	
#define PORT_08_1_G2_GPIO_PIN		 		GPIO_Pin_7			        


//���ƿ�08-2�ӿڹܽŶ���
#define PORT_08_2_R1_GPIO_APBxClock_FUN  RCC_APB2PeriphClockCmd   
#define PORT_08_2_R1_GPIO_PORT    	GPIOC			           
#define PORT_08_2_R1_GPIO_CLK 	    RCC_APB2Periph_GPIOC	
#define PORT_08_2_R1_GPIO_PIN		 		GPIO_Pin_8			        

#define PORT_08_2_G1_GPIO_APBxClock_FUN  RCC_APB2PeriphClockCmd  
#define PORT_08_2_G1_GPIO_PORT    	GPIOC			           
#define PORT_08_2_G1_GPIO_CLK 	    RCC_APB2Periph_GPIOC	
#define PORT_08_2_G1_GPIO_PIN		 		GPIO_Pin_10			        

#define PORT_08_2_R2_GPIO_APBxClock_FUN  RCC_APB2PeriphClockCmd  
#define PORT_08_2_R2_GPIO_PORT    	GPIOC			           
#define PORT_08_2_R2_GPIO_CLK 	    RCC_APB2Periph_GPIOC	
#define PORT_08_2_R2_GPIO_PIN		 		GPIO_Pin_9		        

#define PORT_08_2_G2_GPIO_APBxClock_FUN  RCC_APB2PeriphClockCmd   
#define PORT_08_2_G2_GPIO_PORT    	GPIOC			           
#define PORT_08_2_G2_GPIO_CLK 	    RCC_APB2Periph_GPIOC	
#define PORT_08_2_G2_GPIO_PIN		 		GPIO_Pin_12			        

//���ƿ�12-1�ӿڹܽŶ���
#define PORT_12_1_R_GPIO_APBxClock_FUN  RCC_APB2PeriphClockCmd   
#define PORT_12_1_R_GPIO_PORT    	  GPIOB			           
#define PORT_12_1_R_GPIO_CLK 	      RCC_APB2Periph_GPIOB	
#define PORT_12_1_R_GPIO_PIN		 		GPIO_Pin_14			        

#define PORT_12_1_G_GPIO_APBxClock_FUN  RCC_APB2PeriphClockCmd  
#define PORT_12_1_G_GPIO_PORT    	  GPIOC			           
#define PORT_12_1_G_GPIO_CLK 	      RCC_APB2Periph_GPIOC	
#define PORT_12_1_G_GPIO_PIN		 	  GPIO_Pin_6			        

//���ƿ�12-2�ӿڹܽŶ���
#define PORT_12_2_R_GPIO_APBxClock_FUN  RCC_APB2PeriphClockCmd   
#define PORT_12_2_R_GPIO_PORT    	  GPIOB			           
#define PORT_12_2_R_GPIO_CLK 	      RCC_APB2Periph_GPIOB
#define PORT_12_2_R_GPIO_PIN		 		GPIO_Pin_15

#define PORT_12_2_G_GPIO_APBxClock_FUN  RCC_APB2PeriphClockCmd  
#define PORT_12_2_G_GPIO_PORT    	  GPIOC			           
#define PORT_12_2_G_GPIO_CLK 	      RCC_APB2Periph_GPIOC	
#define PORT_12_2_G_GPIO_PIN		 		GPIO_Pin_7			        

//���ƿ�12-3�ӿڹܽŶ���
#define PORT_12_3_R_GPIO_APBxClock_FUN  RCC_APB2PeriphClockCmd   
#define PORT_12_3_R_GPIO_PORT    	  GPIOC			           
#define PORT_12_3_R_GPIO_CLK 	      RCC_APB2Periph_GPIOC	
#define PORT_12_3_R_GPIO_PIN		 		GPIO_Pin_8		        

#define PORT_12_3_G_GPIO_APBxClock_FUN  RCC_APB2PeriphClockCmd  
#define PORT_12_3_G_GPIO_PORT    	  GPIOC			           
#define PORT_12_3_G_GPIO_CLK 	      RCC_APB2Periph_GPIOC	
#define PORT_12_3_G_GPIO_PIN		 		GPIO_Pin_10			        

//���ƿ�12-4�ӿڹܽŶ���
#define PORT_12_4_R_GPIO_APBxClock_FUN  RCC_APB2PeriphClockCmd   
#define PORT_12_4_R_GPIO_PORT    	  GPIOC			           
#define PORT_12_4_R_GPIO_CLK 	      RCC_APB2Periph_GPIOC	
#define PORT_12_4_R_GPIO_PIN		 		GPIO_Pin_9			        

#define PORT_12_4_G_GPIO_APBxClock_FUN  RCC_APB2PeriphClockCmd  
#define PORT_12_4_G_GPIO_PORT    	  GPIOC			           
#define PORT_12_4_G_GPIO_CLK 	      RCC_APB2Periph_GPIOC	
#define PORT_12_4_G_GPIO_PIN		 		GPIO_Pin_12		  

//���ƿ��ӿ�ʹ�õĹܽŶ������

/** ����ܽ������ƽ
  * 1 - ����ߵ�ƽ
  * 0 - ����͵�ƽ
  */
#define ON  1
#define OFF 0

/* ���κ꣬��������������һ��ʹ�� */
#define STB(x)	if (x)	\
					GPIO_SetBits(PORT_08_12_STB_GPIO_PORT,PORT_08_12_STB_GPIO_PIN);\
					else		\
					GPIO_ResetBits(PORT_08_12_STB_GPIO_PORT,PORT_08_12_STB_GPIO_PIN)

#define CLK(x)	if (x)	\
					GPIO_SetBits(PORT_08_12_SCK_GPIO_PORT,PORT_08_12_SCK_GPIO_PIN);\
					else		\
					GPIO_ResetBits(PORT_08_12_SCK_GPIO_PORT,PORT_08_12_SCK_GPIO_PIN)

#define EN(x)	if (x)	\
					GPIO_SetBits(PORT_08_12_EN_GPIO_PORT,PORT_08_12_EN_GPIO_PIN);\
					else		\
					GPIO_ResetBits(PORT_08_12_EN_GPIO_PORT,PORT_08_12_EN_GPIO_PIN)
					
#define A(x)	if (x)	\
					GPIO_SetBits(PORT_08_12_A_GPIO_PORT,PORT_08_12_A_GPIO_PIN);\
					else		\
					GPIO_ResetBits(PORT_08_12_A_GPIO_PORT,PORT_08_12_A_GPIO_PIN)

#define B(x)	if (x)	\
					GPIO_SetBits(PORT_08_12_B_GPIO_PORT,PORT_08_12_B_GPIO_PIN);\
					else		\
					GPIO_ResetBits(PORT_08_12_B_GPIO_PORT,PORT_08_12_B_GPIO_PIN)
					
#define C(x)	if (x)	\
					GPIO_SetBits(PORT_08_12_C_GPIO_PORT,PORT_08_12_C_GPIO_PIN);\
					else		\
					GPIO_ResetBits(PORT_08_12_C_GPIO_PORT,PORT_08_12_C_GPIO_PIN)
					
#define D(x)	if (x)	\
					GPIO_SetBits(PORT_08_12_D_GPIO_PORT,PORT_08_12_D_GPIO_PIN);\
					else		\
					GPIO_ResetBits(PORT_08_12_D_GPIO_PORT,PORT_08_12_D_GPIO_PIN)

//08-1�ӿڹܽ������ƽ����
#define PORT_08_1_R1(x)	if (x)	\
					GPIO_SetBits(PORT_08_1_R1_GPIO_PORT,PORT_08_1_R1_GPIO_PIN);\
					else		\
					GPIO_ResetBits(PORT_08_1_R1_GPIO_PORT,PORT_08_1_R1_GPIO_PIN)
#define PORT_08_1_G1(x)	if (x)	\
					GPIO_SetBits(PORT_08_1_G1_GPIO_PORT,PORT_08_1_G1_GPIO_PIN);\
					else		\
					GPIO_ResetBits(PORT_08_1_G1_GPIO_PORT,PORT_08_1_G1_GPIO_PIN)
#define PORT_08_1_R2(x)	if (x)	\
					GPIO_SetBits(PORT_08_1_R2_GPIO_PORT,PORT_08_1_R2_GPIO_PIN);\
					else		\
					GPIO_ResetBits(PORT_08_1_R2_GPIO_PORT,PORT_08_1_R2_GPIO_PIN)
#define PORT_08_1_G2(x)	if (x)	\
					GPIO_SetBits(PORT_08_1_G2_GPIO_PORT,PORT_08_1_G2_GPIO_PIN);\
					else		\
					GPIO_ResetBits(PORT_08_1_G2_GPIO_PORT,PORT_08_1_G2_GPIO_PIN)

//08-2�ӿڹܽ������ƽ����
#define PORT_08_2_R1(x)	if (x)	\
					GPIO_SetBits(PORT_08_2_R1_GPIO_PORT,PORT_08_2_R1_GPIO_PIN);\
					else		\
					GPIO_ResetBits(PORT_08_2_R1_GPIO_PORT,PORT_08_2_R1_GPIO_PIN)
#define PORT_08_2_G1(x)	if (x)	\
					GPIO_SetBits(PORT_08_2_G1_GPIO_PORT,PORT_08_2_G1_GPIO_PIN);\
					else		\
					GPIO_ResetBits(PORT_08_2_G1_GPIO_PORT,PORT_08_2_G1_GPIO_PIN)
#define PORT_08_2_R2(x)	if (x)	\
					GPIO_SetBits(PORT_08_2_R2_GPIO_PORT,PORT_08_2_R2_GPIO_PIN);\
					else		\
					GPIO_ResetBits(PORT_08_2_R2_GPIO_PORT,PORT_08_2_R2_GPIO_PIN)
#define PORT_08_2_G2(x)	if (x)	\
					GPIO_SetBits(PORT_08_2_G2_GPIO_PORT,PORT_08_2_G2_GPIO_PIN);\
					else		\
					GPIO_ResetBits(PORT_08_2_G2_GPIO_PORT,PORT_08_2_G2_GPIO_PIN)

//12-1�ӿڹܽ������ƽ����
#define PORT_12_1_R(x)	if (x)	\
					GPIO_SetBits(PORT_12_1_R_GPIO_PORT,PORT_12_1_R_GPIO_PIN);\
					else		\
					GPIO_ResetBits(PORT_12_1_R_GPIO_PORT,PORT_12_1_R_GPIO_PIN)
#define PORT_12_1_G(x)	if (x)	\
					GPIO_SetBits(PORT_12_1_G_GPIO_PORT,PORT_12_1_G_GPIO_PIN);\
					else		\
					GPIO_ResetBits(PORT_12_1_G_GPIO_PORT,PORT_12_1_G_GPIO_PIN)

//12-2�ӿڹܽ������ƽ����
#define PORT_12_2_R(x)	if (x)	\
					GPIO_SetBits(PORT_12_2_R_GPIO_PORT,PORT_12_2_R_GPIO_PIN);\
					else		\
					GPIO_ResetBits(PORT_12_2_R_GPIO_PORT,PORT_12_2_R_GPIO_PIN)
#define PORT_12_2_G(x)	if (x)	\
					GPIO_SetBits(PORT_12_2_G_GPIO_PORT,PORT_12_2_G_GPIO_PIN);\
					else		\
					GPIO_ResetBits(PORT_12_2_G_GPIO_PORT,PORT_12_2_G_GPIO_PIN)

//12-3�ӿڹܽ������ƽ����
#define PORT_12_3_R(x)	if (x)	\
					GPIO_SetBits(PORT_12_3_R_GPIO_PORT,PORT_12_3_R_GPIO_PIN);\
					else		\
					GPIO_ResetBits(PORT_12_3_R_GPIO_PORT,PORT_12_3_R_GPIO_PIN)
#define PORT_12_3_G(x)	if (x)	\
					GPIO_SetBits(PORT_12_3_G_GPIO_PORT,PORT_12_3_G_GPIO_PIN);\
					else		\
					GPIO_ResetBits(PORT_12_3_G_GPIO_PORT,PORT_12_3_G_GPIO_PIN)

//12-4�ӿڹܽ������ƽ����
#define PORT_12_4_R(x)	if (x)	\
					GPIO_SetBits(PORT_12_4_R_GPIO_PORT,PORT_12_4_R_GPIO_PIN);\
					else		\
					GPIO_ResetBits(PORT_12_4_R_GPIO_PORT,PORT_12_4_R_GPIO_PIN)
#define PORT_12_4_G(x)	if (x)	\
					GPIO_SetBits(PORT_12_4_G_GPIO_PORT,PORT_12_4_G_GPIO_PIN);\
					else		\
					GPIO_ResetBits(PORT_12_4_G_GPIO_PORT,PORT_12_4_G_GPIO_PIN)


					
//���ƿ��ӿڹܽų�ʼ��
void Port_08_12_GPIO_Config(void);
void Port_08_12_Comm_GPIO_Config(void); //08��12�ӿڹ��ùܽų�ʼ��
void Port_08_1_GPIO_Config(void);       //08-1�ӿڹܽų�ʼ��
void Port_08_2_GPIO_Config(void);
void Port_12_1_GPIO_Config(void);
void Port_12_2_GPIO_Config(void);
void Port_12_3_GPIO_Config(void);
void Port_12_4_GPIO_Config(void);

#endif

