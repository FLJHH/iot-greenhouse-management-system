#include "ms53lom.h"


void ms53lom_trigger(void (*uart_send)(unsigned char *buff,unsigned int len))
{
    unsigned char send_cmd[9] = {0x51,0x0A,0x00,0x01,0x00,0x05,0x02,0x00,0x63}; //单次请求
   	uart_send(send_cmd,9);

}


void ms53lom_parse(unsigned char *input_buff, unsigned int input_len, void (*callback)(int value))
{
    static unsigned char ms53l0m_data_buff[30]; //用来储存已经接收到的数据
    static unsigned char ms53l0m_rules_buff[8]={0x55,0x0A,0X00,0X01,0X00,0X00,0X05,0X02}; //用来储存已经接收到的数据
    static unsigned int ms53lom_value = 0;
    static int index = 0;                       //记录当前写的buff的位置
    static char flag_state = 0;
    unsigned char *temp_pointer = input_buff;   //记录开始地址
    int len_to_Read = input_len;                //记录获取的长度
    unsigned char temp_value;                   //储存当前数据

    // 判断传进来的是否有数据
    if(len_to_Read > 11)
    {
        // 检测数据是否已经全部读完，并且不能超过 数组的长度
        while((len_to_Read--)&& (index < sizeof(ms53l0m_data_buff)))
        {
            temp_value = *temp_pointer++;

            if(temp_value == 0x55  && !flag_state )
            {
                
                while ((*( temp_pointer + index ) == ms53l0m_rules_buff[index +1]) && index < 7)
                {
                    index++;
                }

                if(index == 7)
                {
                    flag_state = 1;
                    index = 8;
                    temp_pointer = temp_pointer +7;
                }
                else
                {
                    index = 0;
                }
                
            }
          
            else if(flag_state == 1)
            {

                ms53l0m_data_buff[index++] = temp_value;

                if(index >=10)
                {
                    ms53lom_value = (ms53l0m_data_buff[8] << 8) + ms53l0m_data_buff[9];
                    callback(ms53lom_value);
                    index = 0;
                    flag_state = 0;
                }
                
            }

        }

    }

}
















