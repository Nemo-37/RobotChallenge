void setup() {
  pinMode(12, INPUT);
  pinMode(7, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(2, OUTPUT);
  int time = 10;
  // put your setup code here, to run once:
}

void loop() {
  if (digitalRead(12) == HIGH) {
    int time = 8;    
    digitalWrite(4, HIGH);  //1
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(2, HIGH);
    delay(time);
    digitalWrite(4, HIGH);  //2
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(2, LOW);
    delay(time);
    digitalWrite(4, HIGH);  //3
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(2, LOW);
    delay(time);
    digitalWrite(4, HIGH);  //4
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(3, LOW);
    digitalWrite(2, LOW);
    delay(time);
    digitalWrite(4, LOW);  //5
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(3, LOW);
    digitalWrite(2, LOW);
    delay(time);
    digitalWrite(4, LOW);  //6
    digitalWrite(5, LOW);
    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);
    digitalWrite(3, HIGH);
    digitalWrite(2, LOW);
    delay(time);
    digitalWrite(4, LOW);  //7
    digitalWrite(5, LOW);
    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);
    digitalWrite(3, HIGH);
    digitalWrite(2, LOW);
    delay(time);
    digitalWrite(4, LOW);  //8
    digitalWrite(5, LOW);
    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);
    digitalWrite(3, HIGH);
    digitalWrite(2, LOW);
    delay(time);
    digitalWrite(4, LOW);  //9
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(3, LOW);
    digitalWrite(2, LOW);
    delay(time);
    digitalWrite(4, LOW);  //10
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(3, LOW);
    digitalWrite(2, LOW);
    delay(time);
    digitalWrite(4, HIGH);  //11
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(2, HIGH);
    delay(time);
    digitalWrite(4, LOW);  //12
    digitalWrite(5, HIGH);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(3, LOW);
    digitalWrite(2, LOW);
    delay(time);
    digitalWrite(4, LOW);  //13
    digitalWrite(5, LOW);
    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);
    digitalWrite(3, LOW);
    digitalWrite(2, LOW);
    delay(time);
    digitalWrite(4, LOW);  //14
    digitalWrite(5, HIGH);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(3, LOW);
    digitalWrite(2, LOW);
    delay(time);
    digitalWrite(4, HIGH);  //15
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(2, HIGH);
    delay(time);
    digitalWrite(4, LOW);  //16
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(3, LOW);
    digitalWrite(2, LOW);
    delay(time);
    digitalWrite(4, LOW);  //17
    digitalWrite(5, LOW);
    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);
    digitalWrite(3, LOW);
    digitalWrite(2, LOW);
    delay(time);
    digitalWrite(4, LOW);  //18
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(3, LOW);
    digitalWrite(2, LOW);
    delay(time);
    digitalWrite(4, LOW);  //19
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(2, HIGH);
    delay(time);
    digitalWrite(4, HIGH);  //20
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(2, LOW);
    delay(time);
    digitalWrite(4, LOW);  //21
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(2, HIGH);
    delay(time);
    digitalWrite(4, LOW);  //
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(3, LOW);
    digitalWrite(2, LOW);
    delay(time);
    
    
    // put your main code here, to run repeatedly:
  }
}
