#include <Ultrasonic.h>
#include <GyverMotor.h>
#define PIN_PHOTO_SENSOR1 A0
#define PIN_PHOTO_SENSOR3 A2
#define PIN_ENA 6  // Вывод управления скоростью вращения мотора №1
#define PIN_ENB 5  // Вывод управления скоростью вращения мотора №2
#define PIN_IN1 3  // Вывод управления направлением вращения мотора №1
#define PIN_IN2 2  // Вывод управления направлением вращения мотора №1
#define PIN_IN3 7  // Вывод управления направлением вращения мотора №2
#define PIN_IN4 4  // Вывод управления направлением вращения мотора №2
GMotor motor1(DRIVER3WIRE, PIN_IN1, PIN_IN2, PIN_ENA, HIGH);
GMotor motor2(DRIVER3WIRE, PIN_IN3, PIN_IN4, PIN_ENB, HIGH);
Ultrasonic ultrasonic(12, 13);
int distance;
int sensor1 = 650;  //срабатывание первого сенсора 700
int sensor3 = 280;  //срабатывниие третьего сенсора 300

void setup() {
  Serial.begin(9600);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, INPUT);
  pinMode(8, OUTPUT);
  motor1.setMode(AUTO);
  motor2.setMode(AUTO);
  digitalWrite(11, HIGH);
  digitalWrite(10, LOW);
  digitalWrite(8, HIGH);
  // put your setup code here, to run once:
}

void loop() {
  if (digitalRead(9) == HIGH) {
    delay(5000);
    while (true) {
      int sen1 = analogRead(PIN_PHOTO_SENSOR1);
      int sen3 = analogRead(PIN_PHOTO_SENSOR3);
      distance = ultrasonic.read();
      if (sen1 > sensor1) {
        motor1.setSpeed(-215);
        motor2.setSpeed(-255);
        delay(800);
      }
      if (sen3 > sensor3) {
        motor1.setSpeed(-255);
        motor2.setSpeed(-215);
        delay(800);
      }
      if (distance < 100) {
        motor1.setSpeed(255);
        motor2.setSpeed(255);
      } else {
        motor1.setSpeed(185);
        motor2.setSpeed(-185);
      }
    }
  }
}
