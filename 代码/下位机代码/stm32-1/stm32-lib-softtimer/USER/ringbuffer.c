#include "ringbuffer.h"


 
//初始化结构体
int RINGBUF_Init(RINGBUF *r, unsigned char *buf, int size)
{
	//判断传入的结构体地址是否为0 / 判断传入的存放空间地址是否为0 / 判断存放空间大小是否过小
	if (r == 0 || buf == 0 || size < 2)
		return -1;

	//讲读取/写入 位置都设置为保存去开始位置
	r->p_o = r->p_r = r->p_w = buf;

	//
	r->fill_cnt = 0;

	//保存储存区大小
	r->size = size;

	return 0;
}



 

int RINGBUF_Put(RINGBUF *r, unsigned char c)
{
	//判断是否正确  初始化后 p_w 为储存空间开始地址 (地址数值不确定，但一定不为0)
    if(r->p_w==0) 
        return -1 ; //not been init

    //检查是否到了最大值 （已存入的数据不能超过最大存储空间，不能小于=1）
	if (r->fill_cnt >= r->size)
		return -1; // ring buffer is full, this should be atomic operation


	
	// r为结构体指针地址，  fill_cnt元素值 ++    该元素为int类型所以是值加加 ，其他地方是指针，所以是指针地址加加
	// 写入后增加有效数据空间
	r->fill_cnt++; // increase filled slots count, this should be atomic operation

	// *(r->p_w) = c   c存入结构体储存的写入位置地址保存的地址的值    ((*r)-> p_w)++  结构体写入位置存储的地址 +1
	*r->p_w++ = c; // put character into buffer

	// r->p_w（当前储存位置） >= (储存区最开始位置 + 储存空间总数)
	if (r->p_w >= r->p_o + r->size) // rollback if write pointer go pass
		// 从最开始位置从新开始储存	
		r->p_w = r->p_o;            // the physical boundary

	return 0;
}

 
int RINGBUF_Get(RINGBUF *r, unsigned char *c)
{
	//判断是否正确  初始化后 p_w 为储存空间开始地址 (地址数值不确定，但一定不为0)
    if(r->p_w==0) 
        return -1 ; //not been init
    
	//检查是否到了最小值 （已存入的数据不能超过最大存储空间，不能小于=1）
	if (r->fill_cnt <= 0)
		return -1; // ring buffer is empty, this should be atomic operation

	//读取后减少有效数据空间
	r->fill_cnt--; // decrease filled slots count

	// c = *(r->p_r)  读取当前读取位置的字符传输出去   ((*r)-> p_w)++  结构体读取位置存储的地址 +1	
	*c = *r->p_r++; // get the character out

	//  （当前读取位置） >= ( 储存区最开始位置 + 储存空间总数)
	if (r->p_r >= r->p_o + r->size) // rollback if write pointer go pass
		// 从最开始位置从新开始读取
		r->p_r = r->p_o;            // the physical boundary

	return 0;
}
