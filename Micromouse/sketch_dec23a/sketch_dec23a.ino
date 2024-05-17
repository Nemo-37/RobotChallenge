#include <GyverMotor.h>
#include <Wire.h>
#include <VL53L0X.h>  // подключаем библиотеку для экрана

VL53L0X sensor;
VL53L0X sensor2;
VL53L0X sensor3;
VL53L0X sensor4;
VL53L0X sensor5;

int a;
int b;
int c;
int d;
int e;
int s;
int q;
float kp;
float P;

GMotor motor1(DRIVER2WIRE, 18, 20, HIGH);
GMotor motor2(DRIVER2WIRE, 19, 21, HIGH);


void setup() {
  pinMode(25, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(14, OUTPUT);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  digitalWrite(12, LOW);
  digitalWrite(13, LOW);
  digitalWrite(14, LOW);

  delay(500);
  Wire.begin();


  Serial.begin(115200);

  digitalWrite(10, HIGH);
  delay(150);
  Serial.println("00");
  sensor.init(true);

  Serial.println("01");
  delay(100);
  sensor.setAddress((uint8_t)01);
  Serial.println("02");

  digitalWrite(11, HIGH);
  delay(150);
  sensor2.init(true);
  Serial.println("03");
  delay(100);
  sensor2.setAddress((uint8_t)02);
  Serial.println("04");

  digitalWrite(12, HIGH);
  delay(150);
  sensor3.init(true);
  Serial.println("05");
  delay(100);
  sensor3.setAddress((uint8_t)03);
  Serial.println("06");

  digitalWrite(13, HIGH);
  delay(150);
  Serial.println("07");
  sensor4.init(true);

  Serial.println("08");
  delay(100);
  sensor4.setAddress((uint8_t)04);
  Serial.println("09");

  digitalWrite(14, HIGH);
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

  sensor.setMeasurementTimingBudget(4000);
  sensor2.setMeasurementTimingBudget(4000);
  sensor3.setMeasurementTimingBudget(4000);
  sensor4.setMeasurementTimingBudget(4000);
  sensor5.setMeasurementTimingBudget(4000);

  motor1.setMode(BRAKE);
  motor2.setMode(BRAKE);
  //motor1.setDirection(REVERSE);
  s = 130;  //скорость движения
  kp = 0.5;
}

void loop() {
  while (true) {
    a = sensor.readRangeContinuousMillimeters();
    b = sensor2.readRangeContinuousMillimeters();
    c = sensor3.readRangeContinuousMillimeters();
    d = sensor4.readRangeContinuousMillimeters();
    e = sensor5.readRangeContinuousMillimeters();
    if (c < 500) {
      s = 100;
    }
    if (d < b) {
      q = b - d;
      P = kp * q;
      motor1.setMode(AUTO);
      motor2.setMode(AUTO);
      motor1.setSpeed(s - P);
      motor2.setSpeed(s);
    }
    if (b < d) {
      q = d - b;
      P = kp * q;
      motor1.setMode(AUTO);
      motor2.setMode(AUTO);
      motor1.setSpeed(s);
      motor2.setSpeed(s - P);
    }
    if (e > 250 && d > 200) {
      motor1.setMode(AUTO);
      motor2.setMode(AUTO);
      motor1.setSpeed(s);
      motor2.setSpeed(-s);
      delay(180);
      motor1.setMode(AUTO);
      motor2.setMode(AUTO);
      motor1.setSpeed(s);
      motor2.setSpeed(s);
      delay(250);
    }
    if (c < 150) {
      motor1.setMode(AUTO);
      motor2.setMode(AUTO);
      motor1.setSpeed(-s);
      motor2.setSpeed(s);
      delay(150);
      motor1.setMode(AUTO);
      motor2.setMode(AUTO);
      motor1.setSpeed(s);
      motor2.setSpeed(s);
      delay(80);
    }
  }
}