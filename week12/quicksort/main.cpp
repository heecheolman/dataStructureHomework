#include <cstdio>

#define LIST_SIZE 10
#define SWAP(x, y ,temp) ((temp)=(x), (x)=(y), (y)=(temp))


// 1. 피봇 기준 2개의 리스트로 나눔.
// 2. 피봇보다 작은 값은 모두 왼쪽 부분리스트로, 큰값은 오른쪽 부분리스트로 이동

int partition(int list[], int left, int right) {
  int pivot = list[left];
  int low = left;
  int high = right + 1;
  int temp;

  // low 와 high 가 교차할 때까지 반복
  do {

    // list[low] 가 피봇보다 작으면 계속 low를 증가
    do {
      low++;
    } while(low <= right && list[low] < pivot);

    // list[high] 가 피봇보다 크면 high 를 감소
    do {
      high--;
    } while(high >= left && list[high] > pivot);

    // low 와 high 가 교차하지 않았으면 교환
    if(low < high) {
      SWAP(list[low], list[high], temp);
    }

  } while(low < high);

  // low 와 high가 교차했으면 list[left] 와 list[right] 교환
  SWAP(list[left], list[high], temp);
  return high;
}

// 정렬될 list 를 받고, 배열의 시작과 끝값을 받는다
void quickSort(int list[], int left, int right) {
  // recursive
  // 정렬할 데이터가 2개이상일때 수행
  if(left < right) {
    // 분할
    int pivotPos = partition(list, left, right);
    quickSort(list, left, pivotPos - 1);
    quickSort(list, pivotPos + 1, right);
  }
}

int main(void) {
  int list[LIST_SIZE] = {5, 3, 7, 8, 9, 2, 1, 54, 23, 99};

  // 퀵소트 실행
  quickSort(list, 0, LIST_SIZE - 1);
  for(int i = 0; i < LIST_SIZE; i++) {
    printf("%d ", list[i]);
  }
}
