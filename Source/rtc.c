/**
  ******************************************************************************
  * @file    rtc.h
  * @version V1.0.0
  * @date    2016-10-6
  * @brief   stm32F103 ʵʱ��ģ��
  ******************************************************************************
  * @attention
  *
  ******************************************************************************
  */

#include <stdio.h>
#include "rtc.h"
#include "stdbool.h"
#include "LED_Display.h"

#define FEBRUARY		2
#define	STARTOFTIME		1970
#define SECDAY			86400L           /*  һ���ж���s */
#define SECYR			(SECDAY * 365)
#define	leapyear(year)		((year) % 4 == 0)
#define	days_in_year(a) 	(leapyear(a) ? 366 : 365)
#define	days_in_month(a) 	(month_days[(a) - 1])

static int month_days[12] = {	31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
extern uint8_t now[4];    //��ǰʱ�䣬����Ԫ��0��1����Сʱ��2��3�������
extern struct rtc_time system_time;
extern struct_time water_time;
extern bool water_flag;              //������ʼ��־��true--����


/*
 * This only works for the Gregorian calendar - i.e. after 1752 (in the UK)
 */
 /*�������ڼ�*/
void GregorianDay(struct rtc_time * tm)
{
	int leapsToDate;
	int lastYear;
	int day;
	int MonthOffset[] = { 0,31,59,90,120,151,181,212,243,273,304,334 };

	lastYear=tm->rt_year-1;

	/*����ӹ�ԪԪ�굽������ǰһ��֮��һ�������˶��ٸ�����*/
	leapsToDate = lastYear/4 - lastYear/100 + lastYear/400;      

     /*������������һ��Ϊ���꣬�Ҽ������·���2��֮����������1�����򲻼�1*/
	if((tm->rt_year%4==0) &&
	   ((tm->rt_year%100!=0) || (tm->rt_year%400==0)) &&
	   (tm->rt_mon>2)) {
		/*
		 * We are past Feb. 29 in a leap year
		 */
		day=1;
	} else {
		day=0;
	}

	day += lastYear*365 + leapsToDate + MonthOffset[tm->rt_mon-1] + tm->rt_date; /*����ӹ�ԪԪ��Ԫ������������һ���ж�����*/

	tm->rt_day=day%7;
}

/* Converts Gregorian date to seconds since 1970-01-01 00:00:00.
 * Assumes input in normal date format, i.e. 1980-12-31 23:59:59
 * => year=1980, mon=12, day=31, hour=23, min=59, sec=59.
 *
 * [For the Julian calendar (which was used in Russia before 1917,
 * Britain & colonies before 1752, anywhere else before 1582,
 * and is still in use by some communities) leave out the
 * -year/100+year/400 terms, and add 10.]
 *
 * This algorithm was first published by Gauss (I think).
 *
 * WARNING: this function will overflow on 2106-02-07 06:28:16 on
 * machines were long is 32-bit! (However, as time_t is signed, we
 * will already get problems at other places on 2038-01-19 03:14:08)

 *ADD by fire���������ڹ����е��������Ϊ����ʱ�䣬
 ������ת����ʱ���ʱ���Ҫ�ӱ���ʱ��ת��Ϊ��׼ʱ���ʱ���
 */
u32 mktimev(struct rtc_time *tm)
{
	if (0 >= (int) (tm->rt_mon -= 2)) {	/* 1..12 -> 11,12,1..10 */
		tm->rt_mon += 12;		/* Puts Feb last since it has leap day */
		tm->rt_year -= 1;
	}

	return (((
		(u32) (tm->rt_year/4 - tm->rt_year/100 + tm->rt_year/400 + 367*tm->rt_mon/12 + tm->rt_date) +
			tm->rt_year*365 - 719499
	    )*24 + tm->rt_hour /* now have hours */
	  )*60 + tm->rt_min /* now have minutes */
	)*60 + tm->rt_sec-8*60*60; /* finally seconds */
	/*Add by fire: -8*60*60 ������ı���ʱ��ת��Ϊ��׼ʱ�䣬
	��д���ʱ���У�ȷ����ʱ��������Ϊ��׼��UNIXʱ���*/ 
}

void to_tm(u32 tim, struct rtc_time * tm)
{
	register u32    i;
	register long   hms, day;

	day = tim / SECDAY;			/* �ж����� */
	hms = tim % SECDAY;			/* �����ʱ�䣬��λs */

	/* Hours, minutes, seconds are easy */
	tm->rt_hour = hms / 3600;
	tm->rt_min = (hms % 3600) / 60;
	tm->rt_sec = (hms % 3600) % 60;

	/* Number of years in days */ /*�����ǰ��ݣ���ʼ�ļ������Ϊ1970��*/
	for (i = STARTOFTIME; day >= days_in_year(i); i++) {
		day -= days_in_year(i);
	}
	tm->rt_year = i;

	/* Number of months in days left */ /*���㵱ǰ���·�*/
	if (leapyear(tm->rt_year)) {
		days_in_month(FEBRUARY) = 29;
	}
	for (i = 1; day >= days_in_month(i); i++) {
		day -= days_in_month(i);
	}
	days_in_month(FEBRUARY) = 28;
	tm->rt_mon = i;

	/* Days are what is left over (+1) from all that. *//*���㵱ǰ����*/
	tm->rt_date = day + 1;

	/*
	 * Determine the day of week �������ڼ���0-6��0-������
	 */
	GregorianDay(tm);
}

/*
 * ��������Time_Adjust
 * ����  ��ʱ��У��
 * ����  �����ڶ�ȡRTCʱ��Ľṹ��ָ��
 * ���  ����
 * ����  ���ⲿ����
 */
void Time_Adjust(struct rtc_time *tm)
{

  /* Wait until last write operation on RTC registers has finished */
  RTC_WaitForLastTask();

	/* Enable PWR and BKP clocks */
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_PWR | RCC_APB1Periph_BKP, ENABLE);
	
	/* Allow access to BKP Domain */
	PWR_BackupAccessCmd(ENABLE);

	/* �޸ĵ�ǰRTC�����Ĵ������� */
  RTC_SetCounter(mktimev(tm));
	
  /* Wait until last write operation on RTC registers has finished */
	RTC_WaitForLastTask();
}

/*
 * ��������RTC_Configuration
 * ����  ������RTC
 * ����  ����
 * ���  ����
 * ����  ���ⲿ����
 */
void RTC_Configuration(void)
{
	/* ��һ����ͨ�����üĴ���RCC_APB1ENR��PWREN��BKPENλ���򿪵�Դ�ͺ󱸽ӿڵ�ʱ�ӵ��ÿ⺯�� */
	/* Enable PWR and BKP clocks */
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_PWR | RCC_APB1Periph_BKP, ENABLE);

	/* �ڶ�������Դ���ƼĴ���(PWR_CR)��DBPλ��ʹ�ܶԺ󱸼Ĵ�����RTC�ķ��ʵ��ÿ⺯�� */
	/* Allow access to BKP Domain */
	PWR_BackupAccessCmd(ENABLE);
	
	/* ����������ʼ����λBKP�Ĵ��� */
	/* Reset Backup Domain */
	BKP_DeInit();
	
	/* ���Ĳ�������RTCCLK */
	/* Enable LSE */
	RCC_LSEConfig(RCC_LSE_ON);
	
	/* ���岽����RTC����ʱ��ѡ��ΪLSEʱ�����벢ʹ��RTC���ȴ�RTC��APBʱ��ͬ�� */
	/* Wait till LSE is ready */
	while (RCC_GetFlagStatus(RCC_FLAG_LSERDY) == RESET){
	}
	/* Select LSE as RTC Clock Source */
	RCC_RTCCLKConfig(RCC_RTCCLKSource_LSE);
	
	/* Enable RTC Clock */
	RCC_RTCCLKCmd(ENABLE);
	
	/* Wait for RTC registers synchronization 
	 * ��ΪRTCʱ���ǵ��ٵģ��ڻ�ʱ���Ǹ��ٵģ�����Ҫͬ��
	 */
	RTC_WaitForSynchro();
	
	/* Wait until last write operation on RTC registers has finished */
	//RTC_WaitForLastTask();
	
	/* Enable the RTC IT */
	//RTC_ITConfig(RTC_IT_SEC, ENABLE);
	
	/* Wait until last write operation on RTC registers has finished */
	RTC_WaitForLastTask();
	
	/* Set RTC prescaler: set RTC period to 1sec */
	RTC_SetPrescaler(32767); /* RTC period = RTCCLK/RTC_PR = (32.768 KHz)/(32767+1) = 1HZ */
	
	/* Wait until last write operation on RTC registers has finished */
	RTC_WaitForLastTask();
}

/*
 * ��������RTC_Check
 * ����  ������ʱ����RTC���
 * ����  ��tm��ϵͳʱ��ṹָ��
 * ���  ����
 * ����  ���ⲿ����
 */
void RTC_check(void){

	/*������ʱ��鱸�ݼĴ���BKP_DR1��������ݲ���0xD3EA�����ꡱ�Ĺ����룩
	  ������������ʵʱ��*/
	if (BKP_ReadBackupRegister(BKP_DR1) != 0xD3EA){
		/* ʵʱ������ */
		RTC_Configuration();
		BKP_WriteBackupRegister(BKP_DR1, 0xD3EA);
	}
	else{    /*��������������ʱ��*/
		/*����Ƿ��������*/
		if (RCC_GetFlagStatus(RCC_FLAG_PORRST) != RESET){
		  //printf("\r\n\r\n ��������....");
		}
		/*����Ƿ�Reset��λ*/
		else if (RCC_GetFlagStatus(RCC_FLAG_PINRST) != RESET){
			//printf("\r\n\r\n ϵͳ��λ....");
		}
	}
	
	/* Clear reset flags */
	RCC_ClearFlag();
}

/*
*********************************************
*�������ƣ�RTC_AlarmSet
*��    ģ��RTC��������
*��    ������
*�� �� ֵ����
*********************************************
*/

void RTC_AlarmSet(void){
	NVIC_InitTypeDef NVIC_InitStructure;
	//�����ж�
	NVIC_InitStructure.NVIC_IRQChannel=RTC_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=1;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority=1;
	NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;
	NVIC_Init(&NVIC_InitStructure);
	
	//�����ж�
	RTC_ITConfig(RTC_IT_SEC, ENABLE);
}

/*
*********************************************
*�������ƣ�RTC_IRQHandler
*��    ģ��RTC�����жϷ������
*��    ������
*�� �� ֵ����
*********************************************
*/
void RTC_IRQHandler(void){
	if(RTC_GetITStatus(RTC_IT_SEC) != RESET){   //����жϱ�־λ
		RTC_ClearITPendingBit(RTC_IT_SEC);       //�ȴ��������
		RTC_WaitForLastTask();
		to_tm(RTC_GetCounter() + 8*60*60, &system_time);/*�Ѷ�ʱ����ֵת��Ϊ����ʱ��*/	
		now[0]=system_time.rt_hour/10;
		now[1]=system_time.rt_hour%10;
		now[2]=system_time.rt_min /10;
		now[3]=system_time.rt_min %10;
		
		//��ʱʱ���ж�
		if(water_time.hour==system_time.rt_hour && water_time.minute==system_time.rt_min && water_time.second==system_time.rt_sec){
				water_flag = true;
		}
	}
}
