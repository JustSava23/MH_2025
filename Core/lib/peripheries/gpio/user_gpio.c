/*
 * user_gpio.c
 *
 *  Created on: Dec 4, 2025
 *      Author: lazar
 */
#include "stm32f4xx.h"
#include "user_gpio.h"

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	switch(GPIO_Pin)
	{
	case GPIO_PIN_13:
	{
		GPIOA->ODR ^= (1 << 5);
		break;
	}
	}
}

