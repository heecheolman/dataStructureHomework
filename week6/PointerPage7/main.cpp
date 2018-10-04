// PointerPage7
#include <iostream>

int main(void) {
  // 배열 선언
  int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  // 포인터변수 p 선언
  int * p;

  // array 배열의 주소상수를 p 에 할당
  p = array;
  // 주소값 출력
  printf("array = %p, &array[0] = %p, p = %p\n", array, &array[0], p);

  std::cout << std::endl;

  // array 배열의 첫번째 요소의 주소를 p 에 할당
  p = &array[0];
  // 주소값 출력
  printf("array = %p, &array[0] = %p, p = %p\n", array, &array[0], p);
}

/*
[input]

[output]
array = 0x7ffee9631930, &array[0] = 0x7ffee9631930, p = 0x7ffee9631930

array = 0x7ffee9631930, &array[0] = 0x7ffee9631930, p = 0x7ffee9631930
*/
