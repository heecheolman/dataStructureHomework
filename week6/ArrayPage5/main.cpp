// ArrayPage5
#include <iostream>

int main(void) {
  int row, col;

  // input
  // 2차원 배열의 행과 열 입력
  std::cin >> row >> col;
  // 첫번째 배열과 두번째 배열
  int array1[row][col];
  int array2[row][col];
  // 첫번째 배열과 두번째 배열을 더한 값을 갖는 sumArray 배열
  int sumArray[row][col];
  // 첫번째 배열의 요소 입력
  for(int i = 0; i < row; i++) {
    for(int j = 0; j < col; j++) {
      std::cin >> array1[i][j];
    }
  }
  // 두번째 배열의 요소 입력
  for(int i = 0; i < row; i++) {
    for(int j = 0; j < col; j++) {
      std::cin >> array2[i][j];
    }
  }

  // 첫번째 배열과 두번째 배열의 각각 요소를 더해 sumArray 에 더해줌
  for(int i = 0; i < row; i++) {
    for(int j = 0; j < col; j++) {
      sumArray[i][j] = array1[i][j] + array2[i][j];
    }
  }
  std::cout << std::endl;
  // sumArray 출력
  for(int i = 0; i < row; i++) {
    for(int j = 0; j < col; j++) {
      std::cout << sumArray[i][j] << " ";
    }
    std::cout << std::endl;
  }
}

/*
[input - 행, 열, 첫번째배열요소들, 두번째배열 요소들]
5 5
2 1 3 1 2
2 7 8 9 20
23 3 5 6 8
3 45 5 4 2
4 6 10 9 8

2 3 1 7 3
4 1 9 6 8
5 5 2 4 4
6 5 2 6 7
8 4 2 2 2

[output - sumArray]
4 4 4 8 5
6 8 17 15 28
28 8 7 10 12
9 50 7 10 9
12 10 12 11 10
*/
