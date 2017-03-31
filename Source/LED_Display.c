/*
**************************************
* 
* 显示时间
*  
* 创建日期：2017.01.23 
*
*************************************
*/

#include "cmsis_os.h"
#include "LED_Display.h"
#include "Port_08_12.h"

osThreadId LED_display_thread_id;   //显示线程id，创建/中止此线程控制显示的开关

extern struct_time water_time;
uint8_t now[4]={1,2,0,0};    //当前时间，数组元素0，1保存小时，2，3保存分钟
extern uint16_t water_last_second;    //浇花时长，秒为单位

//显示主线程
static void LED_Display(void const *arg);
osThreadDef(LED_Display, osPriorityAboveNormal, 1, 0);


/*----------------------------------------------------------------------------
 * 线程'LED_Dispaly'：LED显示屏扫描显示
 *---------------------------------------------------------------------------*/
static void LED_Display (void const *arg) {
	uint8_t i,j,scan,seg;
	uint8_t font[10]={0xF5,0x05,0xB3,0x97,0x47,0xD6,0xF6,0x85,0xF7,0xD7};   //7段数码管显示0-9的字模
	uint8_t col;
	uint16_t blink=0;    // 小时和分钟之间的 ：号闪亮
	A(0);B(0);C(0);D(0);   //关闭显示
	while(1){
			col=0x01;
			for(i=0;i<4;i++){
				seg=font[now[i]];
				if(i==0 && now[0]==0)   //小时十位上为0，零消隐
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
					
					
					CLK(ON);       //594移位信号
					scan >>= 1;
				}
				STB(0);
				STB(1);  //锁存
				A( col & 0x01 );B( col & 0x02 );C( col & 0x04 );D( col & 0x08 );   //位扫描
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
	*  创建LED显示屏控制信号线程，控制卡控制信号开始输出
	*
	********************************************************
*/

void LED_display_start(void){
		LED_display_thread_id = osThreadCreate (osThread(LED_Display), NULL);
}


/*
	********************************************************
	*  LED显示屏初始化
	********************************************************
*/
void LED_display_init(void){
	
	uint8_t pBuff[5];
	Port_08_12_GPIO_Config();    //初始化控制卡08、12输出接口用到的GPIO引脚

	//从外部闪存读取显示屏参数
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

	EN(OFF);                    //关闭浇水电源
	
}

