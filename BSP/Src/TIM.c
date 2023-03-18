/*
 * TIM.c
 *
 *  Created on: 15-Dec-2022
 *      Author: vicky
 */
#include "TIM.h"

TIM_HandleTypeDef htim;

volatile uint32_t sysTick = 0;;

void Timer_Init(TIM_TypeDef *Timer)
{
	htim.Instance = Timer;
	htim.Init.Prescaler = 1;
	htim.Init.Period = 20000-1;
	if(HAL_TIM_Base_Init(&htim) != HAL_OK)
	{
		Error_Handler();
	}
}

inline void Timer_Start(void)
{
	HAL_TIM_Base_Start(&htim);
}

inline void Timer_Start_IT(void)
{
	HAL_TIM_Base_Start_IT(&htim);
}

inline void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	sysTick++;
}
inline uint32_t SysTick_Get(void)
{
	return sysTick;
}
inline void SysTick_Set(uint8_t tmpSysTick)
{
	sysTick = (uint32_t)tmpSysTick;
}
