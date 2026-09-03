
#ifndef __OLED_H
#define __OLED_H
#include "sys.h"
#include "stdlib.h"

#define OLED_DEVICE_SSD1306_128_64 
// #define OLED_DEVICE_SH1107_128_128 


#ifdef OLED_DEVICE_SH1107_128_128
#define Max_Column 128
#define Max_Row 128
#endif

#ifdef OLED_DEVICE_SSD1306_128_64
#define Max_Column 128
#define Max_Row 64
#endif



//-------------- ---------------

#define OLED_SCLK_Clr() GPIO_ResetBits(GPIOC, GPIO_Pin_15) // sclk
#define OLED_SCLK_Set() GPIO_SetBits(GPIOC, GPIO_Pin_15)

#define OLED_SDIN_Clr() GPIO_ResetBits(GPIOC, GPIO_Pin_14) // sda
#define OLED_SDIN_Set() GPIO_SetBits(GPIOC, GPIO_Pin_14)

#define OLED_CMD 0   
#define OLED_DATA 1  

 
void OLED_WR_Byte(unsigned dat, unsigned cmd);
void OLED_Display_On(void);
void OLED_Display_Off(void);
void OLED_Init(void);
void OLED_Clear(void);
void OLED_DrawPoint(u8 x, u8 y, u8 t);
void OLED_Fill(u8 x1, u8 y1, u8 x2, u8 y2, u8 dot);
void OLED_ShowChar(u8 x, u8 y, u8 chr, u8 Char_Size);
void OLED_ShowNum(u8 x, u8 y, u32 num, u8 len, u8 size);
void OLED_ShowString(u8 x, u8 y, u8 *p, u8 Char_Size);
void OLED_Set_Pos(unsigned char x, unsigned char y);
void OLED_ShowCHinese(u8 x, u8 y, u8 no);
void OLED_DrawBMP(unsigned char x0, unsigned char y0, unsigned char x1, unsigned char y1, unsigned char BMP[]);
void Delay_50ms(unsigned int Del_50ms);
void Delay_1ms(unsigned int Del_1ms);
void fill_picture(unsigned char fill_Data);
void Picture(void);
void IIC_Start(void);
void IIC_Stop(void);
void Write_IIC_Command(unsigned char IIC_Command);
void Write_IIC_Data(unsigned char IIC_Data);
void Write_IIC_Byte(unsigned char IIC_Byte);

void IIC_Wait_Ack(void);
#endif
