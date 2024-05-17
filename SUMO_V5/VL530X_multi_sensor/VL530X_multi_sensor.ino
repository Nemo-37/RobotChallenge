#include <Wire.h>
#include <VL53L0X.h>

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


void setup()
{
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);

  delay(500);
  Wire.begin();


  Serial.begin (9600);

  digitalWrite(7, HIGH);
  delay(150);
  Serial.println("00");
  sensor.init(true);

  Serial.println("01");
  delay(100);
  sensor.setAddress((uint8_t)01);
  Serial.println("02");

  digitalWrite(8, HIGH);
    delay(150);
  sensor2.init(true);
  Serial.println("03");
  delay(100);
  sensor2.setAddress((uint8_t)02);
  Serial.println("04");
  
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

}

void loop()
{
  
  a=sensor.readRangeContinuousMillimeters();
  Serial.print(a);
  Serial.print("  ");
  b=sensor2.readRangeContinuousMillimeters();
  Serial.print(b);
  Serial.print("  ");
  c=sensor3.readRangeContinuousMillimeters();
  Serial.print(c);
  Serial.print("  ");
  d=sensor4.readRangeContinuousMillimeters();
  Serial.print(d);
  Serial.print("  ");
  e=sensor5.readRangeContinuousMillimeters();
  Serial.print(e);
  Serial.print("  ");
Serial.println();
delay(100);
}

