#include "include.h"
#include "sensor_hal.h"
#include "auxiliary.h"

// 软件定时器设定
static Timer timer_detect_sensor;
static Timer timer_recv_data;
static Timer timer_MAX30102;
static Timer timer_1s;
static Timer timer_key;

/*本地函数*/
void HardWare_Init(void); // 硬件初始化
void SoftWare_Init(void); // 软件初始化

void detect_sensor(void);								   // 周期采集传感器信息
void user_send_data(const unsigned char *src, int len);	   // 串口发送函数
void uart_recv_IdValue(const char *id, const char *value); // 处理串口接收到的指令



unsigned char GlobalVar_Module_status_updata_value1 = 0;
unsigned char GlobalVar_Module_status_updata_value2 = 0;
unsigned char GlobalVar_Module_status_updata_value3 = 0;
unsigned char GlobalVar_Module_status_updata_value4 = 0;

unsigned char GlobalVar_Controls_Module_status_jdq = 0;

/*****************************************/
// 硬件部分初始化
/*****************************************/
void HardWare_Init(void)
{
	NVIC_Configuration(); /* 配置NVIC中断模式 */
	delay_init(); /* 延时函数初始化 */
	UART2_Init(38400); // 串口2初始化
	// UART1_Init(9600); //串口1初始化 -- 解析串口数据
	TIM4_Int_Init(1000, 72); /* 开TIM4定时中断 计数到为 1ms */
	// 5个引脚全为普通引脚，但不能再用JTAG&SWD仿真器调试，只能用st-link调试
	//  GPIO_PinRemapConfig(GPIO_Remap_SWJ_Disable, ENABLE);
	// 如果你用PB3，PB4，PA15做普通IO，PA13&14用于SWD调试
	GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable, ENABLE);
}

void func_timer_recv_data()
{
	protocol_pipe_get_IdValue(&protocol_pipe_uart, uart_recv_IdValue); // 解析串口2的控制指令

	protocol_pipe_get_IdValue(&protocol_pipe_uart_2, uart_recv_IdValue_sensor); // 解析串口 传感器数据

	parse_uart_sensor(); // 解析串口1传感器数据

	if (GlobalVar_flag_is_inited_zhendong_DO)
	{
		process_zhendong_DO_100ms();
	}

	if (GlobalVar_flag_liuliang_inited)
	{
		process_liuliang_100ms();
	}
}

void SoftWare_Init(void)
{
	// 通讯协议初始化
	protocol_pipe_init(&protocol_pipe_uart, protocol_pipe_uart_buff, sizeof(protocol_pipe_uart_buff));
	protocol_send_init(&send_protocol_uart, send_protocol_uart_buff, sizeof(send_protocol_uart_buff));

	protocol_pipe_init(&protocol_pipe_uart_2, protocol_pipe_uart_buff_2, sizeof(protocol_pipe_uart_buff_2));

	sensor_hal_protocol_init(&send_protocol_uart); // 初始化

	// 定时器初始化
	timer_init(&timer_detect_sensor, detect_sensor, 2000, 1);	// 周期采集传感器信息
	timer_init(&timer_recv_data, func_timer_recv_data, 100, 1); // 周期解析串口数据指令
	timer_init(&timer_key, func_timer_key, 10, 1);				// 按键检测

	timer_start(&timer_detect_sensor);
	timer_start(&timer_recv_data);
	timer_start(&timer_key);

	key_button_register(key_button_process);								   // 注册按键处理函数
	RINGBUF_Init(&Uart_sensor_RB, uart_sensor_buff, sizeof(uart_sensor_buff)); // 初始化串口环形缓冲器
}

/**************************************************************************************/
/***********************************main 程序入口**************************************/
/**************************************************************************************/

int main(void)
{
	SoftWare_Init(); // 软件初始化
	HardWare_Init(); // 硬件初始化
	while (1)
	{
		timer_loop(); // 定时器执行
	}
}

/**************************************************************************************/
// 定时器  硬件定时器震荡源
/**************************************************************************************/
void TIM4_IRQHandler(void) /* TIM4中断 */
{
	if (TIM_GetITStatus(TIM4, TIM_IT_Update) != RESET) /* 检查指定的TIM中断发生与否:TIM 中断源 */
	{
		TIM_ClearITPendingBit(TIM4, TIM_IT_Update); /* 清除TIMx的中断待处理位:TIM 中断源 */
		timer_ticks(); // 1ms tick to uodate timer
		
		if (GlobalVar_flag_key_inited)
		{
			key_button_scan_1ms();
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////
//
//
//      核心逻辑函数
//
//
/////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////
//
//
//      核心逻辑函数
//
//
/////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////
//
//
//      核心逻辑函数
//
//
/////////////////////////////////////////////////////////////////////////////////


void Adjust_Sensor(void)
{
	static unsigned char jdq_value = 0;
	unsigned char wen_value = 0, gu1_value = 0, gu2_value = 0, tur_value = 0;

	if (GlobalVar_flag_auto_adjust_wendu)
	{
		wen_value = GlobalVar_sensor_dht11_wendu > GlobalVar_Threshold_alert_wendu ? 1 : 0;
		tur_value = GlobalVar_sensor_turang < GlobalVar_Threshold_alert_shidu ? 1 : 0;
		gu1_value = GlobalVar_sensor_guangqiang > GlobalVar_Threshold_alert_guangqiang_max ? 1 : 0;
		gu2_value = GlobalVar_sensor_guangqiang < GlobalVar_Threshold_alert_guangqiang_min ? 1 : 0;

		SetSensor_Jidianqi_1(tur_value);

		jdq_value = gu1_value;

		SetSensor_Deng_1(gu2_value);

		GlobalVar_Module_status_updata_value1 = gu2_value;

		GlobalVar_Module_status_updata_value2 = tur_value;
	}
	else
	{
		jdq_value = GlobalVar_Controls_Module_status_jdq;
	}
	SetSensor_Fan_1(wen_value);

	
	if (wen_value || tur_value || gu1_value || gu2_value)
	{
		GetSensor_IdValue_int("bp2",1);
	}
	else
	{
		GetSensor_IdValue_int("bp2",0);
	}
	

	SetSensor_MOTOR(jdq_value, 5);

	// 步进电机
	GetSensor_IdValue_int("d5", MOTOR_Direction_Control);
	// 灯
	GetSensor_IdValue_int("d6", GlobalVar_Module_status_updata_value1);
	// 继电器
	GetSensor_IdValue_int("d7", GlobalVar_Module_status_updata_value2);
	// 风扇
	GetSensor_IdValue_int("d8", wen_value);
}



void detect_sensor(void)
{


	protocol_send_start(&send_protocol_uart); //

	// ################################################################

	GetSensor_Time("online2"); // 离线检查 开机时间

	GetSensor_Dht11("wendu2", "shidu2"); // dht11温湿度

	GetSensor_Guangqiang("guangqiang2"); // 光强

	GetSensor_Turang("turang2"); //土壤

	Adjust_Sensor(); // 传感器调节判断

	protocol_send_complete(&send_protocol_uart, user_send_data);
}

void uart_recv_IdValue(const char *id, const char *value)
{

	int value_len = protocol_valuelen(value); // 获取协议的数值长度
	int num_value;

	GlobalVar_sensor_online_response++;


	if (protocol_compare(id, "deng2")) // 判断控制指令
	{
		// 判断是否需要控制
		if (GlobalVar_flag_auto_adjust_wendu)
			return; // 自动调节模式下直接返回，防止对自动调节造成干

		if (protocol_compare(value, "on")) // 判断是否是打开指令
		{
			SetSensor_Deng_1(1);
			GlobalVar_Module_status_updata_value1 = 1;
		}
		else
		{
			SetSensor_Deng_1(0);
			GlobalVar_Module_status_updata_value1 = 0;
		}
	}

	else if (protocol_compare(id, "duoji2")) // 判断控制指令
	{
		// 判断是否需要控制
		if (GlobalVar_flag_auto_adjust_wendu)
			return; // 自动调节模式下直接返回，防止对自动调节造成干

		if (protocol_compare(value, "on")) // 判断是否是打开指令
		{
			SetSensor_duoji(180);
			GlobalVar_Controls_Module_status_jdq = 1;
		}
		else
		{
			SetSensor_duoji(0);
			GlobalVar_Controls_Module_status_jdq = 0;
		}
	}

	else if (protocol_compare(id, "jdq2"))
	{
		if (GlobalVar_flag_auto_adjust_wendu)
			return;

		if (protocol_compare(value, "on"))
		{
			SetSensor_Jidianqi_1(1);
			GlobalVar_Module_status_updata_value2 = 1;
		}
		else
		{
			SetSensor_Jidianqi_1(0);
			GlobalVar_Module_status_updata_value2 = 0;
		}
	}

	else if (protocol_compare(id, "a_wen1"))
	{
		if (protocol_compare(value, "on"))
		{
			GlobalVar_flag_auto_adjust_wendu = 1;
		}
		else
		{
			GlobalVar_flag_auto_adjust_wendu = 0;
		}
	}

	else if (protocol_compare(id, "l_wen1"))
	{
		num_value = protocol_atoi(value);

		GlobalVar_Threshold_alert_wendu = num_value;
	}

	else if (protocol_compare(id, "l_shi1"))
	{
		num_value = protocol_atoi(value);

		GlobalVar_Threshold_alert_shidu = num_value;
	}

	else if (protocol_compare(id, "l_gua1"))
	{
		num_value = protocol_atoi(value);

		GlobalVar_Threshold_alert_guangqiang_max = num_value;
	}

	else if (protocol_compare(id, "l_gua2"))
	{
		num_value = protocol_atoi(value);

		GlobalVar_Threshold_alert_guangqiang_min = num_value;
	}


	
}