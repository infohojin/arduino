void setup() {
  pinMode(6,OUTPUT);
}

void loop() {
  // 서서히 밝아지기
  for(int i=0; i<255; i++){
    analogWrite(6,i);
    delay(10); // 0.01초
  }
}
