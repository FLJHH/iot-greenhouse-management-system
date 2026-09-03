#include "include.h"

/*ȫ�ֱ���*/

//----------------------------
// ���ڽ���ͨѶЭ������
struct protocol_send send_protocol_uart;
unsigned char send_protocol_uart_buff[512];

struct protocol_pipe protocol_pipe_uart_2;
unsigned char protocol_pipe_uart_buff_2[1024];

struct protocol_pipe protocol_pipe_uart_1;
unsigned char protocol_pipe_uart_buff_1[1024];

//----------------------------

//-----------------------------
// ������ʱ���趨
static Timer timer_detect_sensor;
static Timer timer_recv_data;
static Timer timer_key;
//-----------------------------

//-----------------------------
// ����������

unsigned char GlobalVar_flag_auto_adjust_tds = 0;
unsigned char GlobalVar_flag_auto_adjust_wendu = 0;
unsigned char GlobalVar_flag_auto_adjust_yanwu = 0;
unsigned char GlobalVar_flag_auto_adjust_renti = 0;
unsigned char GlobalVar_flag_auto_adjust_guangqiang = 0;
unsigned char GlobalVar_flag_auto_adjust_turang = 0;
unsigned char GlobalVar_flag_auto_adjust_shuiwei = 0;
unsigned char GlobalVar_flag_auto_adjust_dianliu = 0;
unsigned char GlobalVar_flag_auto_adjust_dianya = 0;
unsigned char GlobalVar_flag_auto_adjust_huoyan = 0;
unsigned char GlobalVar_flag_auto_adjust_zhendong = 0;
unsigned char GlobalVar_flag_auto_adjust_voice = 0;
unsigned char GlobalVar_flag_auto_adjust_yudi = 0;
unsigned char GlobalVar_flag_auto_adjust_yali = 0;
unsigned char GlobalVar_flag_auto_adjust_zhuodu = 0;

unsigned int Globol_flag_key_pressed = 0;

unsigned int GlobalVar_flag_auto_adjust = 0;

unsigned int GlobalVar_sensor_light = 40;

unsigned int GlobalVar_Threshold_light_min = 40;

unsigned int GlobalVar_sensor_distance = 0;
unsigned int GlobalVar_sensor_DO1 = 0;
unsigned int GlobalVar_sensor_huoyan = 0;
unsigned int GlobalVar_sensor_DO2 = 0;
unsigned int GlobalVar_sensor_DO3 = 0;
unsigned int GlobalVar_sensor_DO4 = 0;
unsigned int GlobalVar_sensor_DO5 = 0;
unsigned int GlobalVar_sensor_AO1 = 0;
unsigned int GlobalVar_sensor_AO2 = 0;
unsigned int GlobalVar_sensor_PM25 = 0;
unsigned int GlobalVar_sensor_TDS_wendu = 0;
unsigned int GlobalVar_sensor_TDS = 0;
unsigned int GlobalVar_sensor_dht11_wendu = 0;
unsigned int GlobalVar_sensor_dht11_shidu = 0;
unsigned int GlobalVar_sensor_ds18b20_wendu = 0;
unsigned int GlobalVar_sensor_heart = 0;
unsigned int GlobalVar_sensor_RenTi = 0;
unsigned int GlobalVar_sensor_guangqiang = 0;
unsigned int GlobalVar_sensor_shuiwei = 0;
unsigned int GlobalVar_sensor_turang = 0;
unsigned int GlobalVar_sensor_jiguangceju = 0;
unsigned int GlobalVar_sensor_dianya = 0;
unsigned int GlobalVar_sensor_dianliu = 0;
unsigned int GlobalVar_sensor_xinlv = 0;
unsigned int GlobalVar_sensor_xueyang = 0;
unsigned int GlobalVar_sensor_PulseSpeed = 0;
unsigned int GlobalVar_sensor_yali = 0;
unsigned int GlobalVar_sensor_voice = 0;
unsigned int GlobalVar_sensor_yanwu = 0;
unsigned int GlobalVar_sensor_yudi = 0;
unsigned int GlobalVar_sensor_zhuodu = 0;
int GlobalVar_sensor_hongwai_wendu = 0;

unsigned int GlobalVar_Threshold_alert_guangqiang_max = 65;
unsigned int GlobalVar_Threshold_alert_guangqiang_min = 30;
unsigned int GlobalVar_Threshold_alert_guangqiang = 28;
unsigned int GlobalVar_Threshold_alert_wendu = 28;
unsigned int GlobalVar_Threshold_alert_tds = 50;
unsigned int GlobalVar_Threshold_alert_yanwu = 30;
unsigned int GlobalVar_Threshold_alert_turang = 30;
unsigned int GlobalVar_Threshold_alert_shuiwei = 30;
unsigned int GlobalVar_Threshold_alert_dianya = 80;
unsigned int GlobalVar_Threshold_alert_dianliu = 8;
unsigned int GlobalVar_Threshold_alert_zhendong = 2000;
unsigned int GlobalVar_Threshold_alert_yudi = 30;
unsigned int GlobalVar_Threshold_alert_yali = 1000;
unsigned int GlobalVar_Threshold_alert_zhuodu = 50;

unsigned int GlobalVar_Threshold_alert_d1 = 5;
unsigned int GlobalVar_Threshold_alert_d2 = 5;
unsigned int GlobalVar_Threshold_alert_d3 = 5;
unsigned int GlobalVar_Threshold_alert_d4 = 5;

unsigned int GlobalVar_sensor_key_vlaue_1 = 0;
unsigned int GlobalVar_sensor_dht11_wendu2 = 0;
unsigned int GlobalVar_sensor_dht11_shidu2 = 0;
unsigned int GlobalVar_sensor_guangqiang2 = 0;
unsigned int GlobalVar_sensor_turang2 = 0;

unsigned int GlobalVar_Threshold_alert_d5 = 5;
unsigned int GlobalVar_Threshold_alert_d6 = 5;
unsigned int GlobalVar_Threshold_alert_d7 = 5;
unsigned int GlobalVar_Threshold_alert_d8 = 5;

unsigned int GlobalVar_Threshold_alert_bp1 = 0;
unsigned int GlobalVar_Threshold_alert_bp2 = 0;

//-----------------------------

int adc_check_init = 0;

/*���غ���*/
void HardWare_Init(void); // Ӳ����ʼ��
void SoftWare_Init(void); // ������ʼ��

void uart_recv_IdValue(const char *id, const char *value); // �������ڽ��յ���ָ��
void detect_sensor();									   // ���ڲɼ���������Ϣ

void user_recive_data(unsigned char *src, unsigned int len);
void user_send_data_uart_1(const unsigned char *src, int len);
void user_send_data_uart_2(const unsigned char *src, int len);



void service_connect(void)
{
	 
	const char * mqtt_service = "423423.iotcloud.tencentdevices.com" ;  //mqtt��������ַ
	const char * mqtt_port = "3306" ; //mqtt �˿�
	const char * mqtt_client_ID = "8632" ; //mqtt client ����ID
	const char * mqtt_device_key = "8632863211" ; // mqtt client������Կ
	const char * mqtt_client_topic = "feF25744Fef444523cfs" ; //mqtt��������

	user_send_data((unsigned char *)mqtt_service, strlen(mqtt_service));
	user_send_data((unsigned char *)mqtt_port, strlen(mqtt_port));
	user_send_data((unsigned char *)mqtt_client_ID, strlen(mqtt_client_ID));
	user_send_data((unsigned char *)mqtt_device_key, strlen(mqtt_device_key));
	user_send_data((unsigned char *)mqtt_client_topic, strlen(mqtt_client_topic));


}

void wireless_config()
{

	char *cfg_server_host = "{\"cfg_server_host\":\"www.tencentiot.top/design/update/m1/pid/8632/uid/ZCficS\"}";

	char *cfg_wifi_ssid = "{\"cfg_wifi_ssid\":\"wifi\"}";
	char *cfg_wifi_passwd = "{\"cfg_wifi_passwd\":\"12345678\"}";

	// config wifi and  gprs
	user_send_data_uart_2(cfg_server_host, strlen(cfg_server_host));

	// wifi only
	user_send_data_uart_2(cfg_wifi_passwd, strlen(cfg_wifi_passwd));
	user_send_data_uart_2(cfg_wifi_ssid, strlen(cfg_wifi_ssid));
}

void Set_GPIO_Init_Mode_DO_PB10(unsigned char value)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	static unsigned char flag_is_init = 0;
	if (flag_is_init == 0)
	{
		flag_is_init = 1;

		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE); // ʹ��PB�˿�ʱ��

		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;		  // �˿�����
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;  // ���ó����
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; // IO���ٶ�Ϊ50MHz
		GPIO_Init(GPIOB, &GPIO_InitStructure);			  // �����趨������ʼ��GPIOA.8
		GPIO_ResetBits(GPIOB, GPIO_Pin_10);				  // �����
	}

	if (value)
	{
		GPIO_ResetBits(GPIOB, GPIO_Pin_10); // ����͵�ƽ
	}
	else
	{
		GPIO_SetBits(GPIOB, GPIO_Pin_10); // �����
	}
}

// ˢ����������
void wireless_config_refresh()
{
	static unsigned int tick_count = 0;
	tick_count++;
	if (tick_count % 30 == 2)
	{
		wireless_config(); // ��ʼ����������
	}
}

void SetSensor_OLED_Chinese(unsigned char x, unsigned char y, int index)
{
	static unsigned char flag_is_init = 0;
	if (flag_is_init == 0)
	{
		flag_is_init = 1;

		OLED_Init();	   // oled��ʼ��
		OLED_Display_On(); // oled������ʾ
	}

	OLED_ShowCHinese(x, y, index);
}

void SetSensor_OLED_Sring(unsigned char x, unsigned char y, unsigned char *buff, unsigned char Char_Size)
{
	static unsigned char flag_is_init = 0;
	if (flag_is_init == 0)
	{
		flag_is_init = 1;

		OLED_Init();	   // oled��ʼ��
		OLED_Display_On(); // oled������ʾ
	}

	OLED_ShowString(x, y, buff, Char_Size);
}

void key_button_process(unsigned char key_number)
{

	if (key_number == 1)
	{
		GlobalVar_sensor_key_vlaue_1 = !GlobalVar_sensor_key_vlaue_1;
	}
}

// �Զ����ں���
// ��ʼ�Զ������жϣ�����¿����ȡ���ڿ��ƣ�
// 1:�����ж��Ƿ������Զ����ڣ����Ƿ�������ڿ��ƵĹ��ܣ�
// 2:����������Զ����ڵĹ��ܣ���ô�����Զ������жϣ��� ��ǿ�����趨����ֵ����ô���ƣ�����صƣ�
void Adjust_Sensor(void)
{
	static unsigned char old_key = 0;
	static char oled_buff[40];

	if (old_key != GlobalVar_sensor_key_vlaue_1)
	{
		OLED_Clear();
		old_key = GlobalVar_sensor_key_vlaue_1;
	}

	if (GlobalVar_sensor_key_vlaue_1)
	{
		memset(oled_buff, 0, sizeof(oled_buff));
		sprintf(oled_buff, "2:%d ", GlobalVar_sensor_dht11_wendu2);
		SetSensor_OLED_Sring(32, 0, (unsigned char *)oled_buff, 16);

		memset(oled_buff, 0, sizeof(oled_buff));
		sprintf(oled_buff, "2:%d ", GlobalVar_sensor_dht11_shidu2);
		SetSensor_OLED_Sring(32, 2, (unsigned char *)oled_buff, 16);

		memset(oled_buff, 0, sizeof(oled_buff));
		sprintf(oled_buff, "2:%d ", GlobalVar_sensor_guangqiang2);
		SetSensor_OLED_Sring(32, 4, (unsigned char *)oled_buff, 16);

		memset(oled_buff, 0, sizeof(oled_buff));
		sprintf(oled_buff, "2:%d ", GlobalVar_sensor_turang2);
		SetSensor_OLED_Sring(32, 6, (unsigned char *)oled_buff, 16);

		
		SetSensor_OLED_Chinese(0, 0, 0);
		SetSensor_OLED_Chinese(16, 0, 1);
		SetSensor_OLED_Chinese(0, 2, 2);
		SetSensor_OLED_Chinese(16, 2, 3);
		SetSensor_OLED_Chinese(0, 4, 4);
		SetSensor_OLED_Chinese(16, 4, 5);
		SetSensor_OLED_Chinese(0, 6, 6);
		SetSensor_OLED_Chinese(16, 6, 7);

		memset(oled_buff, 0, sizeof(oled_buff));
		sprintf(oled_buff, ":%d ", GlobalVar_Threshold_alert_d5);
		SetSensor_OLED_Sring(104, 0, (unsigned char *)oled_buff, 16);

		memset(oled_buff, 0, sizeof(oled_buff));
		sprintf(oled_buff, ":%d ", GlobalVar_Threshold_alert_d6);
		SetSensor_OLED_Sring(104, 2, (unsigned char *)oled_buff, 16);

		memset(oled_buff, 0, sizeof(oled_buff));
		sprintf(oled_buff, ":%d ", GlobalVar_Threshold_alert_d7);
		SetSensor_OLED_Sring(104, 4, (unsigned char *)oled_buff, 16);

		memset(oled_buff, 0, sizeof(oled_buff));
		sprintf(oled_buff, ":%d ", GlobalVar_Threshold_alert_d8);
		SetSensor_OLED_Sring(104, 6, (unsigned char *)oled_buff, 16);

		
		// 设置OLED中文显示，参数：行数，列数，字符串索引
		SetSensor_OLED_Chinese(72, 0, 8);
		SetSensor_OLED_Chinese(88, 0, 9);
		SetSensor_OLED_Chinese(72, 2, 10);
		SetSensor_OLED_Chinese(88, 2, 11);
		SetSensor_OLED_Chinese(72, 4, 12);
		SetSensor_OLED_Chinese(88, 4, 13);
		SetSensor_OLED_Chinese(72, 6, 14);
		SetSensor_OLED_Chinese(88, 6, 15);
	}
	else
	{
		memset(oled_buff, 0, sizeof(oled_buff));
		sprintf(oled_buff, "1:%d ", GlobalVar_sensor_dht11_wendu);
		SetSensor_OLED_Sring(32, 0, (unsigned char *)oled_buff, 16);

		memset(oled_buff, 0, sizeof(oled_buff));
		sprintf(oled_buff, "1:%d ", GlobalVar_sensor_dht11_shidu);
		SetSensor_OLED_Sring(32, 2, (unsigned char *)oled_buff, 16);

		memset(oled_buff, 0, sizeof(oled_buff));
		sprintf(oled_buff, "1:%d ", GlobalVar_sensor_guangqiang);
		SetSensor_OLED_Sring(32, 4, (unsigned char *)oled_buff, 16);

		memset(oled_buff, 0, sizeof(oled_buff));
		sprintf(oled_buff, "1:%d ", GlobalVar_sensor_turang);
		SetSensor_OLED_Sring(32, 6, (unsigned char *)oled_buff, 16);

		
		SetSensor_OLED_Chinese(0, 0, 0);
		SetSensor_OLED_Chinese(16, 0, 1);
		SetSensor_OLED_Chinese(0, 2, 2);
		SetSensor_OLED_Chinese(16, 2, 3);
		SetSensor_OLED_Chinese(0, 4, 4);
		SetSensor_OLED_Chinese(16, 4, 5);
		SetSensor_OLED_Chinese(0, 6, 6);
		SetSensor_OLED_Chinese(16, 6, 7);

		memset(oled_buff, 0, sizeof(oled_buff));
		sprintf(oled_buff, ":%d ", GlobalVar_Threshold_alert_d1);
		SetSensor_OLED_Sring(104, 0, (unsigned char *)oled_buff, 16);

		memset(oled_buff, 0, sizeof(oled_buff));
		sprintf(oled_buff, ":%d ", GlobalVar_Threshold_alert_d2);
		SetSensor_OLED_Sring(104, 2, (unsigned char *)oled_buff, 16);

		memset(oled_buff, 0, sizeof(oled_buff));
		sprintf(oled_buff, ":%d ", GlobalVar_Threshold_alert_d3);
		SetSensor_OLED_Sring(104, 4, (unsigned char *)oled_buff, 16);

		memset(oled_buff, 0, sizeof(oled_buff));
		sprintf(oled_buff, ":%d ", GlobalVar_Threshold_alert_d4);
		SetSensor_OLED_Sring(104, 6, (unsigned char *)oled_buff, 16);

		
		SetSensor_OLED_Chinese(72, 0, 8);
		SetSensor_OLED_Chinese(88, 0, 9);
		SetSensor_OLED_Chinese(72, 2, 10);
		SetSensor_OLED_Chinese(88, 2, 11);
		SetSensor_OLED_Chinese(72, 4, 12);
		SetSensor_OLED_Chinese(88, 4, 13);
		SetSensor_OLED_Chinese(72, 6, 14);
		SetSensor_OLED_Chinese(88, 6, 15);
	}

	if (GlobalVar_Threshold_alert_bp1 || GlobalVar_Threshold_alert_bp2)
	{
		Set_GPIO_Init_Mode_DO_PB10(1);
	}
	else
	{
		Set_GPIO_Init_Mode_DO_PB10(0);
	}
}

/*****************************************/
// Ӳ�����ֳ�ʼ��
/*****************************************/
void HardWare_Init(void)
{

	NVIC_Configuration(); /* ����NVIC�ж�ģʽ */

	delay_init(); /* ��ʱ������ʼ�� */

	UARTx_Init(); // ���ڳ�ʼ��

	TIM4_Int_Init(1000, 72); /* ��TIM4��ʱ�ж� ������Ϊ 1ms */

	// Adc_Init(); /* ADC��ʼ��  adc.h    ch-4567 */
	//   InitSensor_Beep( );   //��������ʼ��

	OLED_Init();	   // oled��ʼ��
	OLED_Display_On(); // oled������ʾ

	// OLED_ShowString(0,2,show_buff,16); //size: 8  16
}

void detect_sensor()
{
	static unsigned char flag_is_init = 0; // ��ʼ����־λ
	//---------------------------------------/////
	wireless_config_refresh();
	//---------------------------------------/////

	if (flag_is_init == 0)
	{
		flag_is_init = 1;
		key_button_init(); // ��ʼ������
	}

	Adjust_Sensor(); // �����������ж�
}

void recv_IdValue_uart_2(const char *id, const char *value)
{
	int value_len = protocol_valuelen(value);
	int num_value;

	if (protocol_compare(id, "wendu1"))
	{
		num_value = protocol_atoi(value);
		GlobalVar_sensor_dht11_wendu = num_value;
	}

	else if (protocol_compare(id, "shidu1"))
	{
		num_value = protocol_atoi(value);
		GlobalVar_sensor_dht11_shidu = num_value;
	}

	else if (protocol_compare(id, "guangqiang1"))
	{
		num_value = protocol_atoi(value);
		GlobalVar_sensor_guangqiang = num_value;
	}

	else if (protocol_compare(id, "turang1"))
	{
		num_value = protocol_atoi(value);
		GlobalVar_sensor_turang = num_value;
	}

	else if (protocol_compare(id, "d1"))
	{
		num_value = protocol_atoi(value);
		GlobalVar_Threshold_alert_d1 = num_value;
	}
	else if (protocol_compare(id, "d2"))
	{
		num_value = protocol_atoi(value);
		GlobalVar_Threshold_alert_d2 = num_value;
	}
	else if (protocol_compare(id, "d3"))
	{
		num_value = protocol_atoi(value);
		GlobalVar_Threshold_alert_d3 = num_value;
	}
	else if (protocol_compare(id, "d4"))
	{
		num_value = protocol_atoi(value);
		GlobalVar_Threshold_alert_d4 = num_value;
	}
	else if (protocol_compare(id, "bp1"))
	{
		num_value = protocol_atoi(value);
		GlobalVar_Threshold_alert_bp1 = num_value;
	}

	else if (protocol_compare(id, "wendu2"))
	{
		num_value = protocol_atoi(value);
		GlobalVar_sensor_dht11_wendu2 = num_value;
	}

	else if (protocol_compare(id, "shidu2"))
	{
		num_value = protocol_atoi(value);
		GlobalVar_sensor_dht11_shidu2 = num_value;
	}

	else if (protocol_compare(id, "guangqiang2"))
	{
		num_value = protocol_atoi(value);
		GlobalVar_sensor_guangqiang2 = num_value;
	}

	else if (protocol_compare(id, "turang2"))
	{
		num_value = protocol_atoi(value);
		GlobalVar_sensor_turang2 = num_value;
	}

	else if (protocol_compare(id, "d5"))
	{
		num_value = protocol_atoi(value);
		GlobalVar_Threshold_alert_d5 = num_value;
	}
	else if (protocol_compare(id, "d6"))
	{
		num_value = protocol_atoi(value);
		GlobalVar_Threshold_alert_d6 = num_value;
	}
	else if (protocol_compare(id, "d7"))
	{
		num_value = protocol_atoi(value);
		GlobalVar_Threshold_alert_d7 = num_value;
	}
	else if (protocol_compare(id, "d8"))
	{
		num_value = protocol_atoi(value);
		GlobalVar_Threshold_alert_d8 = num_value;
	}
	else if (protocol_compare(id, "bp2"))
	{
		num_value = protocol_atoi(value);

		num_value = protocol_atoi(value);
		GlobalVar_Threshold_alert_bp2 = num_value;
	}
}

void func_timer_key()
{
	key_button_scan_10ms();
}


// 接收串口1的数据包，并将其发送到串口2，然后从数据包中获取ID值
void protocol_recv_pack_uart_1(const char *pack, const int len)
{
	user_send_data_uart_2(pack, len); // 将接收到的数据包发送到串口2
	protocol_pipe_get_IdValue_FromPack(&protocol_pipe_uart_1, recv_IdValue_uart_2); // 从数据包中获取ID值
}

// ���մ���2�����ݰ���������ת��
void protocol_recv_pack_uart_2(const char *pack, const int len)
{
	user_send_data_uart_1(pack, len); // ֱ��ת��������2

	// protocol_pipe_get_IdValue_FromPack(&protocol_pipe_uart_1,recv_IdValue_uart_2); //��������
}

void func_timer_recv_data()
{
	// protocol_pipe_get_IdValue(&protocol_pipe_uart, uart_recv_IdValue);

	// 调用protocol_pipe_Pack函数，将protocol_pipe_uart_1和protocol_recv_pack_uart_1参数传入
protocol_pipe_Pack(&protocol_pipe_uart_1, protocol_recv_pack_uart_1);

// 调用protocol_pipe_Pack函数，将protocol_pipe_uart_2和protocol_recv_pack_uart_2参数传入
protocol_pipe_Pack(&protocol_pipe_uart_2, protocol_recv_pack_uart_2);
}

void SoftWare_Init(void)
{

	// ͨѶЭ���ʼ��
	protocol_pipe_init(&protocol_pipe_uart_2, protocol_pipe_uart_buff_2, sizeof(protocol_pipe_uart_buff_2));
	protocol_pipe_init(&protocol_pipe_uart_1, protocol_pipe_uart_buff_1, sizeof(protocol_pipe_uart_buff_1));

	protocol_send_init(&send_protocol_uart, send_protocol_uart_buff, sizeof(send_protocol_uart_buff));

	// ��ʱ����ʼ��
	timer_init(&timer_detect_sensor, detect_sensor, 2000, 1);	// ���ڲɼ���������Ϣ
	timer_init(&timer_recv_data, func_timer_recv_data, 100, 1); // ���ڽ�����������ָ��
	timer_init(&timer_key, func_timer_key, 10, 1);				// �������

	timer_start(&timer_detect_sensor);
	timer_start(&timer_recv_data);
	timer_start(&timer_key);

	key_button_register(key_button_process);
}

/**************************************************************************************/
/***********************************main �������**************************************/
/**************************************************************************************/

int main(void)
{

	SoftWare_Init(); // ������ʼ��

	HardWare_Init(); // Ӳ����ʼ��

	while (1)
	{
		timer_loop(); // ��ʱ��ִ��
	}
}

void user_send_data_uart_2(const unsigned char *src, int len)
{
	UART2_Send_BUFF(src, len);
}

void user_send_data_uart_1(const unsigned char *src, int len)
{
	UART1_Send_BUFF(src, len);
}

/**************************************************************************************/
// ��ʱ��  Ӳ����ʱ����Դ
/**************************************************************************************/
void TIM4_IRQHandler(void) /* TIM4�ж� */
{
	if (TIM_GetITStatus(TIM4, TIM_IT_Update) != RESET) /* ���ָ����TIM�жϷ������:TIM �ж�Դ */
	{

		TIM_ClearITPendingBit(TIM4, TIM_IT_Update); /* ���TIMx���жϴ�����λ:TIM �ж�Դ */

		timer_ticks(); // 1ms tick to uodate timer
	}
}
