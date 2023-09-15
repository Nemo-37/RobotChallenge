#include <iarduino_IR_RX.h>
#include <Wire.h>
iarduino_IR_RX IR(12);
#define PIN_ENA 6      // Вывод управления скоростью вращения мотора №1
#define PIN_ENB 5      // Вывод управления скоростью вращения мотора №2
#define PIN_IN1 3      // Вывод управления направлением вращения мотора №1
#define PIN_IN2 2      // Вывод управления направлением вращения мотора №1
#define PIN_IN3 7      // Вывод управления направлением вращения мотора №2
#define PIN_IN4 4      // Вывод управления направлением вращения мотора №2
uint8_t power = 255;   // Значение ШИМ (или скорости движения)
uint8_t power1 = 150;  // Значение ШИМ (или скорости врашения)
long flagTime; 
void setup() {
    IR.begin();                       // Инициируем работу с ИК-приёмником
  Serial.begin(9600);  
  pinMode(13, OUTPUT);
  // put your setup code here, to run once:
pinMode(PIN_ENA, OUTPUT);
  pinMode(PIN_ENB, OUTPUT);
  pinMode(PIN_IN1, OUTPUT);
  pinMode(PIN_IN2, OUTPUT);
  pinMode(PIN_IN3, OUTPUT);
  pinMode(PIN_IN4, OUTPUT);
}

void loop() {
  digitalWrite(13, HIGH);
  if (IR.check(true)){
    if (IR.data == 0x20DF28D7) {
      flagTime = millis();
  // put your main code here, to run repeatedly:
    analogWrite(PIN_ENA, power);       // Устанавливаем скорость 1-го мотора
    analogWrite(PIN_ENB, power);            // Устанавливаем скорость 2-го мотора
    digitalWrite(PIN_IN1, HIGH);
    digitalWrite(PIN_IN2, LOW);
    // Задаём направление для 2-го мотора
    digitalWrite(PIN_IN3, HIGH);
    digitalWrite(PIN_IN4, LOW);
    delay(100);
    }
    if (IR.data == 0x20DF6897) {
      flagTime = millis();
  // put your main code here, to run repeatedly:
    analogWrite(PIN_ENA, power);       // Устанавливаем скорость 1-го мотора
    analogWrite(PIN_ENB, power);            // Устанавливаем скорость 2-го мотора
    digitalWrite(PIN_IN1, LOW);
    digitalWrite(PIN_IN2, HIGH);
    // Задаём направление для 2-го мотора
    digitalWrite(PIN_IN3, LOW);
    digitalWrite(PIN_IN4, HIGH);
    delay(100);
    }
        if (IR.data == 0x20DF18E7) {
      flagTime = millis();
  // put your main code here, to run repeatedly:
    analogWrite(PIN_ENA, power);       // Устанавливаем скорость 1-го мотора
    analogWrite(PIN_ENB, power);            // Устанавливаем скорость 2-го мотора
    digitalWrite(PIN_IN1, HIGH);
    digitalWrite(PIN_IN2, LOW);
    // Задаём направление для 2-го мотора
    digitalWrite(PIN_IN3, LOW);
    digitalWrite(PIN_IN4, HIGH);
    delay(100);
    }
            if (IR.data == 0x20DF48B7) {
      flagTime = millis();
  // put your main code here, to run repeatedly:
    analogWrite(PIN_ENA, power);       // Устанавливаем скорость 1-го мотора
    analogWrite(PIN_ENB, power);            // Устанавливаем скорость 2-го мотора
    digitalWrite(PIN_IN1, LOW);
    digitalWrite(PIN_IN2, HIGH);
    // Задаём направление для 2-го мотора
    digitalWrite(PIN_IN3, HIGH);
    digitalWrite(PIN_IN4, LOW);
    delay(100);
    }
    if (flagTime + 200 > millis()){ 
          analogWrite(PIN_ENA, power);       // Устанавливаем скорость 1-го мотора
    analogWrite(PIN_ENB, power);            // Устанавливаем скорость 2-го мотора
    digitalWrite(PIN_IN1, HIGH);
    digitalWrite(PIN_IN2, HIGH);
    // Задаём направление для 2-го мотора
    digitalWrite(PIN_IN3, HIGH);
    digitalWrite(PIN_IN4, HIGH);
}
}
}
