#include "key.h"
#include "sys.h"

static volatile unsigned char key_button_state_1 = 0; // 记录按键1 是否被按下过
static volatile unsigned char key_button_state_2 = 0; // 记录按键2 是否被按下过
static volatile unsigned char key_button_state_3 = 0; // 记录按键3 是否被按下过
static volatile unsigned char key_button_state_4 = 0; // 记录按键4 是否被按下过
static volatile unsigned char key16_button_value = 0; // 记录矩阵按键 按下的值
static void (*key_button_callback)(unsigned char key_number);

static volatile unsigned char key_button_state_TEST = 0;

void key_button_init() // 按键引脚初始化
{
	GPIO_InitTypeDef GPIOInit;							  // 定义结构体类型
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE); // 所有时钟默认是关闭状态，使用时需要打开对应的时钟		这里调用的宏定义PA组

	GPIOInit.GPIO_Mode = GPIO_Mode_IPU;		// 上拉输入
	GPIOInit.GPIO_Pin = KEY_GPIO_Pin_1;		// 选择配置的端口号 1~15 						     这里调用的宏定义8号端口
	GPIOInit.GPIO_Speed = GPIO_Speed_50MHz; // IO口速度为50MHz  	输入模式配置无效
	GPIO_Init(KEY_GPIO_Group_1, &GPIOInit); // 根据设定参数初始化引脚 PA8

	// RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE); // 所有时钟默认是关闭状态，使用时需要打开对应的时钟		这里调用的宏定义PA组
	// GPIOInit.GPIO_Mode = GPIO_Mode_IPU;					  // 上拉输入
	// GPIOInit.GPIO_Pin = KEY_GPIO_Pin_2;					  // 选择配置的端口号 1~15 						     这里调用的宏定义15号端口
	// GPIOInit.GPIO_Speed = GPIO_Speed_50MHz;				  // IO口速度为50MHz  	输入模式配置无效
	// GPIO_Init(KEY_GPIO_Group_2, &GPIOInit);				  // 根据设定参数初始化引脚 PA15

	// RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE); // 所有时钟默认是关闭状态，使用时需要打开对应的时钟		这里调用的宏定义PA组
	// GPIOInit.GPIO_Mode = GPIO_Mode_IPU;					  // 上拉输入
	// GPIOInit.GPIO_Pin = KEY_GPIO_Pin_3;					  // 选择配置的端口号 1~15 						     这里调用的宏定义15号端口
	// GPIOInit.GPIO_Speed = GPIO_Speed_50MHz;				  // IO口速度为50MHz  	输入模式配置无效
	// GPIO_Init(KEY_GPIO_Group_3, &GPIOInit);				  // 根据设定参数初始化引脚 PA15

	// RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE); // 所有时钟默认是关闭状态，使用时需要打开对应的时钟		这里调用的宏定义PA组
	// GPIOInit.GPIO_Mode = GPIO_Mode_IPU;					  // 上拉输入
	// GPIOInit.GPIO_Pin = KEY_GPIO_Pin_4;					  // 选择配置的端口号 1~15 						     这里调用的宏定义15号端口
	// GPIOInit.GPIO_Speed = GPIO_Speed_50MHz;				  // IO口速度为50MHz  	输入模式配置无效
	// GPIO_Init(KEY_GPIO_Group_4, &GPIOInit);				  // 根据设定参数初始化引脚 PA15
}

void key16_button_init(int number) // 按键引脚初始化
{
	GPIO_InitTypeDef GPIO_InitStructure;				  // 定义结构体类型
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE); // 使能PB端口时钟

	if (number)
	{
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;																				 // 设置成下拉输入
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;																			 // IO口速度为50MHz
		GPIO_InitStructure.GPIO_Pin = Sensor_Pin_16Key_Row1 | Sensor_Pin_16Key_Row2 | Sensor_Pin_16Key_Row3 | Sensor_Pin_16Key_Row4; // 端口配置
		GPIO_Init(Sensor_Port_16Key_Row1, &GPIO_InitStructure);

		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;																			 // 设置成推挽输出
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;																			 // IO口速度为50MHz
		GPIO_InitStructure.GPIO_Pin = Sensor_Pin_16Key_C0l1 | Sensor_Pin_16Key_C0l2 | Sensor_Pin_16Key_C0l3 | Sensor_Pin_16Key_C0l4; // 端口配置
		GPIO_Init(Sensor_Port_16Key_C0l1, &GPIO_InitStructure);
	}
	else
	{
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;																				 // 设置成上拉输入
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;																			 // IO口速度为50MHz
		GPIO_InitStructure.GPIO_Pin = Sensor_Pin_16Key_C0l1 | Sensor_Pin_16Key_C0l2 | Sensor_Pin_16Key_C0l3 | Sensor_Pin_16Key_C0l4; // 端口配置
		GPIO_Init(Sensor_Port_16Key_C0l1, &GPIO_InitStructure);

		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;																			 // 设置成推挽输出
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;																			 // IO口速度为50MHz
		GPIO_InitStructure.GPIO_Pin = Sensor_Pin_16Key_Row1 | Sensor_Pin_16Key_Row2 | Sensor_Pin_16Key_Row3 | Sensor_Pin_16Key_Row4; // 端口配置
		GPIO_Init(Sensor_Port_16Key_Row1, &GPIO_InitStructure);
	}
}

void key_button_register(void (*callback)(unsigned char key_number)) // 给处理函数赋址
{

	if (callback) // 判断地址是否为空
	{
		key_button_callback = callback; // 将内部指针函数指向指定的按键处理函数
	}
}

static void key_button_poll() // 用于判断 按键是否按下 并调用区分按下按键，调用处理函数处理
{
	if (key_button_state_1) // 判断按键1是否按下过
	{
		if (key_button_callback) // 判断处理函数是否为空
		{
			key_button_callback(1); // 调用处理函数，传入按键编号
		}

		key_button_state_1 = 0; // 重置按键1状态
	}
	else if (key_button_state_2) // 判断按键2是否按下过
	{
		if (key_button_callback) // 判断处理函数是否为空
		{
			key_button_callback(2); // 调用处理函数，传入按键编号
		}

		key_button_state_2 = 0; // 重置按键2状态
	}
	else if (key_button_state_3) // 判断按键3是否按下过
	{
		if (key_button_callback) // 判断处理函数是否为空
		{
			key_button_callback(3); // 调用处理函数，传入按键编号
		}

		key_button_state_3 = 0; // 重置按键2状态
	}
	else if (key_button_state_4) // 判断按键4是否按下过
	{
		if (key_button_callback) // 判断处理函数是否为空
		{
			key_button_callback(4); // 调用处理函数，传入按键编号
		}

		key_button_state_4 = 0; // 重置按键2状态
	}
	else if (key16_button_value)
	{
		if (key_button_callback) // 判断处理函数是否为空
		{
			key_button_callback(key16_button_value); // 调用处理函数，传入按键编号
		}

		key16_button_value = 0; // 重置按键2状态
	}
}

void key_button_scan_10ms()
{
	static char key1_last = 0;			   // 记录按键1上次状态   用于判断是否消抖
	static char key2_last = 0;			   // 记录按键2上次状态   用于判断是否消抖
	static char key3_last = 0;			   // 记录按键1上次状态   用于判断是否消抖
	static char key4_last = 0;			   // 记录按键2上次状态   用于判断是否消抖
	static char key1_up = 0;			   // 记录按键1本次状态
	static char key2_up = 0;			   // 记录按键2本次状态
	static char key3_up = 0;			   // 记录按键1本次状态
	static char key4_up = 0;			   // 记录按键2本次状态
	static unsigned char poll_timeout = 0; // 计数变量

	if (KEY_GPIO_1 == KEY_active_1) // 判断按键1 是否是按下状态(宏定义为0)	判断是否是低电平
	{
		if (key1_last) // 判断按键1上次状态   确认是否是第一次触发，如果是第一次说明还没有消抖，需要下次才能确认是按下了
		{
			key1_up = 1; // 记录按键1状态 	   确认按键已经按下了
		}
		key1_last = 1; // 给按键1 上次的状态赋值， 因为放在判断后面，本次赋值，在下次进入该函数才会使用到
	}
	else
	{
		if (key1_up) // 判断按键是否按下过
		{
			key_button_state_1 = 1; // 将按键已按下的信息放到全局变量，方便其他函数调用
		}
		key1_up = 0;   // 重置按键状态记录变量
		key1_last = 0; // 重置按键状态记录变量
	}

	if (KEY_GPIO_2 == KEY_active_2) //---------------- 同按键1
	{
		if (key2_last)
		{
			key2_up = 1;
		}
		key2_last = 1;
	}
	else
	{
		if (key2_up)
		{
			key_button_state_2 = 1;
		}
		key2_up = 0;
		key2_last = 0;
	}

	if (KEY_GPIO_3 == KEY_active_3) // 判断按键3 是否是按下状态(宏定义为0)	判断是否是低电平
	{
		if (key3_last) // 判断按键3上次状态   确认是否是第一次触发，如果是第一次说明还没有消抖，需要下次才能确认是按下了
		{
			key3_up = 1; // 记录按键3状态 	   确认按键已经按下了
		}
		key3_last = 1; // 给按键3 上次的状态赋值， 因为放在判断后面，本次赋值，在下次进入该函数才会使用到
	}
	else
	{
		if (key3_up) // 判断按键是否按下过
		{
			key_button_state_3 = 1; // 将按键已按下的信息放到全局变量，方便其他函数调用
		}
		key3_up = 0;   // 重置按键状态记录变量
		key3_last = 0; // 重置按键状态记录变量
	}

	if (KEY_GPIO_4 == KEY_active_4) //---------------- 同按键1
	{
		if (key4_last)
		{
			key4_up = 1;
		}
		key4_last = 1;
	}
	else
	{
		if (key4_up)
		{
			key_button_state_4 = 1;
		}
		key4_up = 0;
		key4_last = 0;
	}

	if (poll_timeout++ > 20) // 判断计数变量是否大于20		该函数相当于 每200ms 调用一次，在间隔时间没到之前，被按下的按键只会被记录，到时间后才会进行处理
	{
		key_button_poll(); // 调用按键预处理函数
		poll_timeout = 0;  // 重置计数变量
	}
}

void key16_button_scan_10ms(void)
{
	static unsigned char button_value = 0;

	static unsigned char poll_timeout = 0; // 计数变量

	key16_button_init(0);

	KEY16_Row1_Write = 0;
	KEY16_Row2_Write = 0;
	KEY16_Row3_Write = 0;
	KEY16_Row4_Write = 0;

	if (KEY16_Col1_Read == KEY16_Row)
	{
		button_value = 1;
	}
	else if (KEY16_Col2_Read == KEY16_Row)
	{
		button_value = 2;
	}
	else if (KEY16_Col3_Read == KEY16_Row)
	{
		button_value = 3;
	}
	else if (KEY16_Col4_Read == KEY16_Row)
	{
		button_value = 4;
	}

	key16_button_init(1);
	KEY16_Col1_Write = 1;
	KEY16_Col2_Write = 1;
	KEY16_Col3_Write = 1;
	KEY16_Col4_Write = 1;

	if (KEY16_Row1_Read == KEY16_Col)
	{
		button_value = button_value + 0;
	}
	else if (KEY16_Row2_Read == KEY16_Col)
	{
		button_value = button_value + 4;
	}
	else if (KEY16_Row3_Read == KEY16_Col)
	{
		button_value = button_value + 8;
	}
	else if (KEY16_Row4_Read == KEY16_Col)
	{
		button_value = button_value + 12;
	}

	if (poll_timeout++ > 20) // 判断计数变量是否大于20		该函数相当于 每200ms 调用一次，在间隔时间没到之前，被按下的按键只会被记录，到时间后才会进行处理
	{

		if (button_value != 0)
		{
			key16_button_value = button_value;
			key_button_poll();				   // 调用按键预处理函数
			key_button_callback(button_value); // 调用处理函数，传入按键编号
		}
		button_value = 0;
		poll_timeout = 0; // 重置计数变量
	}
}

void key_button_scan_1ms() // 按键延时函数  该函数确保每隔10ms 调用一次按键检测函数
{
	static unsigned int num = 0; // 计次变量

	num++; // 计次

	if (num >= 10) // 判断是否到到了 10ms
	{
		key_button_scan_10ms(); // 调用按键函数   两次直接间隔10ms 有效的跳过了消抖时间
		num = 0;				// 重置计次变量
	}
}

// //按键初始化函数
// //PA15和PC5 设置成输入
// void KEY_Init(void)
// {

// 	GPIO_InitTypeDef GPIO_InitStructure;

//  	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE,ENABLE);//使能PORTE时钟

// //	GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable, ENABLE);//关闭jtag，使能SWD，可以用SWD模式调试

// 	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_6;//PE6
// 	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; //设置成上拉输入
//  	GPIO_Init(GPIOE, &GPIO_InitStructure);//初始化GPIOA15

// }

// void Simple_Key_Scan( void )
// {
// 	for (;; )
// 	{
// 		if ( GPIO_ReadInputDataBit( GPIOE, GPIO_Pin_6 ) == 0 )
// 		{
// 			delay_ms( 20 ); /* 去抖动 */

// 			if ( GPIO_ReadInputDataBit( GPIOE, GPIO_Pin_6 ) == 0 )
// 			{
// 				break;
// 			}
// 		}
// 	}
// }
// //按键处理函数
// //返回按键值
// //mode:0,不支持连续按;1,支持连续按;
// //返回值：
// //0，没有任何按键按下
// //KEY0_PRES，KEY0按下
// //KEY1_PRES，KEY1按下
// //WKUP_PRES，WK_UP按下
// //注意此函数有响应优先级,KEY0>KEY1>WK_UP!!
// u8 KEY_Scan(u8 mode)
// {
// 	static u8 key_up=1;//按键按松开标志
// 	if(mode)key_up=1;  //支持连按
// 	if(key_up&&(KEY0==0||KEY1==0||WK_UP==1))
// 	{
// 		delay_ms(10);//去抖动
// 		key_up=0;
// 		if(KEY0==0)return KEY0_PRES;
// 		else if(KEY1==0)return KEY1_PRES;
// 		else if(WK_UP==1)return WKUP_PRES;
// 	}else if(KEY0==1&&KEY1==1&&WK_UP==0)key_up=1;
// 	return 0;// 无按键按下
// }
// //单独扫描KEY0是否被按下
// //返回值:0,没按下;1,按下了.
// u8 KEY0_Scan(void)
// {
// 	static u8 key_up=1;//按键按松开标志
// 	if(key_up&&KEY0==0)
// 	{
// 		delay_ms(10);//去抖动
// 		key_up=0;
// 		if(KEY0==0)return 1;
// 	}else if(KEY0==1)key_up=1;
// 	return 0;// 无按键按下
// }
