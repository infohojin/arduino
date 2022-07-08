const int SENSOR = A0;
const int BEEP = 8;

void setup() {
  Serial.begin(115200);
  pinMode(SENSOR, INPUT);

  // 부저
  pinMode(BEEP, OUTPUT);
}

void loop() {
  int value = analogRead(SENSOR);
  
  Serial.print("Sensor = ");
  Serial.println(value);

  if(value<900) {
    digitalWrite(BEEP,HIGH);
    delay(500);
    digitalWrite(BEEP,LOW);
    delay(500);
  }  
}
