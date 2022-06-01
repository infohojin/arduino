void setup()
{
  pinMode(6, OUTPUT);
}

void loop()
{
  analogWrite(6, 255);
  delay(1000); // Wait for 1000 millisecond(s)
  analogWrite(6, 0);
  delay(1000); // Wait for 1000 millisecond(s)
}
