#ifndef __PROTOCOL_H__
#define __PROTOCOL_H__

typedef struct
{
	unsigned char *p_o;          /**< Original pointer */
	unsigned char *volatile p_r; /**< Read pointer */
	unsigned char *volatile p_w; /**< Write pointer */
	volatile int fill_cnt;       /**< Number of filled slots */
	int size;                    /**< Buffer size */
} RINGBUF;

int RINGBUF_Init(RINGBUF *r, unsigned char *buf, int size);
int RINGBUF_Put(RINGBUF *r, unsigned char c);
int RINGBUF_Get(RINGBUF *r, unsigned char *c);

//定义协议管道结构体
struct protocol_pipe
{
	//ringbuf用于存储数据
	RINGBUF ringbuf;

	//回调函数，当接收到数据时调用
	void(*callback)(const char *id, const char *value);

	//get pack
	//存储帧缓冲区
	unsigned char *frame_buff;
	//帧缓冲区最大长度
	unsigned int frame_buff_max_len;
	//帧缓冲区索引
	unsigned int frame_idx;
	//帧缓冲区是否获取头
	unsigned char frame_is_get_head;
};

void protocol_pipe_init(struct protocol_pipe *pipeline, unsigned char *buff, unsigned int max_len);

void protocol_pipe_get_IdValue_FromPack(struct protocol_pipe *pipeline, void(*callback)(const char *id, const char *value));

void protocol_pipe_get_IdValue(struct protocol_pipe *pipeline, void(*callback)(const char *id, const char *value));

void protocol_pipe_put(struct protocol_pipe *pipeline, unsigned char * buff, unsigned int len);

char protocol_compare(const char * src, const char * aa);

int protocol_atoi(const char *str);

int protocol_valuelen(const char *str);






// 定义一个协议发送结构体
struct protocol_send
{
	// 缓冲区
	unsigned char * buffer;
	// 缓冲区最大长度
	unsigned int buffer_max_len;
	// 当前缓冲区的指针
	unsigned int ptr;
};

void protocol_send_init(struct protocol_send *send_protocol, unsigned char *buff, unsigned int max_len);

void protocol_send_start(struct protocol_send * send_protocol);

void protocol_send_IdValue_int(struct protocol_send * send_protocol, const char * id, int value);

void protocol_send_IdValue_str(struct protocol_send * send_protocol, const char * id, const char * value);

void protocol_send_complete(struct protocol_send * send_protocol, void(*device_send)(const unsigned char * src, int len));



#endif
 
