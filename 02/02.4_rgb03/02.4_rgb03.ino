
void setup()
{
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);

  Serial.begin(115200);
  Serial.println("RGB ?");


}

void loop()
{
// 수신데이터가 있는지 확인
  if(Serial.available()){
    // rgb 숫자 읽기
    int rv = Serial.parseInt();
    int gv = Serial.parseInt();
    int bv = Serial.parseInt();
        
    analogWrite(9, rv);
    analogWrite(10, gv);
    analogWrite(11, bv);

    Serial.println(rv);
    Serial.println(gv);
    Serial.println(bv);
    
  }
}
