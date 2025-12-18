/*
 * odom.c
 *
 *  Created on: Dec 18, 2025
 *      Author: lazar
 */

#include "stm32f4xx.h"
#include "odom.h"
#include "peripheries/encoder/encoder.h"

#include <math.h>

const float
c_inc2rad = 2 * M_PI / 8192; //convert inc 2 rad

const float
dt = 1 / 100.0; // 100 Hz

const float
r_desni = 0.076 / 2; // [m]

const float
r_levi = 0.076 / 2; // [m]

const float
razmak_izmedju_tockova = 0.225; // [m]

volatile float
x = 0,
y = 0,
theta = 0,
v = 0,
w = 0,
v_desni = 0,
v_levi = 0;

void odom_update()
{
	int32_t enc1_delta = encoder1_get_delta_inc(); //desni
	int32_t enc2_delta = encoder2_get_delta_inc(); //levi

	v_desni = enc1_delta * c_inc2rad * r_desni / dt;
	v_levi = enc2_delta * c_inc2rad * r_levi / dt;

	v = (v_desni + v_levi) / 2.0;
	w = (v_desni - v_levi) / razmak_izmedju_tockova;

	x += v * dt * cos(theta + w * dt / 2.0);
	y += v * dt * sin(theta + w * dt / 2.0);
	theta += w * dt;

	theta = normalize_rad_angle(theta);

}

float normalize_rad_angle(float angle)
{
	if (angle > M_PI)
	{
		return angle - 2 * M_PI;
	}
	if (angle < -M_PI)
	{
		return angle + 2 * M_PI;
	}

	return angle;
}
