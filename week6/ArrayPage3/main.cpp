// ArrayPage3
#include <iostream>

int main(void) {
  // 변수 선언
  int row, max, total, val;
  // 배열 초기화 및 선언
  int array[7] = {13, 10, 17, 9, 2, 7, 19};
  // 변수 초기화
  total = 0;
  row = 0;
  val = array[0];
  // 모든 배열의 합과 최대값, 그리고 최대값에 해당하는 열의 번호를 알아내는 for문
  for(int i = 0; i < sizeof(array) / sizeof(int); i++) {
    if(val < array[i]) {
      max = array[i];
      val = array[i];
      row = i;
    }
    total += array[i];
  }
  // 출력
  std::cout << "total : " << total << std::endl;
  std::cout << "max : " << max << std::endl;
  std::cout << "row : " << row << std::endl;
}
