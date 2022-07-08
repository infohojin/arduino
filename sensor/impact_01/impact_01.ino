const int SENSOR = A5;

void setup() {
  Serial.begin(115200);
  pinMode(SENSOR, INPUT);
}

void loop() {
  int value = analogRead(SENSOR);
  
  Serial.print("Sensor = ");
  Serial.println(value);

  delay(500);
}
