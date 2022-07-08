// Master
#include <SPI.h>

void setup() {
  Serial.begin(9600);

  SPI.begin();
  digitalWrite(SS, HIGH); // 슬레이브가 선택되지 않은 상태 유지

  SPI.setClockDivider(SPI_CLOCK_DIV16);
}

void loop() {
  SPI.beginTransaction(SPISettings(2000000, MSBFIRST, SPI_MODE0));
  // 슬레이브 선택
  digitalWrite(SS,LOW);

  // 1바이트 데이터를 보내고, 수신
  // 슬레이브에게 0이라는 데이터를 송신하고,
  // 그에 대응하는 데이터 1byte를 수신합니다.
  byte received = SPI.transfer(0);
  digitalWrite(SS,HIGH);
  SPI.endTransaction();
  
  Serial.println(received);
  delay(1000);
}
