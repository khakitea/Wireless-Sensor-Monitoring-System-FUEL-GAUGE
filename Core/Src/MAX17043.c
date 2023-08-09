/*
 * MAX17043.c
 *
 *  Created on: May 4, 2023
 *      Author: owenc
 */

#ifndef __MAX17043_H
#define __MAX17043_H

#include "stm32wbxx_hal.h"
#include "stdbool.h"
#include "MAX17043.h"


#define MAX17043_I2C_ADDRESS 0x36
#define MAX17043_I2C_ADDR 0x36


void MAX17043_Init(I2C_HandleTypeDef *hi2c)
{
  uint8_t configReg[] = {0x02, 0x80};
  HAL_I2C_Master_Transmit(hi2c, MAX17043_I2C_ADDRESS, configReg, sizeof(configReg), HAL_MAX_DELAY);
}
/*
float MAX17043_ReadVoltage(I2C_HandleTypeDef *hi2c)
{
  uint8_t voltageReg[] = {0x02};
  uint8_t voltageData[2] = {0};
  HAL_I2C_Master_Transmit(hi2c, MAX17043_I2C_ADDRESS, voltageReg, sizeof(voltageReg), HAL_MAX_DELAY);
  HAL_I2C_Master_Receive(hi2c, MAX17043_I2C_ADDRESS, voltageData, sizeof(voltageData), HAL_MAX_DELAY);

  uint16_t rawVoltage = (voltageData[0] << 8) | voltageData[1];
  float voltage = rawVoltage * 1.25f;

  return voltage;
}*/

float MAX17043_ReadVoltage(I2C_HandleTypeDef *hi2c)
{
  uint8_t txData[2];
  uint8_t rxData[2];

  txData[0] = 0x02; // Register address for VCELL
  txData[1] = 0x00;

  HAL_I2C_Master_Transmit(hi2c, MAX17043_I2C_ADDR << 1, txData, 1, HAL_MAX_DELAY);
  HAL_I2C_Master_Receive(hi2c, MAX17043_I2C_ADDR << 1, rxData, 2, HAL_MAX_DELAY);

  uint16_t voltage = (rxData[0] << 8) | rxData[1];
  voltage = (voltage >> 4);

  float volts = voltage;
  volts *= 1.25 / 1000;

  return volts;
}



float MAX17043_ReadSoC(I2C_HandleTypeDef *hi2c)
{
	uint8_t txData[2];
	uint8_t rxData[2];

	txData[0] = 0x04; // Register address for SoC
	txData[1] = 0x00;

	HAL_I2C_Master_Transmit(hi2c, MAX17043_I2C_ADDR << 1, txData, 1, HAL_MAX_DELAY);
	HAL_I2C_Master_Receive(hi2c, MAX17043_I2C_ADDR << 1, rxData, 2, HAL_MAX_DELAY);

	uint16_t soc = (rxData[0] << 8) | rxData[1];
	soc = (soc >> 8) + 0.003906f * (soc & 0x00ff);
	//percent /= 256;
	float percent = soc;

	return percent;
}

#endif /* __MAX17043_H */
