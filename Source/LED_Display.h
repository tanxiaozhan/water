#include "cmsis_os.h"
#include "flash_SPI.h"
#include "stdbool.h"

typedef struct{
	uint8_t hour;
	uint8_t minute;
	uint8_t second;
}struct_time;


//��ʾ��ɫ������
typedef enum{
	SINGLE,      //��ɫ
	DOUBLE,      //˫ɫ
	COLOR        //��ɫ
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

