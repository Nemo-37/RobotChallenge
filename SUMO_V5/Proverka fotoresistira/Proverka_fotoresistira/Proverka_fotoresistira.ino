
void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(10, OUTPUT);

  digitalWrite(8, LOW);
  digitalWrite(10, HIGH);
}

void loop() {
  if (500 < analogRead(A7) || analogRead(A7) < 580) {
    digitalWrite(13, HIGH);
  }
  if (analogRead(A7) > 650) {
    digitalWrite(13, LOW);
  }    
  delay(50);
}