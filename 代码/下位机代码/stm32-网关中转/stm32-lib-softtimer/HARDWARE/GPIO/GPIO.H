#ifndef __GPIO_H
#define __GPIO_H

void GPIO_Init_Mode(void);

void InitSensor_Beep(void);

void InitSensor_OUTPUT_DO2(void);
void InitSensor_OUTPUT_DO3(void);

void InitSensor_OUTPUT_DO4(void);

void InitSensor_OUTPUT_DO5(void);

void InitSensor_Jidianqi(void);

void InitSensor_Jidianqi_2(void);
 void SetSensor_Beep(unsigned char value);

void SetSensor_Jidianqi(unsigned char value);

void SetSensor_Jidianqi_2(unsigned char value);

void InitSensor_INPUT_DO2(void);
void InitSensor_INPUT_DO3(void);

void InitSensor_INPUT_DO4(void);

void InitSensor_INPUT_DO5(void);

void SetSensor_DO2(unsigned char value);

void SetSensor_DO3(unsigned char value);

void SetSensor_DO4(unsigned char value);
void SetSensor_DO5(unsigned char value);

unsigned char  Get_DO2(void);

unsigned char  Get_DO3(void);

unsigned char  Get_DO4(void);

unsigned char  Get_DO5(void);

void InitSensor_Voice(void);
unsigned char Get_Voice(void);

void InitSensor_Renti(void);
unsigned char Get_Renti(void);


void InitSensor_Key(void);
unsigned char Get_Key(void);



void InitSensor_Huoyan(void);
unsigned char Get_Huoyan(void);

#endif  
	 

