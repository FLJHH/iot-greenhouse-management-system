// #include <string.h>
#include "ph_dan_lin_jia.h"



void ph_dan_lin_jia_trigger(void (*uart_send)(unsigned char *buff,unsigned int len))
{
	unsigned char send_cmd[8] = {0x01,0x03,0x00,0x03,0x00,0x04,0xB4,0x09}; //单次请求
   	uart_send(send_cmd,8);
}



void ph_dan_lin_jia_parse(unsigned char * input_buff ,unsigned int input_len ,void (*callback)(int ph,int dan,int lin,int jia))
{
	static unsigned char ph_dan_lin_jia_buff[20];
	static int index = 0;
	static unsigned char last_value = 0; //上一个字节
	static unsigned char last_value_last = 0; //上上一个字节
	static unsigned char flag_state = 0;
 
	int len_to_Read = input_len;
	unsigned char temp_value;
	unsigned char * temp_pointer = input_buff ;
	int ph,dan,lin,jia;




	if (len_to_Read > 0)
	{

		while ((len_to_Read--) && (index < sizeof(ph_dan_lin_jia_buff)))
		{
			temp_value = *temp_pointer++;

			if (temp_value == 0x08 && last_value == 0x03 && last_value_last==0x01 && flag_state==0)
			{
				flag_state = 1;  //找到头
				ph_dan_lin_jia_buff[0] = 0x01;
				ph_dan_lin_jia_buff[1] = 0x03;
				ph_dan_lin_jia_buff[2] = 0x08;
				index = 3 ;

			}
			else if(flag_state==1)
			{	
				ph_dan_lin_jia_buff[index++] = temp_value;

				if(index>=13)
				{
					ph = ph_dan_lin_jia_buff[3]*0xff + ph_dan_lin_jia_buff[4];
					dan = ph_dan_lin_jia_buff[5]*0xff + ph_dan_lin_jia_buff[6];
					lin = ph_dan_lin_jia_buff[7]*0xff + ph_dan_lin_jia_buff[8];
					jia = ph_dan_lin_jia_buff[9]*0xff + ph_dan_lin_jia_buff[10];
					
					callback(ph,dan,lin,jia);

					flag_state=0;
					index=0;
				}

			}
			last_value_last = last_value ;
			last_value = temp_value;
		}
	}
}

