/*
 * lps22hb.h
 *
 *  Created on: 17. 11. 2019
 *      Author: Stancoj
 */

#include "main.h"
#include "i2c.h"


#define 	lps22hb_DEVICE_ADDRESS_0				0xB9
#define 	lps22hb_DEVICE_ADDRESS_1				0xBB

#define 	lps22hb_WHO_AM_I_VALUE					0xB1
#define 	lps22hb_WHO_AM_I_ADDRES					0x0F

#define 	lps22hb_ADDRESS_CTRL1					0x10

#define 	lps22hb_ADDRESS_PRESS_OUT_XL			0x28
#define 	lps22hb_ADDRESS_PRESS_OUT_L				0x29
#define 	lps22hb_ADDRESS_PRESS_OUT_H				0x2A

#define     lps22hb_ADDRESS_TEMP_OUT_L				0x2B
#define     lps22hb_ADDRESS_TEMP_OUT_H				0x2C




uint8_t lps22hb_init(void);
uint8_t lps22hb_read_byte(uint8_t reg_addr);
void lps22hb_write_byte(uint8_t reg_addr, uint8_t value);
float lps22hb_get_pressure();
float lps22hb_get_temperature();
