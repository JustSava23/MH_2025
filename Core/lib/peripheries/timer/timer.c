/*
 * timer.c
 *
 *  Created on: Dec 4, 2025
 *      Author: lazar
 */
#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_tim.h"
#include "timer.h"

volatile uint32_t sys_ms = 0;

void
user_delay_ms(uint16_t ms)
{
	uint32_t tmp = sys_ms; // copy current sys_ms
	while ((sys_ms - tmp) < ms);
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if (htim->Instance == TIM4)
	{
		sys_ms++;
	}
}
