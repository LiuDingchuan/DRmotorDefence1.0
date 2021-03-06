#ifndef __CAN1_H
#define __CAN1_H

#include "tim3.h"
#include "param.h"
#include "macro.h"
#include "includes.h"
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_gpio.h"

void CAN1_Configuration(void);
void answer_master(CanRxMsg *rx_message);

#endif


