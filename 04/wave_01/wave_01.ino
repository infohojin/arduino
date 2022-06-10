// ultrasonic waves
const int tringPin = 11;
const int echoPin = 12;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  
  pinMode(tringPin, OUTPUT); // 초음파 발신
  pinMode(echoPin, INPUT); // 초음파 수신
}

void loop() {
  digitalWrite(tringPin, LOW);
  delayMicroseconds(2);
  digitalWrite(tringPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(tringPin, LOW);

  long timeDistance = pulseIn(echoPin, HIGH);
  long distance = (timeDistance/2) / 29.1;

  Serial.print(distance);
  Serial.println("cm");

}
