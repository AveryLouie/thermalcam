// GRIDEYE.h



#ifndef __GRIDEYE__H_
#define __GRIDEYE__H_

// #if (ARDUINO >= 100)
//  #include "Arduino.h"
// #else
//  #include "WProgram.h"
// #endif

#include <Wire.h>

#define GRIDEYE_SUCCESS 1
#define GRIDEYE_FAIL    0

//Registers
#define REG_POWER   0x00
#define REG_RESET   0x01
#define REG_FPSC    0x02
#define REG_INTC    0x03 //interrupt control register, not used right now
#define REG_STAT    0x04
#define REG_SCLR    0x05
#define REG_AVE     0x07 //moving average output mode
#define INTHL       0x08
#define INTHH       0x09
#define INTLL       0x0A
#define INTLH       0x0B
#define INHYSL      0x0C
#define INHYSH      0x0D
#define TTHL        0x0E
#define TTHH        0x0F
#define INTR0        0x10
#define INTR1        0x11
#define INTR2        0x12
#define INTR3        0x13
#define INTR4        0x14
#define INTR5        0x15
#define INTR6        0x16
#define INTR7        0x17
#define TEMP_BASE   0x80



//Power modes
#define MODE_NORMAL     0x00
#define MODE_SLEEP      0x10
#define MODE_STANDBY_60 0x20
#define MODE_STANDBY_10 0x21

//Reset types
#define FLAG_RESET 0x30
#define INIT_RESET 0x3F

//Frame Rates
#define FPS_1  0x01
#define FPS_10 0x00

//Moving average modes
#define MAM_OFF 0x00
#define MAMOD   0x01<<5

uint8_t init_eye(uint8_t adress); //initializes the sensor

uint8_t power_mode(uint8_t mode); //puts int different modes

uint8_t set_fps(uint8_t fps_mode); //sets the frame rate mode

uint8_t set_avg(uint8_t ave_mode); //set averaging mode

uint8_t read_single(uint8_t pixel, uint16_t* pixelbuf); //reads a single pixel

uint8_t read_array(uint16_t* pixelbuf); //reads all the pixels into an array

#endif