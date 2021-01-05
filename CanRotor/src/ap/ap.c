/*
 * ap.c
 *
 *  Created on: Dec 6, 2020
 *      Author: baram
 */


#include "ap.h"
#include "uart.h"

extern flags_t f;
pidc_t pid;


volatile uint32_t currentTime=0, cycleTime=0, previousTime=0, loopTime = 0;
uint16_t cycleTimeMax = 0;
uint16_t cycleTimeMin = 65535;
uint32_t armedTime = 0;

int16_t overrun_count = 0;
uint16_t timeInterleave = 0;

eeror_t Error;

void apInit(void)
{
  uartOpen(_DEF_UART2, 57600);  // Telemetry

  cliOpen(_DEF_UART1, 57600);
  //cliOpenLog(_DEF_UART2, 57600);

  MPU9250_Init();
  MS5611_Init(MS5611_ULTRA_HIGH_RES);
  gps_Init();
	#ifdef IMU_AHRS
  /* Init structure with 100hZ sample rate, 0.1 beta and 3.5 inclination (3.5 degrees is inclination in Ljubljana, Slovenia) on July, 2016 */
  TM_AHRSIMU_Init(250, 1.2f, 0.0f);
  #endif
  Calibrate_gyro();
  //RC_Init();
  mixerInit();
  PIDControlInit(&pid);
  GPS_set_pids();
  EEPROM_Init();
}

void apMain(void)
{
	previousTime = micros();
	while(1)
	{
		computeRC(); //2us~10us
		computeIMU();
#ifdef GPS_Recive
		GPS_mode_check();
#endif
		static uint8_t taskOrder = 0;
		switch (taskOrder)
		{ //4~206us
			case 0: //200us
				taskOrder++;
				if(Baro_update(currentTime)) break;
			case 1:  //80us
				taskOrder++;
				if(getEstimatedAltitude() !=0) break;
			case 2:
				taskOrder++;
#ifdef GPS_Recive
				if (GPS_Compute() != 0) break;
				break;
#endif
			case 3:
				taskOrder++;
				Mag_getADC(); //100~380us
				CAL_Heading(); //125us
				break;
			case 4:  //40~50us
//				time = micros();
				taskOrder = 0;
//				static uint8_t ind = 0;
//				static uint16_t vvec[VBAT_SMOOTH], vsum;
//				HAL_ADC_Start(&hadc1);
//				if(HAL_ADC_PollForConversion(&hadc1,1000000) == HAL_OK)
//				{
//					BAT.VBAT_Sense = HAL_ADC_GetValue(&hadc1);
//					BAT.VBAT = ((((BAT.VBAT_Sense*3.3)/4095)*(BAT_RUP+BAT_RDW))/BAT_RDW)*10;
//				}
//				vsum += BAT.VBAT;
//				vsum -= vvec[ind];
//				vvec[ind++] = BAT.VBAT;
//				ind %= VBAT_SMOOTH;
//				BAT.VBAT = vsum/VBAT_SMOOTH;
				break;
		}

		Control(&pid); //50us
		mixTable();

		flight_mode_signal();

#ifdef Telemetry
		uint8_t t=0;
		timeInterleave = micros();
		SerialCom(); //4us
		while((int16_t)(micros()-timeInterleave)<650) t=1; //650
		if(!t) overrun_count++;
#endif
		cliMain();

		loopTime = micros() - previousTime;
		while(1)
		{
			currentTime = micros();
			cycleTime = currentTime - previousTime;
#if defined(LOOP_TIME)
			if (cycleTime >= LOOP_TIME)
			{
				if(cycleTime > (LOOP_TIME+50))
				{
					ledToggle(RGB_RED);
					Error.error = 4;
				}
				break;
			}
#else
			break;
#endif
		}
		previousTime = currentTime;

		if(f.ARMED)
		{
			armedTime += (uint32_t)cycleTime;
		}

		if(loopTime > cycleTimeMax) cycleTimeMax = loopTime;
		if(loopTime < cycleTimeMin) cycleTimeMin = loopTime;
		static uint16_t z = 0;
		z++;
		if(z >= 250)
		{
			z = 0;
			ledToggle(ST1);
		}
	}
}
