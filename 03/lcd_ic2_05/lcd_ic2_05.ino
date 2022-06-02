#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);
int seconds = 0;

void setup()
{
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("hello world");
}

void loop() {
  // 2번째줄 첫번째칸 선택
  lcd.setCursor(0, 1);
  
  lcd.print(seconds);
  
  // 깜빡임
  lcd.setBacklight(1);
  delay(500); // Wait for 500 millisecond(s)
  lcd.setBacklight(0);
  delay(500); // Wait for 500 millisecond(s)
  
  seconds += 1; 
}
