#ifndef __MAX17043_H
#define __MAX17043_H

#include "stm32wbxx_hal.h"
#include <stdbool.h>

#define MAX17043_I2C_ADDRESS 0x36
#define MAX17043_I2C_ADDR 0x36

void MAX17043_Init(I2C_HandleTypeDef *hi2c);
float MAX17043_ReadVoltage(I2C_HandleTypeDef *hi2c);
float MAX17043_ReadSoC(I2C_HandleTypeDef *hi2c);

#endif /* __MAX17043_H */
