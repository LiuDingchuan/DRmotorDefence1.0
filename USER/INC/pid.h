#ifndef _PID_H
#define _PID_H

#include "stm32f4xx.h"

typedef struct
{
  volatile s32 SetValue;//�趨ֵ
	volatile float KP;//����ϵ��
	volatile float KI;//����ϵ��
	volatile float KD;//΢�ֳ���
	volatile float KS;//�ٶȽ�ϵ
	volatile s32 Udlt;
	volatile s32 CurValue;
	volatile s32 liKkValue[3];//��ֵ���棬�����ͷ����Ĳ�ֵ
}PID_setTypeDef;

void PID_Init(PID_setTypeDef *PID,float KP,float KI,float KD,float KS,s32 Set);
void PID_Operation(PID_setTypeDef *PID);

extern PID_setTypeDef SunnySkyPID, U10PID, DJ3508PID, DJ2006PID;

#endif
