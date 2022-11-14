/*
 * lps22hb.c
 *
 *  Created on: 17. 11. 2019
 *      Author: Stancoj
 */

#include "pressure.h"

uint8_t addres1 = lps22hb_DEVICE_ADDRESS_0;

uint8_t lps22hb_read_byte(uint8_t reg_addr)
{
	uint8_t data = 0;
	return *(i2c_master_read(&data, 1, reg_addr, addres1, 0));
}


void lps22hb_write_byte(uint8_t reg_addr, uint8_t value)
{
	i2c_master_write(value, reg_addr, addres1, 0);
}


void lps22hb_readArray(uint8_t * data, uint8_t reg, uint8_t length)
{
	i2c_master_read(data, length, reg, addres1, 0);
}


float lps22hb_get_pressure()
{
	uint8_t pressure[3];
	pressure[0]=lps22hb_read_byte(lps22hb_ADDRESS_PRESS_OUT_XL);
	pressure[1]=lps22hb_read_byte(lps22hb_ADDRESS_PRESS_OUT_L);
	pressure[2]=lps22hb_read_byte(lps22hb_ADDRESS_PRESS_OUT_H);

	int32_t temp=((pressure[2] << 16) | pressure[1]<<8 | pressure[0]);
	float total_pressure = (float)temp/4096;

	return total_pressure;
}

float lps22hb_get_temperature()
{
	uint8_t temperature[2];
	temperature[0]=lps22hb_read_byte(lps22hb_ADDRESS_TEMP_OUT_L);
	temperature[1]=lps22hb_read_byte(lps22hb_ADDRESS_TEMP_OUT_H);
	int16_t total_t=((temperature[1] << 8) | temperature[0]);
	float temp = (float)total_t/100;
	return temp;
}



uint8_t lps22hb_init(void)
{

	uint8_t status = 1;

	//LIS3MDL_ACC_ON;

	LL_mDelay(100);

	uint8_t val = lps22hb_read_byte(lps22hb_WHO_AM_I_ADDRES);

	if(val == lps22hb_WHO_AM_I_VALUE)
		{
			status = 1;
		}
		else			//if the device is not found on one address, try another one
		{
			addres1 = lps22hb_DEVICE_ADDRESS_1;
			val = lps22hb_read_byte(lps22hb_WHO_AM_I_ADDRES);
			if(val == lps22hb_WHO_AM_I_VALUE)
			{
				status = 1;
			}
			else
			{
				status = 0;
				//return status;
			}
		}

	//acc device init
	uint8_t ctrl1 = lps22hb_read_byte(lps22hb_ADDRESS_CTRL1);
	ctrl1 &= ~0xFF;
	ctrl1 |= 0x18;
	lps22hb_write_byte(lps22hb_ADDRESS_CTRL1, ctrl1);

	return status;
}
