/**
  ******************************************************************************
  * @file    rtc.h
  * @version V1.0.0
  * @date    2016-10-6
  * @brief   stm32F103 实时钟san模块头文件
  ******************************************************************************
  * @attention
  *
  ******************************************************************************
  */

#ifndef __RTC_H
#define __RTC_H


#include "stm32f10x.h"


/*系统时间*/
struct rtc_time {
	int rt_sec;
	int rt_min;
	int rt_hour;
	int rt_date;
	int rt_mon;
	int rt_year;
	int rt_day;
};

/** 
  * @brief  RTC Time structure definition  
  */
typedef struct
{
  uint8_t RTC_Hours;    /*!< Specifies the RTC Time Hour.
                        This parameter must be set to a value in the 0-12 range
                        if the RTC_HourFormat_12 is selected or 0-23 range if
                        the RTC_HourFormat_24 is selected. */

  uint8_t RTC_Minutes;  /*!< Specifies the RTC Time Minutes.
                        This parameter must be set to a value in the 0-59 range. */
  
  uint8_t RTC_Seconds;  /*!< Specifies the RTC Time Seconds.
                        This parameter must be set to a value in the 0-59 range. */

  uint8_t RTC_H12;      /*!< Specifies the RTC AM/PM Time.
                        This parameter can be a value of @ref RTC_AM_PM_Definitions */
}RTC_TimeTypeDef; 


/** 
  * @brief  RTC Date structure definition  
  */
typedef struct
{
  uint8_t RTC_WeekDay; /*!< Specifies the RTC Date WeekDay.
                        This parameter can be a value of @ref RTC_WeekDay_Definitions */
  
  uint8_t RTC_Month;   /*!< Specifies the RTC Date Month (in BCD format).
                        This parameter can be a value of @ref RTC_Month_Date_Definitions */

  uint8_t RTC_Date;     /*!< Specifies the RTC Date.
                        This parameter must be set to a value in the 1-31 range. */
  
  uint8_t RTC_Year;     /*!< Specifies the RTC Date Year.
                        This parameter must be set to a value in the 0-99 range. */
}RTC_DateTypeDef;

/** 
  * @brief  RTC Alarm structure definition  
  */
typedef struct
{
  RTC_TimeTypeDef RTC_AlarmTime;     /*!< Specifies the RTC Alarm Time members. */

  uint32_t RTC_AlarmMask;            /*!< Specifies the RTC Alarm Masks.
                                     This parameter can be a value of @ref RTC_AlarmMask_Definitions */

  uint32_t RTC_AlarmDateWeekDaySel;  /*!< Specifies the RTC Alarm is on Date or WeekDay.
                                     This parameter can be a value of @ref RTC_AlarmDateWeekDay_Definitions */
  
  uint8_t RTC_AlarmDateWeekDay;      /*!< Specifies the RTC Alarm Date/WeekDay.
                                     If the Alarm Date is selected, this parameter
                                     must be set to a value in the 1-31 range.
                                     If the Alarm WeekDay is selected, this 
                                     parameter can be a value of @ref RTC_WeekDay_Definitions */
}RTC_AlarmTypeDef;





void GregorianDay(struct rtc_time * tm);
uint32_t mktimev(struct rtc_time *tm);
void to_tm(uint32_t tim, struct rtc_time * tm);
void Time_Adjust(struct rtc_time *tm);
void RTC_Configuration(void);
void RTC_check(void);
void RTC_AlarmSet(void);

#endif
