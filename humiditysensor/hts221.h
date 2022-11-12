/*
 * HTS221.h
 *
 *  Created on: 17. 11. 2019
 *      Author: T.Jurov
 */

#include "main.h"
#include "i2c.h"


#define 	HTS221_DEVICE_ADDRESS_1				0xBF
#define 	HTS221_DEVICE_ADDRESS_0				0xBE

#define 	HTS221_WHO_AM_I_VALUE					0xBC
#define 	HTS221_WHO_AM_I_ADDRES					0x0F

#define 	HTS221_ADDRESS_AV_CONF					0x10

#define 	HTS221_ADDRESS_CTRL1					0x20
#define 	HTS221_ADDRESS_CTRL2					0x21
#define 	HTS221_ADDRESS_CTRL3					0x22




#define 	HTS221_STATUS_REG					0x27
#define 	HTS221_HUMIDITY_OUT_L				0x28
#define 	HTS221_HUMIDITY_OUT_H				0x29

#define 	HTS221_TEMP_OUT_L					0x2A
#define 	HTS221_TEMP_OUT_H					0x2B

uint8_t hts221_init(void);
void hts221_get_acc(float* x, float * y, float * z);
uint8_t hts221_read_byte(uint8_t reg_addr);
void hts221_write_byte(uint8_t reg_addr, uint8_t value);
int8_t hts221_get_temp();
