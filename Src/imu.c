#include "main.h"
#include "stm32f4xx_hal.h"

#include "gyro-l3gd20.h"
#include "accel-lsm303dlhc.h"

void MyBlink() {
	  HAL_GPIO_TogglePin(LD3_GPIO_Port, LD3_Pin);
	  HAL_Delay(2);
}

uint8_t ImuInit(I2C_HandleTypeDef *hi2c) {
	uint8_t status = HAL_OK;

	if ( (status = GyroInit(hi2c)) != HAL_OK)
		return status;

	if ( (status = AccelInit(hi2c)) != HAL_OK)
		return status;

	return status;
}

void ImuLoop() {
	GyroRead();
	AccelRead();

	MyBlink();
}
