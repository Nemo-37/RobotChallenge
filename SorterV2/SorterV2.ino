#include <Wire.h>
#include <VL53L0X.h>
#include "GyverMotor.h"
GMotor motor1(DRIVER2WIRE, 3, 5, HIGH);

VL53L0X sensor;
int a;
int rad = 0;
int red = 0;
int blue = 0;
int black = 0;
int white = 0;
int yellow = 0;
int value1 = 0;
int value2 = 0;
int value3 = 0;
int value4 = 0;
int value5 = 0;
int timing1 = 700;
int timing2 = 350;
int timing3 = 350;
int timing4 = 350;
int timing5 = 350;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Wire.begin();

  sensor.setTimeout(500);
  if (!sensor.init()) {
    Serial.println("Failed to detect and initialize sensor!");
    while (1) {}
  }
  sensor.setMeasurementTimingBudget(20000);
  pinMode(13, INPUT);
  pinMode(12, INPUT);
  pinMode(2, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(11, INPUT);
  pinMode(10, INPUT);
  pinMode(7, INPUT);
  pinMode(4, INPUT);
  pinMode(9, INPUT);
}

void loop() {
  if (sensor.timeoutOccurred()) { Serial.print(" TIMEOUT"); }
  if (digitalRead(12) == HIGH) {
    motor1.setMode(AUTO);
    motor1.setSpeed(100);
  }
  if (digitalRead(12) == LOW) {
    motor1.setMode(BRAKE);
  }


  if (digitalRead(13) == HIGH) {
    delay(1000);
    while (true) {
      if (digitalRead(13) == HIGH) {  // по часовой
        motor1.setMode(AUTO);
        motor1.setSpeed(-100);
        delay(1000);
        while (true) {
          if (digitalRead(13) == HIGH) {
            motor1.setMode(BRAKE);
            delay(100);
            while (true) {
              a = sensor.readRangeSingleMillimeters();
              if (a < 100) {
                digitalWrite(8, HIGH);
                digitalWrite(2, HIGH);
                delay(100);
                a = sensor.readRangeSingleMillimeters();
                if (a < 100) {
                  delay(5000);
                  Serial.println("cicl");
                  Serial.println(value1);
                  Serial.println(value2);
                  Serial.println(value3);
                  Serial.println(value4);
                  Serial.println(value5);

                  if (value1 == 1 && value2 == 0 && value3 == 0 && value4 == 0 && value5 == 0 && rad == 0 && black == 0) {
                    rad = 1;
                    black = 1;
                    digitalWrite(6, HIGH);
                    delay(timing1);
                    digitalWrite(6, LOW);
                    delay(2000);
                    digitalWrite(8, LOW);
                    digitalWrite(2, HIGH);
                    delay(300);
                    value1 = 0;
                    value2 = 0;
                    value3 = 0;
                    value4 = 0;
                    value5 = 0;
                  }
                  Serial.println("rad");
                  Serial.println(rad);
                  Serial.println("yellow");
                  Serial.println(yellow);
                  if (value1 == 1 && value2 == 1 && value3 == 0 && value4 == 0 && value5 == 0 && rad == 1 && yellow == 0) {
                    rad = 2;
                    yellow = 1;
                    digitalWrite(6, HIGH);
                    delay(timing2);
                    digitalWrite(6, LOW);
                    delay(2000);
                    digitalWrite(8, LOW);
                    digitalWrite(2, HIGH);
                    delay(300);
                    value1 = 0;
                    value2 = 0;
                    value3 = 0;
                    value4 = 0;
                    value5 = 0;
                  }
                  if (value1 == 1 && value2 == 1 && value3 == 1 && value4 == 0 && value5 == 0 && rad == 2 && red == 0) {
                    rad = 3;
                    red = 1;
                    digitalWrite(6, HIGH);
                    delay(timing3);
                    digitalWrite(6, LOW);
                    delay(2000);
                    digitalWrite(8, LOW);
                    digitalWrite(2, HIGH);
                    delay(300);
                    value1 = 0;
                    value2 = 0;
                    value3 = 0;
                    value4 = 0;
                    value5 = 0;
                  }
                  if (value1 == 1 && value2 == 1 && value3 == 1 && value4 == 1 && value5 == 0 && rad == 3 && white == 0) {
                    rad = 4;
                    white = 1;
                    digitalWrite(6, HIGH);
                    delay(timing4);
                    digitalWrite(6, LOW);
                    delay(2000);
                    digitalWrite(8, LOW);
                    digitalWrite(2, HIGH);
                    delay(300);
                    value1 = 0;
                    value2 = 0;
                    value3 = 0;
                    value4 = 0;
                    value5 = 0;
                  }
                  if (value1 == 1 && value2 == 1 && value3 == 1 && value4 == 1 && value5 == 1 && rad == 4 && blue == 0) {
                    rad = 5;
                    blue = 1;
                    digitalWrite(6, HIGH);
                    delay(timing5);
                    digitalWrite(6, LOW);
                    delay(2000);
                    digitalWrite(8, LOW);
                    digitalWrite(2, HIGH);
                    delay(300);
                    value1 = 0;
                    value2 = 0;
                    value3 = 0;
                    value4 = 0;
                    value5 = 0;
                  } else {
                    digitalWrite(8, LOW);
                    digitalWrite(2, HIGH);
                    delay(300);
                    value1 = 0;
                    value2 = 0;
                    value3 = 0;
                    value4 = 0;
                    value5 = 0;
                  }
                } else {
                  digitalWrite(8, LOW);
                  digitalWrite(2, HIGH);
                  delay(300);
                  value1 = 0;
                  value2 = 0;
                  value3 = 0;
                  value4 = 0;
                  value5 = 0;
                }
              }
              if (a > 100) {
                digitalWrite(8, LOW);
                digitalWrite(2, HIGH);
              }
              delay(10);
            }
          }
        }
      }



      if (digitalRead(12) == HIGH) {  // против часовой часовой
        motor1.setMode(AUTO);
        motor1.setSpeed(-100);
        delay(1000);
        while (true) {
          if (digitalRead(13) == HIGH) {
            motor1.setMode(BRAKE);
            delay(100);
            while (true) {
              a = sensor.readRangeSingleMillimeters();
              if (a < 100) {
                digitalWrite(8, HIGH);
                digitalWrite(2, HIGH);
                delay(100);
                a = sensor.readRangeSingleMillimeters();
                if (a < 100) {
                  delay(5000);
                  Serial.println("cicl");
                  Serial.println(value1);
                  Serial.println(value2);
                  Serial.println(value3);
                  Serial.println(value4);
                  Serial.println(value5);

                  if (value1 == 1 && value2 == 0 && value3 == 0 && value4 == 0 && value5 == 0 && rad == 0 && black == 0) {
                    rad = 1;
                    black = 1;
                    digitalWrite(6, HIGH);
                    delay(timing1);
                    digitalWrite(6, LOW);
                    delay(2000);
                    digitalWrite(2, LOW);
                    digitalWrite(8, HIGH);
                    delay(300);
                    value1 = 0;
                    value2 = 0;
                    value3 = 0;
                    value4 = 0;
                    value5 = 0;
                  }
                  Serial.println("rad");
                  Serial.println(rad);
                  Serial.println("yellow");
                  Serial.println(yellow);
                  if (value1 == 1 && value2 == 1 && value3 == 0 && value4 == 0 && value5 == 0 && rad == 1 && yellow == 0) {
                    rad = 2;
                    yellow = 1;
                    digitalWrite(6, HIGH);
                    delay(timing2);
                    digitalWrite(6, LOW);
                    delay(2000);
                    digitalWrite(2, LOW);
                    digitalWrite(8, HIGH);
                    delay(300);
                    value1 = 0;
                    value2 = 0;
                    value3 = 0;
                    value4 = 0;
                    value5 = 0;
                  }
                  if (value1 == 1 && value2 == 1 && value3 == 1 && value4 == 0 && value5 == 0 && rad == 2 && red == 0) {
                    rad = 3;
                    red = 1;
                    digitalWrite(6, HIGH);
                    delay(timing3);
                    digitalWrite(6, LOW);
                    delay(2000);
                    digitalWrite(2, LOW);
                    digitalWrite(8, HIGH);
                    delay(300);
                    value1 = 0;
                    value2 = 0;
                    value3 = 0;
                    value4 = 0;
                    value5 = 0;
                  }
                  if (value1 == 1 && value2 == 1 && value3 == 1 && value4 == 1 && value5 == 0 && rad == 3 && white == 0) {
                    rad = 4;
                    white = 1;
                    digitalWrite(6, HIGH);
                    delay(timing4);
                    digitalWrite(6, LOW);
                    delay(2000);
                    digitalWrite(2, LOW);
                    digitalWrite(8, HIGH);
                    delay(300);
                    value1 = 0;
                    value2 = 0;
                    value3 = 0;
                    value4 = 0;
                    value5 = 0;
                  }
                  if (value1 == 1 && value2 == 1 && value3 == 1 && value4 == 1 && value5 == 1 && rad == 4 && blue == 0) {
                    rad = 5;
                    blue = 1;
                    digitalWrite(6, HIGH);
                    delay(timing5);
                    digitalWrite(6, LOW);
                    delay(2000);
                    digitalWrite(2, LOW);
                    digitalWrite(8, HIGH);
                    delay(300);
                    value1 = 0;
                    value2 = 0;
                    value3 = 0;
                    value4 = 0;
                    value5 = 0;
                  } else {
                    digitalWrite(2, LOW);
                    digitalWrite(8, HIGH);
                    delay(300);
                    value1 = 0;
                    value2 = 0;
                    value3 = 0;
                    value4 = 0;
                    value5 = 0;
                  }
                } else {
                  digitalWrite(2, LOW);
                  digitalWrite(8, HIGH);
                  delay(300);
                  value1 = 0;
                  value2 = 0;
                  value3 = 0;
                  value4 = 0;
                  value5 = 0;
                }
              }
              if (a > 100) {
                digitalWrite(8, HIGH);
                digitalWrite(2, LOW);
              }
              delay(30);
            }
          }
        }
      }
    }
  }
  delay(10);
}
void yield() {
  if (digitalRead(10) == HIGH && digitalRead(4) == HIGH && digitalRead(7) == HIGH && digitalRead(9) == HIGH && digitalRead(11) == HIGH) {
    value5 = 1;
    Serial.println("value5");
  }
  if (digitalRead(4) == HIGH && digitalRead(7) == HIGH && digitalRead(9) == HIGH && digitalRead(11) == HIGH) {
    value4 = 1;
    Serial.println("value4");
  }
  if (digitalRead(7) == HIGH && digitalRead(9) == HIGH && digitalRead(11) == HIGH) {
    value3 = 1;
    Serial.println("value3");
  }
  if (digitalRead(9) == HIGH && digitalRead(11) == HIGH) {
    value2 = 1;
    Serial.println("value2");
  }
  if (digitalRead(11) == HIGH) {
    value1 = 1;
    Serial.println("value1");
  }
}
