#include "LedControl.h" 

// step1 : 매트릭스 설정
const int DIN=7; // DIN 핀을 7번
const int CS=8;  // CS핀을 8번
const int CLK=9; // CLK 핀을 9번에 
const int MATRIX=8; // (DIN, CLK, CS, 연결할 도트 매트릭스의 개수)


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
  int led=B00000001;
  
  for(int i=2, start=0; i<=256; i*=2, start++){
    for(line=start; line<8; line++){
        dot_matrix.setRow(n,line, led);
        delay(100);
    }  

    // 위치 갯수 추가
    led |= i;
  }

  // 초기화
  dot_matrix.clearDisplay(n);  
}