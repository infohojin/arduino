// C++ code
//
void setup()
{
  pinMode(6, OUTPUT);
  pinMode(2, INPUT);
}

void loop()
{
  if(digitalRead(2) == LOW) {
    digitalWrite(6, HIGH);
  } else {
    digitalWrite(6, LOW);
  }

}
