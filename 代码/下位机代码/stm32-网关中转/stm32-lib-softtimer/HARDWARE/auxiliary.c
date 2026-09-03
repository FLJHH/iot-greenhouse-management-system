#include "auxiliary.h"

// 用于解析通讯协议数据
struct protocol_send send_protocol_uart;
unsigned char send_protocol_uart_buff[512];

struct protocol_pipe protocol_pipe_uart;
unsigned char protocol_pipe_uart_buff[1024];

struct protocol_pipe protocol_pipe_uart_2;
unsigned char protocol_pipe_uart_buff_2[256];

// 用于解析串口1的传感器数据
RINGBUF Uart_sensor_RB;
unsigned char uart_sensor_buff[512];

const char *cfg_server_host = "{\"cfg_server_host\":\"www.xiaotongren.top/design/update/m1/pid/8592/uid/tYbjC9\"}";

void user_send_data(const unsigned char *src, int len)
{
	UART2_Send_BUFF(src, len);
}

// 激光扫码模块
void process_card_callback(char *string_code)
{

	protocol_send_start(&send_protocol_uart);

	// ################################################################
	protocol_send_IdValue_str(&send_protocol_uart, "card1", string_code);
	// ################################################################

	protocol_send_complete(&send_protocol_uart, user_send_data);
}

// 红外体温
void process_hongwai_callback(int value)
{
	GlobalVar_sensor_hongwai_wendu = value;
}

// 激光测距
void process_ms53lom_callback(int value)
{
	GlobalVar_sensor_hongwai_juli = value;
}

// mpu6050 (GY-25)
void process_6050_callback(int x, int y, int z)
{
	GlobalVar_sensor_6050_x = x;
	GlobalVar_sensor_6050_y = y;
	GlobalVar_sensor_6050_z = z;
}

// TDS
void process_tds_callback(int tds, int wendu)
{
	GlobalVar_sensor_TDS = tds;
	GlobalVar_sensor_TDS_wendu = wendu;
}

// PM25
void process_pm25_callback(int pm25)
{

	GlobalVar_sensor_pm25 = pm25;
}

void SD_cesu_parse()
{
	static unsigned char temp_value_SD_cesu = 0;
	unsigned char temp_value_hongwai1 = 0;

	GlobalVar_sensor_interval_time++; // 确定累计时间

	if (GlobalVar_sensor_interval_time > 30) // 判断是否超时
	{
		GlobalVar_sensor_sudu = 0; // 超时置0
	}

	temp_value_hongwai1 = GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_12); // 获取当前状态

	if ((temp_value_hongwai1 == 1) && (temp_value_SD_cesu == 0)) // 判断是否满一圈
	{
		GlobalVar_sensor_sudu = (100 / GlobalVar_sensor_interval_time); // 100 / 间隔时间 计算速度
		GlobalVar_sensor_interval_time = 0;								// 清除间隔时间
	}

	temp_value_SD_cesu = temp_value_hongwai1; // 储存久的数值
}

void ph_dan_lin_jia_callback(int ph, int dan, int lin, int jia)
{
	GlobalVar_sensor_ph_dan_lin_jia_PH = ph;
	GlobalVar_sensor_ph_dan_lin_jia_DAN = dan;
	GlobalVar_sensor_ph_dan_lin_jia_LIN = lin;
	GlobalVar_sensor_ph_dan_lin_jia_JIA = jia;
}

// GPS
void process_gps_callback(char *x, char *y)
{
	GlobalVar_flag_gps_parse_success = 1;
	strcpy(GlobalVar_gps_x, x);
	strcpy(GlobalVar_gps_y, y);
}

// 解析UART sensor
void parse_uart_sensor()
{
	static unsigned char read_buff[512];
	unsigned char value;
	unsigned int index = 0;

	while (RINGBUF_Get(&Uart_sensor_RB, &value) == 0 && index < sizeof(read_buff))
	{
		read_buff[index++] = value;
	}

	if (index == 0)
	{
		// return;
	}
	
	if (GlobalVar_flag_hongwaiwendu_inited)
	{
		// 解析外ICS温度
	hongwaiwendu_parse(read_buff, index, process_hongwai_callback);
	}

	if (GlobalVar_flag_ms53lom_inited)
	{
		ms53lom_parse(read_buff, index, process_ms53lom_callback);
	}

	if (GlobalVar_flag_pm25_inited)
	{
		pm25_parse(read_buff, index, process_pm25_callback);
	}

	if (GlobalVar_flag_uart6050_inited)
	{
		uart6050_parse(read_buff, index, process_6050_callback);
	}

	// scanner_parse(read_buff, index, process_card_callback);

	if (GlobalVar_flag_tds_inited)
	{
		tds_parse(read_buff, index, process_tds_callback);
	}

	if (GlobalVar_flag_gps_inited)
	{
		GPS_parse(read_buff, index, process_gps_callback);
	}

	if (GlobalVar_flag_sudu_inited)
	{
		SD_cesu_parse();
	}

	if (GlobalVar_flag_ph_dan_lin_jia_inited)
	{
		ph_dan_lin_jia_parse(read_buff, index, ph_dan_lin_jia_callback);
	}


}

void func_timer_MAX30102()
{
	// 定义两个int类型的变量xinlv和xueyang
	int xinlv, xueyang;
	// 如果GlobalVar_flag_max30102_inited的值为1
	if (GlobalVar_flag_max30102_inited)
	{
		// 调用max30102_detect函数，获取xinlv和xueyang的值
		max30102_detect(&xinlv, &xueyang);
		// 如果xinlv和xueyang的值都不为0
		if (xinlv && xueyang)
		{
			// 将xinlv的值赋给GlobalVar_sensor_max30102_xinlv
			GlobalVar_sensor_max30102_xinlv = xinlv;
			// 将xueyang的值赋给GlobalVar_sensor_max30102_xueyang
			GlobalVar_sensor_max30102_xueyang = xueyang;
		}
	}
}

void func_timer_1s()
{
	static unsigned int time_value = 0;
	static unsigned char beep_value = 0;

	if (GlobalVar_flag_time_inited)
	{
		SetSensor_time_OLED_show_1s();
	}

	if (GlobalVar_sensor_beep_init)
	{
		time_value++;

		if(GlobalVar_sensor_beep_interval)
		{
			if((time_value % GlobalVar_sensor_beep_interval) == 0)
			{
				beep_value = !beep_value;
			}
		}
		else
		{
			beep_value = 0;
		}

		SetSensor_Beep_1(beep_value);
	}
}

// 按键处理函数
void key_button_process(unsigned char key_number)
{

	if (key_number == 1)
	{
		GlobalVar_sensor_key_state = 1;
		GlobalVar_sensor_key_press_1 = 1;
		GlobalVar_sensor_key_vlaue_1 = !GlobalVar_sensor_key_vlaue_1;
		if (GlobalVar_Adjust_key_select_line)
		{
			GlobalVar_Adjust_key_select_state1 = !GlobalVar_Adjust_key_select_state1;
		}
		else
		{
			GlobalVar_Adjust_key_select_state1 = 0;
		}
	}

	else if (key_number == 2)
	{
		GlobalVar_sensor_key_press_2 = 1;
		GlobalVar_sensor_key_vlaue_2 = !GlobalVar_sensor_key_vlaue_2;

		if (GlobalVar_Adjust_key_select_state1)
		{
			if (GlobalVar_Adjust_key_select_line % 5 == 1)
			{
				GlobalVar_Adjust_key_modify_number1++;
			}
			else if (GlobalVar_Adjust_key_select_line % 5 == 2)
			{
				GlobalVar_Adjust_key_modify_number2++;
			}
			else if (GlobalVar_Adjust_key_select_line % 5 == 3)
			{
				GlobalVar_Adjust_key_modify_number3++;
			}
			else if (GlobalVar_Adjust_key_select_line % 5 == 4)
			{
				GlobalVar_Adjust_key_modify_number4++;
			}
		}
		else
		{
			if (GlobalVar_Adjust_key_select_line < 4)
				GlobalVar_Adjust_key_select_line++;
		}
	}

	else if (key_number == 3)
	{

		if (GlobalVar_Adjust_key_select_state1)
		{
			if (GlobalVar_Adjust_key_select_line % 5 == 1)
			{
				if (GlobalVar_Adjust_key_modify_number1)
					GlobalVar_Adjust_key_modify_number1--;
			}
			else if (GlobalVar_Adjust_key_select_line % 5 == 2)
			{
				if (GlobalVar_Adjust_key_modify_number2)
					GlobalVar_Adjust_key_modify_number2--;
			}
			else if (GlobalVar_Adjust_key_select_line % 5 == 3)
			{
				if (GlobalVar_Adjust_key_modify_number3)
					GlobalVar_Adjust_key_modify_number3--;
			}
			else if (GlobalVar_Adjust_key_select_line % 5 == 4)
			{
				if (GlobalVar_Adjust_key_modify_number4)
					GlobalVar_Adjust_key_modify_number4--;
			}
		}
		else
		{
			if (GlobalVar_Adjust_key_select_line)
				GlobalVar_Adjust_key_select_line--;
		}
	}

	else if (key_number == 4)
	{
		GlobalVar_Adjust_key_select_state4 = 1;
	}

	if (GlobalVar_flag_key16_inited)
	{
		GlobalVar_sensor_key16_vlaue = key_number;
	}
}

void func_timer_key()
{
	static unsigned int time_value_temp = 0;
	
	if (GlobalVar_flag_key_inited)
	{
		key_button_scan_10ms();
	}

	if (GlobalVar_flag_key16_inited)
	{
		key16_button_scan_10ms();
	}

	if (GlobalVar_flag_is_inited_zhendong_AO)
	{
		process_zhendong_AO_1ms();
	}

	if(GlobalVar_flag_motor_inited)
	{
		MOTOR_Control(MOTOR_Direction_Control ,((time_value_temp % 4)+1) );
		time_value_temp++;
	}
	
}

void uart_recv_IdValue_sensor(const char *id, const char *value)
{
	// int value_len = protocol_valuelen(value); //获取协议的数值长度
	// int num_value;

	// if (protocol_compare(id, "yuyin")) //语音控制
	// {
	// 	if (protocol_compare(value, "hongloumeng"))
	// 	{
	// 		SetSensor_Beep(1);
	// 	}
	// 	else if (protocol_compare(value, "shuihuzhuan"))
	// 	{
	// 		SetSensor_Beep(1);
	// 	}
	// 	else if (protocol_compare(value, "sanguoyanyi"))
	// 	{
	// 		SetSensor_Beep(1);
	// 	}
	// 	else if (protocol_compare(value, "xiyouji"))
	// 	{
	// 		SetSensor_Beep(1);
	// 	}
	// }
}
