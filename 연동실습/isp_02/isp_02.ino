// Slave
#include <SPI.h>

byte count;

void setup() {
  pinMode(MISO, OUTPUT);
  pinMode(MOSI, INPUT);
  pinMode(SCK, INPUT);
  pinMode(SS, INPUT);

  SPCR |= bit(SPE);
  SPI.attachInterrupt();

  count = 0;
  Serial.begin(9600);
  Serial.println("slave");
}

// SPI 통신 인터럽트
ISR (SPI_STC_vect)
{
  SPDR = count;
}

void loop() {
  count++;
  
  delay(1000);
}
