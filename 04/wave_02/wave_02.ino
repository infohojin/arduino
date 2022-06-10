// ultrasonic waves
const int tringPin = 11;
const int echoPin = 12;

const int activeB = 4;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  
  pinMode(tringPin, OUTPUT); // 초음파 발신
  pinMode(echoPin, INPUT); // 초음파 수신

  // 부저출력
  pinMode(activeB, OUTPUT);
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

  if(distance < 30) {
    digitalWrite(activeB, HIGH);
    delay(distance*10);
    digitalWrite(activeB, LOW);
    delay(distance*10);
  }
}
