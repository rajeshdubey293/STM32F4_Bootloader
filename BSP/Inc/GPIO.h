/*
 * GPIO.h
 *
 *  Created on: Dec 6, 2022
 *      Author: vicky
 */

#ifndef INC_GPIO_H_
#define INC_GPIO_H_

#include "main.h"

/*  STM32F429 LED related Macros */

#define OUTPUT				GPIO_MODE_OUTPUT_PP
//#define OUTPUT_OD			GPIO_MODE_OUTPUT_OD
#define INPUT				GPIO_MODE_INPUT
#define ANALOG				GPIO_MODE_ANALOG

#define RED_LED_PORT		GPIOG
#define RED_LED_PIN			GPIO_PIN_14

#define GREEN_LED_PORT		GPIOG
#define GREEN_LED_PIN		GPIO_PIN_15

#define USER_INPUT_PORT		GPIOA
#define USER_INPUT_PIN		GPIO_PIN_0


void GPIO_Init(GPIO_TypeDef *port, uint16_t pin_number, uint32_t mode);
void Clock_Enable(GPIO_TypeDef *port);

void GPIO_Pin_Toggle(GPIO_TypeDef *port, uint16_t pin_number);
void GPIO_Pin_Reset(GPIO_TypeDef *port, uint16_t pin_number);
void GPIO_Pin_Set(GPIO_TypeDef *port, uint16_t pin_number);

#endif /* INC_GPIO_H_ */
