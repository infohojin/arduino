//아날로그 핀을 디지털 입출력을 사용할 경우 핀번호를 14~19번으로 사용합니다.
const int KEYin=14; 
const int Yin=A1;
const int Xin=A2;

void setup() {
  pinMode(14, INPUT);
  Serial.begin(115200);
}

void loop() {
  int xVal = analogRead(Xin);
  int yVal = analogRead(Yin);
  int buttonVal = digitalRead(KEYin);

  Serial.print("X= ");
  Serial.print(xVal, DEC);

  Serial.print(", Y= ");
  Serial.print(yVal, DEC);

  Serial.print("Button is = ");
  Serial.print(buttonVal);
  if(buttonVal == HIGH){
    Serial.println("not pressed");
  } else {
    Serial.println("PRESSED");
  }

  delay(1000);
  
}
