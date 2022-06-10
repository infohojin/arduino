// C++ code
//
// 라이브러리 사용
#include <Servo.h>

// 서버 연결핀
const int servoPin = 3;
Servo myservo;

void setup()
{
  pinMode(13, OUTPUT);
  pinMode(2,INPUT);
  
  myservo.attach(servoPin);
  myservo.write(0);
  delay(1000);
}

void loop()
{
  
  int sw = digitalRead(2);
  
  
  if(sw == LOW) {
    // 버튼이 눌렸어요
    digitalWrite(13, HIGH);
    myservo.write(180);
  } else {
    // 아니에요...
    digitalWrite(13, LOW);
    myservo.write(0);
  }

}
