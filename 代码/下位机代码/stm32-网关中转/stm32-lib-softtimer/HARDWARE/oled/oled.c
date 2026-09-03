
#include "include.h"
#include "oled.h"
#include "stdlib.h"
#include "oledfont.h"

// OLED的显存
// 存放格式如下.
//[0]0 1 2 3 ... 127
//[1]0 1 2 3 ... 127
//[2]0 1 2 3 ... 127
//[3]0 1 2 3 ... 127
//[4]0 1 2 3 ... 127
//[5]0 1 2 3 ... 127
//[6]0 1 2 3 ... 127
//[7]0 1 2 3 ... 127
/**********************************************
//IIC Start
**********************************************/
/**********************************************
//IIC Start
**********************************************/
void OLED_IIC_Start()
{

	OLED_SCLK_Set();
	OLED_SDIN_Set();
	OLED_SDIN_Clr();
	OLED_SCLK_Clr();
}

/**********************************************
//IIC Stop
**********************************************/
void OLED_IIC_Stop()
{
	OLED_SCLK_Set();
	//	OLED_SCLK_Clr();
	OLED_SDIN_Clr();
	OLED_SDIN_Set();
}

void OLED_IIC_Wait_Ack()
{


	OLED_SCLK_Set();
	OLED_SCLK_Clr();
}
/**********************************************
// IIC Write byte
**********************************************/

void Write_IIC_Byte(unsigned char IIC_Byte)
{
	unsigned char i;
	unsigned char m, da;
	da = IIC_Byte;
	OLED_SCLK_Clr();
	for (i = 0; i < 8; i++)
	{
		m = da;
		//	OLED_SCLK_Clr();
		m = m & 0x80;
		if (m == 0x80)
		{
			OLED_SDIN_Set();
		}
		else
			OLED_SDIN_Clr();
		da = da << 1;
		OLED_SCLK_Set();
		OLED_SCLK_Clr();
	}
}
/**********************************************
// IIC Write Command
**********************************************/
// 定义一个函数，用于写入IIC命令
void Write_IIC_Command(unsigned char IIC_Command)
{
	// 发送IIC开始信号
	OLED_IIC_Start();
	// 发送从机地址，SA0=0
	Write_IIC_Byte(0x78); 
	// 等待接收器响应
	OLED_IIC_Wait_Ack();
	// 发送写命令
	Write_IIC_Byte(0x00); 
	// 等待接收器响应
	OLED_IIC_Wait_Ack();
	// 发送要写的命令
	Write_IIC_Byte(IIC_Command);
	// 等待接收器响应
	OLED_IIC_Wait_Ack();
	// 发送IIC停止信号
	OLED_IIC_Stop();
}
/**********************************************
// IIC Write Data
**********************************************/
// 定义函数Write_IIC_Data，用于写入IIC数据
void Write_IIC_Data(unsigned char IIC_Data)
{
	// 发送开始信号
	OLED_IIC_Start();
	// 写入数据，0x78表示D/C#=0; R/W#=0
	Write_IIC_Byte(0x78); 
	// 等待响应
	OLED_IIC_Wait_Ack();
	// 写入数据，0x40表示写入数据
	Write_IIC_Byte(0x40); 
	// 等待响应
	OLED_IIC_Wait_Ack();
	// 写入数据
	Write_IIC_Byte(IIC_Data); 
	// 等待响应
	OLED_IIC_Wait_Ack();
	// 发送停止信号
	OLED_IIC_Stop();
}
void OLED_WR_Byte(unsigned dat, unsigned cmd)
{
	if (cmd)
	{

		Write_IIC_Data(dat);
	}
	else
	{
		Write_IIC_Command(dat);
	}
}

/********************************************
// fill_Picture
********************************************/
void fill_picture(unsigned char fill_Data)
{
	unsigned char m, n;
	for (m = 0; m < 8; m++)
	{
		OLED_WR_Byte(0xb0 + m, 0); // page0-page1
		OLED_WR_Byte(0x00, 0);	   // low column start address
		OLED_WR_Byte(0x10, 0);	   // high column start address
		for (n = 0; n < 128; n++)
		{
			OLED_WR_Byte(fill_Data, 1);
		}
	}
}

 

void OLED_Set_Pos(unsigned char x, unsigned char y)
{
	OLED_WR_Byte(0xb0 + y, OLED_CMD);
	OLED_WR_Byte(((x & 0xf0) >> 4) | 0x10, OLED_CMD);
	OLED_WR_Byte((x & 0x0f), OLED_CMD);
}
// 开启OLED显示
void OLED_Display_On(void)
{
	OLED_WR_Byte(0X8D, OLED_CMD); // SET DCDC命令
	OLED_WR_Byte(0X14, OLED_CMD); // DCDC ON
	OLED_WR_Byte(0XAF, OLED_CMD); // DISPLAY ON
}
// 关闭OLED显示
void OLED_Display_Off(void)
{
	OLED_WR_Byte(0X8D, OLED_CMD); // SET DCDC命令
	OLED_WR_Byte(0X10, OLED_CMD); // DCDC OFF
	OLED_WR_Byte(0XAE, OLED_CMD); // DISPLAY OFF
}
// 清屏函数,清完屏,整个屏幕是黑色的!和没点亮一样!!!
void OLED_Clear(void)
{
	u8 i, n;
	for (i = 0; i < Max_Row/8; i++)
	{
		OLED_WR_Byte(0xb0 + i, OLED_CMD); // 设置页地址（0~7）
		OLED_WR_Byte(0x00, OLED_CMD);	  // 设置显示位置—列低地址
		OLED_WR_Byte(0x10, OLED_CMD);	  // 设置显示位置—列高地址
		for (n = 0; n < 128; n++)
			OLED_WR_Byte(0, OLED_DATA);
	} // 更新显示
}
 

// 在指定位置显示一个字符,包括部分字符
// x:0~127
// y:0~63
// mode:0,反白显示;1,正常显示
// size:选择字体 16/12
void OLED_ShowChar(u8 x, u8 y, u8 chr, u8 Char_Size)
{
	unsigned char c = 0, i = 0;
	c = chr - ' '; // 得到偏移后的值
	if (x > Max_Column - 1)
	{
		x = 0;
		y = y + 2;
	}
	if (Char_Size == 16)
	{
		OLED_Set_Pos(x, y);
		for (i = 0; i < 8; i++)
			OLED_WR_Byte(F8X16[c * 16 + i], OLED_DATA);
		OLED_Set_Pos(x, y + 1);
		for (i = 0; i < 8; i++)
			OLED_WR_Byte(F8X16[c * 16 + i + 8], OLED_DATA);
	}
	else
	{
		OLED_Set_Pos(x, y);
		for (i = 0; i < 6; i++)
			OLED_WR_Byte(F6x8[c][i], OLED_DATA);
	}
}

 

// 显示一个字符号串
void OLED_ShowString(u8 x, u8 y, u8 *chr, u8 Char_Size)
{
	unsigned char j = 0;
	while (chr[j] != '\0')
	{
		OLED_ShowChar(x, y, chr[j], Char_Size);
		x += 8;
		if (x > 120)
		{
			x = 0;
			y += 2;
		}
		j++;
	}
}
// 显示汉字
void OLED_ShowCHinese(u8 x, u8 y, u8 no)
{
	u8 t, adder = 0;
	OLED_Set_Pos(x, y);
	for (t = 0; t < 16; t++)
	{
		OLED_WR_Byte(Fchinese[2 * no][t], OLED_DATA);
		adder += 1;
	}
	OLED_Set_Pos(x, y + 1);
	for (t = 0; t < 16; t++)
	{
		OLED_WR_Byte(Fchinese[2 * no + 1][t], OLED_DATA);
		adder += 1;
	}
}
/***********功能描述：显示显示BMP图片128×64起始点坐标(x,y),x的范围0～127，y为页的范围0～7*****************/
void OLED_DrawBMP(unsigned char x0, unsigned char y0, unsigned char x1, unsigned char y1, unsigned char BMP[])
{
	unsigned int j = 0;
	unsigned char x, y;

	if (y1 % 8 == 0)
		y = y1 / 8;
	else
		y = y1 / 8 + 1;
	for (y = y0; y < y1; y++)
	{
		OLED_Set_Pos(x0, y);
		for (x = x0; x < x1; x++)
		{
			OLED_WR_Byte(BMP[j++], OLED_DATA);
		}
	}
}

 
void OLED_Init(void)
{

	GPIO_InitTypeDef GPIO_InitStructure;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE); // 使能PC,D,G端口时钟

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14 | GPIO_Pin_15; // P1推挽输出
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;		 // 推挽输出
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 // 速度50MHz
	GPIO_Init(GPIOC, &GPIO_InitStructure);					 // 初始化GPIOD3,6
	GPIO_SetBits(GPIOC, GPIO_Pin_15 | GPIO_Pin_14);			 // PD3,PD6 输出高

 //  GPIO_Init(GPIOD, &GPIO_InitStructure);					 // 初始化GPIOD3,6
//  GPIO_SetBits(GPIOD, GPIO_Pin_15 | GPIO_Pin_14);			 // PD3,PD6 输出高

 
	delay_ms(500);

#ifdef OLED_DEVICE_SSD1306_128_64
	OLED_WR_Byte(0xAE, OLED_CMD); //--display off
	OLED_WR_Byte(0x00, OLED_CMD); //---set low column address
	OLED_WR_Byte(0x10, OLED_CMD); //---set high column address
	OLED_WR_Byte(0x40, OLED_CMD); //--set start line address
	OLED_WR_Byte(0xB0, OLED_CMD); //--set page address
	OLED_WR_Byte(0x81, OLED_CMD); // contract control
	OLED_WR_Byte(0xFF, OLED_CMD); //--128
	OLED_WR_Byte(0xA1, OLED_CMD); // set segment remap
	OLED_WR_Byte(0xA6, OLED_CMD); //--normal / reverse
	OLED_WR_Byte(0xA8, OLED_CMD); //--set multiplex ratio(1 to 64)
	OLED_WR_Byte(0x3F, OLED_CMD); //--1/32 duty
	OLED_WR_Byte(0xC8, OLED_CMD); // Com scan direction
	OLED_WR_Byte(0xD3, OLED_CMD); //-set display offset
	OLED_WR_Byte(0x00, OLED_CMD); //

	OLED_WR_Byte(0xD5, OLED_CMD); // set osc division
	OLED_WR_Byte(0x80, OLED_CMD); //

	OLED_WR_Byte(0xD8, OLED_CMD); // set area color mode off
	OLED_WR_Byte(0x05, OLED_CMD); //

	OLED_WR_Byte(0xD9, OLED_CMD); // Set Pre-Charge Period
	OLED_WR_Byte(0xF1, OLED_CMD); //

	OLED_WR_Byte(0xDA, OLED_CMD); // set com pin configuartion
	OLED_WR_Byte(0x12, OLED_CMD); //

	OLED_WR_Byte(0xDB, OLED_CMD); // set Vcomh
	OLED_WR_Byte(0x30, OLED_CMD); //

	OLED_WR_Byte(0x8D, OLED_CMD); // set charge pump enable
	OLED_WR_Byte(0x14, OLED_CMD); //

	OLED_WR_Byte(0xAF, OLED_CMD); //--turn on oled panel
#endif

#ifdef OLED_DEVICE_SH1107_128_128
	OLED_WR_Byte(0xAE, OLED_CMD); // 关闭显示
	OLED_WR_Byte(0xD5, OLED_CMD); // 设置时钟分频因子,震荡频率
	OLED_WR_Byte(0x50, OLED_CMD); //[3:0],分频因子;[7:4],震荡频率 默认0x50
	OLED_WR_Byte(0xA8, OLED_CMD); // 设置驱动路数
	OLED_WR_Byte(0X7f, OLED_CMD); // 默认(1/64)
	OLED_WR_Byte(0xD3, OLED_CMD); // 设置显示偏移
	OLED_WR_Byte(0X00, OLED_CMD); // 默认为0
	OLED_WR_Byte(0x40, OLED_CMD); // 设置显示开始行 [5:0],行数.
	OLED_WR_Byte(0x8D, OLED_CMD); // 电荷泵设置
	OLED_WR_Byte(0x14, OLED_CMD); // bit2，开启/关闭
	OLED_WR_Byte(0x20, OLED_CMD); // 设置内存地址模式
	OLED_WR_Byte(0x02, OLED_CMD); //[1:0],00，列地址模式;01，行地址模式;10,页地址模式;默认10;
	OLED_WR_Byte(0xA0, OLED_CMD); // 段重定义设置,bit0:0,0->0;1,0->127;  A1
	OLED_WR_Byte(0xC0, OLED_CMD); // 设置COM扫描方向;bit3:0,普通模式;1,重定义模式 COM[N-1]->COM0;N:驱动路数 C0 翻转显示 C8

	OLED_WR_Byte(0xDA, OLED_CMD); // 设置COM硬件引脚配置
	OLED_WR_Byte(0x12, OLED_CMD); //[5:4]配置

	OLED_WR_Byte(0x81, OLED_CMD); // 对比度设置
	OLED_WR_Byte(0x7f, OLED_CMD); // 1~255;默认0X7F (亮度设置,越大越亮)

	OLED_WR_Byte(0xD9, OLED_CMD); // 设置预充电周期
	OLED_WR_Byte(0x22, OLED_CMD); //[3:0],PHASE 1;[7:4],PHASE 2;

	OLED_WR_Byte(0xDB, OLED_CMD); // 设置VCOMH 电压倍率
	OLED_WR_Byte(0x37, OLED_CMD); //[6:4] 000,0.65*vcc;001,0.77*vcc;011,0.83*vcc;

	OLED_WR_Byte(0xA4, OLED_CMD); // 全局显示开启;bit0:1,开启;0,关闭;(白屏/黑屏)
	OLED_WR_Byte(0xA6, OLED_CMD); // 设置显示方式;bit0:1,反相显示;0,正常显示

	OLED_WR_Byte(0xAF, OLED_CMD); // 开启显示
#endif

	OLED_Clear();
}
