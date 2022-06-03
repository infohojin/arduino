void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.print("hello");
  Serial.println("world");
  Serial.println(23, DEC);
  Serial.println(23, HEX);
  Serial.println(23, BIN);
}

void loop() {
  // put your main code here, to run repeatedly:
  
}
