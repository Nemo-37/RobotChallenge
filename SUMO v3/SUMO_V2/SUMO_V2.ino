#include "GyverMotor.h"
#include <Wire.h>
#include <VL53L0X.h>

VL53L0X sensor;
VL53L0X sensor2;
VL53L0X sensor3;
VL53L0X sensor4;
VL53L0X sensor5;

const int PIN_BUTTON = 7;
int a;
int b;
int c;
int d;
int e;
GMotor motor1(DRIVER2WIRE, 2, 6, HIGH);
GMotor motor2(DRIVER2WIRE, 3, 5, HIGH);

void setup() {
  Serial.begin(9600);
  pinMode(PIN_BUTTON, INPUT);
  motor1.setMode(AUTO);
  motor2.setMode(AUTO);

  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  digitalWrite(12, LOW);

  delay(500);
  Wire.begin();


  Serial.begin(9600);

  digitalWrite(8, HIGH);
  delay(150);
  Serial.println("00");
  sensor.init(true);

  Serial.println("01");
  delay(100);
  sensor.setAddress((uint8_t)01);
  Serial.println("02");

  digitalWrite(9, HIGH);
  delay(150);
  sensor2.init(true);
  Serial.println("03");
  delay(100);
  sensor2.setAddress((uint8_t)02);
  Serial.println("04");

  digitalWrite(10, HIGH);
  delay(150);
  sensor3.init(true);
  Serial.println("05");
  delay(100);
  sensor3.setAddress((uint8_t)03);
  Serial.println("06");

  digitalWrite(11, HIGH);
  delay(150);
  Serial.println("07");
  sensor4.init(true);

  Serial.println("08");
  delay(100);
  sensor4.setAddress((uint8_t)04);
  Serial.println("09");

  digitalWrite(12, HIGH);
  delay(150);
  Serial.println("10");
  sensor5.init(true);

  Serial.println("11");
  delay(100);
  sensor5.setAddress((uint8_t)05);
  Serial.println("12");


  Serial.println("addresses set");

  sensor.startContinuous();
  sensor2.startContinuous();
  sensor3.startContinuous();
  sensor4.startContinuous();
  sensor5.startContinuous();

  // put your setup code here, to run once: поворот   motor1.setSpeed(145); motor2.setSpeed(145);     прямо motor1.setSpeed(-255); motor2.setSpeed(255);
}

void loop() {
  Serial.println(digitalRead(PIN_BUTTON));
  if (digitalRead(PIN_BUTTON) == 1) {
    delay(1000);
    while (true) {
      a = sensor.readRangeContinuousMillimeters();
      b = sensor2.readRangeContinuousMillimeters();
      c = sensor3.readRangeContinuousMillimeters();
      d = sensor4.readRangeContinuousMillimeters();
      e = sensor5.readRangeContinuousMillimeters();

      if (a < 200) {
        motor1.setMode(AUTO);
        motor2.setMode(AUTO);
        motor1.setSpeed(155);
        motor2.setSpeed(155);
      }
      if (b < 200) {
        motor1.setMode(AUTO);
        motor2.setMode(AUTO);
        motor1.setSpeed(155);
        motor2.setSpeed(155);
      }
      if (d < 200) {
        motor1.setMode(AUTO);
        motor2.setMode(AUTO);
        motor1.setSpeed(-155);
        motor2.setSpeed(-155);
      }
      if (e < 200) {
        motor1.setMode(AUTO);
        motor2.setMode(AUTO);
        motor1.setSpeed(-155);
        motor2.setSpeed(-155);
      }
      if (c < 300) {
        motor1.setMode(BRAKE);
        motor2.setMode(BRAKE);
      }
      if (c < 100) {
        motor1.setMode(AUTO);
        motor2.setMode(AUTO);
        motor1.setSpeed(-65);
        motor2.setSpeed(65);
      }
    }
  }
}
