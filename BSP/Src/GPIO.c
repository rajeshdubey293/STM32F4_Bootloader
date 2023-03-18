/*
 * GPIO.c
 *
 *  Created on: Dec 6, 2022
 *      Author: vicky
 */

#include "GPIO.h"

void GPIO_Init(GPIO_TypeDef *port, uint16_t pin_number)
{
	GPIO_InitTypeDef gpio_init_struct = {0};
	Clock_Enable(port);
	gpio_init_struct.Pin = pin_number;
	gpio_init_struct.Mode = GPIO_MODE_OUTPUT_PP;
	gpio_init_struct.Pull = GPIO_NOPULL;
	gpio_init_struct.Speed = GPIO_SPEED_FAST;
	HAL_GPIO_Init(port, &gpio_init_struct);
}

void Clock_Enable(GPIO_TypeDef *port)
{
	if(port == GPIOA)
		__HAL_RCC_GPIOA_CLK_ENABLE();
	else if(port == GPIOB)
		__HAL_RCC_GPIOB_CLK_ENABLE();
	else if(port == GPIOC)
		__HAL_RCC_GPIOC_CLK_ENABLE();
	else if(port == GPIOD)
		__HAL_RCC_GPIOD_CLK_ENABLE();
	else if(port == GPIOE)
		__HAL_RCC_GPIOE_CLK_ENABLE();
	else if(port == GPIOF)
		__HAL_RCC_GPIOF_CLK_ENABLE();
	else if(port == GPIOG)
		__HAL_RCC_GPIOG_CLK_ENABLE();
	else if(port == GPIOH)
		__HAL_RCC_GPIOH_CLK_ENABLE();
	else
		printf("Enter Valid Port\r\n");
}

inline void GPIO_Pin_Toggle(GPIO_TypeDef *port, uint16_t pin_number)
{
	HAL_GPIO_TogglePin(port, pin_number);
}
inline void GPIO_Pin_Set(GPIO_TypeDef *port, uint16_t pin_number)
{
	HAL_GPIO_WritePin(port, pin_number, GPIO_PIN_SET);
}
inline void GPIO_Pin_Reset(GPIO_TypeDef *port, uint16_t pin_number)
{
	HAL_GPIO_WritePin(port, pin_number, GPIO_PIN_RESET);
}
