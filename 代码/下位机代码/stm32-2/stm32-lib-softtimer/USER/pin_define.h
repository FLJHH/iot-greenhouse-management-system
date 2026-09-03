#ifndef __PIN_DEFINE_H__
#define __PIN_DEFINE_H__
#include "sys.h"   

#define Port_to_RCC(port)      RCC_APB2Periph_##port


// 脉冲计数

// AO 

// DO 

// 测速

// 光强

// 烟雾

// MQ

// 雨滴

// 水位

// 土壤

// 人体
#define Sensor_Port_Renti_1          GPIOB
#define Sensor_Pin_Renti_1           GPIO_Pin_9
#define Sensor_Rcc_Renti_1           RCC_APB2Periph_GPIOB



#define Sensor_Port_Renti_2          GPIOB
#define Sensor_Pin_Renti_2           GPIO_Pin_15
#define Sensor_Rcc_Renti_2           RCC_APB2Periph_GPIOB

// 声音
#define Sensor_Port_Voice           GPIOB
#define Sensor_Pin_Voice            GPIO_Pin_8
#define Sensor_Rcc_Voice            RCC_APB2Periph_GPIOB


// ds18b20
#define Sensor_Port_Ds18b20         GPIOA
#define Sensor_Pin_Ds18b20          GPIO_Pin_12
#define Sensor_Rcc_Ds18b20          RCC_APB2Periph_GPIOA


// dht11
// //IO方向设置
// #define DHT11_IO_IN()  {GPIOB->CRH&=0XFFFF0FFF;GPIOB->CRH|=8<<12;}
// #define DHT11_IO_OUT() {GPIOB->CRH&=0XFFFF0FFF;GPIOB->CRH|=3<<12;}
// //IO操作函数											   
// #define	DHT11_DQ_OUT PBout(11) //数据端口	PB11 
// #define	DHT11_DQ_IN  PBin(11)  //数据端口	PB11
// #define Sensor_GPIO_Ds18b20     GPIOA
// #define Sensor_PIN_Ds18b20      GPIO_Pin_12


// 火焰
#define Sensor_Port_Huoyan          GPIOB
#define Sensor_Pin_Huoyan           GPIO_Pin_4
#define Sensor_Rcc_Huoyan           RCC_APB2Periph_GPIOB

// 红外对管
#define Sensor_Port_Hongwai         GPIOB
#define Sensor_Pin_Hongwai          GPIO_Pin_12
#define Sensor_Rcc_Hongwai          RCC_APB2Periph_GPIOB

// 震动
#define Sensor_Port_Zhendong_high   GPIOB
#define Sensor_Pin_Zhendong_high    GPIO_Pin_13
#define Sensor_Rcc_Zhendong         RCC_APB2Periph_GPIOB

// key
#define Sensor_Port_Key_1           GPIOA
#define Sensor_Pin_Key_1            GPIO_Pin_8
#define Sensor_Rcc_Key_1            RCC_APB2Periph_GPIOA

#define Sensor_Port_Key_2           GPIOA
#define Sensor_Pin_Key_2            GPIO_Pin_15
#define Sensor_Rcc_Key_2            RCC_APB2Periph_GPIOA

// RC522
#define Sensor_Port_RC522_RST       GPIOA
#define Sensor_Pin_RC522_RST        GPIO_Pin_12
#define Sensor_Rcc_RC522_RST        RCC_APB2Periph_GPIOA

#define Sensor_Port_RC522_MISO      GPIOB
#define Sensor_Pin_RC522_MISO       GPIO_Pin_6
#define Sensor_Rcc_RC522_MISO       RCC_APB2Periph_GPIOB

#define Sensor_Port_RC522_MOSI      GPIOB
#define Sensor_Pin_RC522_MOSI       GPIO_Pin_8
#define Sensor_Rcc_RC522_MOSI       RCC_APB2Periph_GPIOB

#define Sensor_Port_RC522_SCK       GPIOB
#define Sensor_Pin_RC522_SCK        GPIO_Pin_13
#define Sensor_Rcc_RC522_SCK        RCC_APB2Periph_GPIOB

#define Sensor_Port_RC522_NSS       GPIOB
#define Sensor_Pin_RC522_NSS        GPIO_Pin_15
#define Sensor_Rcc_RC522_NSS        RCC_APB2Periph_GPIOB

// 压力/血压
#define Sensor_Port_HX711_SCK       GPIOB
#define Sensor_Pin_HX711_SCK        GPIO_Pin_0
#define Sensor_Rcc_HX711_SCK        RCC_APB2Periph_GPIOB

#define Sensor_Port_HX711_DOUT      GPIOB
#define Sensor_Pin_HX711_DOUT       GPIO_Pin_1
#define Sensor_Rcc_HX711_DOUT       RCC_APB2Periph_GPIOB

#define HX711_SCK PBout(0)// PB0
#define HX711_DOUT PBin(1)// PB1



// 超声波

// 浊度

// PH

// mpu6050--串口1

// 红外测温--串口1

// pm25--串口1

// tds--串口1

// 心率血氧(max30102)

// 紫外线

// 电流

// 电压

// GPS--串口1










#endif



