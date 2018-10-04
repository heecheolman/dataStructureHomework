// PointerPage6
#include <iostream>

int main(void) {
  // 배열 선언
  int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  // 포인터변수 p 선언
  int * p;
  // array 배열의 주소상수를 p 에 할당
  p = array;
  for(int i = 0; i < 10; i++) {
    printf("a[%d] = %d, p[%d] = %d, *(p + %d) = %d\n", i, array[i], i, p[i], i, *(p + i));
  }

  std::cout << std::endl;

  // array 배열의 첫번째 요소의 주소를 p 에 할당
  p = &array[0];
  for(int i = 0; i < 10; i++) {
    printf("a[%d] = %d, p[%d] = %d, *(p + %d) = %d\n", i, array[i], i, p[i], i, *(p + i));
  }
}

/*
[input]

[output]
a[0] = 1, p[0] = 1, *(p + 0) = 1
a[1] = 2, p[1] = 2, *(p + 1) = 2
a[2] = 3, p[2] = 3, *(p + 2) = 3
a[3] = 4, p[3] = 4, *(p + 3) = 4
a[4] = 5, p[4] = 5, *(p + 4) = 5
a[5] = 6, p[5] = 6, *(p + 5) = 6
a[6] = 7, p[6] = 7, *(p + 6) = 7
a[7] = 8, p[7] = 8, *(p + 7) = 8
a[8] = 9, p[8] = 9, *(p + 8) = 9
a[9] = 10, p[9] = 10, *(p + 9) = 10

a[0] = 1, p[0] = 1, *(p + 0) = 1
a[1] = 2, p[1] = 2, *(p + 1) = 2
a[2] = 3, p[2] = 3, *(p + 2) = 3
a[3] = 4, p[3] = 4, *(p + 3) = 4
a[4] = 5, p[4] = 5, *(p + 4) = 5
a[5] = 6, p[5] = 6, *(p + 5) = 6
a[6] = 7, p[6] = 7, *(p + 6) = 7
a[7] = 8, p[7] = 8, *(p + 7) = 8
a[8] = 9, p[8] = 9, *(p + 8) = 9
a[9] = 10, p[9] = 10, *(p + 9) = 10
*/
