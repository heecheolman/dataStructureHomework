// ArrayPage6
#include <iostream>

int main(void) {
  int row, col;

  // input
  // 2차원 배열의 행과 열 입력
  std::cin >> row >> col;
  // 배열 선언
  int array[row][col];
  int rTotal[row];
  int cTotal[col];
  // rTotal 요소 초기화
  for(int i = 0; i < row; i++) {
    rTotal[i] = 0;
  }
  // cTotal 요소 초기화
  for(int i = 0; i < col; i++) {
    cTotal[i] = 0;
  }
  // 각 요소 입력
  for(int i = 0; i < row; i++) {
    for(int j = 0; j < col; j++) {
      std::cin >> array[i][j];
    }
  }

  // 각행은 rTotal의 i 번째 에 누적해서 더해지고
  // 각열은 cTotal의 j 번째 에 누적해서 더해짐
  for(int i = 0; i < row; i++) {
    for(int j = 0; j < col; j++) {
      rTotal[i] += array[i][j];
      cTotal[j] += array[i][j];
    }
  }

  // 출력
  std::cout << "rTotal = { ";
  for(int i = 0; i < row; i++) {
    std::cout << rTotal[i] << ", ";
  }
  std::cout << " }" << std::endl;

  std::cout << "cTotal = { ";
  for(int i = 0; i < col; i++) {
    std::cout << cTotal[i] << ", ";
  }
  std::cout << " }" << std::endl;
}

/*
[input - 행, 열, 첫번째배열요소들, 두번째배열 요소들]
5 5
2 3 1 7 3
4 1 9 6 8
5 5 2 4 4
6 5 2 6 7
8 4 2 2 2

[output - sumArray]
rTotal = { 16, 28, 20, 26, 18,  }
cTotal = { 25, 18, 16, 25, 24,  }
*/
