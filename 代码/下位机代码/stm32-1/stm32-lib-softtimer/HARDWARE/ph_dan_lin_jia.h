#ifndef __PH_DAN_LIN_JIA_H__
#define __PH_DAN_LIN_JIA_H__

 

void ph_dan_lin_jia_trigger(void (*uart_send)(unsigned char *buff,unsigned int len));

void ph_dan_lin_jia_parse(unsigned char * input_buff ,unsigned int input_len ,void (*callback)(int ph,int dan,int lin,int jia));


#endif  
	 

