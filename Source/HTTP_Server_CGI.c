/*------------------------------------------------------------------------------
 * MDK Middleware - Component ::Network:Service
 * Copyright (c) 2004-2014 ARM Germany GmbH. All rights reserved.
 *------------------------------------------------------------------------------
 * Name:    HTTP_Server_CGI.c
 * Purpose: HTTP Server CGI Module
 * Rev.:    V6.00
 *----------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rl_net.h"
#include "rl_net_lib.h"
#include "LED_Display.h"
#include "rtc.h"
#include "water.h"

// net_sys.c
extern  NET_LOCALM net_localm[];
#define LocM   net_localm[NETIF_ETH]

// Net_Config.c
extern struct net_tcp_cfg   net_tcp_config;
extern struct net_http_cfg  net_http_config;
#define tcp_NumSocks    net_tcp_config.NumSocks
#define tcp_socket      net_tcp_config.Scb
#define http_EnAuth     net_http_config.EnAuth
#define http_auth_passw net_http_config.Passw

#define buf_len 20     

extern struct_time water_time;
extern struct rtc_time system_time;
extern uint8_t water_last_second;    //����ʱ������Ϊ��λ


// My structure of CGI status variable.
typedef struct {
  uint16_t xcnt;
  uint16_t unused;
} MY_BUF;
#define MYBUF(p)        ((MY_BUF *)p)



//����ʾ������������浽�ⲿ���棬��ַ0-499
//��ַ�������Doc/extern_flash_address.txt
void save_display_para_to_flash(void){

	uint8_t buff[4];
	//������ַ0��ʼ��4K�洢����
	SPI_FLASH_SectorErase(4096);

	//������Ļ����
	buff[0]=water_time.hour;
	buff[1]=water_time.minute;
	buff[2]=water_time.second;
	buff[3]=water_last_second;
  SPI_FLASH_BufferWrite(buff, 4096, 4);
	water_stop();
}

// Process query string received by GET request.
void netCGI_ProcessQuery (const char *qstr) {
  char var[40];
	/*ʱ��ṹ��*/
	struct rtc_time real_time;
	//printf("cgi_process. qstr:%s\n",qstr);
  do {
    // Loop through all the parameters
    qstr = netCGI_GetEnvVar (qstr, var, sizeof (var));
    // Check return string, 'qstr' now points to the next parameter
    //printf("var[]:%s\n",var);
		if (var[0] != 0) {
      // First character is non-null, string exists
			if (strncmp (var, "alarmHour=", 10) == 0) {
        // ����:Сʱ
				water_time.hour=atoi(&var[10]);
      }
      else if (strncmp (var, "alarmMin=", 9) == 0) {
        // ���ӣ�����
				water_time.minute=atoi(&var[9]);
      }
      else if (strncmp (var, "alarmSec=", 9) == 0) {
        // ���ӣ���
				water_time.second=atoi(&var[9]);
      }
      else if (strncmp (var, "water=", 6) == 0) {
        // ����ʱ������Ϊ��λ
				water_last_second=atoi(&var[6]);
				save_display_para_to_flash();
      }
			else if (strncmp (var, "strDate=", 8) == 0) {
				//ϵͳУʱ����ҳ��������ʱ���ʽ��yyyy-mm-dd-ww-hh-mm-ss
				
				real_time.rt_year=atoi(strtok( var+8, "-" ));
				real_time.rt_mon=atoi(strtok( NULL,"-" ))+1;
				real_time.rt_date=atoi(strtok( NULL,"-" ));
				real_time.rt_day=atoi(strtok( NULL,"-" ));
				real_time.rt_hour=atoi(strtok( NULL,"-" ));
				real_time.rt_min=atoi(strtok( NULL,"-" ));
				real_time.rt_sec=atoi(strtok( NULL,"-" ));
				Time_Adjust(&real_time);    //Уʱ
			}
    }
  } while (qstr);
}

// Process data received by POST request.
// Type code: - 0 = www-url-encoded form data.
//            - 1 = filename for file upload (null-terminated string).
//            - 2 = file upload raw data.
//            - 3 = end of file upload (file close requested).
//            - 4 = any XML encoded POST data (single or last stream).
//            - 5 = the same as 4, but with more XML data to follow.
void netCGI_ProcessData (uint8_t code, const char *data, uint32_t len) {
  char var[40],passw[12];
	//printf("Process data received by Post request.\n Type code:%d\n Post data:%s\n Post len:%d\n",code,data,len);
  if (code != 0) {
    // Ignore all other codes
    return;
  }

  if (len == 0) {
    // No data or all items (radio, checkbox) are off
    return;
  }
  passw[0] = 1;
  do {
    // Parse all parameters
    data = netCGI_GetEnvVar (data, var, sizeof (var));
    if (var[0] != 0) {
      // First character is non-null, string exists
      if (strncmp (var, "txt=",4) == 0) {
        //������ʾ����
      }
			else if (strncmp (var, "auth=true", 9) == 0) {
				//�������֤
				//http_EnAuth=true;
				netHTTPs_LoginOnOff (true);
				save_display_para_to_flash();
			}
			else if (strncmp (var, "auth=false", 10) == 0) {
				//�ر������֤
				netHTTPs_LoginOnOff (false);
				save_display_para_to_flash();
			}
      else if ((strncmp (var, "pw0=", 4) == 0) ||
               (strncmp (var, "pw2=", 4) == 0)) {
        // �޸�����
        if (http_EnAuth) {
          if (passw[0] == 1) {
            strcpy (passw, var+4);
          }
          else if (strcmp (passw, var+4) == 0) {
            // ���������������ͬ
            strcpy (http_auth_passw, passw);
						save_display_para_to_flash();
          }
        }
      }
    }
  } while (data);
}

// Generate dynamic web data from a script line.
uint32_t netCGI_Script (const char *env, char *buf, uint32_t buflen, uint32_t *pcgi) {
  uint32_t len = 0;
	char sys_time[30];
	//printf("Generate dynamic web. \n");
	//printf("env=%s\n",env);
	
  switch (env[0]) {
    // Analyze a 'c' script line starting position 2
    case 'a' :
      // ��ʾ���༭ 'areaEdit.cgi'
    case 'c':
      //���ݹ���


    case 'd':
      //��¼���á��޸����� 'auth.cgi, password.cgi'
      switch (env[2]) {
        case '1':
          len = sprintf (buf, &env[4], http_EnAuth ? "Enabled" : "Disabled");
          break;
        case '2':
          len = sprintf (buf, &env[4], http_auth_passw);
          break;
      }
      break;
			

    case 'l':
      // ��¼���ã��Ƿ����������֤ 'auth.cgi'
			switch(env[2]){
				case '1':
					if (netHTTPs_LoginActive() == true) 
						len = sprintf(buf, &env[4],"checked=checked");
					else
						len = sprintf(buf, &env[4],"");
					break;
				
				case '2':
					if (netHTTPs_LoginActive() == true) 
						len = sprintf(buf, &env[4],"");
					else
						len = sprintf(buf, &env[4],"checked=checked");
					break;
			}
			break;


    case 's':
      //��Ļ����
      switch (env[2]) {
        case 't':    //ϵͳ��ǰ���ڡ�ʱ��
					to_tm(RTC_GetCounter() + 8*60*60, &system_time);/*�Ѷ�ʱ����ֵת��Ϊ����ʱ��*/
					sprintf(sys_time,"%4d-%2d-%2d %d:%d:%d",system_time.rt_year,system_time.rt_mon,
				                    system_time.rt_date,system_time.rt_hour,system_time.rt_min,system_time.rt_sec);
					len = sprintf (buf, &env[4], sys_time);
          break;
				
        case 'h':    //���ӣ�Сʱ
          len = sprintf (buf, &env[4], water_time.hour);
          break;
				
        case 'm':    //���ӣ�����
          len = sprintf (buf, &env[4], water_time.minute);
          break;
        case 's':   //���ӣ���
          len = sprintf (buf, &env[4], water_time.second);
          break;
        case 'w':   //����ʱ��
          len = sprintf (buf, &env[4], water_last_second);
          break;
      }
      break;

  }

  return (len);
}
