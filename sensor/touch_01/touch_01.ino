const int TOUCH_SENSOR = 7;

void setup() {
  pinMode(TOUCH_SENSOR, INPUT);
  Serial.begin(115200);
}

void loop() {
  int status = digitalRead(TOUCH_SENSOR);

  if(status == LOW){
    Serial.println("Touch off");
  } else {
    Serial.println("*** Touch on ***");
  }

  delay(1000);
}
