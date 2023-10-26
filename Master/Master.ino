// Master
#include "Wire.h"

const byte DIP0[] = {2, 3, 4, 5};
const byte DIP1[] = {6, 7, 8, 9};

byte DIP0_check[4];
byte DIP1_check[4];

void setup()
{
  pinMode(DIP0[0], INPUT); pinMode(DIP0[2], INPUT);
  pinMode(DIP0[1], INPUT); pinMode(DIP0[3], INPUT);
  
  pinMode(DIP1[0], INPUT); pinMode(DIP1[2], INPUT);
  pinMode(DIP1[1], INPUT); pinMode(DIP1[3], INPUT);
  
  Wire.begin();
}

void loop()
{
  Wire.beginTransmission(10);
  DIP0_check[0] = digitalRead(DIP0[0]);
  DIP0_check[1] = digitalRead(DIP0[1]);
  DIP0_check[2] = digitalRead(DIP0[2]);
  DIP0_check[3] = digitalRead(DIP0[3]);
  
  DIP1_check[0] = digitalRead(DIP1[0]);
  DIP1_check[1] = digitalRead(DIP1[1]);
  DIP1_check[2] = digitalRead(DIP1[2]);
  DIP1_check[3] = digitalRead(DIP1[3]);
   
  Wire.write(DIP0_check[0]);
  Wire.write(DIP0_check[1]);
  Wire.write(DIP0_check[2]);
  Wire.write(DIP0_check[3]);
  
  Wire.write(DIP1_check[0]);
  Wire.write(DIP1_check[1]);
  Wire.write(DIP1_check[2]);
  Wire.write(DIP1_check[3]);
  Wire.endTransmission();
}