/*
 * pid.h
 *
 *  Created on: 2020. 12. 26.
 *      Author: WANG
 */

#ifndef SRC_COMMON_CORE_PID_H_
#define SRC_COMMON_CORE_PID_H_

#include "def.h"


#define PID_SAMPLING_TIME   0.004f

#define D_FILTER_COFF       0.025f

typedef struct pidc_t {
	float ts;
	float kp[3];
	float kp1[3];
	float kp2[3];
  float kp_rate[3];

	float ki[3];
	float ki1[3];
	float ki2[3];
  float ki_rate[3];

	float kd[3];
	float kd2[3];
  float kd_rate[3];

	float i1_limit[3];
	float i2_limit[3];

	float Iterm[3];
	float Iterm1[3];
	float Iterm2[3];

	float dInput[3];

	float error[3];
	float pre_error[3];
	float pre_deriv[3];

	float lastInput[3];
	float output1[3];
	float output2[3];
} pidc_t;

void PIDControlInit(pidc_t *pid);
void Control(pidc_t *pid);

int constrain(int amt, int low, int high);

#endif /* SRC_COMMON_CORE_PID_H_ */
