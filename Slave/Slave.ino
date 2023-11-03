// Slave
#include "Wire.h"
const byte LED_r[] = { 6, 7, 8, 9 };
const byte LED_l[] = { 2, 3, 4, 5 };

bool DIP0_check[4];
bool DIP1_check[4];
int ADDEND_r, ADDEND_l;

int sum;
int right_digit, left_digit;
int i;

int BinToDec(bool bin[]);

void setup() {
  Serial.begin(9600);
  Wire.begin(10);
  Wire.onReceive(receiveEvent);

  pinMode(LED_l[0], OUTPUT);
  pinMode(LED_l[2], OUTPUT);
  pinMode(LED_l[1], OUTPUT);
  pinMode(LED_l[3], OUTPUT);

  pinMode(LED_r[0], OUTPUT);
  pinMode(LED_r[2], OUTPUT);
  pinMode(LED_r[1], OUTPUT);
  pinMode(LED_r[3], OUTPUT);
}

void loop() {
  delay(5000);
}

void receiveEvent(int howMany) {
  DIP0_check[0] = Wire.read();
  DIP0_check[1] = Wire.read();
  DIP0_check[2] = Wire.read();
  DIP0_check[3] = Wire.read();
  ADDEND_r = BinToDec(DIP0_check);
  Serial.print("ADDEND_r: ");
  Serial.println(ADDEND_r);

  DIP1_check[0] = Wire.read();
  DIP1_check[1] = Wire.read();
  DIP1_check[2] = Wire.read();
  DIP1_check[3] = Wire.read();
  ADDEND_l = BinToDec(DIP1_check);
  Serial.print("ADDEND_l: ");
  Serial.println(ADDEND_l);
  Serial.println();

  sum = ADDEND_r + ADDEND_l;
  Serial.print(ADDEND_l);
  Serial.print(" + ");
  Serial.print(ADDEND_r);
  Serial.print(" = ");
  Serial.print(sum);
  Serial.println();
  Serial.println();

  if (sum >= 100) {
    left_digit = 0;
    right_digit = 0;
  } else {
    left_digit = sum / 10;
    right_digit = sum % 10;
  }

  // Left Digit
  switch (left_digit) {
    case 9:
      digitalWrite(LED_l[3], 1);
      digitalWrite(LED_l[2], 0);
      digitalWrite(LED_l[1], 0);
      digitalWrite(LED_l[0], 1);
      break;
    case 8:
      digitalWrite(LED_l[3], 1);
      digitalWrite(LED_l[2], 0);
      digitalWrite(LED_l[1], 0);
      digitalWrite(LED_l[0], 0);
      break;
    case 7:
      digitalWrite(LED_l[3], 0);
      digitalWrite(LED_l[2], 1);
      digitalWrite(LED_l[1], 1);
      digitalWrite(LED_l[0], 1);
      break;
    case 6:
      digitalWrite(LED_l[3], 0);
      digitalWrite(LED_l[2], 1);
      digitalWrite(LED_l[1], 1);
      digitalWrite(LED_l[0], 0);
      break;
    case 5:
      digitalWrite(LED_l[3], 0);
      digitalWrite(LED_l[2], 1);
      digitalWrite(LED_l[1], 0);
      digitalWrite(LED_l[0], 1);
      break;
    case 4:
      digitalWrite(LED_l[3], 0);
      digitalWrite(LED_l[2], 1);
      digitalWrite(LED_l[1], 0);
      digitalWrite(LED_l[0], 0);
      break;
    case 3:
      digitalWrite(LED_l[3], 0);
      digitalWrite(LED_l[2], 0);
      digitalWrite(LED_l[1], 1);
      digitalWrite(LED_l[0], 1);
      break;
    case 2:
      digitalWrite(LED_l[3], 0);
      digitalWrite(LED_l[2], 0);
      digitalWrite(LED_l[1], 1);
      digitalWrite(LED_l[0], 0);
      break;
    case 1:
      digitalWrite(LED_l[3], 0);
      digitalWrite(LED_l[2], 0);
      digitalWrite(LED_l[1], 0);
      digitalWrite(LED_l[0], 1);
      break;
    default:
      digitalWrite(LED_l[3], 0);
      digitalWrite(LED_l[2], 0);
      digitalWrite(LED_l[1], 0);
      digitalWrite(LED_l[0], 0);
      break;
  }
  
  // Right Digit
  switch (right_digit) {
    case 9:
      digitalWrite(LED_r[3], 1);
      digitalWrite(LED_r[2], 0);
      digitalWrite(LED_r[1], 0);
      digitalWrite(LED_r[0], 1);
      break;
    case 8:
      digitalWrite(LED_r[3], 1);
      digitalWrite(LED_r[2], 0);
      digitalWrite(LED_r[1], 0);
      digitalWrite(LED_r[0], 0);
      break;
    case 7:
      digitalWrite(LED_r[3], 0);
      digitalWrite(LED_r[2], 1);
      digitalWrite(LED_r[1], 1);
      digitalWrite(LED_r[0], 1);
      break;
    case 6:
      digitalWrite(LED_r[3], 0);
      digitalWrite(LED_r[2], 1);
      digitalWrite(LED_r[1], 1);
      digitalWrite(LED_r[0], 0);
      break;
    case 5:
      digitalWrite(LED_r[3], 0);
      digitalWrite(LED_r[2], 1);
      digitalWrite(LED_r[1], 0);
      digitalWrite(LED_r[0], 1);
      break;
    case 4:
      digitalWrite(LED_r[3], 0);
      digitalWrite(LED_r[2], 1);
      digitalWrite(LED_r[1], 0);
      digitalWrite(LED_r[0], 0);
      break;
    case 3:
      digitalWrite(LED_r[3], 0);
      digitalWrite(LED_r[2], 0);
      digitalWrite(LED_r[1], 1);
      digitalWrite(LED_r[0], 1);
      break;
    case 2:
      digitalWrite(LED_r[3], 0);
      digitalWrite(LED_r[2], 0);
      digitalWrite(LED_r[1], 1);
      digitalWrite(LED_r[0], 0);
      break;
    case 1:
      digitalWrite(LED_r[3], 0);
      digitalWrite(LED_r[2], 0);
      digitalWrite(LED_r[1], 0);
      digitalWrite(LED_r[0], 1);
      break;
    default:
      digitalWrite(LED_r[3], 0);
      digitalWrite(LED_r[2], 0);
      digitalWrite(LED_r[1], 0);
      digitalWrite(LED_r[0], 0);
      break;
  }
  Serial.println();

  delay(100);
}

int BinToDec(bool bin[]) {
  int sum = 0;
  for (int i = 0; i < 4; i++) {
    if (i == 0) {
      if (bin[i] == 1)
        sum += 1;
      else
        sum += 0;
    } else if (i == 1) {
      if (bin[i] == 1)
        sum += 2;
      else
        sum += 0;
    } else if (i == 2) {
      if (bin[i] == 1)
        sum += 4;
      else
        sum += 0;
    } else if (i == 3) {
      if (bin[i] == 1)
        sum += 8;
      else
        sum += 0;
    }
  }

  return sum;
}