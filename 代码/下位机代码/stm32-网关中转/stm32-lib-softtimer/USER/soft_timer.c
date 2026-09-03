#include "soft_timer.h"

//timer handle list head.
static struct Timer* head_handle = 0;

//Timer ticks
static unsigned int _timer_ticks = 0;

/**
  * @brief  Initializes the timer struct handle.
  * @param  handle: the timer handle strcut.
  * @param  timeout_cb: timeout callback.
  * @param  repeat: repeat interval time.
  * @retval None
  */
void timer_init(struct Timer* handle, void(*timeout_cb)(), unsigned int timeout, unsigned int repeat)
{
    // 初始化定时器
    // memset(handle, sizeof(struct Timer), 0);
    handle->timeout_cb = timeout_cb;
    // 设置超时时间，以定时器滴答为单位
    handle->timeout = _timer_ticks + timeout;
	// 初始化超时中断的下一个节点
	handle->next = 0;
	
	// 如果重复次数不为0，则设置重复次数
	if(repeat !=0) 
		handle->repeat = timeout;
	else
    	handle->repeat = 0;
}

/**
  * @brief  Start the timer work, add the handle into work list.
  * @param  btn: target handle strcut.
  * @retval 0: succeed. -1: already exist.
  */
int timer_start(struct Timer* handle)
{
    struct Timer* target = head_handle;
    while(target) {
        if(target == handle) return -1; //already exist.
        target = target->next;
    }
    handle->next = head_handle;
    head_handle = handle;
    return 0;
}

/**
  * @brief  Stop the timer work, remove the handle off work list.
  * @param  handle: target handle strcut.
  * @retval None
  */
void timer_stop(struct Timer* handle)
{
    // 遍历链表，找到handle指向的Timer对象
    struct Timer** curr;
    for(curr = &head_handle; *curr; ) {
        struct Timer* entry = *curr;
        // 如果找到，从链表中移除
        if (entry == handle) {
            *curr = entry->next;
//          free(entry);
        } else
            // 如果没有找到，遍历下一个元素
            curr = &entry->next;
    }
}

/**
  * @brief  main loop.
  * @param  None.
  * @retval None
  */
void timer_loop()
{
    struct Timer* target;
    for(target=head_handle; target; target=target->next) {
        if(  (int)target->timeout - (int)_timer_ticks <=0) {  //To prevent overflow
            if(target->repeat == 0) {
                timer_stop(target);
            } else {
                target->timeout = _timer_ticks + target->repeat;
            }
            target->timeout_cb();
        }
    }
}

/**
  * @brief  background ticks, timer repeat invoking interval 1ms.
  * @param  None.
  * @retval None.
  */
void timer_ticks()
{
    _timer_ticks++;
}