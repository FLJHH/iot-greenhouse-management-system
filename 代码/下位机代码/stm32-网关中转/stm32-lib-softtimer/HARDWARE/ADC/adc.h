#ifndef __ADC_H
#define __ADC_H	
#include "sys.h"
/***************************使用说明******************************

考虑到不同型号stm32F103的引脚差别，我们这里默认使用所有板子都有的ADC1模块
使用的时候 先参照通道引脚对应引脚图 打开需要的通道宏定义
***************************使用说明******************************/


/*************************通道对应引脚图***************************

ADC123_IN0->PA0
ADC123_IN1->PA1
ADC123_IN2->PA2
ADC123_IN3->PA3
ADC12_IN4->PA4
ADC12_IN5->PA5
ADC12_IN6->PA6
ADC12_IN7->PA7
ADC12_IN8->PB0
ADC12_IN9->PB1
ADC123_IN10->PC0
ADC123_IN11->PC1
ADC123_IN12->PC2
ADC123_IN13->PC3
ADC12_IN14->PC4
ADC12_IN15->PC5

*************************通道对应引脚图****************************/



/************************以下开启通道定义***********************/
//控制通道的开启(配置相应的IO)
//#define GPIO_Init_CH0
// #define GPIO_Init_CH1
//#define GPIO_Init_CH2
// #define GPIO_Init_CH3
#define GPIO_Init_CH4
#define GPIO_Init_CH5
#define GPIO_Init_CH6
#define GPIO_Init_CH7
//#define GPIO_Init_CH8
//#define GPIO_Init_CH9
//#define GPIO_Init_CH10
//#define GPIO_Init_CH11
//#define GPIO_Init_CH12
//#define GPIO_Init_CH13
//#define GPIO_Init_CH14
//#define GPIO_Init_CH15


void Adc_Init(void); //adc初始化
u16  Get_Adc(u8 ch); //获取adc的平均值   参数对应着通道号（ch ：0~15 之间）
u16 Get_Adc_Average(u8 ch,u8 times);  //取多次adc求出平均值
 
#endif 
