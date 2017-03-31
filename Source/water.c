#include "water.h"
#include "cmsis_os.h"
#include "Port_08_12.h"

/*
********************************************
*
*  开始浇水
*  输入：浇水时长，以秒计
*  输出：无
*
********************************************
*/
void water_start(uint16_t seconds){
	uint16_t i;
	EN(ON);
	for(i=0;i<seconds;i++){
		osDelay(1000);
	}
	EN(OFF);
}

/*
********************************************
*
*  浇水结束
*
********************************************
*/
void water_stop(void){
	EN(OFF);
}

