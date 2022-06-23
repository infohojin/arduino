
const int IN1 = 8;
const int IN2 = 9;

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
}

void loop() {
  // 정방향 회전
  digitalWrite(IN1, HIGH);

  // 점점 속도 증가
  for(int i=50;i<255;i++) {
    analogWrite(IN2,i);
    delay(50);
  }

  // 점점 속도 감소
  for(int i=255;i>50;i--) {
    analogWrite(IN2,i);
    delay(50);
  }
}
