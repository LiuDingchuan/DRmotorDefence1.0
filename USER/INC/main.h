#ifndef _MAIN_H
#define _MAIN_H

#include "led.h"
#include "elmo.h"
#include "beep.h"
#include "param.h"
#include "led8.h"
#include "usart1.h"
#include "usart2.h"
#include "tim2.h"
#include "tim3.h"
#include "can1.h"
#include "visual_scope.h"
#include "stm32f4xx.h"
#include "motor.h"
#include "VisualScope.h"

extern bool motorSwitchOn;
/**UCOSII��������**/
//START����
#define START_TASK_PRIO          5            //�����������ȼ�
#define START_TASK_STK_SIZE      256          //���ö�ջ��С
__align(8) OS_STK START_TASK_STK[START_TASK_STK_SIZE];
static void Task_Start(void *pdata);

//LCD����
#define LCD_TASK_PRIO 10               //�����������ȼ�
#define LCD_STK_SIZE 512                   //���ö�ջ��С
__align(8) OS_STK LCD_TASK_STK[LCD_STK_SIZE];
static void Task_LCD(void *pdata);

//ELMO����
#define ELMO_TASK_PRIO 11 //�����������ȼ�
#define ELMO_STK_SIZE 512 //���ö�ջ��С
__align(8) OS_STK  ELMO_TASK_STK[ELMO_STK_SIZE]; //�����ջ
static void Task_ELMO(void *pdata); //������

//VESC����
#define VESC_TASK_PRIO 12 //�����������ȼ�
#define VESC_STK_SIZE 512 //���ö�ջ��С
__align(8) OS_STK  VESC_TASK_STK[VESC_STK_SIZE]; //�����ջ
static void Task_VESC(void *pdata); //������

//ZERO�����ϵ�ʱλ�����㣩
#define ZERO_TASK_PRIO 14 //�����������ȼ�
#define ZERO_STK_SIZE 64 //���ö�ջ��С
__align(8) OS_STK  ZERO_TASK_STK[ZERO_STK_SIZE]; //�����ջ
static void Task_ZERO(void *pdata); //������

//Task_PICKUPARROW
#define PICKUPARROW_TASK_PRIO 15
#define PICKUPARROW_STK_SIZE 128
__align(8) OS_STK PICKUPARROW_TASK_STK[PICKUPARROW_STK_SIZE];
static void Task_PICKUPARROW(void *pdata);

//Task_SHOOTING
#define SHOOTING_TASK_PRIO 16
#define SHOOTING_STK_SIZE 128
__align(8) OS_STK SHOOTING_TASK_STK[SHOOTING_STK_SIZE];
static void Task_SHOOTING(void *pdata);

//Task_FLAG
#define FLAG_TASK_PRIO 17
#define FLAG_STK_SIZE 128
__align(8) OS_STK FLAG_TASK_STK[FLAG_STK_SIZE];
static void Task_FLAG(void *pdata);

//Task_VisualScope
#define VISUALSCOPE_TASK_PRIO 19 //�����������ȼ�
#define VISUALSCOPE_STK_SIZE 128 //���ö�ջ��С
__align(8) OS_STK  VISUALSCOPE_TASK_STK[VISUALSCOPE_STK_SIZE]; //�����ջ
static void Task_VISUALSCOPE(void *pdata); //������

#define BEEP_TASK_PRIO 8	//�����������ȼ�
#define BEEP_STK_SIZE 64 //���ö�ջ��С
__align(8) OS_STK  BEEP_TASK_STK[BEEP_STK_SIZE]; //�����ջ
static void Task_BEEP(void *pdata); //������

OS_EVENT *RUN;

#endif
