/*
 * odom.h
 *
 *  Created on: Dec 18, 2025
 *      Author: lazar
 */

#ifndef LIB_MODULE_ODOM_ODOM_H_
#define LIB_MODULE_ODOM_ODOM_H_

extern volatile float
x,
y,
theta,
v,
w,
v_desni,
v_levi;

void odom_update();

float normalize_rad_angle(float angle);

#endif /* LIB_MODULE_ODOM_ODOM_H_ */
