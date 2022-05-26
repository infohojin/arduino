const int time = 100;
const int wating = 100;

void setup() {
  pinMode(4,OUTPUT);

}

void loop() {
  // 모르스 Sos
  morse_s();
  morse_o();
  morse_s();
  delay(300);
 
}

void morse_s()
{
  dot();
  dot();
  dot();
}

void morse_o()
{
  bar();
  bar();
  bar();
}

void dot()
{
  digitalWrite(4,HIGH);
  delay(time);
  digitalWrite(4,LOW);

  delay(wating);
}

void bar()
{
  digitalWrite(4,HIGH);
  delay(3*time);
  digitalWrite(4,LOW);

  delay(wating);
}
