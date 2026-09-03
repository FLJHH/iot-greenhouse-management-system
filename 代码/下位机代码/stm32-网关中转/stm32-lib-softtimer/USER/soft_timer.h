#ifndef _SOFT_TIMER_H_
#define _SOFT_TIMER_H_

// #include "stdint.h"

typedef struct Timer {
    unsigned int timeout;
    unsigned int repeat;
    void (*timeout_cb)(void);
    struct Timer* next;
}Timer;

// #ifdef __cplusplus  
// extern "C" {  
// #endif  

// 初始化定时器，参数分别为定时器句柄、超时回调函数、超时时间、重复次数
void timer_init(struct Timer* handle, void(*timeout_cb)(), unsigned int timeout, unsigned int repeat);
// 启动定时器，参数分别为定时器句柄
int  timer_start(struct Timer* handle);
// 停止定时器，参数分别为定时器句柄
void timer_stop(struct Timer* handle);
// 获取定时器毫秒值，无参数
void timer_ticks(void);
// 定时器轮询，无参数
void timer_loop(void);

// void timer_again(struct Timer* handle);
// void timer_set_repeat(struct Timer* handle, unsigned int repeat);

// #ifdef __cplusplus
// } 
// #endif

#endif


