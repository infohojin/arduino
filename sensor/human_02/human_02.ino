const int SENSOR = 7;

void setup() {
  pinMode(SENSOR, INPUT);
  Serial.begin(115200);

  pinMode(13, OUTPUT);
}

void loop() {
  int status = digitalRead(SENSOR);

  if(status == LOW){
    Serial.println("NOT Activated");
    digitalWrite(13,LOW);
  } else {
    Serial.println("*** Activated ***");
    digitalWrite(13,HIGH);
  }

  delay(1000);
}
