#include <cstdio>
#define LIST_SIZE 10

// gapp 만큼 떨어진 요소들을 삽입 정렬
// first ~ last 까지
void incInsertionSort(int list[], int first, int last, int gap) {
  int key, i, j;
  for(i = first + gap; i <= last; i += gap) {
    // 삽입될 숫자를 key에 복사
    key = list[i];

    // 정렬된 배열은 i - gap 까지임 --> i - gap 번째부터 역순 조사
    // j 값은 first 이상 && key(삽입될 숫자)보다 크면 j-gap 번째로 이동
    for(j = i - gap; j >= first && list[j] > key; j -= gap) {
      list[j + gap] = list[j];
    }

    list[j + gap] = key;
  }
}

void shellSort(int list[], int n) {
  int gap;
  for(gap = n / 2; gap > 0; gap /= 2) {
    if(gap % 2 == 0) {
      gap++; // gap 은 홀수가 됨
    }

    // 부분리스트의 개수 == gap
    for(int i = 0; i < gap; i++) {
      // 부분리스트 삽입정렬 수행
      incInsertionSort(list, i, n - 1, gap);
    }
  }
}

int main(void) {
  int list[LIST_SIZE] = {5, 3, 7, 8, 9, 2, 1, 54, 23, 99};

  shellSort(list, LIST_SIZE);

  // 출력
  for(int i = 0; i < LIST_SIZE; i++) {
    printf("%d ", list[i]);
  }
}
