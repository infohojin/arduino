void setup() {
  // put your setup code here, to run once:
  pinMode(12,OUTPUT);
  pinMode(2,INPUT); // 포터센서 output
}

void loop() {
  if(digitalRead(2) == HIGH) {
    // if조건이 참인경우
    digitalWrite(12,HIGH);
  } else {
    // if조건이 거짓인 경우
    digitalWrite(12,LOW);
  }
  
}
