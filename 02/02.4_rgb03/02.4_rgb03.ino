
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
  // 빨강, 파랑, 녹색
// 수신데이터가 있는지 확인
  if(Serial.available()){
    // rgb 숫자 읽기
    int rv = Serial.parseInt();
    int gv = Serial.parseInt();
    int bv = Serial.parseInt();
        
    analogWrite(9, (255-rv)); // 애노드 타입 변환
    analogWrite(10, (255-gv));
    analogWrite(11, (255-bv));

    Serial.println(rv);
    Serial.println(gv);
    Serial.println(bv);
    
  }
}
