#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

void setup()
{
  lcd.init();
  lcd.backlight();
}

void loop() {
  // 첫번째줄 순차적으로 숫자 쓰기
  lcd.setCursor(0,0);
  for(int i=0; i<10; i++){
    lcd.print(i);
    delay(500);
  }

  // 커서이용
  lcd.setCursor(16,1);
  lcd.autoscroll(); // 스크롤시작
  // 한글자 출력할때마다 스크롤됨
  for(int i=0; i<10; i++){
    lcd.print(i);
    delay(500);
  }

  lcd.noAutoscroll();
  lcd.clear();
  
}
