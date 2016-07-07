// GRIDEYE.c

#include "GRIDEYE.h"
// #include <Wire.h>

uint8_t eye_address;

uint8_t init_eye(uint8_t address) //initializes the sensor
{
	eye_address = address;

	Wire.begin();

	Wire.beginTransmission(address);
	Wire.write(0x00);
	Wire.write(MODE_NORMAL);
	Wire.endTransmission();

	return GRIDEYE_SUCCESS;
}

uint8_t power_mode(uint8_t mode) //puts it into different modes
{
	Wire.beginTransmission(eye_address);
	Wire.write(REG_POWER);
	Wire.write(mode);
	Wire.endTransmission();

	return GRIDEYE_SUCCESS;
}

uint8_t read_single(uint8_t pixel, uint16_t* pixelbuf) //reads a single pixel
{
	uint8_t bot, top;

	if (pixel<0 || pixel>64)
	{
		return GRIDEYE_FAIL;
	}

	Wire.beginTransmission(eye_address);
	Wire.write(TEMP_BASE+pixel);
	Wire.endTransmission();

	Wire.requestFrom(eye_address, (uint8_t) 2);
	bot = Wire.read();
	top = Wire.read();

	*pixelbuf = (top << 8) || bot;

	return GRIDEYE_SUCCESS;
}


uint8_t read_array(uint16_t* pixelbuf) //reads all the pixels into an array
{
	uint8_t top, bot;

	Wire.beginTransmission(eye_address);
	Wire.write(TEMP_BASE);
	Wire.endTransmission();

	

	for(uint8_t i = 0; i<64; i++)
	{
		Wire.requestFrom(eye_address, (uint8_t) 2);
		bot = Wire.read();
		top = Wire.read();

		pixelbuf[i] = (top << 8 ) | bot;
	}

	return GRIDEYE_SUCCESS;

}