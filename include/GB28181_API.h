/**
* @file GB28181_API.h
* @author zhuguli
* @desc   
* 1��������GB28181����нӿ�ʵ�ֵ���غ����ӿڼ��ṹ�嶨��
* 2�����µ�SDK�汾�ǻ���GB/T-28181 2016�汾�з�
* 3��֧��IPC��NVR�ļ���ʹ��
* 4��SDK��֧�����ã�����Ż������Ȩ����ʹ��
*/
#ifndef __GB28181_API_H
#define __GB28181_API_H

//#define GB28181_SDK_TEST    /**< SDK ���Ժ궨�� */
#define GB_MAX_PERSET  512    /**< ���Ԥ�õ���� */
#define GB_SUCCESS     0      /**< return successful */
#define GB_FAILURE     -1     /**< return failure */

#define GB_FMT_MAX_NUM  4

#define GB_CAMERA_MAX   32
#define GB_STR_LEN_32   32
#define GB_STR_LEN_64   64
#define GB_STR_LEN_128  128
#define GB_STR_LEN_256  256

#define GB_CHAN_STREAM_MAX (GB_CAMERA_MAX+2) //��ͨ����0��ʼ��0-31ʵʱͨ��,32�ط�ͨ��,33����ͨ��
#define GB_PLAYBACK_CHAN 32
#define GB_DOWNLOAD_CHAN 33

typedef struct{

    char channel_id[GB_STR_LEN_32];    	
}camera_param_t;

typedef struct __gb28181_system_param{
 
	char sipserver_id[GB_STR_LEN_32];                 /**< SIP����������ID�� */
	char sipserver_region[GB_STR_LEN_32];             /**< ������SIP����� */
	char sipserver_ip[GB_STR_LEN_32];                 /**< SIP������IP��ַ */
	int  sipserver_port;                              /**< SIP�������˿� */
	char sip_device_reg_id[GB_STR_LEN_32];            /**< �豸SIP��ע��ID */
	camera_param_t sipdevice_channel_id[GB_CAMERA_MAX];  /**< �豸��ص�ID */
	char sipdevice_broadcast_id[GB_STR_LEN_32];       /**< �豸�������ID */   
	char sipdevice_ipc_password[GB_STR_LEN_32];       /**< �豸SIPͨѶ��Կ */
	//char sipdevice_ipc_alarm_id[GB_STR_LEN_32];     /**< �豸����������ID */
 	int  heartbeatInterval;                           /**< SIP�������(��λ:��) */
 	int  deadline;                                    /**< SIPע�����ʱ��(��λ:��) */
 	int  sip_localport;                               /**< SIP ���ض˿�*/
 	int  sip_transport;                               /**< SIPͨѶ����Э��(0��ʾUDP��1��ʾTCP) */
 	int  heartbeat_timeout;                           /**< ������ʱ���������ڴ�������Է���Ϊ���ߣ�Ĭ��Ϊ3 */
 	char local_ip[GB_STR_LEN_32];	                  /**< �豸��IP��ַ */
    char device_model[GB_STR_LEN_32];                 /**< �豸���ͺ� */
	char device_version[GB_STR_LEN_64];               /**< �豸�İ汾�� */
	char device_manufacturer[GB_STR_LEN_64];          /**< �豸���������� */
	char device_name[GB_STR_LEN_128];                 /**<�豸����>*/

	//����Ŀ¼�ֶ�(��������Ҫ����ַ���)
	int enable;//�Զ������ʹ�ܣ�0�����ã�1����
	char catalog_Block[GB_STR_LEN_32]; //
	char catalog_Longitude[GB_STR_LEN_32]; //
	char catalog_Latitude[GB_STR_LEN_32]; //
	char catalog_PTZType[GB_STR_LEN_32];//
}gb28181_system_param;

typedef enum __GB28181_PTZCMD_CONTROL_T
{
	GB28181_PTZ_PAN_LEFT = 1,    //��̨ˮƽ����
	GB28181_PTZ_PAN_RIGHT,       //��̨ˮƽ����
	GB28181_PTZ_TILT_UP,         //��̨��ֱ����
	GB28181_PTZ_TILT_DOWN,       //��̨��ֱ����
	GB28181_PTZ_LEFT_UP,         //��̨�����˶�
	GB28181_PTZ_LEFT_DOWN,       //��̨�����˶�
	GB28181_PTZ_RIGHT_UP,        //��̨�����˶�
	GB28181_PTZ_RIGHT_DOWN,      //��̨�����˶�

	GB28181_PTZ_ZOOM_OUT,		 //��ͷ�䱶��С
	GB28181_PTZ_ZOOM_IN,         //��ͷ�䱶�Ŵ�

	GB28181_PTZ_FOCUS_NEAR,      //�۽�����
	GB28181_PTZ_FOCUS_FAR,       //�۽���Զ

	GB28181_PTZ_IRIS_OUT,        //��Ȧ��С
	GB28181_PTZ_IRIS_IN,         //��Ȧ�Ŵ�

	GB28181_PTZ_CREAT_PRESET,    //����Ԥ�õ�
	GB28181_PTZ_CALL_PRESET,     //����Ԥ�õ�
	GB28181_PTZ_DELETE_PRESET,   //ɾ��Ԥ�õ�

	//Ѳ��
	GB28181_PTZ_GET_CRUISE_GROUP,     //��ȡѲ����
	GB28181_PTZ_SET_CRUISE_GROUP,     //����Ѳ����
	GB28181_PTZ_DELETE_CRUISE_GROUP,  //ɾ��Ѳ����
	GB28181_PTZ_START_CRUISE,         //��ʼѲ��

	//3D�Ŵ�
	GB28181_PTZ_SEL_ZOOM_IN,          //��̨3D�Ŵ�

	//�Զ�ɨ��
	GB28181_PTZ_START_AUTO_SCAN,      //��ʼ�Զ�ɨ��
	GB28181_PTZ_SET_AUTO_SCAN_LEFT,   //�����Զ�ɨ����߽�
	GB28181_PTZ_SET_AUTO_SCAN_RIGHT,  //�����Զ�ɨ���ұ߽�
	GB28181_PTZ_AUTO_SCAN_SPEED,      //�����Զ�ɨ���ٶ�

	GB28181_PTZ_WIPER_ON,            //��ˢ��
	GB28181_PTZ_WIPER_OFF,           //��ˢ��

	GB28181_PTZ_LIGHT_PWRON_ON,      //�ƹ⿪
	GB28181_PTZ_LIGHT_PWRON_OFF,     //�ƹ��

	GB28181_PTZ_PANTILT_STOP,  //PTZ  ��ֹ̨ͣ����/�켣ֹͣ
	GB28181_PTZ_ZOOM_STOP,     //PTZ  ��ͷ�䱶ֹͣ
	GB28181_PTZ_FOCUS_STOP,    //PTZ  �۽�ֹͣ
	GB28181_PTZ_IRIS_STOP,     //PTZ  ��Ȧֹͣ
	GB28181_PTZ_CRUISE_STOP,   //PTZ  ֹͣѲ��

}GB28181_PTZCMD_CONTROL_T;//3D��̨�Ŵ�����ṹ

typedef struct __ZOOM_POINT_T
{
	int xTop;     //������ʼ���x���� 
	int yTop;     //������ʼ���y����
	int xBottom;  //����������x����
	int yBottom;  //����������y����
	int bCounter; //����
}ZOOM_POINT_T;

/*PTZ���Ʋ���*/
typedef struct __GB28181_PTZCMD_T
{
	GB28181_PTZCMD_CONTROL_T PtzCmd;      //PTZ��������
	unsigned char        speed;           //�ٶ�ֵ
	unsigned int         ptz_preset_num;  //Ԥ��λ���  

	unsigned int         display_width;   //��Ƶ��ʾ���
	unsigned int         display_high;    //��Ƶ��ʾ�߶�
	ZOOM_POINT_T         ptz_sel_zoom_point; //3D�Ŵ����������

}GB28181_PTZCMD_T;

/* ����Ƶ֡��ʶ */
#define GB28181_SDK_VIDEO_FRAME_FLAG	0x00000001		/* ��Ƶ֡��־ */
#define GB28181_SDK_AUDIO_FRAME_FLAG	0x00000002		/* ��Ƶ֡��־ */
#define GB28181_SDK_EVENT_FRAME_FLAG	0x00000004		/* �¼�֡��־ */
#define GB28181_SDK_RTP_FRAME_FLAG		0x00000008		/* RTP֡��־ */
#define GB28181_SDK_SDP_FRAME_FLAG		0x00000010		/* SDP֡��־ */
#define GB28181_SDK_MEDIA_INFO_FLAG 	0x00000020		/* ý�����ͱ�־*/

/* ��Ƶ�ؼ��ֱ�ʶ */
#define GB28181_SDK_VIDEO_FRAME_I		0x01		/* I֡ */
#define GB28181_SDK_VIDEO_FRAME_P		0x02		/* P֡ */
#define GB28181_SDK_VIDEO_FRAME_B		0x03		/* B֡ */
#define GB28181_SDK_VIDEO_FRAME_J		0x04		/* JPEG */


typedef struct __GB28181_AV_FRAME
{
    unsigned int    u32AVFrameFlag;		/* ֡��־  ��Ƶ or ��Ƶ */
    unsigned int    u32AVFrameLen;		/* ֡�ĳ��� */
    unsigned int    u32VFrameType;		/* ��Ƶ�����ͣ�I֡��P֡ */
    unsigned char   *pBuffer;			/* ���� */
	unsigned long 	u64Timestamp;	    /* ʱ���(����)*/
	
}GB28181_AV_FRAME;


typedef struct {
    char preset_id[24];    /**<  Ԥ��λ���� */
	char preset_name[24];  /**<  Ԥ��λ���� */
}gb28181_perset_param;


//----------------------------------------------------------------------------------------
typedef enum __STREAM_SPEED_CONTROL_ENUM
{
	STREAM_SPEED_CONTROL_UNKOWN = 0,
    STREAM_SPEED_CONTROL_SLOW_8,   //����8����
	STREAM_SPEED_CONTROL_SLOW_4,   //����4����
	STREAM_SPEED_CONTROL_SLOW_2,   //����2����
	STREAM_SPEED_CONTROL_PLAY_X1,  //��������1����
	STREAM_SPEED_CONTROL_PLAY_X2,  //���2����
    STREAM_SPEED_CONTROL_PLAY_X4,  //���4����
	STREAM_SPEED_CONTROL_PLAY_X8   //���8����
}STREAM_SPEED_CONTROL_ENUM;

typedef enum __STREAM_CONTROL_ENUM
{
	STREAM_CONTROL_UNKOWN = 0,
	STREAM_CONTROL_PLAY,            //����
    STREAM_CONTROL_PAUSE,           //��ͣ
    STREAM_CONTROL_SPEED,           //���/����
    STREAM_CONTROL_NPT,             //����Ϸ�
    STREAM_CONTROL_TEARDOWN         //ֹͣ
}STREAM_CONTROL_ENUM;

typedef struct __GB28181_STREAM_CONTROL_T
{

    char sip_call_id[GB_STR_LEN_256];       //SIP call id  �����ر���
	STREAM_CONTROL_ENUM streamControl;      //��������
	STREAM_SPEED_CONTROL_ENUM speedControl; //�ٶ�ֵ
	int npt_start;                          //�Ϸſ�ʼʱ�䣨�룩
}GB28181_STREAM_CONTROL_T;

typedef struct __GB28181_RECORD_TIME_T
{
	int year;
	int month;
	int day;
	int hour;
	int min;
	int sec;

}GB28181_RECORD_TIME_T;

typedef enum __RECORD_INFO_TYPE_ENUM
{
	RECORD_INFO_TYPE_TIME = 0, //������¼������
	RECORD_INFO_TYPE_ALARM,   //����������
	RECORD_INFO_TYPE_MANUAL,  //���ֶ�¼������
	RECORD_INFO_TYPE_ALL      //��ѯ����¼��
}RECORD_INFO_TYPE_ENUM;

typedef enum __RECORD_CMD_TYPE_ENUM
{
	RECORD_CMD_TYPE_RECORD = 0, //��ʼ¼��
	RECORD_CMD_TYPE_STOP_RECORD, //ֹͣ¼��
}RECORD_CMD_TYPE_ENUM;

typedef struct __GB28181_RECORD_INFO_T
{
	char cameraIndexCode[32];
	char Name[64];
	char FilePath[32];
	char StartTime[32];
	char EndTime[32];
	int  Secrecy;
	char Type[16];
}GB28181_RECORD_INFO_T;

typedef struct __GB28181_RECORD_INFO_LIST_T
{
	
	int sn;                    //���к�
	int recordInfoNumber;      //�ļ�����
	char cameraIndexCode[32];  //��ص����
	int cur_number;            //����
	GB28181_RECORD_INFO_T *recordInfoList; //�ļ��б�
}GB28181_RECORD_INFO_LIST_T;

//-----------------------------------------------------------------------------------

/****************       ���ڲ��ṩ�Ľӿں��� ***********************/

/**
*@brief ����GB28181 SIP������
*@param param ϵͳ���������ں�����SIP����
*@warning ��Ҫ��֤������׼ȷ�ԣ������޷���������SIP����ͨѶ
*/
int gb28181_startup(gb28181_system_param *sys_param,const char *log_dir,const char *log_name); 

/**
*@brief ֹͣGB28181 SIP������
*
*/
int gb28181_shutdown(void);

/**
*@brief ��������Ƶ֡����
*
*/
int gb28181_push_frame(int channelId, GB28181_AV_FRAME *frame );


/**
*@brief ��ȡע��״̬
*@return 1:ע��ɹ�(����)0:ע��ʧ��(����)
*/
int gb28181_get_register_status(void);

/**
*@brief ��ƽ̨���ͱ�����Ϣ  
*@param device_id �豸ID
*@param alarm_priority ��������(1,2,3,4)
*@param alarm_method ������ʽ
 1 �绰������ 2 �豸������ 
 3 ���ű����� 4 GPSGPS ������ 5 ��Ƶ������ 
 6 �豸���ϱ����� 7 ��������
*@return GB_SUCCESS ���óɹ���GB_FAILURE ʧ�ܡ�
*/
int gb28181_send_alarm_info(const char *device_id,int alarm_priority,int alarm_method);


int gb28181_send_record_info(GB28181_RECORD_INFO_LIST_T *record_info_list);

/***************        SDK��ϵͳ��أ��û���ʵ�ֵĺ��� *******************/
/**
*@brief  ���ñ�������
*@param bEnable=1: ����
        bEnable=0: ����
*@return GB_SUCCESS �ɹ���GB_FAILURE ʧ�ܡ�
*/
int gb28181_set_alarm_status(int set_value);


/**
*@brief ��ȡԤ��λ
*@param perset  Ԥ��λ���뼰����
*@param max_perset     Ԥ��λ�����ֵ
*@return  Ԥ��λ����
*/
int gb28181_get_perset_value(gb28181_perset_param perset[GB_MAX_PERSET]);

/**
*@PTZ ���ƴ���
*@chan_id  ͨ����
*@ptzCmd   PTZ ��������
*@return GB_SUCCESS �ɹ���GB_FAILURE ʧ�ܡ�
*/
int gb28181_ctrl_ptz(int chan_id,GB28181_PTZCMD_T *ptzCmd);


/**
*@brief ����ϵͳ����
*@return GB_SUCCESS �ɹ���GB_FAILURE ʧ�ܡ�
*/
int gb28181_set_sys_reboot(void);

/**
* @brief ����ϵͳʱ��
* @param year  ��
* @param month ��
* @param day   ��
* @param hour  ʱ
* @param min   ��
* @param sec   ��
* @return  GB_SUCCESS ���óɹ���GB_FAILURE ʧ�ܡ�           
*/
int gb28181_sys_set_date_time(int year, int month, int day, int hour, int min, int sec);


/*
* @brief   �����ֶ�¼������
* @param   cmd:1��ʼ�ֶ�¼��,0ֹͣ�ֶ�¼��
* @param   device_id:��ص����
* @return  GB_SUCCESS ���óɹ���GB_FAILURE ʧ�ܡ�
*/
int gb28181_record_cmd(int cmd,const char *device_id);

/*
* ��������,Ӧ��������
* @brief   ��ѯ¼���ļ���Ϣ
* @param   device_id ��ѯID����
* @param   device_id ����SN(�첽�ظ�ʱ����Ҫ)
* @param   startTime ��ʼʱ��
* @param   endTime ����ʱ��
* @param   recordType ¼������
* @return  GB_SUCCESS ���óɹ���GB_FAILURE ʧ�ܡ�
*/
int gb28181_get_record_info(const char *device_id,int SN,GB28181_RECORD_TIME_T *startTime,
                     GB28181_RECORD_TIME_T *endTime,RECORD_INFO_TYPE_ENUM recordType);

/*
��������,Ӧ��������

* @brief   �ط�������,�����߳���ط�ͨ��32 ����
* @param   chanel:��ص�ͨ��
* @param   start_time:��ʼʱ��  
* @param   end_time:����ʱ��
* @param   stream_ctrl:�ط�������
* @return  GB_SUCCESS ���óɹ���GB_FAILURE ʧ�ܡ�
*/

int gb28181_playback_control(int channel,long start_time, long end_time,GB28181_STREAM_CONTROL_T *stream_ctrl);


/*
��������,Ӧ��������

* @brief   ����������,�����߳���ط�ͨ��33 ����
* @param   chanel:��ص�ͨ��
* @param   call_id: ���ỰID
* @param   start_time:��ʼʱ��  
* @param   end_time:����ʱ��
* @param   download_speed:�����ٶȱ���(ֵ����-1����ֹͣ)
* @return  GB_SUCCESS ���óɹ���GB_FAILURE ʧ�ܡ�
*/
int gb28181_download_control(int channel,const char *call_id,long start_time, long end_time,int download_speed);

/*
* @brief   ֹͣ���ͻط�������������
* @param   call_id: ���ỰID
* @return  GB_SUCCESS ���óɹ���GB_FAILURE ʧ�ܡ�
*/
int gb28181_stop_send_stream(const char *call_id);


/***************         end             ***********************/
#endif
