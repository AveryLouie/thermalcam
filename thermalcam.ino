#include <Wire.h>
#include <GRIDEYE.h>
#include <Adafruit_LEDBackpack.h>
#include <Adafruit_GFX.h>
#include <stdio.h>
//void setup(){}
//void loop(){}


Adafruit_BicolorMatrix matrix = Adafruit_BicolorMatrix();

static const uint8_t PROGMEM
flame_bmp[]=
{
  B00000000,
  B00001000,
  B00001000,
  B00101010,
  B00111110,
  B01111110,
  B01111100,
  B00111100
};

static const uint8_t PROGMEM
all_bmp[]=
{
  B11111111,
  B11111111,
  B11111111,
  B11111111,
  B11111111,
  B11111111,
  B11111111,
  B11111111
};



void setup()
{
  Serial.begin(9600);
  Serial.println("Beginning");
  matrix.begin(0x70);
  init_eye(0x68);  
}

void filter(uint16_t* tbuf, uint16_t thresh, uint8_t* bmp)
{
  uint8_t temp;
  for(int i = 0; i<8 ; i++)
  {
    temp = 0;
    for(int j = 0; j<8 ; j++)
    {
      if (tbuf[i*8+j] > thresh)
        temp |= 1<<j;
    }
    bmp[i]=temp;
  }
}

void loop()
{
  matrix.clear();
  matrix.drawBitmap(0,0,flame_bmp,8,8,LED_GREEN);
  matrix.writeDisplay();
  uint16_t temps[64];
  char printbuf[48];
  uint8_t hot_bmp[8];
  uint8_t med_bmp[8];
  uint8_t col_bmp[8];

  while(1)
  {
    read_array(temps);
    filter(temps, (uint16_t) 120, med_bmp);
    filter(temps, (uint16_t) 125, hot_bmp);
    matrix.drawBitmap(0,0,all_bmp,8,8,LED_GREEN);
    matrix.drawBitmap(0,0,med_bmp,8,8,LED_YELLOW);
    matrix.drawBitmap(0,0,hot_bmp,8,8,LED_RED);
    matrix.writeDisplay();
    for(int i=0; i<48; i+=8)
    { 
      sprintf(printbuf, "%6u%6u%6u%6u%6u%6u%6u%6u", temps[i],temps[i+1],temps[i+2],temps[i+3],temps[i+4],temps[i+5],temps[i+6],temps[i+7]);
      Serial.println(printbuf);
    }
    delay(100);
//  Serial.print("\n\n\n");
  }
}

