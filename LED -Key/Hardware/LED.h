#include "stm32f10x.h"                  // Device header

#ifndef __LED_H
#define __LED_H

void LED_Init(uint32_t GPIO,uint16_t Pin);
void LED_Ctrl(uint8_t Sta,GPIO_TypeDef* GPIOx,uint16_t Pin);
#endif
