# Wireless-Sensor-Monitoring-System-FUEL-GAUGE

This is a part of the code for capstone project at University of Washington, Seattle.


This is for monitoring the battery level, which was additional task requested by the industry sponsor. The state of charge of the cell is calculated by ModelGauge algorithm, and the capacity is displayed in %.


Hardware:
1. Vcc connected with 5V pin
2. C pin of MAX17043 (2-cell battery fuel gauge) connected to I2C (SCL) pin of STM32 (PC0/A0)
3. D pin of MAX17043 connected to I2C (SDA) pin of STM32 (PC1/A1)


Software setup (Cube MX):
1. NVIC: PC0 / I2C SCL signal / alt func open drain / pull-up / max output speed high
2. NVIC: PC1 / I2C SDA signal / alt func open drain / pull-up / max output speed high
3. Hclk 1 and 2 : 16MHz

For code content:
1. Core > Inc > "MAX17043.h"
2. Core > Src > "main.c"
		"MAX17043.c"
