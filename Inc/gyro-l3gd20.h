#ifndef GYRO_L3GD20_H
#define GYRO_L3GD20_H

#include "stm32f4xx_hal.h"

#define WRITE_ADDR	0xD6
#define READ_ADDR   0xD7

typedef struct _Gyro_t {
	I2C_HandleTypeDef *hi2c;
	uint16_t write;
	uint16_t read;
	uint8_t data[16];
} Gyro_t;

enum GyroRegisters{
	WHO_AM_I = 0x0F,
	CTRL_REG1 = 0x20,
	CTRL_REG2,
	CTRL_REG3,
	CTRL_REG4,
	CTRL_REG5,
	REFERENCE,
	OUT_TEMP,
	STATUS_REG,
	OUT_X_L,
	OUT_X_H,
	OUT_Y_L,
	OUT_Y_H,
	OUT_Z_L,
	OUT_Z_H,
	FIFO_CTRL_REG,
	FIFO_SRC_REG,
	INT1_CFG,
	INT1_SRC,
	INT1_TSH_XH,
	INT1_TSH_XL,
	INT1_TSH_YH,
	INT1_TSH_YL,
	INT1_TSH_ZH,
	INT1_TSH_ZL,
	INT1_DURATION
};

extern uint8_t GyroInit(I2C_HandleTypeDef *);
extern void GyroRead();

#endif // GYRO_L3GD20_H