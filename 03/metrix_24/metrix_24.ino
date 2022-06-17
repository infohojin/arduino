#include "LedControl.h" 

// step1 : 매트릭스 설정
const int DIN=7; // DIN 핀을 7번
const int CS=8;  // CS핀을 8번
const int CLK=9; // CLK 핀을 9번에 
const int MATRIX=4; // (DIN, CLK, CS, 연결할 도트 매트릭스의 개수)

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

void setup(){
  // 메트릭스 LED를 초기화 합니다.
  dot_metrix_init(MATRIX);
}


void loop() {
  int n = 0; // 첫번째 LED모듈,
  int line = 0; // 첫번째줄
  
  int led = 256;
  int i;
  
  for(i=1, line=0; i<255; i*=2, line++) {
    led &= 256 - i; // 각자리의 LED를 or 연산하여 누적합니다.
    dot_matrix.setRow(n,line, led);
    delay(500);
  }

  // 초기화
  led = 256;
  dot_matrix.clearDisplay(0); // 매트릭스를 초기화
}
