// L298N motor driver
//
#define ENB 6
#define IN3 8
#define IN4 9

#define ENCODER_B_A 2
#define ENCODER_B_B A0

byte encoderBLast;
bool encoderBDir = true;
int encoderBCount = 0;
bool active_A = false;

int distance= 0;

void ISR_encoderB() {
  byte encoderBA = digitalRead(ENCODER_B_A);

  // 방향체크
  if (encoderBLast == LOW && encoderBA == HIGH) {
    byte encoderBB = digitalRead(ENCODER_B_B);
    if (encoderBB == LOW) {
      encoderBDir = true;
    } else if (encoderBB == HIGH) {
      encoderBDir = false;
    }
  }
  encoderBLast = encoderBA;

  // 회전 카운트
  if (encoderBDir) {
    encoderBCount++;
  } else {
    encoderBCount--;
  }

  if(distance == encoderBCount) {
    dc_stop();
  }
  
  
}

void setup() {
  Serial.begin(115200);
  
  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(ENCODER_B_A, INPUT);
  pinMode(ENCODER_B_B, INPUT);
  
  attachInterrupt(digitalPinToInterrupt(ENCODER_B_A), ISR_encoderB, FALLING);

  
}

unsigned long lastTime = 0;
bool logging = false;
int speed = 40;

void loop() {

  if (Serial.available()) {
    char cmd = Serial.read();
    if (cmd == 'f') {
      Serial.println("forward");
      distance = 2000;
      
      dc_forward();
      logging = true;
    } if (cmd == 'b') {
      Serial.println("backward");
      distance = 2000;
      dc_backward();
      logging = true;
    } else if (cmd == 's') {
      Serial.println("stop");

      Serial.print(", distance = ");
      Serial.print(distance);

      Serial.print(" encoderB = ");
      Serial.print(encoderBCount);
      
      dc_stop();
      logging = false;
    } 
  }

  unsigned long currTime = millis();
  if (active_A && (currTime - lastTime > 100)) {
    Serial.print("speedB = ");
    Serial.print(currTime - lastTime);

    Serial.print(", distance = ");
    Serial.print(distance);

    Serial.print(" encoderB = ");
    Serial.print(encoderBCount);
    
    Serial.println();
    lastTime = currTime;
  }
  
}



void dc_backward()
{
  if(!active_A) {
    digitalWrite(IN3, HIGH);
    
    //digitalWrite(IN4, LOW);
    // 모터 스피드 pwm
    analogWrite(IN4, speed);
    
    analogWrite(ENB, 125);

    //동작시작
    active_A = true;
  }  
}

void dc_forward()
{
  if(!active_A) {
    digitalWrite(IN3, LOW);
    
    //digitalWrite(IN4, HIGH);
    analogWrite(IN4, speed); // 모터 스피드 pwm
  
    analogWrite(ENB, 125);
  
    //동작시작
    active_A = true;
  }  
}

void dc_stop()
{
  if(active_A) {
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
    analogWrite(ENB, 0);

    //동작시작
    active_A = false;
  }
}
