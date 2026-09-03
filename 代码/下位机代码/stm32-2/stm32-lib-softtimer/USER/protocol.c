#include "protocol.h"

 struct protocol_send *sensor_protocol;
void protocol_pipe_init(struct protocol_pipe *pipeline, unsigned char *buff, unsigned int max_len)
{
	//记录缓存区的1/3 大小
	unsigned int offset = max_len / 3;
	//初始化结构体的读写位置和首地址 (以传入的空间的1/3处开始读写，只用后2/3)
	RINGBUF_Init(&(pipeline->ringbuf), buff + offset, max_len - offset);

	//记录传入空间的首地址
	pipeline->frame_buff = buff;
	//记录传入空间的1/3空间大小
	pipeline->frame_buff_max_len = offset;
	pipeline->frame_idx = 0;
	pipeline->frame_is_get_head = 0;


}




void protocol_pipe_parseFrame(struct protocol_pipe *pipeline)
{
	//记录缓存空间地址信息 （用的前1/3）
	char *ptr = (char *)pipeline->frame_buff;

	char *id = (char *)pipeline->frame_buff + 1;

	char *value;

	//以地址信息计数历遍 frame_idx 个元素
	for (; ptr < (char *)(pipeline->frame_buff + pipeline->frame_idx); ptr++)
	{
		//找到,} 
		if (*ptr == ',' || *ptr == '}')
		{
			//将value 设置为上次的结束位置后一个
			value = id;
			//历遍 开始位置 到 ，或}的位置
			while (value++ < ptr)
			{
				//寻找引号位置
				if (*value == ':')
				{
					//（这时候id在最开始的位置，value在冒号的位置）
					//例{“wendu1”:"123"}
					//	id        value

					value++;	//跳过冒号

					//判断是否有“ 有则跳过
					if (*id == '\"') id++;
					if (*value == '\"') value++;

					//调用回调函数
					pipeline->callback(id, value);
					//终止循环
					break;
				}
			}
			//记录本次的结束位置后一个，方便下次查找
			id = ptr + 1;
		}
	}
}



void protocol_pipe_Pack(struct protocol_pipe *pipeline, void(*callback)(const char *pack, const int len))
{
	unsigned char recv_byte;

	//获取数据并判断返回状态（全部获取完会返回-1终止循环）    （在后2/3的空间的空间查找，写入到前1/3）
	while (RINGBUF_Get(&(pipeline->ringbuf), &recv_byte) == 0)
	{
		//判断获取到的数据是否是包头 { 标志
		if (recv_byte == '{')
		{
			//将收到包头标志状态记录
			pipeline->frame_is_get_head = 1;
			//重置接收数据数量累计变量
			pipeline->frame_idx = 0;
			//将收到的包头标志{ 写入储存区，并将接收数据数量累计变量加1
			pipeline->frame_buff[pipeline->frame_idx++] = recv_byte;

			continue;//跳出本次循环 ---理论上可以不写
		}
		else if (recv_byte == '}')	//判断获取到的数据是否是包尾 } 标志
		{
			//判读之前是否接收到过包头标志
			if (pipeline->frame_is_get_head)
			{
				//将收到的包头标志{ 写入储存区，并将接收数据数量累计变量加1
				pipeline->frame_buff[pipeline->frame_idx++] = recv_byte;

				//callback : parse success and get one frame
				//调用传入的函数，并传入本次接收的包头位置，和包长度
				callback((char*)pipeline->frame_buff, pipeline->frame_idx);
				//重置接收数据数量累计变量
				pipeline->frame_idx = 0;
				//重置包头标志记录状态
				pipeline->frame_is_get_head = 0;
			}
			else
			{
				//清空累计值
				pipeline->frame_idx = 0;
			}
		}
		else
		{	
			//判读包头状态 和 记录的数据数量是否超过记录的空间打小
			if (pipeline->frame_is_get_head && (pipeline->frame_idx < (pipeline->frame_buff_max_len) - 2) )
			{
				//写入获取的字符
				pipeline->frame_buff[pipeline->frame_idx++] = recv_byte;
			}
		}
	}
}



//和上面的函数 protocol_pipe_parseFrame  功能一致，区别在于可以修改回调函数
void protocol_pipe_get_IdValue_FromPack(struct protocol_pipe *pipeline, void(*callback)(const char *id, const char *value))
{

	char *ptr = (char *)pipeline->frame_buff;	//（用到前1/3空间）

	char *id = (char *)pipeline->frame_buff + 1;

	char *value;

	pipeline->callback = callback;


	for (; ptr < (char *)(pipeline->frame_buff + pipeline->frame_idx); ptr++)
	{
		if (*ptr == ',' || *ptr == '}')
		{
			value = id;
			while (value++ < ptr)
			{
				if (*value == ':')
				{
					value++;
					if (*id == '\"') id++;
					if (*value == '\"') value++;
					pipeline->callback(id, value);
					break;
				}
			}
			id = ptr + 1;
		}
	}
}


//和上面的函数 protocol_pipe_Pack 功能一致， 区别在于protocol_pipe_Pack的函数没有储存
void protocol_pipe_get_IdValue(struct protocol_pipe *pipeline, void(*callback)(const char *id, const char *value))
{
	unsigned char recv_byte;

	pipeline->callback = callback;
	
	//（在后2/3的空间的空间查找，写入到前1/3）
	while (RINGBUF_Get(&(pipeline->ringbuf), &recv_byte) == 0)
	{

		if (recv_byte == '{')
		{
			pipeline->frame_is_get_head = 1;
			pipeline->frame_idx = 0;
			pipeline->frame_buff[pipeline->frame_idx++] = recv_byte;

			continue;
		}
		else if (recv_byte == '}')
		{
			if (pipeline->frame_is_get_head)
			{
				pipeline->frame_buff[pipeline->frame_idx++] = recv_byte;

				//callback : parse success and get one frame

				protocol_pipe_parseFrame(pipeline);

				pipeline->frame_idx = 0;
				pipeline->frame_is_get_head = 0;
			}
			else
			{
				pipeline->frame_idx = 0;
			}
		}
		else
		{
			if (pipeline->frame_is_get_head &&  (pipeline->frame_idx < (pipeline->frame_buff_max_len) - 2)  )
			{
				pipeline->frame_buff[pipeline->frame_idx++] = recv_byte;
			}
		}
	}
}




//将所有传入的字符写入到指定的位置 ringbuf 中记录了上次写入位置，和总空间大小，以及上次读取位置
void protocol_pipe_put(struct protocol_pipe *pipeline, unsigned char * buff, unsigned int len)
{
	unsigned int i;
	//写入在后2/3空间中
	for (i = 0; i < len; i++)
	{	
		RINGBUF_Put(&pipeline->ringbuf, buff[i]);
	}
}



//比对两个字符串是否相同
char protocol_compare(const char * src, const char * aa)
{
	const char * start = src;
	int i = 0;
	int len = 0;
	//历遍其中一个字符串找到字符串结束标志 \0 记录历遍次数确定字符串长度
	while ((*(aa + len)) != '\0')
	{
		len++;
	}


	//if (*src == '\"') start = src + 1;
	//历遍整个字符串确认两个字符串是否完全一致
	for (i = 0; i < len; i++)
	{
		if (start[i] != aa[i])  return 0;
	}

	return 1;

}



//字符串转整数类型
int protocol_atoi(const char *str)
{
	int value = 0;
	//判断字符串是否是数字
	while (*str >= '0' && *str <= '9')
	{
		//上次计算的结果乘10，留出末位来累加本次的数值  -- 初始值为0不影响数据
		value *= 10;
		
		//加入本次的数值
		//*str 解析后应该是字符串类型的数字，两个字符串相减，会转换成ASCLL码值相减 
		value += *str - '0';
		
		str++;
	}
	return value;	//返回最终结果
}




//计算字符串中，有效字符的长度
int protocol_valuelen(const char *str)
{
	int len = 0;
	//遍历字符串 计算遇到}，：之前的字符长度
	while ((*(str + len)) != '}' && (*(str + len)) != ',' && (*(str + len)) != '\"' && (*(str + len)) != ':')
	{
		len++;
	}
	//返回长度
	return len;	
}

//初始化结构体
void protocol_send_init(struct protocol_send *send_protocol, unsigned char *buff, unsigned int max_len)
{
	//记录起始位置和储存空间大小
	send_protocol->buffer = buff;
	send_protocol->buffer_max_len = max_len;


}
//向发送缓存区内写入包头（{）
void protocol_send_start(struct protocol_send * send_protocol)
{
	//重置缓存区写入位置
	send_protocol->ptr = 0;
	//写入字符
	send_protocol->buffer[0] = '{';
	send_protocol->ptr++;

}



// void my_itoa(long num, char *string)
// {
// 	int power = 0, j = 0;

// 	j = num;
// 	for (power = 1; j>10; j /= 10)
// 		power *= 10;

// 	for (; power>0; power /= 10)
// 	{
// 		*string++ = '0' + num / power;
// 		num %= power;
// 	}
// 	*string = '\0';

// }


//向发送缓存区内写入单个字符
void protocol_send_insert_value(struct protocol_send * send_protocol, unsigned char byte)
{
	//判断缓存区是否写满
	if (send_protocol->ptr < send_protocol->buffer_max_len)
	{	
		//向缓存区写入数据
		send_protocol->buffer[send_protocol->ptr++] = byte;
	}

}

//向发送缓存区内写入数据（整数类型的）
void protocol_send_IdValue_int(struct protocol_send * send_protocol, const char * id, int value)
{
	int power = 0, j = 0;
	//向发送缓存区内写入单个字符
	protocol_send_insert_value(send_protocol, '\"');

	//历遍整个id字符串并写入缓存区
	while (*id != '\0')
	{
		protocol_send_insert_value(send_protocol, *id);
		id++;
	}

	//向发送缓存区内写入单个字符
	protocol_send_insert_value(send_protocol, '\"');
	protocol_send_insert_value(send_protocol, ':');
	protocol_send_insert_value(send_protocol, '\"');

	//判断收到的数据是否为负数
	if(value<0)
	{
		//将负数取正值
		value = -value;
		//写入负号
		protocol_send_insert_value(send_protocol, '-');
	}

	j = value;
	//判断数据有几位数，每多一位，power 乘一次 10 ，
	for (power = 1; j >= 10; j /= 10)
		power *= 10;

	//遍历数据的每一个数值，将其转换为字符写入缓存区
	for (; power > 0; power /= 10)
	{
		//写入当前数据的最高位
		protocol_send_insert_value(send_protocol, '0' + value / power);

		//去掉已经传输的数字
		value %= power;
	}

	//向发送缓存区内写入单个字符
	protocol_send_insert_value(send_protocol, '\"');
	protocol_send_insert_value(send_protocol, ',');

}


//向发送缓存区内写入数据（字符类型的）
void protocol_send_IdValue_str(struct protocol_send * send_protocol, const char * id, const  char * value)
{
	//向发送缓存区内写入单个字符
	protocol_send_insert_value(send_protocol, '\"');

	//写入id
	while (*id != '\0')
	{
		protocol_send_insert_value(send_protocol, *id);
		id++;
	}
	protocol_send_insert_value(send_protocol, '\"');
	protocol_send_insert_value(send_protocol, ':');

	protocol_send_insert_value(send_protocol, '\"');

	//写入value
	while (*value != '\0')
	{
		protocol_send_insert_value(send_protocol, *value);
		value++;
	}

	protocol_send_insert_value(send_protocol, '\"');
	protocol_send_insert_value(send_protocol, ',');

}


//写入包尾并调用回调函数发送
void protocol_send_complete(struct protocol_send * send_protocol, void(*device_send)(const unsigned char * src, int len))
{
	//上面添加过数据后会在后面写入一个，
	//检测最后一位是否是 ， 是证明有添加过数据
	if (send_protocol->buffer[send_protocol->ptr - 1] == ',')
	{	
		//将 ， 修改为 } 
		send_protocol->buffer[send_protocol->ptr - 1] = '}';

		//调用回调函数发送，并传入起始地址 和数据长度
		device_send(&send_protocol->buffer[0], send_protocol->ptr);

	}

}


void float2char(float slope,char*buffer,int n)  //浮点型数，存储的字符数组，字符数组的长度
{
    int temp,i,j;
    if(slope>=0)//判断是否大于0
        buffer[0] = '+';
    else
    {
        buffer[0] = '-';
        slope = -slope;
    }
    temp = (int)slope;//取整数部分
    for(i=0;temp!=0;i++)//计算整数部分的位数
        temp /=10;
    temp =(int)slope;
    for(j=i;j>0;j--)//将整数部分转换成字符串型
    {
        buffer[j] = temp%10+'0';
        temp /=10;
    }
    buffer[i+1] = '.';
    slope -=(int)slope;
    for(i=i+2;i<n-1;i++)//将小数部分转换成字符串型
    {
        slope*=10;
        buffer[i]=(int)slope+'0';
        slope-=(int)slope;
    }
    buffer[n-1] = '\0';
}


//向发送缓存区内写入数据（小数类型的）
void protocol_send_IdValue_float(struct protocol_send * send_protocol, const char * id, float value)
{
	static char buffer_float[8];
	float2char(value,buffer_float,sizeof(buffer_float));
	if(value<0)
	{
		protocol_send_IdValue_str(send_protocol,id,buffer_float);
	}
	else
	{
		protocol_send_IdValue_str(send_protocol,id,&buffer_float[1]);
	}

	 
}

void sensor_hal_protocol_init(struct protocol_send *protocol)
{
    sensor_protocol = protocol;
}

void GetSensor_IdValue_int(char *name, int value)
{
    protocol_send_IdValue_int(sensor_protocol, name, value);
}

void GetSensor_IdValue_str(char *name, char *value)
{
    protocol_send_IdValue_str(sensor_protocol, name, value);
}

void GetSensor_date_time(void)
{
    protocol_send_IdValue_int(sensor_protocol, "__time", 0);
}

void GetSensor_Time(char *name)
{
    static unsigned int time_count = 0;

    time_count++;

    protocol_send_IdValue_int(sensor_protocol, name, time_count);
}














