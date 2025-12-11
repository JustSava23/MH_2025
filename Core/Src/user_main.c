/*
 * user_main.c
 *
 *  Created on: 04.12.2025.
 *      Author: lazar
 */
#include "stm32f4xx.h"
#include "user_main.h"
#include "peripheries/timer/timer.h"
#include "peripheries/gpio/user_gpio.h"
#include "tim.h"

typedef enum
{
	NO_BLINK,
	BLINK100MS,
	BLINK500MS,
	BLINK1000MS,
}FSM_States_TypeDef;


void
user_main()
{
	/* Init */
	FSM_States_TypeDef current_state = NO_BLINK;
	uint8_t init_state = 0;

	// Pokreni tajmer da broji
	HAL_TIM_Base_Start_IT(&htim4);

	/* While petlja */
	while (1)
	{

		switch (current_state) {
		case NO_BLINK:
			/* Init */

			/* Telo */

			/* Provera uslova prelaska */
			if (flg_blue_btn_pressed)
			{
				current_state = BLINK100MS;
				flg_blue_btn_pressed = 0;
				init_state = 1;
			}
			break;
		case BLINK100MS:
			/* Init */
			if (init_state)
			{
				set_timeout_ms(100);
				init_state = 0;
			}
			/* Telo */
			if (timeout_flags.timeout_end)
			{
				GPIOA->ODR ^= (1 << 5);
				set_timeout_ms(100);
			}
			/* Provera uslova prelaska */
			if (flg_blue_btn_pressed)
			{
				flg_blue_btn_pressed = 0;
				current_state = BLINK500MS;
				init_state = 1;
			}
			break;

		case BLINK500MS:
			/* Init */
			if (init_state)
			{
				set_timeout_ms(500);
				init_state = 0;
			}
			/* Telo */
			if (timeout_flags.timeout_end)
			{
				GPIOA->ODR ^= (1 << 5);
				set_timeout_ms(500);
			}

			/* Provera uslova prelaska */
			if (flg_blue_btn_pressed)
			{
				flg_blue_btn_pressed = 0;
				current_state = BLINK1000MS;
				init_state = 1;
			}
			break;

		case BLINK1000MS:
			/* Init */
			if (init_state)
			{
				set_timeout_ms(1000);
				init_state = 0;
			}
			/* Telo */
			if (timeout_flags.timeout_end)
			{
				GPIOA->ODR ^= (1 << 5);
				set_timeout_ms(1000);
			}

			/* Provera uslova prelaska */
			if (flg_blue_btn_pressed)
			{
				flg_blue_btn_pressed = 0;
				current_state = BLINK100MS;
				init_state = 1;
			}
			break;
		}


	}
}
