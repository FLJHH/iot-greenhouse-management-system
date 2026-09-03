#ifndef __KEY_H
#define __KEY_H	 

// A8 A12 B3 B4 B5 B6

#define  KEY_GPIO_Group_1   GPIOA
#define  KEY_GPIO_Pin_1     GPIO_Pin_8
#define  KEY_GPIO_1         GPIO_ReadInputDataBit( KEY_GPIO_Group_1, KEY_GPIO_Pin_1 )

#define  KEY_GPIO_Group_2   GPIOA
#define  KEY_GPIO_Pin_2     GPIO_Pin_12
#define  KEY_GPIO_2         GPIO_ReadInputDataBit( KEY_GPIO_Group_2, KEY_GPIO_Pin_2 )

#define  KEY_GPIO_Group_3   GPIOB
#define  KEY_GPIO_Pin_3     GPIO_Pin_3
#define  KEY_GPIO_3         GPIO_ReadInputDataBit( KEY_GPIO_Group_3, KEY_GPIO_Pin_3 )

#define  KEY_GPIO_Group_4   GPIOB
#define  KEY_GPIO_Pin_4     GPIO_Pin_4
#define  KEY_GPIO_4         GPIO_ReadInputDataBit( KEY_GPIO_Group_4, KEY_GPIO_Pin_4 )

#define KEY_active_1  (0)
#define KEY_active_2  (0)
#define KEY_active_3  (0)
#define KEY_active_4  (0)

#define KEY16_Row (0)
#define KEY16_Col (1)

// ���󰴼�

#define Sensor_Port_16Key_C0l1    GPIOB
#define Sensor_Pin_16Key_C0l1     GPIO_Pin_6

#define Sensor_Port_16Key_C0l2    GPIOB
#define Sensor_Pin_16Key_C0l2     GPIO_Pin_7

#define Sensor_Port_16Key_C0l3    GPIOB
#define Sensor_Pin_16Key_C0l3     GPIO_Pin_8

#define Sensor_Port_16Key_C0l4    GPIOB
#define Sensor_Pin_16Key_C0l4     GPIO_Pin_9

#define Sensor_Port_16Key_Row1    GPIOB
#define Sensor_Pin_16Key_Row1    GPIO_Pin_12

#define Sensor_Port_16Key_Row2    GPIOB
#define Sensor_Pin_16Key_Row2    GPIO_Pin_13

#define Sensor_Port_16Key_Row3    GPIOB
#define Sensor_Pin_16Key_Row3    GPIO_Pin_14

#define Sensor_Port_16Key_Row4    GPIOB
#define Sensor_Pin_16Key_Row4    GPIO_Pin_15

#define KEY16_Row1_Write       PBout(15)
#define KEY16_Row2_Write       PBout(14)
#define KEY16_Row3_Write       PBout(13)
#define KEY16_Row4_Write       PBout(12)

#define KEY16_Row1_Read        PBin(15)
#define KEY16_Row2_Read        PBin(14)
#define KEY16_Row3_Read        PBin(13)
#define KEY16_Row4_Read        PBin(12)

#define KEY16_Col1_Write       PBout(6)
#define KEY16_Col2_Write       PBout(7)
#define KEY16_Col3_Write       PBout(8)
#define KEY16_Col4_Write       PBout(9)

#define KEY16_Col1_Read        PBin(6)
#define KEY16_Col2_Read        PBin(7)
#define KEY16_Col3_Read        PBin(8)
#define KEY16_Col4_Read        PBin(9)


void key_button_init(void);

void key_button_register( void (*callback)(unsigned char key_number) );

void key_button_scan_10ms(void);

void key_button_scan_1ms(void);

void key16_button_scan_10ms(void);
	

#endif
