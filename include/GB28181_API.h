/**
* @file GB28181_API.h
* @author zhuguli
* @desc   
* 1、用于与GB28181库进行接口实现的相关函数接口及结构体定义
* 2、最新的SDK版本是基于GB/T-28181 2016版本研发
* 3、支持IPC或NVR的集成使用
* 4、SDK仅支持试用，购买才会进行授权永久使用
*/
#ifndef __GB28181_API_H
#define __GB28181_API_H

//#define GB28181_SDK_TEST    /**< SDK 测试宏定义 */
#define GB_MAX_PERSET  512    /**< 最大预置点个数 */
#define GB_SUCCESS     0      /**< return successful */
#define GB_FAILURE     -1     /**< return failure */

#define GB_FMT_MAX_NUM  4

#define GB_CAMERA_MAX   32
#define GB_STR_LEN_32   32
#define GB_STR_LEN_64   64
#define GB_STR_LEN_128  128
#define GB_STR_LEN_256  256

#define GB_CHAN_STREAM_MAX (GB_CAMERA_MAX+2) //流通道从0开始，0-31实时通道,32回放通道,33下载通道
#define GB_PLAYBACK_CHAN 32
#define GB_DOWNLOAD_CHAN 33

typedef struct{

    char channel_id[GB_STR_LEN_32];    	
}camera_param_t;

typedef struct __gb28181_system_param{
 
	char sipserver_id[GB_STR_LEN_32];                 /**< SIP服务器编码ID号 */
	char sipserver_region[GB_STR_LEN_32];             /**< 服务器SIP域编码 */
	char sipserver_ip[GB_STR_LEN_32];                 /**< SIP服务器IP地址 */
	int  sipserver_port;                              /**< SIP服务器端口 */
	char sip_device_reg_id[GB_STR_LEN_32];            /**< 设备SIP的注册ID */
	camera_param_t sipdevice_channel_id[GB_CAMERA_MAX];  /**< 设备监控点ID */
	char sipdevice_broadcast_id[GB_STR_LEN_32];       /**< 设备语音输出ID */   
	char sipdevice_ipc_password[GB_STR_LEN_32];       /**< 设备SIP通讯密钥 */
	//char sipdevice_ipc_alarm_id[GB_STR_LEN_32];     /**< 设备自身报警编码ID */
 	int  heartbeatInterval;                           /**< SIP心跳间隔(单位:秒) */
 	int  deadline;                                    /**< SIP注册过期时间(单位:秒) */
 	int  sip_localport;                               /**< SIP 本地端口*/
 	int  sip_transport;                               /**< SIP通讯传输协议(0表示UDP，1表示TCP) */
 	int  heartbeat_timeout;                           /**< 心跳超时次数，大于此数将会对方认为掉线；默认为3 */
 	char local_ip[GB_STR_LEN_32];	                  /**< 设备的IP地址 */
    char device_model[GB_STR_LEN_32];                 /**< 设备的型号 */
	char device_version[GB_STR_LEN_64];               /**< 设备的版本号 */
	char device_manufacturer[GB_STR_LEN_64];          /**< 设备的生产厂家 */
	char device_name[GB_STR_LEN_128];                 /**<设备名称>*/

	//新增目录字段(参数都需要变成字符串)
	int enable;//自定义参数使能，0不启用，1启用
	char catalog_Block[GB_STR_LEN_32]; //
	char catalog_Longitude[GB_STR_LEN_32]; //
	char catalog_Latitude[GB_STR_LEN_32]; //
	char catalog_PTZType[GB_STR_LEN_32];//
}gb28181_system_param;

typedef enum __GB28181_PTZCMD_CONTROL_T
{
	GB28181_PTZ_PAN_LEFT = 1,    //云台水平向左
	GB28181_PTZ_PAN_RIGHT,       //云台水平向右
	GB28181_PTZ_TILT_UP,         //云台垂直向上
	GB28181_PTZ_TILT_DOWN,       //云台垂直向下
	GB28181_PTZ_LEFT_UP,         //云台左上运动
	GB28181_PTZ_LEFT_DOWN,       //云台左下运动
	GB28181_PTZ_RIGHT_UP,        //云台右上运动
	GB28181_PTZ_RIGHT_DOWN,      //云台右下运动

	GB28181_PTZ_ZOOM_OUT,		 //镜头变倍缩小
	GB28181_PTZ_ZOOM_IN,         //镜头变倍放大

	GB28181_PTZ_FOCUS_NEAR,      //聚焦拉近
	GB28181_PTZ_FOCUS_FAR,       //聚焦拉远

	GB28181_PTZ_IRIS_OUT,        //光圈缩小
	GB28181_PTZ_IRIS_IN,         //光圈放大

	GB28181_PTZ_CREAT_PRESET,    //设置预置点
	GB28181_PTZ_CALL_PRESET,     //调用预置点
	GB28181_PTZ_DELETE_PRESET,   //删除预置点

	//巡航
	GB28181_PTZ_GET_CRUISE_GROUP,     //获取巡航组
	GB28181_PTZ_SET_CRUISE_GROUP,     //设置巡航组
	GB28181_PTZ_DELETE_CRUISE_GROUP,  //删除巡航组
	GB28181_PTZ_START_CRUISE,         //开始巡航

	//3D放大
	GB28181_PTZ_SEL_ZOOM_IN,          //云台3D放大

	//自动扫描
	GB28181_PTZ_START_AUTO_SCAN,      //开始自动扫描
	GB28181_PTZ_SET_AUTO_SCAN_LEFT,   //设置自动扫描左边界
	GB28181_PTZ_SET_AUTO_SCAN_RIGHT,  //设置自动扫描右边界
	GB28181_PTZ_AUTO_SCAN_SPEED,      //设置自动扫描速度

	GB28181_PTZ_WIPER_ON,            //雨刷开
	GB28181_PTZ_WIPER_OFF,           //雨刷关

	GB28181_PTZ_LIGHT_PWRON_ON,      //灯光开
	GB28181_PTZ_LIGHT_PWRON_OFF,     //灯光关

	GB28181_PTZ_PANTILT_STOP,  //PTZ  云台停止操作/轨迹停止
	GB28181_PTZ_ZOOM_STOP,     //PTZ  镜头变倍停止
	GB28181_PTZ_FOCUS_STOP,    //PTZ  聚焦停止
	GB28181_PTZ_IRIS_STOP,     //PTZ  光圈停止
	GB28181_PTZ_CRUISE_STOP,   //PTZ  停止巡航

}GB28181_PTZCMD_CONTROL_T;//3D云台放大参数结构

typedef struct __ZOOM_POINT_T
{
	int xTop;     //方框起始点的x坐标 
	int yTop;     //方框起始点的y坐标
	int xBottom;  //方框结束点的x坐标
	int yBottom;  //方框结束点的y坐标
	int bCounter; //保留
}ZOOM_POINT_T;

/*PTZ控制参数*/
typedef struct __GB28181_PTZCMD_T
{
	GB28181_PTZCMD_CONTROL_T PtzCmd;      //PTZ操作命令
	unsigned char        speed;           //速度值
	unsigned int         ptz_preset_num;  //预置位编号  

	unsigned int         display_width;   //视频显示宽度
	unsigned int         display_high;    //视频显示高度
	ZOOM_POINT_T         ptz_sel_zoom_point; //3D放大的像素坐标

}GB28181_PTZCMD_T;

/* 音视频帧标识 */
#define GB28181_SDK_VIDEO_FRAME_FLAG	0x00000001		/* 视频帧标志 */
#define GB28181_SDK_AUDIO_FRAME_FLAG	0x00000002		/* 音频帧标志 */
#define GB28181_SDK_EVENT_FRAME_FLAG	0x00000004		/* 事件帧标志 */
#define GB28181_SDK_RTP_FRAME_FLAG		0x00000008		/* RTP帧标志 */
#define GB28181_SDK_SDP_FRAME_FLAG		0x00000010		/* SDP帧标志 */
#define GB28181_SDK_MEDIA_INFO_FLAG 	0x00000020		/* 媒体类型标志*/

/* 视频关键字标识 */
#define GB28181_SDK_VIDEO_FRAME_I		0x01		/* I帧 */
#define GB28181_SDK_VIDEO_FRAME_P		0x02		/* P帧 */
#define GB28181_SDK_VIDEO_FRAME_B		0x03		/* B帧 */
#define GB28181_SDK_VIDEO_FRAME_J		0x04		/* JPEG */


typedef struct __GB28181_AV_FRAME
{
    unsigned int    u32AVFrameFlag;		/* 帧标志  视频 or 音频 */
    unsigned int    u32AVFrameLen;		/* 帧的长度 */
    unsigned int    u32VFrameType;		/* 视频的类型，I帧或P帧 */
    unsigned char   *pBuffer;			/* 数据 */
	unsigned long 	u64Timestamp;	    /* 时间戳(毫秒)*/
	
}GB28181_AV_FRAME;


typedef struct {
    char preset_id[24];    /**<  预置位编码 */
	char preset_name[24];  /**<  预置位名称 */
}gb28181_perset_param;


//----------------------------------------------------------------------------------------
typedef enum __STREAM_SPEED_CONTROL_ENUM
{
	STREAM_SPEED_CONTROL_UNKOWN = 0,
    STREAM_SPEED_CONTROL_SLOW_8,   //慢放8倍速
	STREAM_SPEED_CONTROL_SLOW_4,   //慢放4倍速
	STREAM_SPEED_CONTROL_SLOW_2,   //慢放2倍速
	STREAM_SPEED_CONTROL_PLAY_X1,  //正常播放1倍速
	STREAM_SPEED_CONTROL_PLAY_X2,  //快进2倍速
    STREAM_SPEED_CONTROL_PLAY_X4,  //快进4倍速
	STREAM_SPEED_CONTROL_PLAY_X8   //快进8倍速
}STREAM_SPEED_CONTROL_ENUM;

typedef enum __STREAM_CONTROL_ENUM
{
	STREAM_CONTROL_UNKOWN = 0,
	STREAM_CONTROL_PLAY,            //播放
    STREAM_CONTROL_PAUSE,           //暂停
    STREAM_CONTROL_SPEED,           //快进/慢放
    STREAM_CONTROL_NPT,             //随机拖放
    STREAM_CONTROL_TEARDOWN         //停止
}STREAM_CONTROL_ENUM;

typedef struct __GB28181_STREAM_CONTROL_T
{

    char sip_call_id[GB_STR_LEN_256];       //SIP call id  主动关闭用
	STREAM_CONTROL_ENUM streamControl;      //控制类型
	STREAM_SPEED_CONTROL_ENUM speedControl; //速度值
	int npt_start;                          //拖放开始时间（秒）
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
	RECORD_INFO_TYPE_TIME = 0, //按正常录像类型
	RECORD_INFO_TYPE_ALARM,   //按报警类型
	RECORD_INFO_TYPE_MANUAL,  //按手动录像类型
	RECORD_INFO_TYPE_ALL      //查询所有录像
}RECORD_INFO_TYPE_ENUM;

typedef enum __RECORD_CMD_TYPE_ENUM
{
	RECORD_CMD_TYPE_RECORD = 0, //开始录像
	RECORD_CMD_TYPE_STOP_RECORD, //停止录像
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
	
	int sn;                    //序列号
	int recordInfoNumber;      //文件总数
	char cameraIndexCode[32];  //监控点编码
	int cur_number;            //计数
	GB28181_RECORD_INFO_T *recordInfoList; //文件列表
}GB28181_RECORD_INFO_LIST_T;

//-----------------------------------------------------------------------------------

/****************       库内部提供的接口函数 ***********************/

/**
*@brief 启动GB28181 SIP服务器
*@param param 系统参数，用于后续的SIP服务
*@warning 需要保证参数的准确性，否则将无法正常进行SIP交互通讯
*/
int gb28181_startup(gb28181_system_param *sys_param,const char *log_dir,const char *log_name); 

/**
*@brief 停止GB28181 SIP服务器
*
*/
int gb28181_shutdown(void);

/**
*@brief 推送音视频帧数据
*
*/
int gb28181_push_frame(int channelId, GB28181_AV_FRAME *frame );


/**
*@brief 获取注册状态
*@return 1:注册成功(在线)0:注册失败(离线)
*/
int gb28181_get_register_status(void);

/**
*@brief 向平台发送报警信息  
*@param device_id 设备ID
*@param alarm_priority 报警级别(1,2,3,4)
*@param alarm_method 报警方式
 1 电话报警， 2 设备报警， 
 3 短信报警， 4 GPSGPS 报警， 5 视频报警， 
 6 设备故障报警， 7 其它报警
*@return GB_SUCCESS 设置成功，GB_FAILURE 失败。
*/
int gb28181_send_alarm_info(const char *device_id,int alarm_priority,int alarm_method);


int gb28181_send_record_info(GB28181_RECORD_INFO_LIST_T *record_info_list);

/***************        SDK与系统相关，用户需实现的函数 *******************/
/**
*@brief  设置报警开关
*@param bEnable=1: 布防
        bEnable=0: 撤防
*@return GB_SUCCESS 成功，GB_FAILURE 失败。
*/
int gb28181_set_alarm_status(int set_value);


/**
*@brief 获取预置位
*@param perset  预置位编码及名称
*@param max_perset     预置位数最大值
*@return  预置位个数
*/
int gb28181_get_perset_value(gb28181_perset_param perset[GB_MAX_PERSET]);

/**
*@PTZ 控制处理
*@chan_id  通道号
*@ptzCmd   PTZ 控制命令
*@return GB_SUCCESS 成功，GB_FAILURE 失败。
*/
int gb28181_ctrl_ptz(int chan_id,GB28181_PTZCMD_T *ptzCmd);


/**
*@brief 设置系统重启
*@return GB_SUCCESS 成功，GB_FAILURE 失败。
*/
int gb28181_set_sys_reboot(void);

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
int gb28181_sys_set_date_time(int year, int month, int day, int hour, int min, int sec);


/*
* @brief   设置手动录像命令
* @param   cmd:1开始手动录像,0停止手动录像
* @param   device_id:监控点编码
* @return  GB_SUCCESS 设置成功，GB_FAILURE 失败。
*/
int gb28181_record_cmd(int cmd,const char *device_id);

/*
* 不可阻塞,应立即返回
* @brief   查询录像文件信息
* @param   device_id 查询ID编码
* @param   device_id 交互SN(异步回复时候需要)
* @param   startTime 开始时间
* @param   endTime 结束时间
* @param   recordType 录像类型
* @return  GB_SUCCESS 设置成功，GB_FAILURE 失败。
*/
int gb28181_get_record_info(const char *device_id,int SN,GB28181_RECORD_TIME_T *startTime,
                     GB28181_RECORD_TIME_T *endTime,RECORD_INFO_TYPE_ENUM recordType);

/*
不可阻塞,应立即返回

* @brief   回放流控制,创建线程向回放通道32 推流
* @param   chanel:监控点通道
* @param   start_time:开始时间  
* @param   end_time:结束时间
* @param   stream_ctrl:回放流控制
* @return  GB_SUCCESS 设置成功，GB_FAILURE 失败。
*/

int gb28181_playback_control(int channel,long start_time, long end_time,GB28181_STREAM_CONTROL_T *stream_ctrl);


/*
不可阻塞,应立即返回

* @brief   下载流控制,创建线程向回放通道33 推流
* @param   chanel:监控点通道
* @param   call_id: 流会话ID
* @param   start_time:开始时间  
* @param   end_time:结束时间
* @param   download_speed:下载速度倍速(值等于-1代表停止)
* @return  GB_SUCCESS 设置成功，GB_FAILURE 失败。
*/
int gb28181_download_control(int channel,const char *call_id,long start_time, long end_time,int download_speed);

/*
* @brief   停止发送回放流或者下载流
* @param   call_id: 流会话ID
* @return  GB_SUCCESS 设置成功，GB_FAILURE 失败。
*/
int gb28181_stop_send_stream(const char *call_id);


/***************         end             ***********************/
#endif
