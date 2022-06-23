#include "LedControl.h" 

// step1 : 매트릭스 설정
const int DIN=7; // DIN 핀을 7번
const int CS=8;  // CS핀을 8번
const int CLK=9; // CLK 핀을 9번에 
const int MATRIX=8; // (DIN, CLK, CS, 연결할 도트 매트릭스의 개수)

const int WIDTH = 4;
const int HIGHT = 2;

// 도트 매트릭스 제어 객체 선언
LedControl dot_matrix=LedControl(DIN,CS,CLK, MATRIX); 

void dot_metrix_init(int matrix) {
  // 매트릭스 0번부터 3번까지 세팅
  for(int i=0; i<matrix; i++) {
   dot_matrix.shutdown(i,false); // 0~3번까지 매트릭스 절전모드 해제
   dot_matrix.setIntensity(i,8); // 매트릭스의 밝기 0-15 사이의 정수
   dot_matrix.clearDisplay(i); // 매트릭스를 초기화
  }
}

int data[MATRIX][8];

void setup(){
  // 메트릭스 LED를 초기화 합니다.
  dot_metrix_init(MATRIX);

  // led 데이터 초기화
  for(int i=0; i<WIDTH * HIGHT; i++) {
    for(int j=0; j<8; j++){
      data[i][j] = 0;          
    }
  }
}

int cell[2][4] = {
  {0,1,2,3},
  {4,5,6,7}
};

void coordinate(int x, int y, int value = 1) {
  int posx, posy;
  int line;
  
  if(x>0) posx = x/8; else posx = 0;
  if(y>0) {
    posy = y/8;
    line = y % 8; 
  } else {
    posy = 0;
    line = 0;
  }

  int width = 4;
  int position = posy * width + posx; 

  int mydata = data[position][line];

  int bit = 0x01 << (posx = x%8);

  if(value == 1) {
    mydata |= bit;
  } else {
    mydata &= (0xff - bit);
  }
  
  data[position][line] = mydata;

  dot_matrix.setRow(position, line, mydata);
  
}


void loop() {
  //coordinate(0, 0);
  //delay(2000);
  
  for(int i=0, start=0; i<16; i++, start++){
    for(int j=0; j<=start; j++){
      coordinate(i, j);
      delay(50);
    }
  }

  delay(1000);

  for(int i=0, start=0; i<16; i++, start++){
    for(int j=0; j<=start; j++){
      coordinate(i, j, 0);
      delay(50);
    }
  }

  delay(1000);

  

}
