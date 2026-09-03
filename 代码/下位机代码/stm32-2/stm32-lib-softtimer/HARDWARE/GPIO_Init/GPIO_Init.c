#include "GPIO_Init.h"

// -------AO读取----

unsigned int Get_GPIO_Init_Mode_AO_PA0(void)
{
	unsigned int value;
	static unsigned char flag_is_init = 0;
	if (flag_is_init == 0)
	{
		flag_is_init = 1;
		Adc_Init_channel(0);
	}

	value = Get_ADC_channel(0); // channel and repeat times

	return value;
}

unsigned int Get_GPIO_Init_Mode_AO_PA1(void)
{
	unsigned int value;
	static unsigned char flag_is_init = 0;
	if (flag_is_init == 0)
	{
		flag_is_init = 1;
		Adc_Init_channel(1);
	}

	value = Get_ADC_channel(1); // channel and repeat times

	return value;
}

unsigned int Get_GPIO_Init_Mode_AO_PA2(void)
{
	unsigned int value;
	static unsigned char flag_is_init = 0;
	if (flag_is_init == 0)
	{
		flag_is_init = 1;
		Adc_Init_channel(2);
	}

	value = Get_ADC_channel(2); // channel and repeat times

	return value;
}

unsigned int Get_GPIO_Init_Mode_AO_PA3(void)
{
	unsigned int value;
	static unsigned char flag_is_init = 0;
	if (flag_is_init == 0)
	{
		flag_is_init = 1;
		Adc_Init_channel(3);
	}

	value = Get_ADC_channel(3); // channel and repeat times

	return value;
}

unsigned int Get_GPIO_Init_Mode_AO_PA4(void)
{
	unsigned int value;
	static unsigned char flag_is_init = 0;
	if (flag_is_init == 0)
	{
		flag_is_init = 1;
		Adc_Init_channel(4);
	}

	value = Get_ADC_channel(4); // channel and repeat times

	return value;
}

unsigned int Get_GPIO_Init_Mode_AO_PA5(void)
{
	unsigned int value;
	static unsigned char flag_is_init = 0;
	if (flag_is_init == 0)
	{
		flag_is_init = 1;
		Adc_Init_channel(5);
	}

	value = Get_ADC_channel(5); // channel and repeat times

	return value;
}

unsigned int Get_GPIO_Init_Mode_AO_PA6(void)
{
	unsigned int value;
	static unsigned char flag_is_init = 0;
	if (flag_is_init == 0)
	{
		flag_is_init = 1;
		Adc_Init_channel(6);
	}

	value = Get_ADC_channel(6); // channel and repeat times

	return value;
}

unsigned int Get_GPIO_Init_Mode_AO_PA7(void)
{
	unsigned int value;
	static unsigned char flag_is_init = 0;
	if (flag_is_init == 0)
	{
		flag_is_init = 1;
		Adc_Init_channel(7);
	}

	value = Get_ADC_channel(7); // channel and repeat times

	return value;
}

// -------DO读取----

unsigned char Get_GPIO_Init_Mode_DO_PA0(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	unsigned char value;

	static unsigned char flag_is_init = 0;
	if (flag_is_init == 0)
	{
		flag_is_init = 1;
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_Init(GPIOA, &GPIO_InitStructure);
		GPIO_ResetBits(GPIOA, GPIO_Pin_0);
	}
	value = GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0);
	return value;
}

unsigned char Get_GPIO_Init_Mode_DO_PA1(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	unsigned char value;

	static unsigned char flag_is_init = 0;
	if (flag_is_init == 0)
	{
		flag_is_init = 1;
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_Init(GPIOA, &GPIO_InitStructure);
		GPIO_ResetBits(GPIOA, GPIO_Pin_1);
	}
	value = GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_1);
	return value;
}

unsigned char Get_GPIO_Init_Mode_DO_PA2(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	unsigned char value;

	static unsigned char flag_is_init = 0;
	if (flag_is_init == 0)
	{
		flag_is_init = 1;
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_Init(GPIOA, &GPIO_InitStructure);
		GPIO_ResetBits(GPIOA, GPIO_Pin_2);
	}
	value = GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_2);
	return value;
}

unsigned char Get_GPIO_Init_Mode_DO_PA3(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	unsigned char value;

	static unsigned char flag_is_init = 0;
	if (flag_is_init == 0)
	{
		flag_is_init = 1;
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_Init(GPIOA, &GPIO_InitStructure);
		GPIO_ResetBits(GPIOA, GPIO_Pin_3);
	}
	value = GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_3);
	return value;
}

unsigned char Get_GPIO_Init_Mode_DO_PA4(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	unsigned char value;

	static unsigned char flag_is_init = 0;
	if (flag_is_init == 0)
	{
		flag_is_init = 1;
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_Init(GPIOA, &GPIO_InitStructure);
		GPIO_ResetBits(GPIOA, GPIO_Pin_4);
	}
	value = GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_4);
	return value;
}

unsigned char Get_GPIO_Init_Mode_DO_PA5(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	unsigned char value;

	static unsigned char flag_is_init = 0;
	if (flag_is_init == 0)
	{
		flag_is_init = 1;
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_Init(GPIOA, &GPIO_InitStructure);
		GPIO_ResetBits(GPIOA, GPIO_Pin_5);
	}
	value = GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_5);
	return value;
}

unsigned char Get_GPIO_Init_Mode_DO_PA6(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	unsigned char value;

	static unsigned char flag_is_init = 0;
	if (flag_is_init == 0)
	{
		flag_is_init = 1;
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_Init(GPIOA, &GPIO_InitStructure);
		GPIO_ResetBits(GPIOA, GPIO_Pin_6);
	}
	value = GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_6);
	return value;
}

unsigned char Get_GPIO_Init_Mode_DO_PA7(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	unsigned char value;

	static unsigned char flag_is_init = 0;
	if (flag_is_init == 0)
	{
		flag_is_init = 1;
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_Init(GPIOA, &GPIO_InitStructure);
		GPIO_ResetBits(GPIOA, GPIO_Pin_7);
	}
	value = GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_7);
	return value;
}

unsigned char Get_GPIO_Init_Mode_DO_PA8(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	unsigned char value;

	static unsigned char flag_is_init = 0;
	if (flag_is_init == 0)
	{
		flag_is_init = 1;
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_Init(GPIOA, &GPIO_InitStructure);
		GPIO_ResetBits(GPIOA, GPIO_Pin_8);
	}
	value = GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_8);
	return value;
}

unsigned char Get_GPIO_Init_Mode_DO_PA9(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	unsigned char value;

	static unsigned char flag_is_init = 0;
	if (flag_is_init == 0)
	{
		flag_is_init = 1;
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_Init(GPIOA, &GPIO_InitStructure);
		GPIO_ResetBits(GPIOA, GPIO_Pin_9);
	}
	value = GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_9);
	return value;
}

unsigned char Get_GPIO_Init_Mode_DO_PA10(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	unsigned char value;

	static unsigned char flag_is_init = 0;
	if (flag_is_init == 0)
	{
		flag_is_init = 1;
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_Init(GPIOA, &GPIO_InitStructure);
		GPIO_ResetBits(GPIOA, GPIO_Pin_10);
	}
	value = GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_10);
	return value;
}

unsigned char Get_GPIO_Init_Mode_DO_PA11(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	unsigned char value;

	static unsigned char flag_is_init = 0;
	if (flag_is_init == 0)
	{
		flag_is_init = 1;
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_Init(GPIOA, &GPIO_InitStructure);
		GPIO_ResetBits(GPIOA, GPIO_Pin_11);
	}
	value = GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_11);
	return value;
}

unsigned char Get_GPIO_Init_Mode_DO_PA12(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	unsigned char value;

	static unsigned char flag_is_init = 0;
	if (flag_is_init == 0)
	{
		flag_is_init = 1;
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_Init(GPIOA, &GPIO_InitStructure);
		GPIO_ResetBits(GPIOA, GPIO_Pin_12);
	}
	value = GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_12);
	return value;
}

unsigned char Get_GPIO_Init_Mode_DO_PA15(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	unsigned char value;

	static unsigned char flag_is_init = 0;
	if (flag_is_init == 0)
	{
		flag_is_init = 1;
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_Init(GPIOA, &GPIO_InitStructure);
		GPIO_ResetBits(GPIOA, GPIO_Pin_15);
	}
	value = GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_15);
	return value;
}

unsigned char Get_GPIO_Init_Mode_DO_PB0(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	unsigned char value;

	static unsigned char flag_is_init = 0;
	if (flag_is_init == 0)
	{
		flag_is_init = 1;
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_Init(GPIOB, &GPIO_InitStructure);
		GPIO_ResetBits(GPIOB, GPIO_Pin_0);
	}
	value = GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_0);
	return value;
}

unsigned char Get_GPIO_Init_Mode_DO_PB1(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	unsigned char value;

	static unsigned char flag_is_init = 0;
	if (flag_is_init == 0)
	{
		flag_is_init = 1;
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_Init(GPIOB, &GPIO_InitStructure);
		GPIO_ResetBits(GPIOB, GPIO_Pin_1);
	}
	value = GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_1);
	return value;
}

unsigned char Get_GPIO_Init_Mode_DO_PB3(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	unsigned char value;

	static unsigned char flag_is_init = 0;
	if (flag_is_init == 0)
	{
		flag_is_init = 1;
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_Init(GPIOB, &GPIO_InitStructure);
		GPIO_ResetBits(GPIOB, GPIO_Pin_3);
	}
	value = GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_3);
	return value;
}

unsigned char Get_GPIO_Init_Mode_DO_PB4(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	unsigned char value;

	static unsigned char flag_is_init = 0;
	if (flag_is_init == 0)
	{
		flag_is_init = 1;
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_Init(GPIOB, &GPIO_InitStructure);
		GPIO_ResetBits(GPIOB, GPIO_Pin_4);
	}
	value = GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_4);
	return value;
}

unsigned char Get_GPIO_Init_Mode_DO_PB5(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	unsigned char value;

	static unsigned char flag_is_init = 0;
	if (flag_is_init == 0)
	{
		flag_is_init = 1;
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_Init(GPIOB, &GPIO_InitStructure);
		GPIO_ResetBits(GPIOB, GPIO_Pin_5);
	}
	value = GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_5);
	return value;
}

unsigned char Get_GPIO_Init_Mode_DO_PB6(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	unsigned char value;

	static unsigned char flag_is_init = 0;
	if (flag_is_init == 0)
	{
		flag_is_init = 1;
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_Init(GPIOB, &GPIO_InitStructure);
		GPIO_ResetBits(GPIOB, GPIO_Pin_6);
	}
	value = GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_6);
	return value;
}

unsigned char Get_GPIO_Init_Mode_DO_PB7(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	unsigned char value;

	static unsigned char flag_is_init = 0;
	if (flag_is_init == 0)
	{
		flag_is_init = 1;
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_Init(GPIOB, &GPIO_InitStructure);
		GPIO_ResetBits(GPIOB, GPIO_Pin_7);
	}
	value = GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_7);
	return value;
}

unsigned char Get_GPIO_Init_Mode_DO_PB8(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	unsigned char value;

	static unsigned char flag_is_init = 0;
	if (flag_is_init == 0)
	{
		flag_is_init = 1;
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_Init(GPIOB, &GPIO_InitStructure);
		GPIO_ResetBits(GPIOB, GPIO_Pin_8);
	}
	value = GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_8);
	return value;
}

unsigned char Get_GPIO_Init_Mode_DO_PB9(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	unsigned char value;

	static unsigned char flag_is_init = 0;
	if (flag_is_init == 0)
	{
		flag_is_init = 1;
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_Init(GPIOB, &GPIO_InitStructure);
		GPIO_ResetBits(GPIOB, GPIO_Pin_9);
	}
	value = GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_9);
	return value;
}

unsigned char Get_GPIO_Init_Mode_DO_PB10(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	unsigned char value;

	static unsigned char flag_is_init = 0;
	if (flag_is_init == 0)
	{
		flag_is_init = 1;
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_Init(GPIOB, &GPIO_InitStructure);
		GPIO_ResetBits(GPIOB, GPIO_Pin_10);
	}
	value = GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_10);
	return value;
}

unsigned char Get_GPIO_Init_Mode_DO_PB11(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	unsigned char value;

	static unsigned char flag_is_init = 0;
	if (flag_is_init == 0)
	{
		flag_is_init = 1;
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_Init(GPIOB, &GPIO_InitStructure);
		GPIO_ResetBits(GPIOB, GPIO_Pin_11);
	}
	value = GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_11);
	return value;
}

unsigned char Get_GPIO_Init_Mode_DO_PB12(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	unsigned char value;

	static unsigned char flag_is_init = 0;
	if (flag_is_init == 0)
	{
		flag_is_init = 1;
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_Init(GPIOB, &GPIO_InitStructure);
		GPIO_ResetBits(GPIOB, GPIO_Pin_12);
	}
	value = GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_12);
	return value;
}

unsigned char Get_GPIO_Init_Mode_DO_PB13(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	unsigned char value;

	static unsigned char flag_is_init = 0;
	if (flag_is_init == 0)
	{
		flag_is_init = 1;
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_Init(GPIOB, &GPIO_InitStructure);
		GPIO_ResetBits(GPIOB, GPIO_Pin_13);
	}
	value = GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_13);
	return value;
}

unsigned char Get_GPIO_Init_Mode_DO_PB14(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	unsigned char value;

	static unsigned char flag_is_init = 0;
	if (flag_is_init == 0)
	{
		flag_is_init = 1;
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_Init(GPIOB, &GPIO_InitStructure);
		GPIO_ResetBits(GPIOB, GPIO_Pin_14);
	}
	value = GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_14);
	return value;
}

unsigned char Get_GPIO_Init_Mode_DO_PB15(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	unsigned char value;

	static unsigned char flag_is_init = 0;
	if (flag_is_init == 0)
	{
		flag_is_init = 1;
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_Init(GPIOB, &GPIO_InitStructure);
		GPIO_ResetBits(GPIOB, GPIO_Pin_15);
	}
	value = GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_15);
	return value;
}

unsigned char Get_GPIO_Init_Mode_DO_PC13(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	unsigned char value;

	static unsigned char flag_is_init = 0;
	if (flag_is_init == 0)
	{
		flag_is_init = 1;
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_Init(GPIOC, &GPIO_InitStructure);
		GPIO_ResetBits(GPIOC, GPIO_Pin_13);
	}
	value = GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_13);
	return value;
}

unsigned char Get_GPIO_Init_Mode_DO_PC14(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	unsigned char value;

	static unsigned char flag_is_init = 0;
	if (flag_is_init == 0)
	{
		flag_is_init = 1;
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_Init(GPIOC, &GPIO_InitStructure);
		GPIO_ResetBits(GPIOC, GPIO_Pin_14);
	}
	value = GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_14);
	return value;
}

unsigned char Get_GPIO_Init_Mode_DO_PC15(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	unsigned char value;

	static unsigned char flag_is_init = 0;
	if (flag_is_init == 0)
	{
		flag_is_init = 1;
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_Init(GPIOC, &GPIO_InitStructure);
		GPIO_ResetBits(GPIOC, GPIO_Pin_15);
	}
	value = GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_15);
	return value;
}

// -------DO预设----

void Set_GPIO_Init_Mode_DO_PB0(unsigned char value)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	static unsigned char flag_is_init = 0;
	if (flag_is_init == 0)
	{
		flag_is_init = 1;

		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE); // 使能PB端口时钟

		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;		  // 端口配置
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;  // 设置成输出
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; // IO口速度为50MHz
		GPIO_Init(GPIOB, &GPIO_InitStructure);			  // 根据设定参数初始化GPIOA.8
		GPIO_ResetBits(GPIOB, GPIO_Pin_0);				  // 输出低
	}

	if (value)
	{
		GPIO_ResetBits(GPIOB, GPIO_Pin_0); // 输出低电平
	}
	else
	{
		GPIO_SetBits(GPIOB, GPIO_Pin_0); // 输出高
	}
}

void Set_GPIO_Init_Mode_DO_PB1(unsigned char value)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	static unsigned char flag_is_init = 0;
	if (flag_is_init == 0)
	{
		flag_is_init = 1;

		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE); // 使能PB端口时钟

		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;		  // 端口配置
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;  // 设置成输出
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; // IO口速度为50MHz
		GPIO_Init(GPIOB, &GPIO_InitStructure);			  // 根据设定参数初始化GPIOA.8
		GPIO_ResetBits(GPIOB, GPIO_Pin_1);				  // 输出低
	}

	if (value)
	{
		GPIO_ResetBits(GPIOB, GPIO_Pin_1); // 输出低电平
	}
	else
	{
		GPIO_SetBits(GPIOB, GPIO_Pin_1); // 输出高
	}
}

void Set_GPIO_Init_Mode_DO_PB2(unsigned char value)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	static unsigned char flag_is_init = 0;
	if (flag_is_init == 0)
	{
		flag_is_init = 1;

		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE); // 使能PB端口时钟

		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;		  // 端口配置
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;  // 设置成输出
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; // IO口速度为50MHz
		GPIO_Init(GPIOB, &GPIO_InitStructure);			  // 根据设定参数初始化GPIOA.8
		GPIO_ResetBits(GPIOB, GPIO_Pin_2);				  // 输出低
	}

	if (value)
	{
		GPIO_ResetBits(GPIOB, GPIO_Pin_2); // 输出低电平
	}
	else
	{
		GPIO_SetBits(GPIOB, GPIO_Pin_2); // 输出高
	}
}

void Set_GPIO_Init_Mode_DO_PB3(unsigned char value)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	static unsigned char flag_is_init = 0;
	if (flag_is_init == 0)
	{
		flag_is_init = 1;

		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE); // 使能PB端口时钟

		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;		  // 端口配置
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;  // 设置成输出
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; // IO口速度为50MHz
		GPIO_Init(GPIOB, &GPIO_InitStructure);			  // 根据设定参数初始化GPIOA.8
		GPIO_ResetBits(GPIOB, GPIO_Pin_3);				  // 输出低
	}

	if (value)
	{
		GPIO_ResetBits(GPIOB, GPIO_Pin_3); // 输出低电平
	}
	else
	{
		GPIO_SetBits(GPIOB, GPIO_Pin_3); // 输出高
	}
}

void Set_GPIO_Init_Mode_DO_PB4(unsigned char value)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	static unsigned char flag_is_init = 0;
	if (flag_is_init == 0)
	{
		flag_is_init = 1;

		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE); // 使能PB端口时钟

		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;		  // 端口配置
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;  // 设置成输出
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; // IO口速度为50MHz
		GPIO_Init(GPIOB, &GPIO_InitStructure);			  // 根据设定参数初始化GPIOA.8
		GPIO_ResetBits(GPIOB, GPIO_Pin_4);				  // 输出低
	}

	if (value)
	{
		GPIO_ResetBits(GPIOB, GPIO_Pin_4); // 输出低电平
	}
	else
	{
		GPIO_SetBits(GPIOB, GPIO_Pin_4); // 输出高
	}
}

void Set_GPIO_Init_Mode_DO_PB5(unsigned char value)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	static unsigned char flag_is_init = 0;
	if (flag_is_init == 0)
	{
		flag_is_init = 1;

		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE); // 使能PB端口时钟

		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;		  // 端口配置
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;  // 设置成输出
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; // IO口速度为50MHz
		GPIO_Init(GPIOB, &GPIO_InitStructure);			  // 根据设定参数初始化GPIOA.8
		GPIO_ResetBits(GPIOB, GPIO_Pin_5);				  // 输出低
	}

	if (value)
	{
		GPIO_ResetBits(GPIOB, GPIO_Pin_5); // 输出低电平
	}
	else
	{
		GPIO_SetBits(GPIOB, GPIO_Pin_5); // 输出高
	}
}

void Set_GPIO_Init_Mode_DO_PB6(unsigned char value)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	static unsigned char flag_is_init = 0;
	if (flag_is_init == 0)
	{
		flag_is_init = 1;

		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE); // 使能PB端口时钟

		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;		  // 端口配置
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;  // 设置成输出
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; // IO口速度为50MHz
		GPIO_Init(GPIOB, &GPIO_InitStructure);			  // 根据设定参数初始化GPIOA.8
		GPIO_ResetBits(GPIOB, GPIO_Pin_6);				  // 输出低
	}

	if (value)
	{
		GPIO_ResetBits(GPIOB, GPIO_Pin_6); // 输出低电平
	}
	else
	{
		GPIO_SetBits(GPIOB, GPIO_Pin_6); // 输出高
	}
}

void Set_GPIO_Init_Mode_DO_PB7(unsigned char value)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	static unsigned char flag_is_init = 0;
	if (flag_is_init == 0)
	{
		flag_is_init = 1;

		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE); // 使能PB端口时钟

		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;		  // 端口配置
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;  // 设置成输出
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; // IO口速度为50MHz
		GPIO_Init(GPIOB, &GPIO_InitStructure);			  // 根据设定参数初始化GPIOA.8
		GPIO_ResetBits(GPIOB, GPIO_Pin_7);				  // 输出低
	}

	if (value)
	{
		GPIO_ResetBits(GPIOB, GPIO_Pin_7); // 输出低电平
	}
	else
	{
		GPIO_SetBits(GPIOB, GPIO_Pin_7); // 输出高
	}
}

void Set_GPIO_Init_Mode_DO_PB8(unsigned char value)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	static unsigned char flag_is_init = 0;
	if (flag_is_init == 0)
	{
		flag_is_init = 1;

		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE); // 使能PB端口时钟

		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;		  // 端口配置
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;  // 设置成输出
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; // IO口速度为50MHz
		GPIO_Init(GPIOB, &GPIO_InitStructure);			  // 根据设定参数初始化GPIOA.8
		GPIO_ResetBits(GPIOB, GPIO_Pin_8);				  // 输出低
	}

	if (value)
	{
		GPIO_ResetBits(GPIOB, GPIO_Pin_8); // 输出低电平
	}
	else
	{
		GPIO_SetBits(GPIOB, GPIO_Pin_8); // 输出高
	}
}

void Set_GPIO_Init_Mode_DO_PB9(unsigned char value)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	static unsigned char flag_is_init = 0;
	if (flag_is_init == 0)
	{
		flag_is_init = 1;

		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE); // 使能PB端口时钟

		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;		  // 端口配置
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;  // 设置成输出
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; // IO口速度为50MHz
		GPIO_Init(GPIOB, &GPIO_InitStructure);			  // 根据设定参数初始化GPIOA.8
		GPIO_ResetBits(GPIOB, GPIO_Pin_9);				  // 输出低
	}

	if (value)
	{
		GPIO_ResetBits(GPIOB, GPIO_Pin_9); // 输出低电平
	}
	else
	{
		GPIO_SetBits(GPIOB, GPIO_Pin_9); // 输出高
	}
}

void Set_GPIO_Init_Mode_DO_PB10(unsigned char value)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	static unsigned char flag_is_init = 0;
	if (flag_is_init == 0)
	{
		flag_is_init = 1;

		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE); // 使能PB端口时钟

		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;		  // 端口配置
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;  // 设置成输出
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; // IO口速度为50MHz
		GPIO_Init(GPIOB, &GPIO_InitStructure);			  // 根据设定参数初始化GPIOA.8
		GPIO_ResetBits(GPIOB, GPIO_Pin_10);				  // 输出低
	}

	if (value)
	{
		GPIO_ResetBits(GPIOB, GPIO_Pin_10); // 输出低电平
	}
	else
	{
		GPIO_SetBits(GPIOB, GPIO_Pin_10); // 输出高
	}
}

void Set_GPIO_Init_Mode_DO_PB11(unsigned char value)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	static unsigned char flag_is_init = 0;
	if (flag_is_init == 0)
	{
		flag_is_init = 1;

		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE); // 使能PB端口时钟

		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;		  // 端口配置
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;  // 设置成输出
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; // IO口速度为50MHz
		GPIO_Init(GPIOB, &GPIO_InitStructure);			  // 根据设定参数初始化GPIOA.8
		GPIO_ResetBits(GPIOB, GPIO_Pin_11);				  // 输出低
	}

	if (value)
	{
		GPIO_ResetBits(GPIOB, GPIO_Pin_11); // 输出低电平
	}
	else
	{
		GPIO_SetBits(GPIOB, GPIO_Pin_11); // 输出高
	}
}

void Set_GPIO_Init_Mode_DO_PB12(unsigned char value)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	static unsigned char flag_is_init = 0;
	if (flag_is_init == 0)
	{
		flag_is_init = 1;

		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE); // 使能PB端口时钟

		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;		  // 端口配置
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;  // 设置成输出
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; // IO口速度为50MHz
		GPIO_Init(GPIOB, &GPIO_InitStructure);			  // 根据设定参数初始化GPIOA.8
		GPIO_ResetBits(GPIOB, GPIO_Pin_12);				  // 输出低
	}

	if (value)
	{
		GPIO_ResetBits(GPIOB, GPIO_Pin_12); // 输出低电平
	}
	else
	{
		GPIO_SetBits(GPIOB, GPIO_Pin_12); // 输出高
	}
}

void Set_GPIO_Init_Mode_DO_PB13(unsigned char value)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	static unsigned char flag_is_init = 0;
	if (flag_is_init == 0)
	{
		flag_is_init = 1;

		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE); // 使能PB端口时钟

		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;		  // 端口配置
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;  // 设置成输出
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; // IO口速度为50MHz
		GPIO_Init(GPIOB, &GPIO_InitStructure);			  // 根据设定参数初始化GPIOA.8
		GPIO_ResetBits(GPIOB, GPIO_Pin_13);				  // 输出低
	}

	if (value)
	{
		GPIO_ResetBits(GPIOB, GPIO_Pin_13); // 输出低电平
	}
	else
	{
		GPIO_SetBits(GPIOB, GPIO_Pin_13); // 输出高
	}
}

void Set_GPIO_Init_Mode_DO_PB14(unsigned char value)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	static unsigned char flag_is_init = 0;
	if (flag_is_init == 0)
	{
		flag_is_init = 1;

		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE); // 使能PB端口时钟

		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14;		  // 端口配置
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;  // 设置成输出
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; // IO口速度为50MHz
		GPIO_Init(GPIOB, &GPIO_InitStructure);			  // 根据设定参数初始化GPIOA.8
		GPIO_ResetBits(GPIOB, GPIO_Pin_14);				  // 输出低
	}

	if (value)
	{
		GPIO_ResetBits(GPIOB, GPIO_Pin_14); // 输出低电平
	}
	else
	{
		GPIO_SetBits(GPIOB, GPIO_Pin_14); // 输出高
	}
}

void Set_GPIO_Init_Mode_DO_PB15(unsigned char value)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	static unsigned char flag_is_init = 0;
	if (flag_is_init == 0)
	{
		flag_is_init = 1;

		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE); // 使能PB端口时钟

		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15;		  // 端口配置
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;  // 设置成输出
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; // IO口速度为50MHz
		GPIO_Init(GPIOB, &GPIO_InitStructure);			  // 根据设定参数初始化GPIOA.8
		GPIO_ResetBits(GPIOB, GPIO_Pin_15);				  // 输出低
	}

	if (value)
	{
		GPIO_ResetBits(GPIOB, GPIO_Pin_15); // 输出低电平
	}
	else
	{
		GPIO_SetBits(GPIOB, GPIO_Pin_15); // 输出高
	}
}

void Set_GPIO_Init_Mode_DO_PC13(unsigned char value)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	static unsigned char flag_is_init = 0;
	if (flag_is_init == 0)
	{
		flag_is_init = 1;

		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE); // 使能PB端口时钟

		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;		  // 端口配置
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;  // 设置成输出
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; // IO口速度为50MHz
		GPIO_Init(GPIOC, &GPIO_InitStructure);			  // 根据设定参数初始化GPIOA.8
		GPIO_ResetBits(GPIOC, GPIO_Pin_13);				  // 输出低
	}

	if (value)
	{
		GPIO_ResetBits(GPIOC, GPIO_Pin_13); // 输出低电平
	}
	else
	{
		GPIO_SetBits(GPIOC, GPIO_Pin_13); // 输出高
	}
}

void Set_GPIO_Init_Mode_DO_PC14(unsigned char value)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	static unsigned char flag_is_init = 0;
	if (flag_is_init == 0)
	{
		flag_is_init = 1;

		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE); // 使能PB端口时钟

		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14;		  // 端口配置
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;  // 设置成输出
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; // IO口速度为50MHz
		GPIO_Init(GPIOC, &GPIO_InitStructure);			  // 根据设定参数初始化GPIOA.8
		GPIO_ResetBits(GPIOC, GPIO_Pin_14);				  // 输出低
	}

	if (value)
	{
		GPIO_ResetBits(GPIOC, GPIO_Pin_14); // 输出低电平
	}
	else
	{
		GPIO_SetBits(GPIOC, GPIO_Pin_14); // 输出高
	}
}

void Set_GPIO_Init_Mode_DO_PC15(unsigned char value)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	static unsigned char flag_is_init = 0;
	if (flag_is_init == 0)
	{
		flag_is_init = 1;
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE); // 使能PB端口时钟

		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15;		  // 端口配置
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;  // 设置成输出
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; // IO口速度为50MHz
		GPIO_Init(GPIOC, &GPIO_InitStructure);			  // 根据设定参数初始化GPIOA.8
		GPIO_ResetBits(GPIOC, GPIO_Pin_15);				  // 输出低
	}

	if (value)
	{
		GPIO_ResetBits(GPIOC, GPIO_Pin_15); // 输出低电平
	}
	else
	{
		GPIO_SetBits(GPIOC, GPIO_Pin_15); // 输出高
	}
}



