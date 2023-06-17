  /******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  * (c) EE2028 Teaching Team
  ******************************************************************************/


/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "../../Drivers/BSP/B-L475E-IOT01/stm32l475e_iot01_accelero.h"
#include "../../Drivers/BSP/B-L475E-IOT01/stm32l475e_iot01_tsensor.h"
#include "stdio.h"

extern void initialise_monitor_handles(void);	// for semi-hosting support (printf)

int main(void)
{
	initialise_monitor_handles(); // for semi-hosting support (printf)

	/* Reset of all peripherals, Initializes the Flash interface and the Systick. */
	HAL_Init();

	/* Peripheral initializations using BSP functions */
	BSP_ACCELERO_Init();
	BSP_TSENSOR_Init();

	while (1)
	{
		float accel_data[3];
		int16_t accel_data_i16[3] = { 0 };			// array to store the x, y and z readings.
		BSP_ACCELERO_AccGetXYZ(accel_data_i16);		// read accelerometer
		// the function above returns 16 bit integers which are 100 * acceleration_in_m/s2. Converting to float to print the actual acceleration.
		accel_data[0] = (float)accel_data_i16[0] / 100.0f;
		accel_data[1] = (float)accel_data_i16[1] / 100.0f;
		accel_data[2] = (float)accel_data_i16[2] / 100.0f;

		float temp_data;
		temp_data = BSP_TSENSOR_ReadTemp();			// read temperature sensor

		printf("Accel X : %f; Accel Y : %f; Accel Z : %f; Temperature : %f\n", accel_data[0], accel_data[1], accel_data[2], temp_data);

		HAL_Delay(1000);	// read once a ~second.

	}

}
