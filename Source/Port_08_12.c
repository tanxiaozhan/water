/*
*************************************************************
*
* ���ƿ�����ӿڣ�08��12���ܽ�����
* �������ڣ�2016.09.11
*
*************************************************************
*/


#include "Port_08_12.h"


/*
	*************************************************
	*
  * @brief  ��ʼ�� 08��12 �˿ڹ��õ�GPIO����
	*          ��A��B��C��D��STB��CLK��EN ����
  * @param  ��
  * @retval ��
	*
	*************************************************
*/
void Port_08_12_Comm_GPIO_Config ( void )
{
	/*����һ��GPIO_InitTypeDef���͵Ľṹ��*/
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;   //��������ģʽΪͨ���������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;  //������������Ϊ50MHz    

	//����STB����
	PORT_08_12_STB_GPIO_APBxClock_FUN ( PORT_08_12_STB_GPIO_CLK, ENABLE );  //����GPIOB��GPIOF������ʱ��
	GPIO_InitStructure.GPIO_Pin = PORT_08_12_STB_GPIO_PIN;	                //ѡ��Ҫ���Ƶ�GPIOB����	
	GPIO_Init ( PORT_08_12_STB_GPIO_PORT, & GPIO_InitStructure );	        //���ÿ⺯������ʼ��GPIO
	
	// ���� SCK ����
	PORT_08_12_SCK_GPIO_APBxClock_FUN ( PORT_08_12_SCK_GPIO_CLK, ENABLE ); 
	GPIO_InitStructure.GPIO_Pin = PORT_08_12_SCK_GPIO_PIN;	
	GPIO_Init ( PORT_08_12_SCK_GPIO_PORT, & GPIO_InitStructure );

	// ���� EN ����
	PORT_08_12_EN_GPIO_APBxClock_FUN ( PORT_08_12_EN_GPIO_CLK, ENABLE ); 
	GPIO_InitStructure.GPIO_Pin = PORT_08_12_EN_GPIO_PIN;	
	GPIO_Init ( PORT_08_12_EN_GPIO_PORT, & GPIO_InitStructure );

	// ���� A ����
	PORT_08_12_A_GPIO_APBxClock_FUN ( PORT_08_12_A_GPIO_CLK, ENABLE ); 
	GPIO_InitStructure.GPIO_Pin = PORT_08_12_A_GPIO_PIN;	
	GPIO_Init ( PORT_08_12_A_GPIO_PORT, & GPIO_InitStructure );
	
	// ���� B ����
	PORT_08_12_B_GPIO_APBxClock_FUN ( PORT_08_12_B_GPIO_CLK, ENABLE ); 
	GPIO_InitStructure.GPIO_Pin = PORT_08_12_B_GPIO_PIN;	
	GPIO_Init ( PORT_08_12_B_GPIO_PORT, & GPIO_InitStructure );
	
	// ���� C ����
	PORT_08_12_C_GPIO_APBxClock_FUN ( PORT_08_12_C_GPIO_CLK, ENABLE ); 
	GPIO_InitStructure.GPIO_Pin = PORT_08_12_C_GPIO_PIN;	
	GPIO_Init ( PORT_08_12_C_GPIO_PORT, & GPIO_InitStructure );
	
	// ���� D ����
	PORT_08_12_D_GPIO_APBxClock_FUN ( PORT_08_12_D_GPIO_CLK, ENABLE ); 
	GPIO_InitStructure.GPIO_Pin = PORT_08_12_D_GPIO_PIN;	
	GPIO_Init ( PORT_08_12_D_GPIO_PORT, & GPIO_InitStructure );
}

/*
	*************************************************
	*
  * @brief  ��ʼ�� 08-1 �˿��õ���GPIO����
  * @param  ��
  * @retval ��
	*************************************************
*/
void Port_08_1_GPIO_Config ( void )
{
	/*����һ��GPIO_InitTypeDef���͵Ľṹ��*/
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;   //��������ģʽΪͨ���������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;  //������������Ϊ50MHz    

	// ���� R1 ����
	PORT_08_1_R1_GPIO_APBxClock_FUN ( PORT_08_1_R1_GPIO_CLK, ENABLE ); 
	GPIO_InitStructure.GPIO_Pin = PORT_08_1_R1_GPIO_PIN;	
	GPIO_Init ( PORT_08_1_R1_GPIO_PORT, & GPIO_InitStructure );
	
	// ���� R2 ����
	PORT_08_1_R2_GPIO_APBxClock_FUN ( PORT_08_1_R2_GPIO_CLK, ENABLE ); 
	GPIO_InitStructure.GPIO_Pin = PORT_08_1_R2_GPIO_PIN;	
	GPIO_Init ( PORT_08_1_R2_GPIO_PORT, & GPIO_InitStructure );
	
	// ���� G1 ����
	PORT_08_1_G1_GPIO_APBxClock_FUN ( PORT_08_1_G1_GPIO_CLK, ENABLE ); 
	GPIO_InitStructure.GPIO_Pin = PORT_08_1_G1_GPIO_PIN;	
	GPIO_Init ( PORT_08_1_G1_GPIO_PORT, & GPIO_InitStructure );
	
	// ���� G2 ����
	PORT_08_1_G2_GPIO_APBxClock_FUN ( PORT_08_1_G2_GPIO_CLK, ENABLE ); 
	GPIO_InitStructure.GPIO_Pin = PORT_08_1_G2_GPIO_PIN;	
	GPIO_Init ( PORT_08_1_G2_GPIO_PORT, & GPIO_InitStructure );
}

/*
	*************************************************
	*
  * @brief  ��ʼ�� 08-2 �˿��õ���GPIO����
  * @param  ��
  * @retval ��
	*************************************************
*/
void Port_08_2_GPIO_Config ( void )
{
	/*����һ��GPIO_InitTypeDef���͵Ľṹ��*/
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;   //��������ģʽΪͨ���������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;  //������������Ϊ50MHz    

	// ���� 08-2�ӿ�GPIO����
	// ���� R1 ����
	PORT_08_2_R1_GPIO_APBxClock_FUN ( PORT_08_2_R1_GPIO_CLK, ENABLE ); 
	GPIO_InitStructure.GPIO_Pin = PORT_08_2_R1_GPIO_PIN;	
	GPIO_Init ( PORT_08_2_R1_GPIO_PORT, & GPIO_InitStructure );
	
	// ���� R2 ����
	PORT_08_2_R2_GPIO_APBxClock_FUN ( PORT_08_2_R2_GPIO_CLK, ENABLE ); 
	GPIO_InitStructure.GPIO_Pin = PORT_08_2_R2_GPIO_PIN;	
	GPIO_Init ( PORT_08_2_R2_GPIO_PORT, & GPIO_InitStructure );
	
	// ���� G1 ����
	PORT_08_2_G1_GPIO_APBxClock_FUN ( PORT_08_2_G1_GPIO_CLK, ENABLE ); 
	GPIO_InitStructure.GPIO_Pin = PORT_08_2_G1_GPIO_PIN;	
	GPIO_Init ( PORT_08_2_G1_GPIO_PORT, & GPIO_InitStructure );
	
	// ���� G2 ����
	PORT_08_2_G2_GPIO_APBxClock_FUN ( PORT_08_2_G2_GPIO_CLK, ENABLE ); 
	GPIO_InitStructure.GPIO_Pin = PORT_08_2_G2_GPIO_PIN;	
	GPIO_Init ( PORT_08_2_G2_GPIO_PORT, & GPIO_InitStructure );
}
	
/*
	*************************************************
	*
  * @brief  ��ʼ�� 12-1 �˿��õ���GPIO����
  * @param  ��
  * @retval ��
	*************************************************
*/
void Port_12_1_GPIO_Config ( void )
{
	/*����һ��GPIO_InitTypeDef���͵Ľṹ��*/
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;   //��������ģʽΪͨ���������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;  //������������Ϊ50MHz    

	// ���� 12-1�ӿ�GPIO����
	// ���� R ����
	PORT_12_1_R_GPIO_APBxClock_FUN ( PORT_12_1_R_GPIO_CLK, ENABLE ); 
	GPIO_InitStructure.GPIO_Pin = PORT_12_1_R_GPIO_PIN;	
	GPIO_Init ( PORT_12_1_R_GPIO_PORT, & GPIO_InitStructure );
	
	// ���� G ����
	PORT_12_1_G_GPIO_APBxClock_FUN ( PORT_12_1_G_GPIO_CLK, ENABLE ); 
	GPIO_InitStructure.GPIO_Pin = PORT_12_1_G_GPIO_PIN;	
	GPIO_Init ( PORT_12_1_G_GPIO_PORT, & GPIO_InitStructure );
}
	
/*
	*************************************************
	*
  * @brief  ��ʼ�� 12-2 �˿��õ���GPIO����
  * @param  ��
  * @retval ��
	*************************************************
*/
void Port_12_2_GPIO_Config ( void )
{
	/*����һ��GPIO_InitTypeDef���͵Ľṹ��*/
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;   //��������ģʽΪͨ���������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;  //������������Ϊ50MHz    

	// ���� 12-2 �ӿ�GPIO����
	// ���� R ����
	PORT_12_2_R_GPIO_APBxClock_FUN ( PORT_12_2_R_GPIO_CLK, ENABLE ); 
	GPIO_InitStructure.GPIO_Pin = PORT_12_2_R_GPIO_PIN;	
	GPIO_Init ( PORT_12_2_R_GPIO_PORT, & GPIO_InitStructure );
	
	// ���� G1 ����
	PORT_12_2_G_GPIO_APBxClock_FUN ( PORT_12_2_G_GPIO_CLK, ENABLE ); 
	GPIO_InitStructure.GPIO_Pin = PORT_12_2_G_GPIO_PIN;	
	GPIO_Init ( PORT_12_2_G_GPIO_PORT, & GPIO_InitStructure );
}
	
/*
	*************************************************
	*
  * @brief  ��ʼ�� 12-3 �˿��õ���GPIO����
  * @param  ��
  * @retval ��
	*************************************************
*/
void Port_12_3_GPIO_Config ( void )
{
	/*����һ��GPIO_InitTypeDef���͵Ľṹ��*/
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;   //��������ģʽΪͨ���������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;  //������������Ϊ50MHz    

	// ���� 12-3�ӿ�GPIO����
	// ���� R ����
	PORT_12_3_R_GPIO_APBxClock_FUN ( PORT_12_3_R_GPIO_CLK, ENABLE ); 
	GPIO_InitStructure.GPIO_Pin = PORT_12_3_R_GPIO_PIN;	
	GPIO_Init ( PORT_12_3_R_GPIO_PORT, & GPIO_InitStructure );
	
	// ���� G ����
	PORT_12_3_G_GPIO_APBxClock_FUN ( PORT_12_3_G_GPIO_CLK, ENABLE ); 
	GPIO_InitStructure.GPIO_Pin = PORT_12_3_G_GPIO_PIN;	
	GPIO_Init ( PORT_12_3_G_GPIO_PORT, & GPIO_InitStructure );
}
	
/*
	*************************************************
	*
  * @brief  ��ʼ�� 12-4 �˿��õ���GPIO����
  * @param  ��
  * @retval ��
	*************************************************
*/
void Port_12_4_GPIO_Config ( void )
{
	/*����һ��GPIO_InitTypeDef���͵Ľṹ��*/
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;   //��������ģʽΪͨ���������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;  //������������Ϊ50MHz    

	// ���� 12-4 �ӿ�GPIO����
	// ���� R1 ����
	PORT_12_4_R_GPIO_APBxClock_FUN ( PORT_12_4_R_GPIO_CLK, ENABLE ); 
	GPIO_InitStructure.GPIO_Pin = PORT_12_4_R_GPIO_PIN;	
	GPIO_Init ( PORT_12_4_R_GPIO_PORT, & GPIO_InitStructure );
	
	// ���� G ����
	PORT_12_4_G_GPIO_APBxClock_FUN ( PORT_12_4_G_GPIO_CLK, ENABLE ); 
	GPIO_InitStructure.GPIO_Pin = PORT_12_4_G_GPIO_PIN;	
	GPIO_Init ( PORT_12_4_G_GPIO_PORT, & GPIO_InitStructure );
}
	

/*
	*************************************************
	*
  * @brief  ��ʼ�����ƿ�08��12�˿��õ���GPIO����
  * @param  ��
  * @retval ��
	*************************************************
*/
void Port_08_12_GPIO_Config(void){
	
	Port_08_12_Comm_GPIO_Config();

	GPIO_SetBits(PORT_08_12_EN_GPIO_PORT, PORT_08_12_EN_GPIO_PIN);  		// �رն˿�EN�ܽ�

	Port_08_1_GPIO_Config();
	Port_08_2_GPIO_Config();
	Port_12_1_GPIO_Config();
	Port_12_2_GPIO_Config();
	Port_12_3_GPIO_Config();
	Port_12_4_GPIO_Config();

}
