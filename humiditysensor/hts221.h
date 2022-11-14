/*
 * hts221.h
 *
 *  Created on: 17. 11. 2019
 *      Author: Stancoj
 */

#include "main.h"
#include "i2c.h"


#define 	hts221_DEVICE_ADDRESS_0				0xBF

#define 	hts221_WHO_AM_I_VALUE					0xBC
#define 	hts221_WHO_AM_I_ADDRES					0x0F

#define 	hts221_ADDRESS_CTRL1					0x20

#define 	hts221_ADDRESS_HUMIDITY_L				0x28
#define 	hts221_ADDRESS_HUMIDITY_H				0x29

#define 	hts221_ADDRESS_H0_T0_OUT_L 				0x36
#define 	hts221_ADDRESS_H0_T0_OUT_H 				0x37

#define     hts221_ADDRESS_H0_rH_x2                 0x30
#define     hts221_ADDRESS_H1_rH_x2                 0x31



#define 	hts221_ADDRESS_H1_T0_OUT_L 				0x3A
#define 	hts221_ADDRESS_H1_T0_OUT_H 				0x3B


#define 	hts221_ADDRESS_TEMP_L					0x20

uint8_t hts221_init(void);
//void hts221_get_acc(float* x, float * y, float * z);
uint8_t hts221_read_byte(uint8_t reg_addr);
void hts221_write_byte(uint8_t reg_addr, uint8_t value);
int8_t hts221_get_humidity();
