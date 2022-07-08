const int SENSOR = A0;

void setup() {
  pinMode(SENSOR, INPUT);
  Serial.begin(115200);
}

void loop() {
  int status = analogRead(SENSOR);

  Serial.print("sound =");
  Serial.println(status);
  /*
  if(status == LOW){
    Serial.println("sound off");
  } else {
    Serial.println("*** Sound ON ***");
  }
  */

  delay(100);
}
