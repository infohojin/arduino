const int TOUCH_SENSOR = 7;

void setup() {
  pinMode(TOUCH_SENSOR, INPUT);
  Serial.begin(115200);

  pinMode(13, OUTPUT);
}

void loop() {
  int status = digitalRead(TOUCH_SENSOR);

  if(status == LOW){
    Serial.println("Touch off");
    digitalWrite(13,LOW);
  } else {
    Serial.println("*** Touch on ***");
    digitalWrite(13,HIGH);
  }

  delay(1000);
}
