/**
 * SG90
 */
// 라이브러리 사용
#include <Servo.h>

// 서보객체 생성
Servo myservo;

// 서버 연결핀
const int servoPin = 3;
int minPulse = 600; // 60 micro seconds
int maxPulse = 2500; // 2500 micro second

void setup(){
  myservo.attach(servoPin, minPulse, maxPulse);
}

void loop() {

  // 정방향
  for(int i=0;i<=180;i++){
    myservo.write(i);
    delay(15);
  }

  // 역방향
  for(int i=180;i>0;i--){
    myservo.write(i);
    delay(15);
  }

}
