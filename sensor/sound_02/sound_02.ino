const int SENSOR = A0;
const int LED = 9;

void setup() {
  pinMode(SENSOR, INPUT);
  Serial.begin(115200);

  pinMode(LED, OUTPUT);
}

void loop() {
  int sound = analogRead(SENSOR);

  Serial.print("sound =");
  Serial.println(sound);

  if(sound > 30) {
    digitalWrite(LED, HIGH);
    delay(1000);
  } else {
    digitalWrite(LED, LOW);
  }

  delay(100);
}
