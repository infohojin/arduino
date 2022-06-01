// i2c 통신을 위하여 해더 설정
#include <Wire.h>

void setup()
{
  Serial.begin(115200);
  Serial.println("\n I2C Scanner");
  
  i2c_scanning();
}

void loop() {
  
    
}

void i2c_scanning()
{
  byte Err, adr;
  int N_Device;

  Wire.begin();

  Serial.println("Scanning...");
  N_Device = 0;

  for(adr=1;adr<127; adr++){
    Wire.beginTransmission(adr);
    Err = Wire.endTransmission();
    

    // 전송성공
    if(Err == 0) {
      Serial.print("0x");
      Serial.print(adr, HEX);
      Serial.print(" => ");
      Serial.println("I2C device found at address");
      N_Device++;
    } else 
    // 주소 전송단계에서 NACK 응답이 발생한 경우
    // 해당 주소값을 가진 슬레이브 기기가 없는 경우
    if(Err == 2) {
    } else 
    // 그외의 오류 발생
    if(Err == 4) {
    }
   
    // delay(1000);    
  }

  if(N_Device == 0) {
    Serial.println("No I2C Device found");
  } else {
    Serial.println("Done");
  }
}
