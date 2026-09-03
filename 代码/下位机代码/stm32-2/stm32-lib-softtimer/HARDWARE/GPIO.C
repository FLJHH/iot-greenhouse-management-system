#include "gpio.h"
#include "delay.h"   //根据时钟晶振配置的延时函数
#include "sys.h"			//基础配置（包括 gpio输入输出简化 及变量名的简化
#include "pin_define.h"

volatile int maichongjishu = 0;

void GPIO_Init_Mode(void)
{

	GPIO_InitTypeDef GPIO_InitStructure;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE, ENABLE); //使能PG,PD端口时钟

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14;		  // 端口配置
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;  //设置成上拉输入
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; //IO口速度为50MHz
	GPIO_Init(GPIOE, &GPIO_InitStructure);			  //根据设定参数初始化GPIOA.8
	GPIO_SetBits(GPIOE, GPIO_Pin_14);				  // 输出高

	// GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;				 //LED0-->PA.8 端口配置
	// GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //推挽输出
	// GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO口速度为50MHz
	// GPIO_Init(GPIOE, &GPIO_InitStructure);					 //根据设定参数初始化GPIOA.8
	// GPIO_ResetBits(GPIOE,GPIO_Pin_9);						 //PA.8 输出低

	// GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;	    		 //LED1-->PD.2 端口配置, 推挽输出
	// GPIO_Init(GPIOE, &GPIO_InitStructure);	  				 //推挽输出 ，IO口速度为50MHz
	// GPIO_SetBits(GPIOE,GPIO_Pin_9); 						 //PD.2 输出高
}

  
 
 


void InitSensor_Voice(void)
{

	GPIO_InitTypeDef GPIOInit;
	RCC_APB2PeriphClockCmd(Sensor_Rcc_Voice, ENABLE);
	GPIOInit.GPIO_Mode = GPIO_Mode_IPU;
	GPIOInit.GPIO_Pin = Sensor_Pin_Voice;
	GPIOInit.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(Sensor_Port_Voice, &GPIOInit);
}

unsigned char Get_Voice(void)
{

	static unsigned char record = 0;
	unsigned char state = 0;

	state = GPIO_ReadInputDataBit(Sensor_Port_Voice, Sensor_Pin_Voice);

	if (state == 0)
	{
		record = ((record << 1) | 0x01);
	}
	else
	{
		record = ((record << 1) & (~0x01));
	}

	if ((record & 0xf) == 0)
	{
		return (0);
	}
	else
	{
		return (1);
	}
}







void InitSensor_Renti(void)
{

	GPIO_InitTypeDef GPIOInit;
	RCC_APB2PeriphClockCmd(Sensor_Rcc_Renti_1, ENABLE);
	GPIOInit.GPIO_Mode = GPIO_Mode_IPU;
	GPIOInit.GPIO_Pin = Sensor_Pin_Renti_1;
	GPIOInit.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(Sensor_Port_Renti_1, &GPIOInit);
}



void InitSensor_Renti_2(void)
{

	GPIO_InitTypeDef GPIOInit;
	RCC_APB2PeriphClockCmd(Sensor_Rcc_Renti_2, ENABLE);
	GPIOInit.GPIO_Mode = GPIO_Mode_IPU;
	GPIOInit.GPIO_Pin = Sensor_Pin_Renti_2;
	GPIOInit.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(Sensor_Port_Renti_2, &GPIOInit);
}



void InitSensor_Huoyan(void)
{

	GPIO_InitTypeDef GPIOInit;
	RCC_APB2PeriphClockCmd(Sensor_Rcc_Huoyan, ENABLE);
	GPIOInit.GPIO_Mode = GPIO_Mode_IPU;
	GPIOInit.GPIO_Pin = Sensor_Pin_Huoyan;
	GPIOInit.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(Sensor_Port_Huoyan, &GPIOInit);
}




unsigned char Get_Huoyan(void)
{

	static unsigned char record = 0;
	unsigned char state = 0;

	state = GPIO_ReadInputDataBit(Sensor_Port_Huoyan, Sensor_Pin_Huoyan);

	if (state == 0)
	{
		record = ((record << 1) | 0x01);
	}
	else
	{
		record = ((record << 1) & (~0x01));
	}

	if ((record & 0x7) == 0)   // 0x07   ==  00000111
	{
		return (0);
	}
	else
	{
		return (1);
	}
}





unsigned char Get_Renti(void)
{

	static unsigned char record = 0;
	unsigned char state = 0;

	state = GPIO_ReadInputDataBit(Sensor_Port_Renti_1, Sensor_Pin_Renti_1);

	if (state == 1)
	{
		record = ((record << 1) | 0x01);
	}
	else
	{
		record = ((record << 1) & (~0x01));
	}

	if ((record & 0x0f) == 0)
	{
		return (0);
	}
	else
	{
		return (1);
	}
}



unsigned char Get_Renti_2(void)
{

	static unsigned char record = 0;
	unsigned char state = 0;

	state = GPIO_ReadInputDataBit(Sensor_Port_Renti_2, Sensor_Pin_Renti_2);

	if (state == 1)
	{
		record = ((record << 1) | 0x01);
	}
	else
	{
		record = ((record << 1) & (~0x01));
	}

	if ((record & 0x0f) == 0)
	{
		return (0);
	}
	else
	{
		return (1);
	}
}


// gpiob4
void InitSensor_maichongjishu(void)
{

	/**定义结构体*/

	EXTI_InitTypeDef EXTI_InitStructure;

	GPIO_InitTypeDef GPIO_InitStructure;

	NVIC_InitTypeDef NVIC_InitStructure;

	/**时钟配置(要打开AFIO时钟)*/

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB | RCC_APB2Periph_AFIO, ENABLE);

	/**外部中断使用的GPIO的配置使用PB口的4引脚*/

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;

	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;

	GPIO_Init(GPIOB, &GPIO_InitStructure);

	/**外部中断使用的GPIO引脚也就是PB口的9引脚连接到EXTILine9*/

	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB, GPIO_PinSource4);

	/**配置外部中断*/

	EXTI_InitStructure.EXTI_Line = EXTI_Line4;

	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;

	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;

	EXTI_InitStructure.EXTI_LineCmd = ENABLE;

	EXTI_Init(&EXTI_InitStructure);

	/**配置NVIC*/

	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);

	NVIC_InitStructure.NVIC_IRQChannel = EXTI4_IRQn;

	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;

	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;

	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;

	NVIC_Init(&NVIC_InitStructure);
	
}

void EXTI4_IRQHandler(void)
{

	//上升沿  高电平
	if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_4))
	{
		maichongjishu++;
	}

	EXTI_ClearITPendingBit(EXTI_Line4); //清除LINE4上的中断标志位
}





// void InitSensor_Key(void)  
// {  
//     GPIO_InitTypeDef GPIOInit;
// 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);  
      
//     GPIOInit.GPIO_Mode = GPIO_Mode_IPU;   //上拉输入
//     GPIOInit.GPIO_Pin = GPIO_Pin_8 ;  
//     GPIOInit.GPIO_Speed = GPIO_Speed_50MHz;  
//     GPIO_Init(GPIOA, &GPIOInit);  
// }  



// void InitSensor_Key_2(void)  
// {  
//     GPIO_InitTypeDef GPIOInit;
// 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);  
      
//     GPIOInit.GPIO_Mode = GPIO_Mode_IPU;   //上拉输入
//     GPIOInit.GPIO_Pin = GPIO_Pin_13 ;  
//     GPIOInit.GPIO_Speed = GPIO_Speed_50MHz;  
//     GPIO_Init(GPIOC, &GPIOInit);  
// }  




  
// unsigned char Get_Key(void)  
// {  
	
// 	if(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_8) == 0)
// 	{
// 		delay_ms(10);
		
// 		if(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_8) == 0)
// 		{
// 			return 1;
// 		}
// 	}
// 	return 0;
// }  


// unsigned char Get_Key_2(void)  
// {  
	
// 	if(GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_13) == 0)
// 	{
// 		delay_ms(10);
		
// 		if(GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_13) == 0)
// 		{
// 			return 1;
// 		}
// 	}
// 	return 0;
// }  



