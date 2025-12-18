/*
 * encoder.c
 *
 *  Created on: Dec 18, 2025
 *      Author: lazar
 */

#include "encoder.h"


/*
 * @brief Set initial values for encoders.
 */
void
encoders_init()
{
	TIM2->CNT = ENC_START_CNT;
	TIM3->CNT = ENC_START_CNT;
}

int32_t
encoder1_get_delta_inc()
{
	int32_t tmp = (TIM2->CNT - ENC_START_CNT);
	TIM2->CNT = ENC_START_CNT;
	return tmp;
}

int32_t
encoder2_get_delta_inc()
{
	int32_t tmp = (TIM3->CNT - ENC_START_CNT);
	TIM3->CNT = ENC_START_CNT;
	return tmp;
}
