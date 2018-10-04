// ArrayPage4
#include <iostream>

int main(void) {
  // 변수 초기화
  int row, col, total;
  int saveR, saveC, saveVal; // 행과 열을 저장하는 변수
  // 배열의 행 열 입력
  std::cin >> row >> col;
  // 배열의 행열만큼 사이즈를 정해줌
  int array[row][col];
  // 배열 초기화
  for(int i = 0; i < row; i++) {
    for(int j = 0; j < col; j++) {
      std::cin >> array[i][j];
    }
  }
  // 첫번째 값을 저장
  saveVal = array[0][0];
  total = 0;
  // 순회
  for(int i = 0; i < row; i++) {
    for(int j = 0; j < col; j++) {
      // 현재있는 값이 기존의 값보다 크다면 행과 열, 그리고 그 값을 저장
      if(array[i][j] > saveVal) {
        saveR = i;
        saveC = j;
        saveVal = array[i][j];
      }
      // 배열의 각요소를 total 에 더해줌
      total += array[i][j];
    }
  }
  // 출력
  std::cout << "total : " << total << std::endl;
  std::cout << "max : " << saveVal << std::endl;
  std::cout << "row : " << saveR << std::endl;
  std::cout << "col : " << saveC << std::endl;
}


/*
[input - 행, 열, 배열]
5 5
2 1 3 1 2
2 7 8 9 20
23 3 5 6 8
3 45 5 4 2
4 6 10 9 8

[output]
total : 196
max : 45
row : 3
col : 1


*/
