/*
 * user_main.c
 *
 *  Created on: 04.12.2025.
 *      Author: lazar
 */
#include "stm32f4xx.h"
#include "user_main.h"
#include "peripheries/timer/timer.h"
#include "tim.h"

void
user_main()
{
	/* Init */

	// Pokreni tajmer da broji
	HAL_TIM_Base_Start_IT(&htim4);

	/* While petlja */
	while (1)
	{
		GPIOA->ODR ^= (1 << 5);
		user_delay_ms(500);
	}
}
