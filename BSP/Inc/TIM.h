/*
 * TIM.h
 *
 *  Created on: 15-Dec-2022
 *      Author: vicky
 */

#ifndef INC_TIM_H_
#define INC_TIM_H_

#include "main.h"


void Timer_Init(TIM_TypeDef *timer);

void Timer_Start(void);
void Timer_Start_IT(void);

void SysTick_Set(uint8_t tmpSysTick);
uint32_t SysTick_Get(void);


#endif /* INC_TIM_H_ */
