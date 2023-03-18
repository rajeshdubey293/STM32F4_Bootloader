/*
 * GPIO.h
 *
 *  Created on: Dec 6, 2022
 *      Author: vicky
 */

#ifndef INC_GPIO_H_
#define INC_GPIO_H_

#include "main.h"


void GPIO_Init(GPIO_TypeDef *port, uint16_t pin_number);
void Clock_Enable(GPIO_TypeDef *port);

void GPIO_Pin_Toggle(GPIO_TypeDef *port, uint16_t pin_number);
void GPIO_Pin_Reset(GPIO_TypeDef *port, uint16_t pin_number);
void GPIO_Pin_Set(GPIO_TypeDef *port, uint16_t pin_number);

#endif /* INC_GPIO_H_ */
