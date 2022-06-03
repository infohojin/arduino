// 서버 연결핀
const int servoPin = 3;
int freq = 20000; // 20 milliseconds (50Hz)
int minPulse = 600; // 60 micro seconds
int maxPulse = 2500; // 2500 micro second

void setup(){
  pinMode(servoPin, OUTPUT);
  digitalWrite(servoPin, LOW);
}

void loop() {
  for(int i=0; i<180;i++){
    setServo(i);
  }  

  for(int i=180;i>0;i--){
    setServo(i);
  } 
}

void setServo(int degree){
  int hTime = 0;
  int lTime = 0;

  if(degree <0) {
    degree = 0;
  } else if(degree>180){
    degree = 180;
  }

  hTime = (int)(minPulse + ((maxPulse-minPulse)/180.0 * degree));
  lTime = freq - hTime;

  digitalWrite(servoPin,HIGH);
  delayMicroseconds(hTime);
  digitalWrite(servoPin,LOW);
  delayMicroseconds(lTime);
}
