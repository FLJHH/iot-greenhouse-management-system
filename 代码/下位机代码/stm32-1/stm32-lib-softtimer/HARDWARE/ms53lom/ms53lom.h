
#ifndef _MS53L0M_H
#define _MS53L0M_H

void ms53lom_trigger(void (*uart_send)(unsigned char *buff,unsigned int len));
void ms53lom_parse(unsigned char *input_buff, unsigned int input_len, void (*callback)(int value));

#endif
