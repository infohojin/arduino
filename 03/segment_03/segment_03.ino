// C++ code
//
const int a = 12;
const int b = 13; 
const int c = 7;
const int d = 8;
const int e = 9;
const int f = 11;
const int g = 10;
const int dp = 6;

const int led[8] = {12, 13, 7, 8, 9, 11, 10, 6};
byte number[10][8] = {
  {1,1,1,1,1,1,0,0}, //0
  {0,1,1,0,0,0,0,0}, //1
  {1,1,0,1,1,0,1,0}, //2
  {1,1,1,1,0,0,1,0}, //3
  {0,1,1,0,0,1,1,0}, //4
  {1,0,1,1,0,1,1,0}, //5
  {1,0,1,1,1,1,1,0}, //6
  {1,1,1,0,0,1,0,0}, //7
  {1,1,1,1,1,1,1,0}, //8
  {1,1,1,1,0,1,1,0} //9
};
  

void setup()
{
  for(int i=0; i<8;i++){
    pinMode(led[i], OUTPUT);
  }
  
  pinMode(2, INPUT);
}

void loop()
{
  int btn = digitalRead(2);
  if(btn == LOW) {
    // 난수발생 패턴이 일정하지 않도록 seed값을 지정
    randomSeed(analogRead(0));
    int num = random(0, 6); // 0~5 임의수
    
    for(int j=0; j<8; j++){
      digitalWrite(led[j], number[num][j]);
    }    
  }
}
