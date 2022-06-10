// C++ code
//
const int a = 12;
const int b = 13; 
const int c = 7;
const int d = 8;
const int e = 9;
const int f = 11;
const int g = 10;
const int dp = 6;
  
void setup()
{
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(dp, OUTPUT);
}

void loop()
{
  // 켜기
  digitalWrite(a, HIGH);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(b, HIGH);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(c, HIGH);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(d, HIGH);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(e, HIGH);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(f, HIGH);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(g, HIGH);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(dp, HIGH);
  delay(1000); // Wait for 1000 millisecond(s)
  
  // 끄기
  digitalWrite(a, LOW);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(b, LOW);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(c, LOW);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(d, LOW);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(e, LOW);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(f, LOW);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(g, LOW);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(dp, LOW);
  delay(1000); // Wait for 1000 millisecond(s)

}
