/*
 * pid.c
 *
 *  Created on: 2020. 12. 26.
 *      Author: WANG
 */

#include "pid.h"


static float dt_recip;

extern flags_t f;
extern rc RC;
extern imu_t imu;
extern uint16_t debug[4];
extern int16_t  GPS_angle[2];
extern gps_t GPS;
extern int16_t  nav[2];


// Configure PID
#ifdef MOTOR_DC
#define OUT_MAX      800      // Out PID maximum 250
#define OUT_MAX_Y    800      // Out PID maximum 250
#define I_MAX        400      // Out I_term maximum 300
#define I_MAX_Y      400      // Out I_term maximum 300
#define DIR        1        // Direct PID Direction 1
#endif
#ifdef MOTOR_ESC
#define OUT_MAX      1000      // Out PID maximum 500
#define OUT_MAX_Y    1000      // Out PID maximum 500
#define I_MAX        500      // Out I_term maximum 300
#define I_MAX_Y      500      // Out I_term maximum 300
#define DIR        1        // Direct PID Direction 1
#endif
/* AHRS/IMU structure */

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//PID gain and limit settings
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static bool (*pidCal)(pidc_t *pid);

static bool AcroPID(pidc_t *pid);
static bool AnglePID(pidc_t *pid);
static bool GpsPID(pidc_t *pid);

void PIDControlInit(pidc_t *pid)
{
	pid->ts = 0.004f;
	pid->kp[ROLL]  = 15.0f;
	pid->kp[PITCH] = pid->kp[ROLL];
	pid->kp[YAW]   = 10.0f;  // angle Mode = 8

	pid->ki[ROLL]  = 5.0f;
	pid->ki[PITCH] = pid->ki[ROLL];
	pid->ki[YAW]   = 5.0f;  // angle Mode = 5

	pid->kd[ROLL]  = 4.0f;
	pid->kd[PITCH] = pid->kd[ROLL];
	pid->kd[YAW]   = 3.0f;  // angle Mode = 6

	///////////////////////////////////////
	pid->kp_rate[ROLL]  = 2.5f;
	pid->kp_rate[PITCH] = pid->kp_rate[ROLL];
	pid->kp_rate[YAW]   = 2.0f;

	pid->ki_rate[ROLL]  = 0.5f;
	pid->ki_rate[PITCH] = pid->ki_rate[ROLL];
	pid->ki_rate[YAW]   = 0.2f;

	pid->kd_rate[ROLL]  = 0.1f;
	pid->kd_rate[PITCH] = pid->kd_rate[ROLL];
	pid->kd_rate[YAW]   = 0.0f;
	///////////////////////////////////
	pid->kp1[ROLL] = 4.0f;
	pid->kp1[PITCH] = 4.0f;
	pid->kp1[YAW] = 5.0f;

	pid->ki1[ROLL] = 0.1f;
	pid->ki1[PITCH] = 0.1f;
	pid->ki1[YAW] = 0.0f;
	/////////////////////////////////
	pid->kp2[ROLL] = 2.5f;
	pid->kp2[PITCH] = 2.5f;
	pid->kp2[YAW] = 2.0f;

	pid->ki2[ROLL] = 0.5f;
	pid->ki2[PITCH] = 0.5f;
	pid->ki2[YAW] = 0.5f;

	pid->kd2[ROLL] = 0.2f;
	pid->kd2[PITCH] = 0.2f;
	pid->kd2[YAW] = 0.0f;
	////////////////////////////////////////

	pid->i1_limit[ROLL] = 5.0f;
	pid->i1_limit[PITCH] = 5.0f;
	pid->i1_limit[YAW] = 10.0f;

	pid->i2_limit[ROLL] = 500.0f;
	pid->i2_limit[PITCH] = 500.0f;
	pid->i2_limit[YAW] = 500.0f;

	pid->Iterm[ROLL] = 0.0f ;
	pid->Iterm[PITCH] = 0.0f;
	pid->Iterm[YAW] = 0.0f;

	pid->Iterm1[ROLL] = 0.0f ;
	pid->Iterm1[PITCH] = 0.0f;
	pid->Iterm1[YAW] = 0.0f;

	pid->Iterm2[ROLL] = 0.0f ;
	pid->Iterm2[PITCH] = 0.0f;
	pid->Iterm2[YAW] = 0.0f;

	pid->dInput[ROLL] = 0.0f ;
	pid->dInput[PITCH] = 0.0f;
	pid->dInput[YAW] = 0.0f;

	pid->error[ROLL] = 0.0f ;
	pid->error[PITCH] = 0.0f;
	pid->error[YAW] = 0.0f;

	pid->pre_error[ROLL] = 0.0f ;
	pid->pre_error[PITCH] = 0.0f;
	pid->pre_error[YAW] = 0.0f;

	pid->pre_deriv[ROLL] = 0.0f ;
	pid->pre_deriv[PITCH] = 0.0f;
	pid->pre_deriv[YAW] = 0.0f;

	pid->lastInput[ROLL] = 0.0f ;
	pid->lastInput[PITCH] = 0.0f;
	pid->lastInput[YAW] = 0.0f;

	pid->output1[ROLL] = 0.0f ;
	pid->output1[PITCH] = 0.0f;
	pid->output1[YAW] = 0.0f;

	pid->output2[ROLL] = 0.0f ;
	pid->output2[PITCH] = 0.0f;
	pid->output2[YAW] = 0.0f;
	pidCal = AcroPID;
}

int16_t  magHold, headFreeModeHold; //[-180;+180]

void Control(pidc_t *pid)
{
	pidc_t *pid_handle = pid;

	dt_recip = 1/pid->ts;

	if(!f.ARMED){
		headFreeModeHold = imu.actual_compass_heading;
		imu.yawheadinghold = imu.actual_compass_heading;
	}

	//TODO: split cos_yaw calculations into two phases (X and Y)
	if (( f.GPS_MODE != GPS_MODE_NONE ) && GPS.fixquality )
	{
		float sin_yaw_y = sin(imu.actual_compass_heading*0.0174532925f);
		float cos_yaw_x = cos(imu.actual_compass_heading*0.0174532925f);
		GPS_angle[ROLL]   = (nav[LON]*cos_yaw_x - nav[LAT]*sin_yaw_y)/10;
		GPS_angle[PITCH]  = (nav[LON]*sin_yaw_y + nav[LAT]*cos_yaw_x)/10;
	} else
	{
		GPS_angle[ROLL]  = 0;
		GPS_angle[PITCH] = 0;
	}

#if defined(HEADFREE)
	if(f.HEADFREE_MODE) { //to optimize
		float radDiff = (imu.actual_compass_heading - headFreeModeHold) * 0.0174533f; // where PI/180 ~= 0.0174533
		float cosDiff = cosf(radDiff);
		float sinDiff = sinf(radDiff);
		int16_t rcCommand_PITCH = RC.rcCommand[PITCH]*cosDiff + RC.rcCommand[ROLL]*sinDiff;
		RC.rcCommand[ROLL] =  RC.rcCommand[ROLL]*cosDiff - RC.rcCommand[PITCH]*sinDiff;
		RC.rcCommand[PITCH] = rcCommand_PITCH;
	}
#endif
	if(f.ACRO_MODE){
		pidCal = AcroPID;
	}else if(f.ANGLE_MODE){
		pidCal = AnglePID;
	}else if(f.GPS_HOLD_MODE){
		pidCal = GpsPID;
	}

	pidCal(pid_handle);
}

bool AcroPID(pidc_t *pid)
{
	bool ret = true;

	pid->error[ROLL] = RC.rcCommand[ROLL] - imu.gyroRaw[ROLL];
	pid->Iterm[ROLL] += pid->error[ROLL] * pid->ts;
	if(pid->Iterm[ROLL] > I_MAX) pid->Iterm[ROLL] = I_MAX;
	else if(pid->Iterm[ROLL] < -I_MAX) pid->Iterm[ROLL] = -I_MAX;
	pid->dInput[ROLL] = (pid->error[ROLL] - pid->pre_error[ROLL])  / pid->ts;

	/*Compute PID Output*/
	pid->output2[ROLL] = (pid->kp_rate[ROLL] * pid->error[ROLL]) + (pid->ki_rate[ROLL] * pid->Iterm[ROLL]) + (pid->kd_rate[ROLL] * pid->dInput[ROLL]);

	if(pid->output2[ROLL] > OUT_MAX) pid->output2[ROLL] = OUT_MAX;
	else if(pid->output2[ROLL] < -OUT_MAX) pid->output2[ROLL] = -OUT_MAX;

	/*Remember some variables for next time*/
	pid->pre_error[ROLL] = pid->error[ROLL];

	/////////////////////////////////////////////////////////////////////////////////////////////////

	/*Compute all the working error variables*/
	pid->error[PITCH] = RC.rcCommand[PITCH] - imu.gyroRaw[PITCH];
	pid->Iterm[PITCH] += pid->error[PITCH] * pid->ts;
	if(pid->Iterm[PITCH] > I_MAX) pid->Iterm[PITCH] = I_MAX;
	else if(pid->Iterm[PITCH] < -I_MAX) pid->Iterm[PITCH] = -I_MAX;
	pid->dInput[PITCH] = (pid->error[PITCH] - pid->pre_error[PITCH]) / pid->ts;

	/*Compute PID Output*/
	pid->output2[PITCH] = (pid->kp_rate[PITCH] * pid->error[PITCH]) + (pid->ki_rate[PITCH] *  pid->Iterm[PITCH]) + (pid->kd_rate[PITCH] * pid->dInput[PITCH]);

	if(pid->output2[PITCH] > OUT_MAX) pid->output2[PITCH] = OUT_MAX;
	else if(pid->output2[PITCH] < -OUT_MAX) pid->output2[PITCH] = -OUT_MAX;

	/*Remember some variables for next time*/
	pid->pre_error[PITCH] = pid->error[PITCH];

	//////////////////////////////////////////////////////////////////////////////////////////////////

	/*Compute all the working error variables*/
	pid->error[YAW] = RC.rcCommand[YAW] - imu.gyroRaw[YAW];
	pid->Iterm[YAW] += pid->error[YAW] * pid->ts;
	if(pid->Iterm[YAW] > I_MAX) pid->Iterm[YAW] = I_MAX;
	else if(pid->Iterm[YAW] < -I_MAX) pid->Iterm[YAW] = -I_MAX;
	pid->dInput[YAW] = (pid->error[YAW] - pid->pre_error[YAW]) / pid->ts;

	/*Compute PID Output*/
	pid->output2[YAW] = (pid->kp_rate[YAW] * pid->error[YAW]) + (pid->ki_rate[YAW] * pid->Iterm[YAW]) + (pid->kd_rate[YAW] * pid->dInput[YAW]);

	if(pid->output2[YAW] > OUT_MAX) pid->output2[YAW] = OUT_MAX;
	else if(pid->output2[YAW] < -OUT_MAX) pid->output2[YAW] = -OUT_MAX;

	/*Remember some variables for next time*/
	pid->pre_error[YAW] = pid->error[YAW];//imu.Yaw

	return ret;
}

bool AnglePID(pidc_t *pid)
{
	uint8_t ret = true;
	int axis;
	float error, deriv;
	//axis pid
	for(axis = 0; axis < 2; axis++){
		error = RC.rcCommand[axis] - imu.AHRS[axis];
		pid->Iterm1[axis] += error * pid->ts;
		if(pid->Iterm1[axis] > pid->i1_limit[axis]) pid->Iterm1[axis] = pid->i1_limit[axis];
		else if(pid->Iterm1[axis] < -pid->i1_limit[axis]) pid->Iterm1[axis] = -pid->i1_limit[axis];
		pid->output1[axis] = pid->kp1[axis]*error + pid->ki1[axis]*pid->Iterm1[axis];

		error = pid->output1[axis] - imu.gyroRaw[axis];
		pid->Iterm2[axis] += error * pid->ts;
		if(pid->Iterm2[axis] > pid->i2_limit[axis]) pid->Iterm2[axis] = pid->i2_limit[axis];
		else if(pid->Iterm2[axis] < -pid->i2_limit[axis]) pid->Iterm2[axis] = -pid->i2_limit[axis];
		deriv = (error - pid->pre_error[axis])*dt_recip;
		pid->pre_error[axis] = error;
		pid->output2[axis] = pid->kp2[axis]*error + pid->ki2[axis]*pid->Iterm2[axis] + pid->kd2[axis]*deriv;

		if(pid->output2[axis] > OUT_MAX) pid->output2[axis] = OUT_MAX;
		if(pid->output2[axis] < -OUT_MAX) pid->output2[axis] = -OUT_MAX;
	}

	if(RC.rcCommand[YAW]>-5 && RC.rcCommand[YAW]<5){
		error = imu.yawheadinghold - imu.actual_compass_heading;
		imu.debug1 = error;
		if(error > 180) error -= 360;
		if(error < -180) error += 360;
		imu.debug2 = error;
		pid->Iterm2[YAW] += error * pid->ts;
		if(pid->Iterm2[YAW] > pid->i2_limit[YAW]) pid->Iterm2[YAW] = pid->i2_limit[YAW];
		else if(pid->Iterm2[YAW] < -pid->i2_limit[YAW]) pid->Iterm2[YAW] = -pid->i2_limit[YAW];
		deriv = (error - pid->pre_error[YAW])*dt_recip;
		pid->pre_error[YAW] = error;

		pid->output2[YAW] = pid->kp2[YAW]*error + pid->ki2[YAW]*pid->Iterm2[YAW] + pid->kd2[YAW]*deriv;

		if(pid->output2[YAW] > OUT_MAX) pid->output2[YAW] = OUT_MAX;
		if(pid->output2[YAW] < -OUT_MAX) pid->output2[YAW] = -OUT_MAX;
	}else{
		error = RC.rcCommand[YAW] - (-imu.gyroRaw[YAW]);
		pid->Iterm2[YAW] += error * pid->ts;
		if(pid->Iterm2[YAW] > pid->i2_limit[YAW]) pid->Iterm2[YAW] = pid->i2_limit[YAW];
		else if(pid->Iterm2[YAW] < -pid->i2_limit[YAW]) pid->Iterm2[YAW] = -pid->i2_limit[YAW];
		deriv = (error - pid->pre_error[YAW])*dt_recip;
		pid->pre_error[YAW] = error;

		pid->output2[YAW] = pid->kp2[YAW]*error + pid->ki2[YAW]*pid->Iterm2[YAW] + pid->kd2[YAW]*deriv;

		if(pid->output2[YAW] > OUT_MAX) pid->output2[YAW] = OUT_MAX;
		if(pid->output2[YAW] < -OUT_MAX) pid->output2[YAW] = -OUT_MAX;
		imu.yawheadinghold = imu.actual_compass_heading;
	}
	return ret;
}

bool GpsPID(pidc_t *pid)
{
	bool ret = true;
	int axis;
	float error, deriv;
	//axis pid
	for(axis = 0; axis < 2; axis++){
		error = constrain(RC.rcCommand[axis] + GPS_angle[axis], -20, 20) - imu.AHRS[axis];
		pid->Iterm1[axis] += error * pid->ts;
		if(pid->Iterm1[axis] > pid->i1_limit[axis]) pid->Iterm1[axis] = pid->i1_limit[axis];
		else if(pid->Iterm1[axis] < -pid->i1_limit[axis]) pid->Iterm1[axis] = -pid->i1_limit[axis];
		pid->output1[axis] = pid->kp1[axis]*error + pid->ki1[axis]*pid->Iterm1[axis];

		error = pid->output1[axis] - imu.gyroRaw[axis];
		pid->Iterm2[axis] += error * pid->ts;
		if(pid->Iterm2[axis] > pid->i2_limit[axis]) pid->Iterm2[axis] = pid->i2_limit[axis];
		else if(pid->Iterm2[axis] < -pid->i2_limit[axis]) pid->Iterm2[axis] = -pid->i2_limit[axis];
		deriv = (error - pid->pre_error[axis])*dt_recip;
		pid->pre_error[axis] = error;
		pid->output2[axis] = pid->kp2[axis]*error + pid->ki2[axis]*pid->Iterm2[axis] + pid->kd2[axis]*deriv;

		if(pid->output2[axis] > OUT_MAX) pid->output2[axis] = OUT_MAX;
		if(pid->output2[axis] < -OUT_MAX) pid->output2[axis] = -OUT_MAX;
	}

	if(RC.rcCommand[YAW]>-5 && RC.rcCommand[YAW]<5){
		error = imu.yawheadinghold - imu.actual_compass_heading;
		imu.debug1 = error;
		if(error > 180) error -= 360;
		if(error < -180) error += 360;
		imu.debug2 = error;
		pid->Iterm2[YAW] += error * pid->ts;
		if(pid->Iterm2[YAW] > pid->i2_limit[YAW]) pid->Iterm2[YAW] = pid->i2_limit[YAW];
		else if(pid->Iterm2[YAW] < -pid->i2_limit[YAW]) pid->Iterm2[YAW] = -pid->i2_limit[YAW];
		deriv = (error - pid->pre_error[YAW])*dt_recip;
		pid->pre_error[YAW] = error;

		pid->output2[YAW] = pid->kp2[YAW]*error + pid->ki2[YAW]*pid->Iterm2[YAW] + pid->kd2[YAW]*deriv;

		if(pid->output2[YAW] > OUT_MAX) pid->output2[YAW] = OUT_MAX;
		if(pid->output2[YAW] < -OUT_MAX) pid->output2[YAW] = -OUT_MAX;
	}else{
		error = RC.rcCommand[YAW] - (-imu.gyroRaw[YAW]);
		pid->Iterm2[YAW] += error * pid->ts;
		if(pid->Iterm2[YAW] > pid->i2_limit[YAW]) pid->Iterm2[YAW] = pid->i2_limit[YAW];
		else if(pid->Iterm2[YAW] < -pid->i2_limit[YAW]) pid->Iterm2[YAW] = -pid->i2_limit[YAW];
		deriv = (error - pid->pre_error[YAW])*dt_recip;
		pid->pre_error[YAW] = error;

		pid->output2[YAW] = pid->kp2[YAW]*error + pid->ki2[YAW]*pid->Iterm2[YAW] + pid->kd2[YAW]*deriv;

		if(pid->output2[YAW] > OUT_MAX) pid->output2[YAW] = OUT_MAX;
		if(pid->output2[YAW] < -OUT_MAX) pid->output2[YAW] = -OUT_MAX;
		imu.yawheadinghold = imu.actual_compass_heading;
	}

	return ret;
}

int constrain(int amt, int low, int high)
{
	if (amt < low)
		return low;
	else if (amt > high)
		return high;
	else
		return amt;
}
