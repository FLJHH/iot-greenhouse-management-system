#ifndef __28BYJ48_H
#define __28BYJ48_H
#include "pin_define.h"

#define MOTOR_A         GPIO_Pin_7
#define MOTOR_B         GPIO_Pin_6
#define MOTOR_C         GPIO_Pin_4
#define MOTOR_D         GPIO_Pin_3
#define MOTOR_PROF      GPIOB

#define MOTOR_A_HING    GPIO_SetBits(MOTOR_PROF, MOTOR_A)				// �����
#define MOTOR_A_LOW     GPIO_ResetBits(MOTOR_PROF, MOTOR_A)			// �����

#define MOTOR_B_HING    GPIO_SetBits(MOTOR_PROF, MOTOR_B)				// �����
#define MOTOR_B_LOW     GPIO_ResetBits(MOTOR_PROF, MOTOR_B)		    // �����

#define MOTOR_C_HING    GPIO_SetBits(MOTOR_PROF, MOTOR_C)				// �����
#define MOTOR_C_LOW     GPIO_ResetBits(MOTOR_PROF, MOTOR_C)			// �����

#define MOTOR_D_HING    GPIO_SetBits(MOTOR_PROF, MOTOR_D)				// �����
#define MOTOR_D_LOW     GPIO_ResetBits(MOTOR_PROF, MOTOR_D)		    // �����






void MOTOR_Init(void);
void MOTOR_Control(unsigned char direction,unsigned int phase);



// void Step_Motor_GPIO_Init(void);
// void SetMotor(unsigned char InputData);//���ݴ��͵�����Inputdata���������������
// void motorNcircle(int n,int position);//nΪ�������ת����Ȧ����positionΪ��ת���߷�ת


#endif
