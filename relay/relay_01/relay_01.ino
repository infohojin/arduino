const int RELAY = 10;

void setup() {
  // 릴레이 신호 10번핀 연결
  pinMode(RELAY,OUTPUT);
}

void loop() {
  // 릴레이 신호 깜빡임
  digitalWrite(RELAY, HIGH);
  delay(500);

  digitalWrite(RELAY, LOW);
  delay(500);
}
