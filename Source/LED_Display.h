#include "cmsis_os.h"
#include "flash_SPI.h"
#include "stdbool.h"

typedef struct{
	uint8_t hour;
	uint8_t minute;
	uint8_t second;
}struct_time;


//显示屏色彩类型
typedef enum{
	SINGLE,      //单色
	DOUBLE,      //双色
	COLOR        //彩色
}led_display_color;



void Port_08_1_GPIO_Config(void);
void Port_08_2_GPIO_Config(void);
void Port_12_1_GPIO_Config(void);
void Port_12_2_GPIO_Config(void);
void Port_12_3_GPIO_Config(void);
void Port_12_4_GPIO_Config(void);
void Port_08_12_GPIO_Config(void);

void LED_display_init(void);
void LED_display_start(void);

