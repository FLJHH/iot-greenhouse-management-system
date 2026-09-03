#ifndef __AUXULIARY_H__
#define __AUXULIARY_H__

#include "include.h"
#include "protocol.h"
#include "sensor_hal.h"
#include "usart.h"

//用于解析通讯协议数据
extern struct protocol_send send_protocol_uart;
extern unsigned char send_protocol_uart_buff[512];

extern struct protocol_pipe protocol_pipe_uart;
extern unsigned char protocol_pipe_uart_buff[1024];

extern struct protocol_pipe protocol_pipe_uart_2;
extern unsigned char protocol_pipe_uart_buff_2[256];
//用于解析串口1的传感器数据
extern RINGBUF Uart_sensor_RB;
extern unsigned char uart_sensor_buff[512];

// extern const char *cfg_server_host ;
extern const char *cfg_server_host ;

void func_timer_MAX30102(void);

void func_timer_1s(void);

void parse_uart_sensor(void);

void key_button_process(unsigned char key_number);

void func_timer_recv_data(void);

void func_timer_key(void);

void uart_recv_IdValue_sensor(const char *id, const char *value);

#endif  



