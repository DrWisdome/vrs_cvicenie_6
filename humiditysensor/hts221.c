/*
 * hts221.c
 *
 *  Created on: 17. 11. 2019
 *      Author: Stancoj
 */

#include "hts221.h"

uint8_t addres = hts221_DEVICE_ADDRESS_0;

uint8_t hts221_read_byte(uint8_t reg_addr)
{
	uint8_t data = 0;
	return *(i2c_master_read(&data, 1, reg_addr, addres, 0));
}


void hts221_write_byte(uint8_t reg_addr, uint8_t value)
{
	i2c_master_write(value, reg_addr, addres, 0);
}


void hts221_readArray(uint8_t * data, uint8_t reg, uint8_t length)
{
	i2c_master_read(data, length, reg, addres, 0);
}


int8_t hts221_get_humidity()
{
	uint8_t humidity[2];
	humidity[0]=hts221_read_byte(hts221_ADDRESS_HUMIDITY_L);
	humidity[1]=hts221_read_byte(hts221_ADDRESS_HUMIDITY_H);
	int16_t total_h=((humidity[1] << 8) | humidity[0]);

	uint8_t cal0[2];
	cal0[0]=hts221_read_byte(hts221_ADDRESS_H0_T0_OUT_L);
	cal0[1]=hts221_read_byte(hts221_ADDRESS_H0_T0_OUT_H);
	int16_t total_cal0=((cal0[1] << 8) | cal0[0]);

	uint8_t cal1[2];
	cal1[0]=hts221_read_byte(hts221_ADDRESS_H1_T0_OUT_L);
	cal1[1]=hts221_read_byte(hts221_ADDRESS_H1_T0_OUT_H);
	int16_t total_cal1=((cal1[1] << 8) | cal1[0]);

	uint8_t cal0_y=hts221_read_byte(hts221_ADDRESS_H0_rH_x2);
	uint8_t cal1_y=hts221_read_byte(hts221_ADDRESS_H1_rH_x2);

	float k=(float)(cal1_y-cal0_y)/(total_cal1-total_cal0);
	float q =(float)(cal1_y-k*total_cal1);
	int8_t total =(int8_t)((k*total_h+q)/2);
	return total;
}

float hts221_get_temperature()
{
	uint8_t temperature[2];
	temperature[0]=hts221_read_byte(hts221_ADDRESS_TEMP_OUT_L);
	temperature[1]=hts221_read_byte(hts221_ADDRESS_TEMP_OUT_H);
	int16_t total_t=((temperature[1] << 8) | temperature[0]);

	uint8_t cal0[2];
	cal0[0]=hts221_read_byte(hts221_ADDRESS_T0_OUT_L);
	cal0[1]=hts221_read_byte(hts221_ADDRESS_T0_OUT_H);
	int16_t total_cal0=((cal0[1] << 8) | cal0[0]);

	uint8_t cal1[2];
	cal1[0]=hts221_read_byte(hts221_ADDRESS_T1_OUT_L);
	cal1[1]=hts221_read_byte(hts221_ADDRESS_T1_OUT_H);
	int16_t total_cal1=((cal1[1] << 8) | cal1[0]);

	uint8_t cal0_y_temp=hts221_read_byte(hts221_ADDRESS_T0_degC_x8);
	uint8_t cal1_y_temp=hts221_read_byte(hts221_ADDRESS_T1_degC_x8);
	uint8_t temp0 = hts221_read_byte(hts221_ADDRESS_T1T0_msb) & 0x03;
	uint8_t temp1 = hts221_read_byte(hts221_ADDRESS_T1T0_msb)>>2 & 0x03;
	int16_t cal0_y= temp0<<8 | cal0_y_temp;
	int16_t cal1_y= temp1<<8 | cal1_y_temp;



	float k=(float)(cal1_y-cal0_y)/(total_cal1-total_cal0);
	float q =(float)(cal1_y-k*total_cal1);
	float total =(float)((k*total_t+q)/8);
	return total;
}



uint8_t hts221_init(void)
{

	uint8_t status = 1;

	//LIS3MDL_ACC_ON;

	LL_mDelay(100);

	uint8_t val = hts221_read_byte(hts221_WHO_AM_I_ADDRES);

	if(val == hts221_WHO_AM_I_VALUE)
	{
		status = 1;
	}
	else			//if the device is not found on one address, try another one
	{
			status = 0;
			//return status;
	}

	//acc device init
	uint8_t ctrl1 = hts221_read_byte(hts221_ADDRESS_CTRL1);
	ctrl1 &= 0x78;
	ctrl1 |= 0x81;
	hts221_write_byte(hts221_ADDRESS_CTRL1, ctrl1);

	return status;
}
