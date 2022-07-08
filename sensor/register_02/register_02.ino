// 가변저항
void setup()
{
  Serial.begin(9600);
}

void loop()
{
  int readValue = analogRead(A0);
  Serial.println(readValue);
}
