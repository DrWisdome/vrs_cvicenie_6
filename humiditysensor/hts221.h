/*
 * hts221.h
 *
 *  Created on: 17. 11. 2019
 *      Author: Stancoj
 */

#include "main.h"
#include "i2c.h"


#define 	HTS221_DEVICE_ADDRESS_0					0xBF

#define 	HTS221_WHO_AM_I_VALUE					0xBC
#define 	HTS221_WHO_AM_I_ADDRES					0x0F

#define 	HTS221_ADDRESS_CTRL1					0x20

#define 	HTS221_ADDRESS_HUMIDITY_L				0x28
#define 	HTS221_ADDRESS_HUMIDITY_H				0x29

#define 	HTS221_ADDRESS_H0_T0_OUT_L 				0x36
#define 	HTS221_ADDRESS_H0_T0_OUT_H 				0x37

#define 	HTS221_ADDRESS_H1_T0_OUT_L 				0x3A
#define 	HTS221_ADDRESS_H1_T0_OUT_H 				0x3B

#define     HTS221_ADDRESS_H0_rH_x2                 0x30
#define     HTS221_ADDRESS_H1_rH_x2                 0x31

#define 	HTS221_ADDRESS_TEMP_OUT_L				0x2A
#define 	HTS221_ADDRESS_TEMP_OUT_H				0x2B

#define 	HTS221_ADDRESS_T0_OUT_L 				0x3C
#define 	HTS221_ADDRESS_T0_OUT_H 				0x3D

#define     HTS221_ADDRESS_T1_OUT_L                 0x3E
#define     HTS221_ADDRESS_T1_OUT_H                 0x3F

#define 	HTS221_ADDRESS_T0_degC_x8  				0x32
#define 	HTS221_ADDRESS_T1_degC_x8 				0x33
#define 	HTS221_ADDRESS_T1T0_msb                 0x35


uint8_t hts221_init(void);
uint8_t hts221_read_byte(uint8_t reg_addr);
void hts221_write_byte(uint8_t reg_addr, uint8_t value);
int8_t hts221_get_humidity();
float hts221_get_temperature();
