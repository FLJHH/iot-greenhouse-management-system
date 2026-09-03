
#include "sensor_hal.h"
#include "protocol.h"
#include "pin_define.h"
#include "include.h"

//-----------------------------
// 传感器变量

unsigned int GlobalVar_sensor_distance = 0;
unsigned int GlobalVar_sensor_distance_2 = 0;
unsigned int GlobalVar_sensor_DO1 = 0;
unsigned int GlobalVar_sensor_huoyan = 0;
unsigned int GlobalVar_sensor_hongwai_duiguan = 0;
unsigned int GlobalVar_sensor_SD_cesu = 0;
unsigned int GlobalVar_sensor_DO_diedao = 0;
unsigned int GlobalVar_sensor_DO2 = 0;
unsigned int GlobalVar_sensor_DO3 = 0;
unsigned int GlobalVar_sensor_DO4 = 0;
unsigned int GlobalVar_sensor_DO5 = 0;
unsigned int GlobalVar_sensor_AO1 = 0;
unsigned int GlobalVar_sensor_AO2 = 0;

unsigned int GlobalVar_sensor_TDS_wendu = 0;
unsigned int GlobalVar_sensor_TDS = 0;
unsigned int GlobalVar_sensor_dht11_wendu = 0;
unsigned int GlobalVar_sensor_dht11_shidu = 0;
unsigned int GlobalVar_sensor_ds18b20_wendu = 0;
unsigned int GlobalVar_sensor_heart = 0;
unsigned int GlobalVar_sensor_RenTi = 0;
unsigned int GlobalVar_sensor_RenTi_2 = 0;
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
unsigned int GlobalVar_sensor_yanwu_2 = 0;
unsigned int GlobalVar_sensor_MQ1 = 0;
unsigned int GlobalVar_sensor_MQ2 = 0;
unsigned int GlobalVar_sensor_MQ3 = 0;
unsigned int GlobalVar_sensor_MQ4 = 0;
unsigned int GlobalVar_sensor_yudi = 0;
unsigned int GlobalVar_sensor_zhuodu = 0;
unsigned int GlobalVar_sensor_ph = 0;
float GlobalVar_sensor_ph_float = 0;
int GlobalVar_sensor_hongwai_wendu = 0;
int GlobalVar_sensor_ph_dan_lin_jia_PH = 0;
int GlobalVar_sensor_ph_dan_lin_jia_DAN = 0;
int GlobalVar_sensor_ph_dan_lin_jia_LIN = 0;
int GlobalVar_sensor_ph_dan_lin_jia_JIA = 0;
unsigned int GlobalVar_sensor_hongwai_juli = 0;
int GlobalVar_sensor_pm25 = 0;
unsigned int GlobalVar_sensor_light = 40;
unsigned int GlobalVar_sensor_zhendong_DO = 0;
unsigned int GlobalVar_sensor_zhendong_AO = 0;
int GlobalVar_sensor_6050_x = 0;
int GlobalVar_sensor_6050_y = 0;
int GlobalVar_sensor_6050_z = 0;
int GlobalVar_sensor_max30102_xinlv = 0;
int GlobalVar_sensor_max30102_xueyang = 0;
unsigned int GlobalVar_sensor_ziwaixian = 0;
unsigned char GlobalVar_sensor_key_press_1 = 0;
unsigned char GlobalVar_sensor_key_vlaue_1 = 0;
unsigned char GlobalVar_sensor_key_press_2 = 0;
unsigned char GlobalVar_sensor_key_vlaue_2 = 0;
unsigned char GlobalVar_sensor_key16_vlaue = 0;
unsigned int GlobalVar_sensor_online_response = 0;
int GlobalVar_sensor_maichongjishu = 0;

unsigned int GlobalVar_sensor_interval_time = 0;
unsigned int GlobalVar_sensor_sudu = 0;

unsigned int GlobalVar_sensor_juli = 0;

int GlobalVar_sensor_liuliang_enter = 0;
int GlobalVar_sensor_liuliang_output = 0;

unsigned int GlobalVar_sensor_beep_init = 0;
unsigned int GlobalVar_sensor_beep_interval = 0;

//-----------------------------
// 自动调节变量
unsigned char GlobalVar_flag_auto_adjust_RX = 0;
unsigned char GlobalVar_flag_auto_adjust_tds = 0;
unsigned char GlobalVar_flag_auto_adjust_wendu = 0;
unsigned char GlobalVar_flag_auto_adjust_moshi = 0;
unsigned char GlobalVar_flag_auto_adjust_churuku = 0;
unsigned char GlobalVar_flag_auto_adjust_shidu = 0;
unsigned char GlobalVar_flag_auto_adjust_yanwu = 0;
unsigned char GlobalVar_flag_auto_adjust_yanwu_2 = 0;
unsigned char GlobalVar_flag_auto_adjust_MQ1 = 0;
unsigned char GlobalVar_flag_auto_adjust_MQ2 = 0;
unsigned char GlobalVar_flag_auto_adjust_ziwaixian = 0;
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
unsigned char GlobalVar_flag_auto_adjust_ph = 0;
unsigned int GlobalVar_flag_auto_adjust = 0;
unsigned int GlobalVar_flag_max30102_inited = 0;
unsigned char GlobalVar_flag_auto_adjust_distance = 0;
unsigned char GlobalVar_flag_auto_adjust_hongwai_duiguan = 0;
unsigned char GlobalVar_flag_scanner_inited = 0;
unsigned char GlobalVar_flag_uart6050_inited = 0;
unsigned char GlobalVar_flag_gps_inited = 0;
unsigned char GlobalVar_flag_sudu_inited = 0;
unsigned char GlobalVar_flag_ph_dan_lin_jia_inited = 0;
unsigned char GlobalVar_flag_gps_parse_success = 0;
unsigned char GlobalVar_flag_hongwaiwendu_inited = 0;
unsigned char GlobalVar_flag_ms53lom_inited = 0;
unsigned char GlobalVar_flag_pm25_inited = 0;
unsigned char GlobalVar_flag_tds_inited = 0;
unsigned char GlobalVar_flag_key_inited = 0;
unsigned char GlobalVar_flag_time_inited = 0;
unsigned char GlobalVar_flag_is_inited_zhendong_DO = 0;
unsigned char GlobalVar_flag_is_inited_zhendong_AO = 0;
unsigned char GlobalVar_flag_key16_inited = 0;
unsigned char GlobalVar_flag_liuliang_inited = 0;
unsigned char GlobalVar_flag_motor_inited = 0;
//-----------------------------
// 阈值变量
unsigned int GlobalVar_Threshold_alert_guangqiang_max = 65;
unsigned int GlobalVar_Threshold_alert_guangqiang_min = 30;
unsigned int GlobalVar_Threshold_alert_guangqiang = 28;
unsigned int GlobalVar_Threshold_alert_wendu = 28;
unsigned int GlobalVar_Threshold_alert_wendu_max = 28;
unsigned int GlobalVar_Threshold_alert_shidu = 60;
unsigned int GlobalVar_Threshold_alert_shidu_max = 60;
unsigned int GlobalVar_Threshold_alert_tds = 50;
unsigned int GlobalVar_Threshold_alert_yanwu = 30;
unsigned int GlobalVar_Threshold_alert_yanwu_2 = 30;
unsigned int GlobalVar_Threshold_alert_MQ1 = 30;
unsigned int GlobalVar_Threshold_alert_MQ2 = 30;
unsigned int GlobalVar_Threshold_alert_ziwaixian = 30;
unsigned int GlobalVar_Threshold_alert_turang = 30;
unsigned int GlobalVar_Threshold_alert_shuiwei = 30;
unsigned int GlobalVar_Threshold_alert_dianya = 80;
unsigned int GlobalVar_Threshold_alert_dianliu = 8;
unsigned int GlobalVar_Threshold_alert_zhendong = 100;
unsigned int GlobalVar_Threshold_alert_zhendong_x = 100;
unsigned int GlobalVar_Threshold_alert_zhendong_y = 100;
unsigned int GlobalVar_Threshold_alert_zhendong_z = 100;
unsigned int GlobalVar_Threshold_alert_yudi = 30;
unsigned int GlobalVar_Threshold_alert_yali = 1000;
unsigned int GlobalVar_Threshold_alert_zhuodu = 50;
unsigned int GlobalVar_Threshold_alert_ph = 5;
unsigned int GlobalVar_Threshold_light_min = 40;
unsigned int GlobalVar_Threshold_alert_distance = 15;

unsigned int GlobalVar_sensor_key_state = 0;

unsigned int GlobalVar_sensor_alert_auto_timer1 = 0;
unsigned int GlobalVar_sensor_alert_t_start1 = 0;
unsigned int GlobalVar_sensor_alert_t_end1 = 0;
unsigned int GlobalVar_Threshold_alert_data1 = 0;
unsigned int GlobalVar_Threshold_alert_data2 = 0;
unsigned int GlobalVar_Threshold_alert_data3 = 0;
unsigned int GlobalVar_Threshold_alert_data4 = 0;

unsigned int GlobalVar_Adjust_key_select_state1 = 0;
unsigned int GlobalVar_Adjust_key_select_state4 = 0;
unsigned int GlobalVar_Adjust_key_select_line = 0;
unsigned int GlobalVar_Adjust_key_modify_number1 = 0;
unsigned int GlobalVar_Adjust_key_modify_number2 = 0;
unsigned int GlobalVar_Adjust_key_modify_number3 = 0;
unsigned int GlobalVar_Adjust_key_modify_number4 = 0;

unsigned char MOTOR_Direction_Control = 2;

//---------------------------------
char GlobalVar_phone_number[13] = {"13007151200"};
char GlobalVar_gps_x[15];
char GlobalVar_gps_y[15];
char time_current_buffer[21] = {"2021-4-11 12:22:21"};
char float_wendu1[8] = {"00.000"};
// char float_wendu2[8] = {"00.000"};
unsigned int zhendong_buffer_100ms[20];
//--------------------------------

// void process_zhendong_AO_100ms()
// {

//   static unsigned int index = 0;

//   zhendong_buffer_100ms[index++] = Sensor_port_Get_AO2();

//   if (index >= (sizeof(zhendong_buffer_100ms)/sizeof(zhendong_buffer_100ms[0])))
//     index = 0;
// }

void process_zhendong_AO_1ms()
{

    static int index = 0; // buffer index .
    static int count_1ms_times = 0;
    static unsigned int max_value = 0;
    unsigned int temp_value = 0;

    temp_value = Get_ADC_channel(5);

    if (max_value < temp_value)
        max_value = temp_value;

    count_1ms_times++;
    if (count_1ms_times >= 100)
    {
        count_1ms_times = 0;
        zhendong_buffer_100ms[index++] = max_value;
        max_value = 0;

        if (index >= (sizeof(zhendong_buffer_100ms) / sizeof(zhendong_buffer_100ms[0])))
            index = 0;
    }
}

void process_zhendong_DO_100ms(void)
{

    static unsigned int index = 0;

    zhendong_buffer_100ms[index++] = GPIO_ReadInputDataBit(Sensor_Port_Zhendong_high, Sensor_Pin_Zhendong_high);

    if (index >= (sizeof(zhendong_buffer_100ms) / sizeof(zhendong_buffer_100ms[0])))
        index = 0;
}

void GetSensor_Zhendong_AO(char *name)
{

    unsigned char index = 0;
    int value = 0;

    static char flag_is_init = 0;
    if (flag_is_init == 0)
    {
        flag_is_init = 1;

        Adc_Init_channel(5);
        GlobalVar_flag_is_inited_zhendong_AO = 1;
    }

    for (index = 0; index < (sizeof(zhendong_buffer_100ms) / sizeof(zhendong_buffer_100ms[0])); index++)
    {
        value += zhendong_buffer_100ms[index];
    }
    value = (value / 20) + 20;

    GlobalVar_sensor_zhendong_AO = value;

    protocol_send_IdValue_int(sensor_protocol, name, GlobalVar_sensor_zhendong_AO);
}

void GetSensor_Zhendong_DO_high(char *name)
{
    GPIO_InitTypeDef GPIO_InitStructure;

    unsigned char index = 0;

    static char flag_is_init = 0;
    if (flag_is_init == 0)
    {
        flag_is_init = 1;

        RCC_APB2PeriphClockCmd(Sensor_Rcc_Zhendong, ENABLE); // 使能PB端口时钟

        GPIO_InitStructure.GPIO_Pin = Sensor_Pin_Zhendong_high;              // 端口配置
        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;                        // 设置成上拉输入
        GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;                    // IO口速度为50MHz
        GPIO_Init(Sensor_Port_Zhendong_high, &GPIO_InitStructure);           // 根据设定参数初始化GPIOB13
        GPIO_ResetBits(Sensor_Port_Zhendong_high, Sensor_Pin_Zhendong_high); // 输出低

        GlobalVar_flag_is_inited_zhendong_DO = 1;
    }

    GlobalVar_sensor_zhendong_DO = 0;

    for (index = 0; index < (sizeof(zhendong_buffer_100ms) / sizeof(zhendong_buffer_100ms[0])); index++)
    {
        if (zhendong_buffer_100ms[index] > 0)
        {
            GlobalVar_sensor_zhendong_DO = 1;
            break;
        }
    }

    protocol_send_IdValue_int(sensor_protocol, name, GlobalVar_sensor_zhendong_DO);
}

void GetSensor_Zhendong_DO_low(char *name)
{
    GPIO_InitTypeDef GPIO_InitStructure;

    unsigned char index = 0;

    static char flag_is_init = 0;
    if (flag_is_init == 0)
    {
        flag_is_init = 1;

        RCC_APB2PeriphClockCmd(Sensor_Rcc_Zhendong, ENABLE); // 使能PB端口时钟

        GPIO_InitStructure.GPIO_Pin = Sensor_Pin_Zhendong_high;              // 端口配置
        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;                        // 设置成上拉输入
        GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;                    // IO口速度为50MHz
        GPIO_Init(Sensor_Port_Zhendong_high, &GPIO_InitStructure);           // 根据设定参数初始化Sensor_Port_Zhendong_high13
        GPIO_ResetBits(Sensor_Port_Zhendong_high, Sensor_Pin_Zhendong_high); // 输出低

        GlobalVar_flag_is_inited_zhendong_DO = 1;
    }

    GlobalVar_sensor_zhendong_DO = 0;

    for (index = 0; index < (sizeof(zhendong_buffer_100ms) / sizeof(zhendong_buffer_100ms[0])); index++)
    {
        if (zhendong_buffer_100ms[index] == 0)
        {
            GlobalVar_sensor_zhendong_DO = 1;
            break;
        }
    }

    protocol_send_IdValue_int(sensor_protocol, name, GlobalVar_sensor_zhendong_DO);
}

void process_liuliang_100ms()
{
    static int times_value = 0, time_do1 = 0, time_do2 = 0;
    static char last_value_do1 = 0, last_value_do2 = 0;
    static char do1_state = 0, do2_state = 0;
    char value_do1 = 0, value_do2 = 0;
    int interval = 0;

    times_value++; // 累计时间

    value_do1 = GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_12); // 采集第一个模块
    value_do2 = GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_13); // 采集第二个模块

    if (value_do1 && !last_value_do1) // 判断模块1是否是刚检测到有人
    {
        time_do1 = times_value; // 记录检测到有人的时间
        do1_state = 1;          // 记录模块1检测就绪状态
    }

    if (value_do2 && !last_value_do2) // 判断模块1是否是刚检测到有人
    {
        time_do2 = times_value; // 记录检测到有人的时间
        do2_state = 1;          // 记录模块2检测就绪状态
    }

    if (do1_state && do2_state) // 判断两个模块是否都检测到过人
    {
        interval = time_do1 > time_do2 ? (time_do1 - time_do2) : time_do2 - time_do1; // 计算两次的时间间隔

        if (interval < 10) // 时间间隔小于10认为有效
        {
            if (time_do1 > time_do2) // 根据时间判断进出
            {
                GlobalVar_sensor_liuliang_enter++; // 记录进入次数
            }
            else if (time_do1 < time_do2) // 根据时间判断进出
            {
                GlobalVar_sensor_liuliang_output++; // 记录出去次数
            }
            do1_state = 0; // 清空就绪状态
            do2_state = 0; // 清空就绪状态
        }
        else
        {
            if (time_do1 > time_do2) // 按照时间丢弃旧的值
            {
                do2_state = 0; // 清空就绪状态
            }
            else
            {
                do1_state = 0; // 清空就绪状态
            }
        }
    }

    last_value_do1 = value_do1; // 记录本次采集的模块1数据
    last_value_do2 = value_do2; // 记录本次采集的模块2数据
}

void GetSensor_diedao_DO(char *name)
{
    GPIO_InitTypeDef GPIO_InitStructure;

    unsigned char index = 0;
    unsigned int zhendong_sum_100ms = 0;

    static char flag_is_init = 0;
    if (flag_is_init == 0)
    {
        flag_is_init = 1;

        RCC_APB2PeriphClockCmd(Sensor_Rcc_Zhendong, ENABLE); // 使能PB端口时钟

        GPIO_InitStructure.GPIO_Pin = Sensor_Pin_Zhendong_high;              // 端口配置
        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;                        // 设置成上拉输入
        GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;                    // IO口速度为50MHz
        GPIO_Init(Sensor_Port_Zhendong_high, &GPIO_InitStructure);           // 根据设定参数初始化Sensor_Port_Zhendong_high13
        GPIO_ResetBits(Sensor_Port_Zhendong_high, Sensor_Pin_Zhendong_high); // 输出低

        GlobalVar_flag_is_inited_zhendong_DO = 1;
    }

    for (index = 0; index < (sizeof(zhendong_buffer_100ms) / sizeof(zhendong_buffer_100ms[0])); index++)
    {
        zhendong_sum_100ms = zhendong_sum_100ms + zhendong_buffer_100ms[index];
    }

    if (zhendong_sum_100ms > 18)
    {
        GlobalVar_sensor_DO_diedao = 1;
    }
    else if (zhendong_sum_100ms < 16)
    {
        GlobalVar_sensor_DO_diedao = 0;
    }

    protocol_send_IdValue_int(sensor_protocol, name, GlobalVar_sensor_DO3);
}

// guangqiang AO5
void GetSensor_Guangqiang(char *name)
{
    int value;
    value = Get_GPIO_Init_Mode_AO_PA5(); // channel 5
    value = (4096 - value) / 32;

    if (value < 0)
        value = 0;

    protocol_send_IdValue_int(sensor_protocol, name, value);

    GlobalVar_sensor_guangqiang = value;
}

// guangqiang AO6
void GetSensor_Yanwu(char *name)
{
    static unsigned int Initial_value = 0;
    static unsigned char temp_value = 0;
    unsigned int value;

    value = Get_GPIO_Init_Mode_AO_PA6(); // channel and repeat times

    if (temp_value < 4)
    {
        Initial_value = value;
        temp_value++;
    }

    if (value > Initial_value)
    {
        value = (value - Initial_value) / 32;
    }
    else
    {
        value = 0;
    }

    protocol_send_IdValue_int(sensor_protocol, name, value);

    GlobalVar_sensor_yanwu = value;
    // GlobalVar_sensor_MQ1 = value;
}

void GetSensor_MQ1(char *name)
{
    static unsigned int Initial_value = 0;
    static unsigned char temp_value = 0;
    unsigned int value;

    value = Get_GPIO_Init_Mode_AO_PA6(); // channel and repeat times

    if (temp_value < 4)
    {
        Initial_value = value;
        temp_value++;
    }

    if (value > Initial_value)
    {
        value = (value - Initial_value) / 32;
    }
    else
    {
        value = 0;
    }

    GlobalVar_sensor_MQ1 = value;

    protocol_send_IdValue_int(sensor_protocol, name, value);
}

// yanwu2 AO7
void GetSensor_Yanwu_2(char *name)
{
    static unsigned int Initial_value = 0;
    static unsigned char temp_value = 0;
    unsigned int value;

    value = Get_GPIO_Init_Mode_AO_PA7(); // channel and repeat times

    if (temp_value < 4)
    {
        Initial_value = value;
        temp_value++;
    }

    if (value > Initial_value)
    {
        value = (value - Initial_value) / 32;
    }
    else
    {
        value = 0;
    }

    GlobalVar_sensor_yanwu_2 = value;
    protocol_send_IdValue_int(sensor_protocol, name, value);
}

void GetSensor_MQ2(char *name)
{
    static unsigned int Initial_value = 0;
    static unsigned char temp_value = 0;
    unsigned int value;

    value = Get_GPIO_Init_Mode_AO_PA7(); // channel and repeat times

    if (temp_value < 4)
    {
        Initial_value = value;
        temp_value++;
    }

    if (value > Initial_value)
    {
        value = (value - Initial_value) / 32;
    }
    else
    {
        value = 0;
    }

    GlobalVar_sensor_MQ2 = value;
    protocol_send_IdValue_int(sensor_protocol, name, value);
}

void GetSensor_MQ3(char *name)
{
    static unsigned int Initial_value = 0;
    static unsigned char temp_value = 0;
    unsigned int value;

    value = Get_GPIO_Init_Mode_AO_PA0(); // channel and repeat times

    if (temp_value < 4)
    {
        Initial_value = value;
        temp_value++;
    }

    if (value > Initial_value)
    {
        value = (value - Initial_value) / 32;
    }
    else
    {
        value = 0;
    }

    GlobalVar_sensor_MQ3 = value;
    protocol_send_IdValue_int(sensor_protocol, name, value);
}

void GetSensor_MQ4(char *name)
{
    static unsigned int Initial_value = 0;
    static unsigned char temp_value = 0;
    unsigned int value;

    value = Get_GPIO_Init_Mode_AO_PA4(); // channel and repeat times

    if (temp_value < 4)
    {
        Initial_value = value;
        temp_value++;
    }

    if (value > Initial_value)
    {
        value = (value - Initial_value) / 32;
    }
    else
    {
        value = 0;
    }

    GlobalVar_sensor_MQ4 = value;
    protocol_send_IdValue_int(sensor_protocol, name, value);
}
// guangqiang AO6
void GetSensor_Ziwaixian(char *name)
{
    static unsigned int Initial_value = 0;
    static unsigned char temp_value = 0;
    unsigned int value;

    value = Get_GPIO_Init_Mode_AO_PA6(); // channel and repeat times

    if (temp_value < 4)
    {
        Initial_value = value;
        temp_value++;
    }

    if (value > Initial_value)
    {
        value = value / 32;
    }
    else
    {
        value = 0;
    }

    GlobalVar_sensor_ziwaixian = value;

    protocol_send_IdValue_int(sensor_protocol, name, value);
}

// yudi  AO1
void GetSensor_Yudi_1(char *name)
{
    unsigned int value;

    value = Get_GPIO_Init_Mode_AO_PA1(); // channel and repeat times
    value = value / 32;

    value = value > 128 ? 128 : value;
    value = value < 40 ? 40 : value;
    value = 128 - value;

    GlobalVar_sensor_yudi = value;

    protocol_send_IdValue_int(sensor_protocol, name, value);
}

// yudi  AO1
void GetSensor_Yudi_2(char *name)
{
    unsigned int value;

    value = Get_GPIO_Init_Mode_AO_PA5(); // channel and repeat times
    value = value / 32;

    value = value > 128 ? 128 : value;
    value = value < 40 ? 40 : value;
    value = 128 - value;

    GlobalVar_sensor_yudi = value;

    protocol_send_IdValue_int(sensor_protocol, name, value);
}

// yudi  AO1
void GetSensor_Shuiwei_1(char *name)
{
    unsigned int value;

    value = Get_GPIO_Init_Mode_AO_PA0(); // channel and repeat times
    value = value / 32;

    value = value < 40 ? 40 : value;
    value = value > 65 ? 65 : value;
    value = value - 40;
    value = value * 4;

    GlobalVar_sensor_shuiwei = value;
    protocol_send_IdValue_int(sensor_protocol, name, value);
}

// yudi  AO1
void GetSensor_Shuiwei_2(char *name)
{
    unsigned int value;

    value = Get_GPIO_Init_Mode_AO_PA5(); // channel and repeat times
    value = value / 32;

    value = value < 40 ? 40 : value;
    value = value > 65 ? 65 : value;
    value = value - 40;
    value = value * 4;

    GlobalVar_sensor_shuiwei = value;
    protocol_send_IdValue_int(sensor_protocol, name, value);
}

// dianliu  A1  100mA
void GetSensor_Dianliu(char *name)
{
    static unsigned char reserve_value = 0, time_value = 0;
    static unsigned char flag_is_init = 0;
    unsigned int value;
    unsigned long count_num;

    if (flag_is_init == 0)
    {
        flag_is_init = 1;
        Adc_Init_channel(1);
    }

    value = Get_ADC_channel(1); // channel and repeat times

    // 2048  2080

    if (2048 > value)
    {
        count_num = 2048 - value;
    }
    else
    {
        count_num = value - 2048;
    }

    //  (count_num /4096 )* (3.3 *1000)  /100  *1000  /10   === 10ma
    //  (count_num /4096 )* (3300)
    //  (count_num *33 / 41)   ====== 10ma
    //  (count_num *33 / 41)   =====100ma

    value = count_num * 33 / 410; // get 100mA

    if (time_value < 3)
    {
        reserve_value = value;
        time_value++;
    }

    if (value > reserve_value)
    {
        value = value - reserve_value;
    }
    else
    {
        value = reserve_value - value;
    }

    if (value < 3)
        value = 0;

    GlobalVar_sensor_dianliu = value;

    protocol_send_IdValue_int(sensor_protocol, name, GlobalVar_sensor_dianliu);
}

// dianya  A0  110mv
void GetSensor_Dianya(char *name)
{
    unsigned int value;

    value = Get_GPIO_Init_Mode_AO_PA0(); // channel and repeat times
    value = value / 32;

    value = value * 5 * 33 / 128; // 100mv

    GlobalVar_sensor_dianya = value;
    protocol_send_IdValue_int(sensor_protocol, name, value);
}

// turang  AO4
// 功能：获取传感器Turang的值
// 参数：name：传感器Turang的名称
void GetSensor_Turang(char *name)
{
    unsigned int value;

    value = Get_GPIO_Init_Mode_AO_PA4(); // channel and repeat times
    value = value / 32;

    value = value > 127 ? 127 : value;
    value = 127 - value;

    protocol_send_IdValue_int(sensor_protocol, name, value);

    GlobalVar_sensor_turang = value;
}

// A7
void GetSensor_Zhuodu(char *name)
{
    unsigned int value;

    value = Get_GPIO_Init_Mode_AO_PA7(); // channel and repeat times
    value = value / 32;

    if (value > 128)
        value = 128;
    value = 128 - value;

    GlobalVar_sensor_zhuodu = value;
    protocol_send_IdValue_int(sensor_protocol, name, value);
}

// A6
void GetSensor_PH(char *name)
{
    unsigned int temp_value;
    unsigned int value;

    value = Get_GPIO_Init_Mode_AO_PA6(); // channel and repeat times

    // value -   PH
    // 82    -  9.18
    // 115   -  4.0
    // 98    -  6.86
    value = value / 32;
    if (value >= 98)
    {
        temp_value = ((value - 98) * 10 / 55);
        if (temp_value > 7)
            temp_value = 7;
        value = 7 - temp_value;
    }
    else
    {
        temp_value = ((98 - value) * 10 / 62);
        if (temp_value > 7)
            temp_value = 7;
        value = 7 + temp_value;
    }

    //     if (value > 3178)
    // {
    //     value = 3178;
    // }
    // if (value < 686)
    // {
    //     value = 686;
    // }

    // value = (value - 508) / 178;

    // value = 14 - value;

    // if (value < 1)
    // {
    //     value = 0;
    // }

    GlobalVar_sensor_ph = value;

    protocol_send_IdValue_int(sensor_protocol, name, value);
}

// A6
void GetSensor_PH_float(char *name)
{
    float value;
    float temp_value;
    char buff[30];

    value = Get_GPIO_Init_Mode_AO_PA6(); // channel and repeat times
    value = value / 32;
    // value -   PH
    // 82    -  9.18
    // 115   -  4.0
    // 98    -  6.86

    if (value >= 98)
    {
        temp_value = ((value - 98) * 10 / 55);
        if (temp_value > 7)
            temp_value = 7;
        value = 7 - temp_value;
    }
    else
    {
        temp_value = ((98 - value) * 10 / 62);
        if (temp_value > 7)
            temp_value = 7;
        value = 7 + temp_value;
    }

    GlobalVar_sensor_ph_float = value;

    sprintf(buff, "%f", GlobalVar_sensor_ph_float);

    protocol_send_IdValue_str(sensor_protocol, name, buff);
}

// A1
void GetSensor_AO1(char *name)
{
    unsigned int value;

    value = Get_GPIO_Init_Mode_AO_PA1(); // channel and repeat times
    value = value / 32;

    protocol_send_IdValue_int(sensor_protocol, name, value);

    GlobalVar_sensor_turang = value;
}

// B12
void GetSensor_DO1(char *name)
{
    unsigned char value;

    value = Get_GPIO_Init_Mode_DO_PB12();

    GlobalVar_sensor_DO1 = value;

    protocol_send_IdValue_int(sensor_protocol, name, value);
}

// B13
void GetSensor_DO2(char *name)
{
    unsigned char value;

    value = Get_GPIO_Init_Mode_DO_PB13();

    GlobalVar_sensor_DO2 = value;

    protocol_send_IdValue_int(sensor_protocol, name, value);
}

// B12
void GetSensor_hongwai_duiguan_6(char *name)
{
    unsigned char value;

    value = Get_GPIO_Init_Mode_DO_PB12();

    GlobalVar_sensor_hongwai_duiguan = !value;

    protocol_send_IdValue_int(sensor_protocol, name, GlobalVar_sensor_hongwai_duiguan);
}

// B3
void GetSensor_hongwai_duiguan_5(char *name)
{
    unsigned char value;

    value = Get_GPIO_Init_Mode_DO_PB3();

    GlobalVar_sensor_hongwai_duiguan = !value;

    protocol_send_IdValue_int(sensor_protocol, name, GlobalVar_sensor_hongwai_duiguan);
}

// B4
void GetSensor_hongwai_duiguan_4(char *name)
{
    unsigned char value;

    value = Get_GPIO_Init_Mode_DO_PB4();

    GlobalVar_sensor_hongwai_duiguan = !value;

    protocol_send_IdValue_int(sensor_protocol, name, GlobalVar_sensor_hongwai_duiguan);
}

// B5
void GetSensor_hongwai_duiguan_3(char *name)
{
    unsigned char value;

    value = Get_GPIO_Init_Mode_DO_PB15();

    GlobalVar_sensor_hongwai_duiguan = !value;

    protocol_send_IdValue_int(sensor_protocol, name, GlobalVar_sensor_hongwai_duiguan);
}

// B0
void GetSensor_hongwai_duiguan_1(char *name)
{
    unsigned char value;

    value = Get_GPIO_Init_Mode_DO_PB0();

    GlobalVar_sensor_hongwai_duiguan = !value;

    protocol_send_IdValue_int(sensor_protocol, name, GlobalVar_sensor_hongwai_duiguan);
}

// B1
void GetSensor_hongwai_duiguan_2(char *name)
{
    unsigned char value;

    value = Get_GPIO_Init_Mode_DO_PB1();

    GlobalVar_sensor_hongwai_duiguan = !value;

    protocol_send_IdValue_int(sensor_protocol, name, GlobalVar_sensor_hongwai_duiguan);
}

// B14
void GetSensor_DO3(char *name)
{
    unsigned char value;

    value = Get_GPIO_Init_Mode_DO_PB14();

    GlobalVar_sensor_DO3 = value;

    protocol_send_IdValue_int(sensor_protocol, name, value);
}

void SetSensor_Deng_1(unsigned char value)
{
    Set_GPIO_Init_Mode_DO_PB9(value);
}

void SetSensor_Beep_1(unsigned char value)
{
    Set_GPIO_Init_Mode_DO_PB10(value);
}

void SetSensor_Beep_interval_1(unsigned char value)
{
    if (!GlobalVar_sensor_beep_init)
    {
        GlobalVar_sensor_beep_init = value;
    }
    GlobalVar_sensor_beep_interval = value;

    // Set_GPIO_Init_Mode_DO_PB10(value);
}

void SetSensor_Deng_2(unsigned char value)
{
    Set_GPIO_Init_Mode_DO_PB12(value);
}

void SetSensor_Deng_3(unsigned char value)
{
    Set_GPIO_Init_Mode_DO_PB13(value);
}

void SetSensor_Deng_4(unsigned char value)
{
    Set_GPIO_Init_Mode_DO_PB14(value);
}

void SetSensor_Jidianqi_4(unsigned char value)
{
    Set_GPIO_Init_Mode_DO_PB8(value);
}

void SetSensor_Jidianqi_3(unsigned char value)
{
    Set_GPIO_Init_Mode_DO_PB7(value);
}

void SetSensor_Jidianqi_2(unsigned char value)
{
    Set_GPIO_Init_Mode_DO_PB6(value);
}

void SetSensor_Jidianqi_1(unsigned char value)
{
    Set_GPIO_Init_Mode_DO_PB5(value);
}

void SetSensor_Fan_1(unsigned char value)
{
    Set_GPIO_Init_Mode_DO_PB14(value);
}

void SetSensor_Fan_2(unsigned char value)
{
    Set_GPIO_Init_Mode_DO_PB15(value);
}

void GetSensor_max30102(char *xinlv, char *xueyang)
{

    static unsigned char flag_is_init = 0;
    if (flag_is_init == 0)
    {
        flag_is_init = 1;

        GlobalVar_flag_max30102_inited = 1;

        max30102_init_main();
    }

    protocol_send_IdValue_int(sensor_protocol, xinlv, GlobalVar_sensor_max30102_xinlv);
    protocol_send_IdValue_int(sensor_protocol, xueyang, GlobalVar_sensor_max30102_xueyang);
}

void GetSensor_Renti(char *name)
{
    unsigned int value;
    static unsigned char flag_is_init = 0;
    if (flag_is_init == 0)
    {
        flag_is_init = 1;
        InitSensor_Renti();
    }

    value = Get_Renti();

    protocol_send_IdValue_int(sensor_protocol, name, value);

    GlobalVar_sensor_RenTi = value;
}

void GetSensor_Renti_2(char *name)
{
    unsigned int value;
    static unsigned char flag_is_init = 0;
    if (flag_is_init == 0)
    {
        flag_is_init = 1;
        InitSensor_Renti_2();
    }

    value = Get_Renti_2();

    protocol_send_IdValue_int(sensor_protocol, name, value);

    GlobalVar_sensor_RenTi_2 = value;
}

void GetSensor_Voice(char *name)
{
    unsigned int value;
    static unsigned char flag_is_init = 0;
    if (flag_is_init == 0)
    {
        flag_is_init = 1;
        InitSensor_Voice();
    }

    value = Get_Voice();

    protocol_send_IdValue_int(sensor_protocol, name, value);

    GlobalVar_sensor_voice = value;
}

void GetSensor_Huoyan(char *name)
{
    unsigned int value;
    static unsigned char flag_is_init = 0;
    if (flag_is_init == 0)
    {
        flag_is_init = 1;
        InitSensor_Huoyan();
    }

    value = Get_Huoyan();

    protocol_send_IdValue_int(sensor_protocol, name, value);

    GlobalVar_sensor_huoyan = value;
}

void GetSensor_Key(char *name)
{
    // unsigned int value;
    static unsigned char flag_is_init = 0;
    if (flag_is_init == 0)
    {
        flag_is_init = 1;
        key_button_init();
        GlobalVar_flag_key_inited = 1;
    }

    if (GlobalVar_sensor_key_press_1)
    {
        GlobalVar_sensor_key_press_1 = 0;

        protocol_send_IdValue_int(sensor_protocol, name, GlobalVar_sensor_key_vlaue_1);
    }
}

void GetSensor_Key_2(char *name)
{
    // unsigned int value;
    static unsigned char flag_is_init = 0;
    if (flag_is_init == 0)
    {
        flag_is_init = 1;
        key_button_init();
        GlobalVar_flag_key_inited = 1;
    }

    if (GlobalVar_sensor_key_press_2)
    {
        GlobalVar_sensor_key_press_2 = 0;

        protocol_send_IdValue_int(sensor_protocol, name, GlobalVar_sensor_key_vlaue_2);
    }
}

void GetSensor_Dht11(char *name_wendu, char *name_shidu)
{
    unsigned char wendu = 0;
    unsigned char shidu = 0;
    static unsigned char flag_is_init = 0;
    if (flag_is_init == 0)
    {
        flag_is_init = 1;
        DHT11_Init();
    }

    DHT11_Read_Data(&wendu, &shidu);

    protocol_send_IdValue_int(sensor_protocol, name_wendu, wendu);
    protocol_send_IdValue_int(sensor_protocol, name_shidu, shidu);

    GlobalVar_sensor_dht11_wendu = wendu;
    GlobalVar_sensor_dht11_shidu = shidu;
}

void GetSensor_Yali(char *name)
{
    static unsigned int temp_value = 0, time_value = 0;
    unsigned int value;
    static unsigned char flag_is_init = 0;
    if (flag_is_init == 0)
    {
        flag_is_init = 1;
        yali_init();

        yali_Weight_calibration(); // 压力传感器校准
    }

    value = yali_Get_Weight();

    if (time_value < 3)
    {
        temp_value = value;
        time_value++;
    }

    if (value > temp_value)
    {
        value = value - temp_value;
    }
    else
    {
        value = 0;
    }
    protocol_send_IdValue_int(sensor_protocol, name, value);

    GlobalVar_sensor_yali = value;
}

void GetSensor_Xueya(char *name)
{
    unsigned int value;
    static unsigned char flag_is_init = 0;
    if (flag_is_init == 0)
    {
        flag_is_init = 1;
        yali_init();

        yali_Weight_calibration(); // 压力传感器校准
    }

    value = yali_Get_Weight();

    value = value / 500;

    if (value < 50)
        value = 0;

    if (value)
    {
        GlobalVar_sensor_yali = value;
    }
    protocol_send_IdValue_int(sensor_protocol, name, GlobalVar_sensor_yali);
}

void GetSensor_Chaoshengbo(char *name)
{
    unsigned int value;
    static unsigned char flag_is_init = 0;
    if (flag_is_init == 0)
    {
        flag_is_init = 1;
        UltrasonicWave_Configuration_channel(3);
    }

    value = UltrasonicWave_GetDistance_ch3();

    protocol_send_IdValue_int(sensor_protocol, name, value);

    GlobalVar_sensor_distance = value;
}

void GetSensor_Chaoshengbo_2(char *name)
{
    unsigned int value;
    static unsigned char flag_is_init = 0;
    if (flag_is_init == 0)
    {
        flag_is_init = 1;
        UltrasonicWave_Configuration_channel(2);
    }

    value = UltrasonicWave_GetDistance_ch2();

    protocol_send_IdValue_int(sensor_protocol, name, value);

    GlobalVar_sensor_distance_2 = value;
}

void GetSensor_Ds18b20(char *name)
{
    unsigned int value;
    static unsigned char flag_is_init = 0;
    if (flag_is_init == 0)
    {
        flag_is_init = 1;
        ds18b20_start();
    }

    value = ds18b20_read();

    // value = value / 10;

    GlobalVar_sensor_ds18b20_wendu = value;

    protocol_send_IdValue_int(sensor_protocol, name, value);
}

void GetSensor_Ds18b20_float(char *name)
{
    float value;
    float temp_value;
    static unsigned char flag_is_init = 0;
    if (flag_is_init == 0)
    {
        flag_is_init = 1;
        ds18b20_start();
    }

    value = ds18b20_read_float();

    temp_value = value - ((int)value);

    GlobalVar_sensor_ds18b20_wendu = (int)(value) / 16;

    value = (float)GlobalVar_sensor_ds18b20_wendu + temp_value;

    protocol_send_IdValue_float(sensor_protocol, name, value);
}

unsigned char GetSensor_Rc522(char *name)
{
    char state;
    unsigned char value[10];
    char temp[20];
    unsigned int len;

    static unsigned char flag_is_init = 0;
    if (flag_is_init == 0)
    {
        flag_is_init = 1;
        RC522_GPIO_init();         // 引脚初始化rc522
        PcdReset();                // 复位RC522
        PcdAntennaOff();           // 关闭天线
        PcdAntennaOn();            // 开启天线
        M500PcdConfigISOType('A'); // 选择模式
    }

    state = PcdRequest(PICC_REQIDL, value);
    if (!state)
    {
        state = PcdAnticoll(value);

        if (state == MI_OK)
        {
            len = sprintf(temp, "%02X%02X%02X%02X", value[0], value[1], value[2], value[3]);
            temp[len] = 0;

            // OLED_P6x8Str(0,4,temp);

            protocol_send_IdValue_str(sensor_protocol, name, temp);

            // if(GlobalVar_flag_auto_adjust_churuku)
            // {
            //     protocol_send_IdValue_str(sensor_protocol, "churuku_inout", "out");
            // }
            // else
            // {
            //     protocol_send_IdValue_str(sensor_protocol, "churuku_inout", "in");
            // }

            return 1;
        }
    }

    return 0;
}

//----
// B12
void SetSensor_SD_cesu(char *name)
{
    static unsigned char flag_is_init = 0;
    unsigned int value;

    GPIO_InitTypeDef GPIO_InitStructure;

    if (flag_is_init == 0)
    {
        flag_is_init = 1;

        RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE); // 使能PG,PD端口时钟
        GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;            // 端口配置
        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;         // 设置成上拉输入 GPIO_Mode_IPU  GPIO_Mode_Out_PP
        GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;     // IO口速度为50MHz
        GPIO_Init(GPIOB, &GPIO_InitStructure);                // 根据设定参数初始化GPIOA.8
        GPIO_SetBits(GPIOB, GPIO_Pin_12);                     // 输出高 -- 低电平触发

        GlobalVar_flag_sudu_inited = 1;
    }
    value = GlobalVar_sensor_sudu;

    protocol_send_IdValue_int(sensor_protocol, name, value);
}

void GetSensor_liuliang(char *enter, char *output)
{
    static unsigned char flag_is_init = 0;
    GPIO_InitTypeDef GPIO_InitStructure;

    // int difference_value = 0;

    if (flag_is_init == 0)
    {
        flag_is_init = 1;

        RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE); // 使能PG,PD端口时钟

        GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;        // 端口配置
        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;     // 设置成上拉输入
        GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; // IO口速度为50MHz
        GPIO_Init(GPIOB, &GPIO_InitStructure);            // 根据设定参数初始化GPIOA.8

        GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;        // 端口配置
        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;     // 设置成上拉输入
        GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; // IO口速度为50MHz
        GPIO_Init(GPIOB, &GPIO_InitStructure);            // 根据设定参数初始化GPIOA.8

        GlobalVar_flag_liuliang_inited = 1;
    }
    // difference_value = GlobalVar_sensor_liuliang_enter - GlobalVar_sensor_liuliang_output;
    protocol_send_IdValue_int(sensor_protocol, enter, GlobalVar_sensor_liuliang_enter);
    protocol_send_IdValue_int(sensor_protocol, output, GlobalVar_sensor_liuliang_output);
    // protocol_send_IdValue_int(sensor_protocol, difference, difference_value);
}

void GetSensor_shuiliu(char *name)
{
    static unsigned char flag_is_init = 0;
    static unsigned int GlobalVar_sensor_old_maichongjishu = 0;
    unsigned int GlobalVar_sensor_current_maichongjishu = 0;

    if (flag_is_init == 0)
    {
        flag_is_init = 1;

        InitSensor_maichongjishu();
    }

    GlobalVar_sensor_current_maichongjishu = (maichongjishu - GlobalVar_sensor_old_maichongjishu); // 每分钟多少升（7.5不好计算，写的8）

    GlobalVar_sensor_current_maichongjishu = GlobalVar_sensor_current_maichongjishu / 8;

    protocol_send_IdValue_int(sensor_protocol, name, GlobalVar_sensor_current_maichongjishu);
}

void GetSensor_maichongjishu(char *name)
{
    static unsigned char flag_is_init = 0;
    if (flag_is_init == 0)
    {
        flag_is_init = 1;

        InitSensor_maichongjishu();
    }

    GlobalVar_sensor_maichongjishu = maichongjishu;

    protocol_send_IdValue_int(sensor_protocol, name, maichongjishu);
}

void GetSensor_ms53lom_juli(char *name)
{

    static unsigned char flag_is_init = 0;

    if (flag_is_init == 0)
    {
        flag_is_init = 1;
        UART1_Init(115200); // v1
        // UART1_Init(9600);  //v2
        GlobalVar_flag_ms53lom_inited = 1;
    }

    ms53lom_trigger((void (*)(unsigned char *, unsigned int))UART1_Send_BUFF);

    protocol_send_IdValue_int(sensor_protocol, name, GlobalVar_sensor_hongwai_juli);
}

//---串口采集

void GetSensor_hongwai_wendu(char *name)
{

    static unsigned char flag_is_init = 0;

    if (flag_is_init == 0)
    {
        flag_is_init = 1;
        UART1_Init(115200); // v1
        // UART1_Init(9600);  //v2
        GlobalVar_flag_hongwaiwendu_inited = 1;
    }

    hongwaiwendu_trigger((void (*)(unsigned char *, unsigned int))UART1_Send_BUFF);

    protocol_send_IdValue_int(sensor_protocol, name, GlobalVar_sensor_hongwai_wendu);
}

void GetSensor_ph_dan_lin_jia(char *ph, char *dan, char *lin, char *jia)
{

    static unsigned char flag_is_init = 0;

    if (flag_is_init == 0)
    {
        flag_is_init = 1;
        UART1_Init(9600); // v2
        GlobalVar_flag_ph_dan_lin_jia_inited = 1;
    }

    ph_dan_lin_jia_trigger((void (*)(unsigned char *, unsigned int))UART1_Send_BUFF);

    protocol_send_IdValue_int(sensor_protocol, ph, GlobalVar_sensor_hongwai_wendu);
    protocol_send_IdValue_int(sensor_protocol, dan, GlobalVar_sensor_hongwai_wendu);
    protocol_send_IdValue_int(sensor_protocol, lin, GlobalVar_sensor_hongwai_wendu);
    protocol_send_IdValue_int(sensor_protocol, jia, GlobalVar_sensor_hongwai_wendu);
}

void GetSensor_pm25(char *name)
{

    static unsigned char flag_is_init = 0;

    if (flag_is_init == 0)
    {
        flag_is_init = 1;
        // UART1_Init(115200); //v1
        UART1_Init(9600); // v2
        GlobalVar_flag_pm25_inited = 1;
    }

    protocol_send_IdValue_int(sensor_protocol, name, GlobalVar_sensor_pm25);
}

void GetSensor_uart6050(char *x, char *y, char *z)
{

    static unsigned char flag_is_init = 0;
    if (flag_is_init == 0)
    {
        flag_is_init = 1;

        UART1_Init(115200);

        GlobalVar_flag_uart6050_inited = 1;
    }

    uart6050_trigger((void (*)(unsigned char *, unsigned int))UART1_Send_BUFF);

    protocol_send_IdValue_int(sensor_protocol, x, GlobalVar_sensor_6050_x);
    protocol_send_IdValue_int(sensor_protocol, y, GlobalVar_sensor_6050_y);
    protocol_send_IdValue_int(sensor_protocol, z, GlobalVar_sensor_6050_z);
}

void GetSensor_tds(char *tds, char *wendu)
{

    static unsigned char flag_is_init = 0;
    if (flag_is_init == 0)
    {
        flag_is_init = 1;

        UART1_Init(9600);

        GlobalVar_flag_tds_inited = 1;
    }

    tds_trigger((void (*)(unsigned char *, unsigned int))UART1_Send_BUFF);

    protocol_send_IdValue_int(sensor_protocol, tds, GlobalVar_sensor_TDS);
    protocol_send_IdValue_int(sensor_protocol, wendu, GlobalVar_sensor_TDS_wendu);
}

void GetSensor_GPS(char *gps_x, char *gps_y)
{
    static unsigned char flag_is_init = 0;
    if (flag_is_init == 0)
    {
        flag_is_init = 1;

        UART1_Init(9600);

        GlobalVar_flag_gps_inited = 1;
    }
    if (GlobalVar_flag_gps_parse_success)
    {
        protocol_send_IdValue_str(sensor_protocol, gps_x, GlobalVar_gps_x);
        protocol_send_IdValue_str(sensor_protocol, gps_y, GlobalVar_gps_y);
    }
}

void SetSensor_yuyin_bobao(unsigned char value) // 语音播报
{
    static unsigned char flag_is_init = 0;
    static const unsigned char yuyin_bobao[70] = {
        0x7E, 0x05, 0x41, 0x00, 0x01, 0x45, 0xEF,
        0x7E, 0x05, 0x41, 0x00, 0x02, 0x46, 0xEF,
        0x7E, 0x05, 0x41, 0x00, 0x03, 0x47, 0xEF,
        0x7E, 0x05, 0x41, 0x00, 0x04, 0x40, 0xEF,
        0x7E, 0x05, 0x41, 0x00, 0x05, 0x41, 0xEF,
        0x7E, 0x05, 0x41, 0x00, 0x06, 0x42, 0xEF,
        0x7E, 0x05, 0x41, 0x00, 0x07, 0x43, 0xEF,
        0x7E, 0x05, 0x41, 0x00, 0x08, 0x4C, 0xEF,
        0x7E, 0x05, 0x41, 0x00, 0x09, 0x4D, 0xEF,
        0x7E, 0x05, 0x41, 0x00, 0x0A, 0x4E, 0xEF};

    if (flag_is_init == 0)
    {
        flag_is_init = 1;
        UART1_Init(9600); // v2
    }

    if (value > 10)
        value = 10;
    if (value < 1)
        value = 1;

    UART1_Send_BUFF((yuyin_bobao + (value - 1) * 7), 7);
}

//---

void SetSensor_Ws2812b_rgb(unsigned char red, unsigned char green, unsigned char blue)
{
    static unsigned char flag_is_init = 0;
    if (flag_is_init == 0)
    {
        flag_is_init = 1;

        ws2812b_init();
    }

    ws2812b_rgb(red, green, blue);
}

void SetSensor_Ws2812b_red(unsigned char red)
{
    static unsigned char flag_is_init = 0;
    if (flag_is_init == 0)
    {
        flag_is_init = 1;

        ws2812b_init();
    }

    ws2812b_red(red);
}

void SetSensor_Ws2812b_green(unsigned char green)
{
    static unsigned char flag_is_init = 0;
    if (flag_is_init == 0)
    {
        flag_is_init = 1;

        ws2812b_init();
    }

    ws2812b_green(green);
}

void SetSensor_Ws2812b_blue(unsigned char blue)
{
    static unsigned char flag_is_init = 0;
    if (flag_is_init == 0)
    {
        flag_is_init = 1;

        ws2812b_init();
    }

    ws2812b_blue(blue);
}

void SetSensor_Ws2812b_rgb_2(unsigned char red, unsigned char green, unsigned char blue)
{
    static unsigned char flag_is_init = 0;
    if (flag_is_init == 0)
    {
        flag_is_init = 1;

        ws2812b_init_2();
    }

    ws2812b_rgb_2(red, green, blue);
}

void SetSensor_Ws2812b_red_2(unsigned char red)
{
    static unsigned char flag_is_init = 0;
    if (flag_is_init == 0)
    {
        flag_is_init = 1;

        ws2812b_init_2();
    }

    ws2812b_red_2(red);
}

void SetSensor_Ws2812b_green_2(unsigned char green)
{
    static unsigned char flag_is_init = 0;
    if (flag_is_init == 0)
    {
        flag_is_init = 1;

        ws2812b_init_2();
    }

    ws2812b_green_2(green);
}

void SetSensor_Ws2812b_blue_2(unsigned char blue)
{
    static unsigned char flag_is_init = 0;
    if (flag_is_init == 0)
    {
        flag_is_init = 1;

        ws2812b_init_2();
    }

    ws2812b_blue_2(blue);
}

void SetSensor_Ws2812b_rgb_3(unsigned char red, unsigned char green, unsigned char blue)
{
    static unsigned char flag_is_init = 0;
    if (flag_is_init == 0)
    {
        flag_is_init = 1;

        ws2812b_init_3();
    }

    ws2812b_rgb_3(red, green, blue);
}

void SetSensor_Ws2812b_red_3(unsigned char red)
{
    static unsigned char flag_is_init = 0;
    if (flag_is_init == 0)
    {
        flag_is_init = 1;

        ws2812b_init_3();
    }

    ws2812b_red_3(red);
}

void SetSensor_Ws2812b_green_3(unsigned char green)
{
    static unsigned char flag_is_init = 0;
    if (flag_is_init == 0)
    {
        flag_is_init = 1;

        ws2812b_init_3();
    }

    ws2812b_green_3(green);
}

void SetSensor_Ws2812b_blue_3(unsigned char blue)
{
    static unsigned char flag_is_init = 0;
    if (flag_is_init == 0)
    {
        flag_is_init = 1;

        ws2812b_init_3();
    }

    ws2812b_blue_3(blue);
}

void SetSensor_Ws2812b_rgb_4(unsigned char red, unsigned char green, unsigned char blue)
{
    static unsigned char flag_is_init = 0;
    if (flag_is_init == 0)
    {
        flag_is_init = 1;

        ws2812b_init_4();
    }

    ws2812b_rgb_4(red, green, blue);
}

void SetSensor_Ws2812b_red_4(unsigned char red)
{
    static unsigned char flag_is_init = 0;
    if (flag_is_init == 0)
    {
        flag_is_init = 1;

        ws2812b_init_4();
    }

    ws2812b_red_4(red);
}

void SetSensor_Ws2812b_green_4(unsigned char green)
{
    static unsigned char flag_is_init = 0;
    if (flag_is_init == 0)
    {
        flag_is_init = 1;

        ws2812b_init_4();
    }

    ws2812b_green_4(green);
}

void SetSensor_Ws2812b_blue_4(unsigned char blue)
{
    static unsigned char flag_is_init = 0;
    if (flag_is_init == 0)
    {
        flag_is_init = 1;

        ws2812b_init_4();
    }

    ws2812b_blue_4(blue);
}

void SetSensor_PWM(unsigned char value)
{
    static unsigned char flag_is_init = 0;
    if (flag_is_init == 0)
    {
        flag_is_init = 1;

        // TIM1_PWM_Init( 100, 72);
        TIM1_PWM_Init(100, 1);
    }

    SetSensor_Pwm10(value);
}

void SetSensor_PWM_2(unsigned char value)
{
    static unsigned char flag_is_init = 0;
    if (flag_is_init == 0)
    {
        flag_is_init = 1;

        // TIM1_PWM_Init( 100, 72);
        TIM1_PWM_Init(100, 1);
    }

    SetSensor_Pwm11(value);
}

void SetSensor_duoji(unsigned int value)
{
    unsigned int temp_value = 0;
    static unsigned char flag_is_init = 0;

    if (flag_is_init == 0)
    {
        flag_is_init = 1;

        TIM1_PWM_Init(2000, 720);
    }

    if (value > 180)
        value = 180;

    temp_value = value;

    temp_value = 1750 + (temp_value * 20) / 18;

    TIM_SetCompare4(TIM1, temp_value);
}

void SetSensor_OLED_Sring(unsigned char x, unsigned char y, unsigned char *buff, unsigned char Char_Size)
{
    static unsigned char flag_is_init = 0;
    if (flag_is_init == 0)
    {
        flag_is_init = 1;

        OLED_Init();       // oled初始化
        OLED_Display_On(); // oled开启显示
    }

    OLED_ShowString(x, y, buff, Char_Size);
}

void SetSensor_OLED_Chinese(unsigned char x, unsigned char y, int index)
{
    static unsigned char flag_is_init = 0;
    if (flag_is_init == 0)
    {
        flag_is_init = 1;

        OLED_Init();       // oled初始化
        OLED_Display_On(); // oled开启显示
    }

    OLED_ShowCHinese(x, y, index);
}

void SetSensor_Sms(char *sms)
{
    protocol_send_start(sensor_protocol); //
    protocol_send_IdValue_str(sensor_protocol, "cfg_phone_number", GlobalVar_phone_number);
    protocol_send_IdValue_str(sensor_protocol, "sms", sms);
    protocol_send_complete(sensor_protocol, (void (*)(const unsigned char *src, int len))UART2_Send_BUFF);
}

void SetSensor_phone_number(const char *number)
{
    int index = 0;
    const char *pointer = number;

    for (; index < 11; index++)
    {
        GlobalVar_phone_number[index] = *pointer++;
    }

    GlobalVar_phone_number[11] = 0;
}

void SetSensor_time_update(const char *value)
{
    char index = 0;
    const char *p_value = value;

    static unsigned char flag_is_init = 0;

    if (flag_is_init == 0)
    {
        flag_is_init = 1;

        GlobalVar_flag_time_inited = 1;
    }

    if (*p_value == '2')
    {
        while (index < 19)
        {
            time_current_buffer[index++] = *p_value++;
        }
        time_current_buffer[index] = 0;
    }
}

void SetSensor_float_wendu(const char *value)
{
    char index = 0;

    const char *p_value = value;

    if (*p_value >= '0' && *p_value <= '9')
    {
        while (index < 6)
        {
            float_wendu1[index++] = *p_value++;
        }
        float_wendu1[index] = 0;
    }
}

void SetSensor_time_OLED_show_1s(void)
{
    static unsigned int record_time = 0;

    unsigned int compare_timestamp = 0;

    unsigned int diff_time = 0;

    static char time_buffer_date[12];
    static char time_buffer_time[10];

    char *p_value = time_current_buffer;

    unsigned char index = 0;

    record_time++;

    compare_timestamp = ((time_current_buffer[14] - '0') * 10 + (time_current_buffer[15] - '0')) * 60 +
                        ((time_current_buffer[17] - '0') * 10 + (time_current_buffer[18] - '0'));

    diff_time = compare_timestamp > record_time ? (compare_timestamp - record_time) : (record_time - compare_timestamp);

    if (diff_time > 3)
    {
        record_time = compare_timestamp;
    }

    while (index < 11)
    {
        time_buffer_date[index++] = *p_value++;
    }

    time_buffer_date[4] = '-';
    time_buffer_date[7] = '-';
    time_buffer_date[10] = 0;

    index = 0;
    while (index < 8)
    {
        time_buffer_time[index++] = *p_value++;
    }

    time_buffer_time[2] = ':';
    time_buffer_time[5] = ':';
    time_buffer_time[8] = 0;

    time_buffer_time[7] = (record_time % 60 % 10) + '0';
    time_buffer_time[6] = (record_time % 60 / 10) + '0';

    time_buffer_time[4] = (record_time / 60 % 10) + '0';
    time_buffer_time[3] = (record_time / 60 / 10) + '0';

    SetSensor_OLED_Sring(16, 0, (unsigned char *)time_buffer_date, 8);
    SetSensor_OLED_Sring(22, 1, (unsigned char *)time_buffer_time, 8);
}

// void SetSensor_28byj_48(unsigned int value, unsigned int position)
// {

// static unsigned char flag_is_init = 0;

// if (flag_is_init == 0)
// {
//     flag_is_init = 1;

//     Step_Motor_GPIO_Init();
// }

// motorNcircle(value, position); // n为步进电机转动的度数，position为正转或者反转
// }

// 设置电机控制函数
void SetSensor_MOTOR(unsigned char value, unsigned char time)
{
    // 初始化标志位
    static unsigned char flag_is_init = 0;
    // 定义时间值和温度值
    static unsigned char time_value = 0, temp_value = 5;

    // 如果初始化标志位为0，则初始化电机
    if (flag_is_init == 0)
    {
        flag_is_init = 1;
        MOTOR_Init();
        GlobalVar_flag_motor_inited = 1;
    }

    // 如果温度值不等于输入值，则将时间值和温度值重置
    if (temp_value != value)
    {
        time_value = 0;
        temp_value = value;
    }

    // 如果时间值小于输入时间，则控制电机
    if (time_value < time)
    {
        time_value++;
        MOTOR_Direction_Control = value;
    }
    // 否则停止电机
    else
    {
        MOTOR_Direction_Control = 2;
    }
}

// 获取16位按键传感器函数
void Getsensor_16key(void)
{
    // 如果16位按键传感器未初始化，则初始化
    if (!GlobalVar_flag_key16_inited)
    {
        GlobalVar_flag_key16_inited = 1;
    }
}