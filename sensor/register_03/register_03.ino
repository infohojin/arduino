// 가변저항
void setup()
{
  Serial.begin(9600);
  pinMode(11,OUTPUT);
}

void loop()
{
  int readValue = analogRead(A3);
  Serial.print("analog= ");
  Serial.print(readValue);

  // 범위변경
  int y = map(readValue, 0, 1023, 0, 255);
  // pwm 으로 밝기 조절
  analogWrite(11,y);
  Serial.print("LED= ");
  Serial.println(y);
}
