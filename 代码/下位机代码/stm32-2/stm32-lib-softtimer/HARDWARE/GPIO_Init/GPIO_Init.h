#ifndef __GPIO_INIT_H
#define __GPIO_INIT_H

#include "gpio.h"
#include "delay.h"   //根据时钟晶振配置的延时函数
#include "sys.h"			//基础配置（包括 gpio输入输出简化 及变量名的简化)
#include "adc.h"


// -------读取-----


unsigned int Get_GPIO_Init_Mode_AO_PA0(void);
unsigned int Get_GPIO_Init_Mode_AO_PA1(void);
unsigned int Get_GPIO_Init_Mode_AO_PA2(void);
unsigned int Get_GPIO_Init_Mode_AO_PA3(void);
unsigned int Get_GPIO_Init_Mode_AO_PA4(void);
unsigned int Get_GPIO_Init_Mode_AO_PA5(void);
unsigned int Get_GPIO_Init_Mode_AO_PA6(void);
unsigned int Get_GPIO_Init_Mode_AO_PA7(void);

unsigned char Get_GPIO_Init_Mode_DO_PA0(void);
unsigned char Get_GPIO_Init_Mode_DO_PA1(void);
unsigned char Get_GPIO_Init_Mode_DO_PA2(void);
unsigned char Get_GPIO_Init_Mode_DO_PA3(void);
unsigned char Get_GPIO_Init_Mode_DO_PA4(void);
unsigned char Get_GPIO_Init_Mode_DO_PA5(void);
unsigned char Get_GPIO_Init_Mode_DO_PA6(void);
unsigned char Get_GPIO_Init_Mode_DO_PA7(void);
unsigned char Get_GPIO_Init_Mode_DO_PA8(void);
unsigned char Get_GPIO_Init_Mode_DO_PA9(void);
unsigned char Get_GPIO_Init_Mode_DO_PA10(void);
unsigned char Get_GPIO_Init_Mode_DO_PA11(void);
unsigned char Get_GPIO_Init_Mode_DO_PA12(void);
unsigned char Get_GPIO_Init_Mode_DO_PA15(void);

unsigned char Get_GPIO_Init_Mode_DO_PB0(void);
unsigned char Get_GPIO_Init_Mode_DO_PB1(void);
unsigned char Get_GPIO_Init_Mode_DO_PB3(void);
unsigned char Get_GPIO_Init_Mode_DO_PB4(void);
unsigned char Get_GPIO_Init_Mode_DO_PB5(void);
unsigned char Get_GPIO_Init_Mode_DO_PB6(void);
unsigned char Get_GPIO_Init_Mode_DO_PB7(void);
unsigned char Get_GPIO_Init_Mode_DO_PB8(void);
unsigned char Get_GPIO_Init_Mode_DO_PB9(void);
unsigned char Get_GPIO_Init_Mode_DO_PB10(void);
unsigned char Get_GPIO_Init_Mode_DO_PB11(void);
unsigned char Get_GPIO_Init_Mode_DO_PB12(void);
unsigned char Get_GPIO_Init_Mode_DO_PB13(void);
unsigned char Get_GPIO_Init_Mode_DO_PB14(void);
unsigned char Get_GPIO_Init_Mode_DO_PB15(void);

unsigned char Get_GPIO_Init_Mode_DO_PC13(void);
unsigned char Get_GPIO_Init_Mode_DO_PC14(void);
unsigned char Get_GPIO_Init_Mode_DO_PC15(void);


// ------设置-----

void Set_GPIO_Init_Mode_DO_PB0(unsigned char value);
void Set_GPIO_Init_Mode_DO_PB1(unsigned char value);
void Set_GPIO_Init_Mode_DO_PB3(unsigned char value);
void Set_GPIO_Init_Mode_DO_PB4(unsigned char value);
void Set_GPIO_Init_Mode_DO_PB5(unsigned char value);
void Set_GPIO_Init_Mode_DO_PB6(unsigned char value);
void Set_GPIO_Init_Mode_DO_PB7(unsigned char value);
void Set_GPIO_Init_Mode_DO_PB8(unsigned char value);
void Set_GPIO_Init_Mode_DO_PB9(unsigned char value);
void Set_GPIO_Init_Mode_DO_PB10(unsigned char value);
void Set_GPIO_Init_Mode_DO_PB11(unsigned char value);
void Set_GPIO_Init_Mode_DO_PB12(unsigned char value);
void Set_GPIO_Init_Mode_DO_PB13(unsigned char value);
void Set_GPIO_Init_Mode_DO_PB14(unsigned char value);
void Set_GPIO_Init_Mode_DO_PB15(unsigned char value);

void Set_GPIO_Init_Mode_DO_PC13(unsigned char value);
void Set_GPIO_Init_Mode_DO_PC14(unsigned char value);
void Set_GPIO_Init_Mode_DO_PC15(unsigned char value);



#endif  
	 

