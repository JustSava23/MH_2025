/*
 * user_gpio.c
 *
 *  Created on: Dec 4, 2025
 *      Author: lazar
 */
#include "stm32f4xx.h"
#include "user_gpio.h"

volatile uint8_t flg_blue_btn_pressed = 0;

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	switch(GPIO_Pin)
	{
	case GPIO_PIN_13:
	{
		flg_blue_btn_pressed = 1;
		break;
	}
	}
}

