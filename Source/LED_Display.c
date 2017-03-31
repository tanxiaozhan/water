/*
**************************************
* 
* ��ʾʱ��
*  
* �������ڣ�2017.01.23 
*
*************************************
*/

#include "cmsis_os.h"
#include "LED_Display.h"
#include "Port_08_12.h"

osThreadId LED_display_thread_id;   //��ʾ�߳�id������/��ֹ���߳̿�����ʾ�Ŀ���

extern struct_time water_time;
uint8_t now[4]={1,2,0,0};    //��ǰʱ�䣬����Ԫ��0��1����Сʱ��2��3�������
extern uint16_t water_last_second;    //����ʱ������Ϊ��λ

//��ʾ���߳�
static void LED_Display(void const *arg);
osThreadDef(LED_Display, osPriorityAboveNormal, 1, 0);


/*----------------------------------------------------------------------------
 * �߳�'LED_Dispaly'��LED��ʾ��ɨ����ʾ
 *---------------------------------------------------------------------------*/
static void LED_Display (void const *arg) {
	uint8_t i,j,scan,seg;
	uint8_t font[10]={0xF5,0x05,0xB3,0x97,0x47,0xD6,0xF6,0x85,0xF7,0xD7};   //7���������ʾ0-9����ģ
	uint8_t col;
	uint16_t blink=0;    // Сʱ�ͷ���֮��� ��������
	A(0);B(0);C(0);D(0);   //�ر���ʾ
	while(1){
			col=0x01;
			for(i=0;i<4;i++){
				seg=font[now[i]];
				if(i==0 && now[0]==0)   //Сʱʮλ��Ϊ0��������
					seg =0x0;
				scan=0x80;
				for(j=0;j<8;j++){
					CLK(OFF);     

					if(blink>200 && i==1){
						PORT_12_4_R( !((seg | 0x08) & scan ));
					}
					else{
						PORT_12_4_R( !(seg & scan ));
					}
					
					
					CLK(ON);       //594��λ�ź�
					scan >>= 1;
				}
				STB(0);
				STB(1);  //����
				A( col & 0x01 );B( col & 0x02 );C( col & 0x04 );D( col & 0x08 );   //λɨ��
				osDelay(5);
				col <<= 1;
				blink++;
				if(blink>400)
					blink=0;
			}
		}
}


/*
	********************************************************
	*
	*  ����LED��ʾ�������ź��̣߳����ƿ������źſ�ʼ���
	*
	********************************************************
*/

void LED_display_start(void){
		LED_display_thread_id = osThreadCreate (osThread(LED_Display), NULL);
}


/*
	********************************************************
	*  LED��ʾ����ʼ��
	********************************************************
*/
void LED_display_init(void){
	
	uint8_t pBuff[5];
	Port_08_12_GPIO_Config();    //��ʼ�����ƿ�08��12����ӿ��õ���GPIO����

	//���ⲿ�����ȡ��ʾ������
	SPI_FLASH_BufferRead(pBuff,4096,5);
	water_time.hour=9;
	water_time.minute=0;
	water_time.second=0;
  water_last_second=pBuff[3]*256+pBuff[4];
	
	if (pBuff[0]<24)
		water_time.hour=pBuff[0] ;
	if (pBuff[1]<60)
		water_time.minute=pBuff[1];
	if (pBuff[2]<60)
		water_time.second=pBuff[2];

	EN(OFF);                    //�رս�ˮ��Դ
	
}

