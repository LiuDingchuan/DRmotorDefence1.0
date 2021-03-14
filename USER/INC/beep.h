#ifndef _BEEP_H
#define _BEEP_H

#include "includes.h"
#include "sys.h"
#include "delay.h"  
#include "led.h"
#include "tim1.h"

#define  ZERO  0
#define  R1  10000 //F_CLOCK/(psc+1)=10000
#define  L1       (R1/262)-1        //µÍ1¡¡DO
#define  half_L1 £¨R1/277)-1        //#1¡¡DO#
#define  L2       (R1/294)-1
#define  half_L2  (R1/311)-1
#define  L3       (R1/330)-1
#define  L4       (R1/349)-1
#define  half_L4  (R1/370)-1
#define  L5       (R1/392)-1
#define  half_L5  (R1/410)-1
#define  L6       (R1/440)-1
#define  half_L6  (R1/466)-1
#define  L7       (R1/494)-1

#define  M1       (R1/523)-1        //ÖÐ1¡¡DO
#define  half_M1 £¨R1/554)-1        //#1¡¡ DO#
#define  M2       (R1/600)-1
#define  half_M2  (R1/622)-1
#define  M3       (R1/659)-1
#define  M4       (R1/698)-1
#define  half_M4  (R1/740)-1
#define  M5       (R1/784)-1
#define  half_M5  (R1/831)-1
#define  M6       (R1/880)-1
#define  half_M6  (R1/932)-1
#define  M7       (R1/988)-1

#define  H1       (R1/1046)-1        //¸ß1¡¡DO
#define  half_H1 £¨R1/1109)-1        //#1¡¡DO#
#define  H2       (R1/1175)-1
#define  half_H2  (R1/1245)-1
#define  H3       (R1/1318)-1
#define  H4       (R1/1397)-1
#define  half_H4  (R1/1480)-1
#define  H5       (R1/1568)-1
#define  half_H5  (R1/1661)-1
#define  H6       (R1/1760)-1
#define  half_H6  (R1/1865)-1
#define  H7       (R1/1967)-1

extern int length;
extern int tune[];
extern float duration[];
extern u8 Beep_Count;

#define BEEP_ON     	 GPIOA->BSRRL = GPIO_Pin_8
#define BEEP_OFF     	 GPIOA->BSRRH = GPIO_Pin_8

void Beep_Configuration(void);
void Beep_Show(u8 num);
void Beep_Music(void);

#endif


