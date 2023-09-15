#define PIN_PHOTO_SENSOR A0

void setup() {
  Serial.begin(9600);
}

void loop() {
  int val = analogRead(PIN_PHOTO_SENSOR);
  Serial.println(val);
  delay(50);
}
