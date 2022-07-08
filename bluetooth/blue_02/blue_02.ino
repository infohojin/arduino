#include <SoftwareSerial.h>
#define BT_RXD 8
#define BT_TXD 7

SoftwareSerial bluetooth(BT_RXD, BT_TXD);

void setup() {
  Serial.begin(9600);
  bluetooth.begin(9600);

  Serial.println("START");
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
}

void loop() {
  char val = bluetooth.read();
 
  if(bluetooth.available()){
    Serial.write(bluetooth.read());
  }

  if(val == 'a') {
    digitalWrite(3, HIGH);
  } 
  
  if(val == 'b') {
    digitalWrite(5, HIGH);
  } 

  if(val == 'c') {
    digitalWrite(3, LOW);
    digitalWrite(5, LOW);
  }
    
}
