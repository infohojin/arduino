// 1번만 실행됨
void setup()
{
  pinMode(6, OUTPUT);
}

// 반복적으로 실행됨
void loop()
{
  digitalWrite(6, HIGH);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(6, LOW);
  delay(1000); // Wait for 1000 millisecond(s)
}
