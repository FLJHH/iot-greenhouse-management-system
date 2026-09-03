#ifndef __USART_H
#define __USART_H

#include <stdio.h>
#include <stm32f10x.h>


#define Open_UART1      //是否开启串口1
#define Open_UART2			//是否开启串口2
//#define Open_UART3			//是否开启串口3

#define BaudRate_UART1  38400   //串口1波特率  ---- 支持printf() 打印输出
#define BaudRate_UART2	38400     //串口2波特率
#define BaudRate_UART3	9600     //串口3波特率


#if defined (Open_UART1)

/***************************************************************
*	UART1_TX   PA9 
*	UART1_RX   PA10
****************************************************************/
#define USART1_GPIO_Cmd		       RCC_APB2PeriphClockCmd
#define USART1_GPIO_CLK          RCC_APB2Periph_GPIOA

#define USART1_AFIO_Cmd		       RCC_APB2PeriphClockCmd
#define USART1_AFIO_CLK          RCC_APB2Periph_AFIO

#define USART1_CLK_Cmd		       RCC_APB2PeriphClockCmd
#define USART1_CLK               RCC_APB2Periph_USART1 

#define USART1_GPIO_PORT         GPIOA
#define USART1_RxPin             GPIO_Pin_10
#define USART1_TxPin             GPIO_Pin_9

#endif

#if defined (Open_UART2)

#define USART2_GPIO_Cmd		       RCC_APB2PeriphClockCmd
#define USART2_GPIO_CLK          RCC_APB2Periph_GPIOA

#define USART2_AFIO_Cmd		       RCC_APB2PeriphClockCmd
#define USART2_AFIO_CLK          RCC_APB2Periph_AFIO

#define USART2_CLK_Cmd		       RCC_APB1PeriphClockCmd
#define USART2_CLK               RCC_APB1Periph_USART2 

#define USART2_GPIO_PORT         GPIOA
#define USART2_RxPin             GPIO_Pin_3
#define USART2_TxPin             GPIO_Pin_2

#endif


#if defined (Open_UART3)

#define USART3_GPIO_Cmd		       RCC_APB2PeriphClockCmd
#define USART3_GPIO_CLK          RCC_APB2Periph_GPIOC

#define USART3_AFIO_Cmd		       RCC_APB2PeriphClockCmd
#define USART3_AFIO_CLK          RCC_APB2Periph_AFIO

#define USART3_CLK_Cmd		       RCC_APB1PeriphClockCmd
#define USART3_CLK               RCC_APB1Periph_USART3 

#define USART3_GPIO_PORT         GPIOC
#define USART3_RxPin             GPIO_Pin_11
#define USART3_TxPin             GPIO_Pin_10

#endif	

void PrintChar(char *s);


void UARTx_Init(void);  //初始化串口配置

void UART1_Send_DATA(uint8_t data); //串口1发送字符
void UART2_Send_DATA(uint8_t data); //串口2发送字符
void UART3_Send_DATA(uint8_t data); //串口3发送字符


void UART1_Send_BUFF(const uint8_t *Buf, uint16_t PackLen); //串口1发送数组
void UART2_Send_BUFF(const uint8_t *Buf, uint16_t PackLen); //串口2发送数组
void UART3_Send_BUFF(const uint8_t *Buf, uint16_t PackLen); //串口3发送数组
#endif /*_USART_H*/


