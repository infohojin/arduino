// ultrasonic waves
#include <Wire.h>
#include <LiquidCrystal_I2C.h>


const int tringPin = 11;
const int echoPin = 12;

const int activeB = 4;

// i2c 기기 번호 0x27
LiquidCrystal_I2C lcd(0x27,16,2);


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  
  pinMode(tringPin, OUTPUT); // 초음파 발신
  pinMode(echoPin, INPUT); // 초음파 수신

  // 부저출력
  pinMode(activeB, OUTPUT);

  // LCD 초기화
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("ultrasonic waves");
}

void loop() {

  digitalWrite(tringPin, LOW);
  delayMicroseconds(2);
  digitalWrite(tringPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(tringPin, LOW);

  long timeDistance = pulseIn(echoPin, HIGH);
  long distance = (timeDistance/2) / 29.1;

  Serial.print(distance);
  Serial.println("cm");

  if(distance < 30) {
    digitalWrite(activeB, HIGH);
    delay(distance*10);
    digitalWrite(activeB, LOW);
    delay(distance*10);
  }
 
  // 2번째줄 첫번째칸 선택
  lcd.setCursor(0, 1);
  lcd.print(distance);
  
}
