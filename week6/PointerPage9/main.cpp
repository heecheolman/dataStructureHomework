// PointerPage9
#include <iostream>

int main(void) {
  int array[4][3];
  int * p;

  // array initialization
  int count = 1;
  for(int i = 0; i < 4; i++) {
    for(int j = 0; j < 3; j++) {
      array[i][j] = count++;
    }
  }


  // 첫번째 행의 주소를 p 에 담는다
  p = array[0];
  for(int i = 0; i < 3; i++) {
    printf("p[%d] = %d, array[0][%d] = %d, *(p + %d) = %d\n", i, p[i], i, array[0][i], i, *(p + i));
  }

  // 두번째 행의 주소를 p 에 담는다
  p = array[1];
  for(int i = 0; i < 3; i++) {
    printf("p[%d] = %d, array[0][%d] = %d, *(p + %d) = %d\n", i, p[i], i, array[1][i], i, *(p + i));
  }


}

/*
[input]

[output]
p[0] = 1, array[0][0] = 1, *(p + 0) = 1
p[1] = 2, array[0][1] = 2, *(p + 1) = 2
p[2] = 3, array[0][2] = 3, *(p + 2) = 3
p[0] = 4, array[0][0] = 4, *(p + 0) = 4
p[1] = 5, array[0][1] = 5, *(p + 1) = 5
p[2] = 6, array[0][2] = 6, *(p + 2) = 6
*/
