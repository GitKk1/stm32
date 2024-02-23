#include "stm32f10x.h"                  // Device header


#ifndef __Key_H
#define __Key_H

uint8_t Key_Judge(void);
void Key_Init(uint32_t GPIO,uint16_t Pin);
 

#endif
