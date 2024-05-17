#include "GyverMotor.h"
#include <Wire.h>
#include <VL53L0X.h>

VL53L0X sensor;
VL53L0X sensor3;
VL53L0X sensor4;
VL53L0X sensor5;

int fotores0 = 400;
int fotores1 = 400;
const int PIN_BUTTON = 12;
int a;
int b;
int c;
int d;
int e;
GMotor motor2(DRIVER2WIRE, 2, 3, HIGH);
GMotor motor1(DRIVER2WIRE, 5, 6, HIGH);

void setup() {
  Serial.begin(9600);
  motor2.setDirection(NORMAL);
  pinMode(PIN_BUTTON, INPUT);
  motor1.setMode(BRAKE);
  motor2.setMode(BRAKE);

  pinMode(7, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  digitalWrite(7, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);

  delay(500);
  Wire.begin();


  Serial.begin(9600);

  digitalWrite(7, HIGH);
  delay(150);
  Serial.println("00");
  sensor.init(true);

  Serial.println("01");
  delay(100);
  sensor.setAddress((uint8_t)01);
  Serial.println("02");

  digitalWrite(9, HIGH);
  delay(150);
  sensor3.init(true);
  Serial.println("05");
  delay(100);
  sensor3.setAddress((uint8_t)03);
  Serial.println("06");

  digitalWrite(10, HIGH);
  delay(150);
  Serial.println("07");
  sensor4.init(true);

  Serial.println("08");
  delay(100);
  sensor4.setAddress((uint8_t)04);
  Serial.println("09");

  digitalWrite(11, HIGH);
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
  motor1.setDirection(REVERSE);
  // put your setup code here, to run once: поворот   motor1.setSpeed(145); motor2.setSpeed(145);     прямо motor1.setSpeed(-255); motor2.setSpeed(255);
}

void loop() {
  Serial.println(digitalRead(PIN_BUTTON));
  if (digitalRead(PIN_BUTTON) == 1) {
    delay(1000);
    while (true) {
      int foto1 = analogRead(A6);
      int foto2 = analogRead(A7);
      int speed = 115;
      int dist = 200;
      a = sensor.readRangeContinuousMillimeters();
      b = sensor2.readRangeContinuousMillimeters();
      c = sensor3.readRangeContinuousMillimeters();
      d = sensor4.readRangeContinuousMillimeters();
      e = sensor5.readRangeContinuousMillimeters();

      if (a < dist) {
        motor1.setMode(AUTO);
        motor2.setMode(AUTO);
        motor1.setSpeed(1 - speed);
        motor2.setSpeed(speed);
      }
      if (b < dist) {
        motor1.setMode(AUTO);
        motor2.setMode(AUTO);
        motor1.setSpeed(1 - speed);
        motor2.setSpeed(speed);
      }
      if (d < dist) {
        motor1.setMode(AUTO);
        motor2.setMode(AUTO);
        motor1.setSpeed(speed);
        motor2.setSpeed(1 - speed);
      }
      if (e < dist) {
        motor1.setMode(AUTO);
        motor2.setMode(AUTO);
        motor1.setSpeed(speed);
        motor2.setSpeed(1 - speed);
      }
      if (c < dist) {
        motor1.setMode(AUTO);
        motor2.setMode(AUTO);
        motor1.setSpeed(speed);
        motor2.setSpeed(speed);
      }
      if (foto1 < fotores0) {
        motor1.setMode(AUTO);
        motor2.setMode(AUTO);
        motor1.setSpeed(-speed);
        motor2.setSpeed(-speed);
        delay(200);
      }
      if (foto2 < fotores1) {
        motor1.setMode(AUTO);
        motor2.setMode(AUTO);
        motor1.setSpeed(-speed);
        motor2.setSpeed(-speed);
        delay(200);
      }
      if (foto1 > fotores0 && foto2 > fotores1 && c > dist && a > dist && b > dist && d > dist && e > dist) {
        motor1.setMode(AUTO);
        motor2.setMode(AUTO);
        motor1.setSpeed(-speed);
        motor2.setSpeed(speed);
      }
    }
  }
}
