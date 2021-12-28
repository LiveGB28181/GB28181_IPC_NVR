/**
* @file gb28181_main.c
* @author zhuguli
* @desc 
* GB28181 SDK测试demo
* 相关函数接口根据要求补充，license有时间限制
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <pthread.h>
#include <sched.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/prctl.h>

#if !defined(WIN32) && !defined(_WIN32_WCE) && !defined(__arc__)
#define _GNU_SOURCE
#include <getopt.h>
#endif


//#define GB28181_SDK_TEST    //测试宏

#ifdef GB28181_SDK_TEST

#include <system_default.h>
#include "sys_msg_drv.h"
#include <file_msg_drv.h>
#include <sys_env_type.h>
#include <sysctrl.h>
#include "para_list.h"
#include <rtspi.h>
#include <link.h>

struct commType g28181Comm;

#endif

#include "GB28181_API.h"

#define TMEP_BUFF 1024
static int g_run_status=1;
static int g_alarm_enable=0;
#define SIGN_BIT    (0x80)      /* Sign bit for a A-law byte. */  
#define QUANT_MASK  (0xf)       /* Quantization field mask.   */  
#define NSEGS       (8)         /* Number of A-law segments.  */  
#define SEG_SHIFT   (4)         /* Left shift for segment number. */  
#define SEG_MASK    (0x70)      /* Segment field mask. */ 


unsigned char ulaw2alaw(unsigned char  uval);

unsigned char _u2a[128] = { /* u- to A-law conversions */  
    1,  1,  2,  2,  3,  3,  4,  4,  
    5,  5,  6,  6,  7,  7,  8,  8,  
    9,  10, 11, 12, 13, 14, 15, 16,  
    17, 18, 19, 20, 21, 22, 23, 24,  
    25, 27, 29, 31, 33, 34, 35, 36,  
    37, 38, 39, 40, 41, 42, 43, 44,  
    46, 48, 49, 50, 51, 52, 53, 54,  
    55, 56, 57, 58, 59, 60, 61, 62,  
    64, 65, 66, 67, 68, 69, 70, 71,  
    72, 73, 74, 75, 76, 77, 78, 79,  
    81, 82, 83, 84, 85, 86, 87, 88,  
    89, 90, 91, 92, 93, 94, 95, 96,  
    97, 98, 99, 100,101,102,103,104,  
    105,106,107,108,109,110,111,112,  
    113,114,115,116,117,118,119,120,  
    121,122,123,124,125,126,127,128  
}; 

unsigned char _a2u[128] = { /* A- to u-law conversions */  
    1,  3,  5,  7,  9,  11, 13, 15,  
    16, 17, 18, 19, 20, 21, 22, 23,  
    24, 25, 26, 27, 28, 29, 30, 31,  
    32, 32, 33, 33, 34, 34, 35, 35,  
    36, 37, 38, 39, 40, 41, 42, 43,  
    44, 45, 46, 47, 48, 48, 49, 49,  
    50, 51, 52, 53, 54, 55, 56, 57,  
    58, 59, 60, 61, 62, 63, 64, 64,  
    65, 66, 67, 68, 69, 70, 71, 72,  
    73, 74, 75, 76, 77, 78, 79, 79,  
    80, 81, 82, 83, 84, 85, 86, 87,  
    88, 89, 90, 91, 92, 93, 94, 95,  
    96, 97, 98, 99, 100,101,102,103,  
    104,105,106,107,108,109,110,111,  
    112,113,114,115,116,117,118,119,  
    120,121,122,123,124,125,126,127  
};  
/* u-law to A-law conversion */  
unsigned char ulaw2alaw(unsigned char  uval)  
{  
    uval &= 0xff;  
    return ((uval & 0x80) ? (0xD5 ^ (_u2a[0xFF ^ uval] - 1)):  
           (0x55 ^ (_u2a[0x7F ^ uval] - 1)));  
}


/**
*@PTZ 控制处理
*@chan_id  通道号
*@ptzCmd   PTZ 控制命令
*@return GB_SUCCESS 成功，GB_FAILURE 失败。
*/
int gb28181_ctrl_ptz(int chan_id,GB28181_PTZCMD_T *ptzCmd)
{
    
    return GB_SUCCESS;
}


/**
*@brief PTZ控制看守卫
* enable:1开启0关闭
* reset_time:自动归位时间
* minInclusive:调用预置位编号最小值
* maxInclusive:调用预置位编号最大值
*@return GB_SUCCESS 成功，GB_FAILURE 失败。
*/
int gb28181_ctrl_home_position(int enable,int reset_time,int minInclusive,int maxInclusive)
{

    return GB_SUCCESS;
}


/**
*@brief 设置系统重启
*@return GB_SUCCESS 成功，GB_FAILURE 失败。
*/
int gb28181_set_sys_reboot(void)
{

    return GB_SUCCESS;
}

/**
* @brief 设置系统时间
* @param year  年
* @param month 月
* @param day   日
* @param hour  时
* @param min   分
* @param sec   秒
* @return  GB_SUCCESS 设置成功，GB_FAILURE 失败。           
*/
int gb28181_sys_set_date_time(int year, int month, int day, int hour, int min, int sec)
{
	

	return GB_SUCCESS;
}

/**
*@brief  获取系统的报警状态值
*@return 1  报警已触发,0  无报警
*/
int gb28181_get_alarm_value(void)
{

    return 0;

}

/**
*@brief  获取语音广播状态
*@param broadcast_id 语音广播的设备ID(需要赋值，长度必须小于24 bytes)
*@param status  0:有语音广播设备
                1: 无语音广播设备
*@return GB_SUCCESS 成功，GB_FAILURE 失败。
*/
int gb281281_get_broadcast_status(char *broadcast_id,int *status)
{

    
    return GB_SUCCESS;
}

/**
*@brief 获取预置位
*@param preset  预置位编码及名称
*@param len     预置位数最大值
*@return  预置位个数
*/
int gb28181_get_perset_value(gb28181_perset_param preset[GB_MAX_PERSET])
{

    return 2;
}

/**
*@brief  设置报警开关
*@param bEnable=1: 布防
        bEnable=0: 撤防
*@return GB_SUCCESS 成功，GB_FAILURE 失败。
*/
int gb28181_set_alarm_status(int bEnable)
{


    return 0;
}

/**
*@brief  设置报警复位
*
*@return GB_SUCCESS 成功，GB_FAILURE 失败。
*/
int gb28181_alarm_reset(void)
{


    return 0;
}

/**
*@brief  强制关键帧命令
*
*@return GB_SUCCESS 成功，GB_FAILURE 失败。
*/
int gb28181_send_key_frame(void)
{


    return 0;
}

/**
*@brief  设置移动设备数据上报间隔
*
*@return GB_SUCCESS 成功，GB_FAILURE 失败。
*/
int gb28181_mobile_position_value(int value)
{

#ifdef GB28181_SDK_TEST
   
#endif
    return 0;
}

int gb28181_record_cmd(int cmd,const char *device_id)
{
    return 0;
}

int test_send_record_info(void)
{
    int ret=0,i=0;
    GB28181_RECORD_INFO_LIST_T recordinfo_list;
    strcpy(recordinfo_list.cameraIndexCode,"34020000001320000001");
    recordinfo_list.recordInfoNumber = 10;
    recordinfo_list.sn = 300;
    recordinfo_list.recordInfoList = (GB28181_RECORD_INFO_T *)malloc(sizeof(GB28181_RECORD_INFO_T)*10); 
    if(recordinfo_list.recordInfoList == NULL)
        return -1;
    for(i=0;i<10;i++)
    {
        strcpy(recordinfo_list.recordInfoList[i].cameraIndexCode,"34020000001320000001");
    }
    gb28181_send_record_info(&recordinfo_list);
    free(recordinfo_list.recordInfoList);
    return 0;
}


int gb28181_get_record_info(const char *device_id,int SN,GB28181_RECORD_TIME_T *startTime,
                     GB28181_RECORD_TIME_T *endTime,RECORD_INFO_TYPE_ENUM recordType)
{
    
    
    return 0;
}


int gb28181_playback_control(int channel,long start_time, long end_time,GB28181_STREAM_CONTROL_T *stream_ctrl)
{

    return 0;
}

int gb28181_download_control(int channel,const char *call_id,long start_time, long end_time,int download_speed)
{


    return 0;
}


//推送音视频帧到国标库
void *send_real_stream(void *param)
{

    //TODO 从系统获取的音视频帧数据再调用gb28181_push_frame接口进行推流
	printf("========pthread send_real_stream exit =========\n");
	pthread_exit(NULL);
	
 }

void exit_cleanly(void)
{
    int ret;
    printf("======exit cleanly=======\n");
    gb28181_shutdown();
    g_run_status = 0;
    sleep(2);
    exit(0);
}


/**

**/
int main(int argc, char *argv[])
{

	int ret=0,i=0;
	
	pthread_t send_frame_pthread;
	
    
	signal(SIGTERM, exit_cleanly);
    signal(SIGINT, exit_cleanly);
    signal(SIGQUIT, exit_cleanly); 
    
    gb28181_system_param system_param;
 
    //参数需要按要求填写
    printf("sipserver_ip:%s \n",system_param.sipserver_ip);
	printf("sipserver_region:%s \n",system_param.sipserver_region);
	printf("sipserver_id:%s \n",system_param.sipserver_id);
	printf("sipserver_port:%d \n",system_param.sipserver_port);
	printf("deadline:%d \n",system_param.deadline);
	printf("sip_localport:%d \n",system_param.sip_localport);
	printf("sip_transport:%d \n",system_param.sip_transport);
	printf("heartbeatInterval:%d \n",system_param.heartbeatInterval);
    printf("heartbeat_timeout:%d \n",system_param.heartbeat_timeout);

    printf("sipdevice_broadcast_id:%s \n",system_param.sipdevice_broadcast_id);
	printf("sip_device_reg_id:%s \n",system_param.sip_device_reg_id);
	for(i=0;i<GB_CAMERA_MAX;i++){
	    if(strlen(system_param.sipdevice_channel_id[i].channel_id) > 0){
            printf("channel %d id:%s \n",i+1,system_param.sipdevice_channel_id[i].channel_id);
	    }
        
	}
	printf("sipdevice_ipc_password:%s \n",system_param.sipdevice_ipc_password);
	printf("local_ip:%s \n",system_param.local_ip);
	printf("device_model:%s \n",system_param.device_model);
	printf("device_version:%s \n",system_param.device_version);
	printf("device_version:%s \n",system_param.device_manufacturer);
    printf("device_name:%s \n",system_param.device_name);
	printf("-------------start gb281281 sip process---------------\n");
    gb28181_startup(&system_param,NULL,NULL);
    if(pthread_create(&send_frame_pthread,NULL,send_real_stream,NULL) < 0){
        perror("error send_real_stream: ");
        return -1;
    }
    
    while(g_run_status){
        
        sleep(1);
    }
    return 0;

}

