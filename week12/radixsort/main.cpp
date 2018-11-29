#include <stdio.h>
#include <stdlib.h>

// list 크기 10
#define LIST_SIZE 10

#define RADIX 10
#define DIGIT 2

/* Queue 구현 */

typedef int element;
typedef struct QueueNode {
    element data;
    struct QueueNode * link;
} QueueNode;

typedef struct {
    QueueNode * front;
    QueueNode * rear;
} LinkedQueueType;

// 큐 초기화 작업
LinkedQueueType * createQueue() {
    LinkedQueueType *LQ;
    LQ = (LinkedQueueType *)malloc(sizeof(LinkedQueueType));
    LQ->front = NULL;
    LQ->rear = NULL;
    return LQ;
}

// LQ->front 가 NULL 이면 비어있는 상태      1반환
//                 아니면 하나라도 있는상태   0반환
int isEmpty(LinkedQueueType * LQ) {
    return LQ->front ? 0 : 1;
}

void enQueue(LinkedQueueType * LQ, element data) {
    QueueNode * newNode = (QueueNode *)malloc(sizeof(QueueNode));
    newNode->data = data;
    newNode->link = NULL;
    // 공백큐인 경우
    if(LQ->front == NULL) {
        LQ->front = newNode;
        LQ->rear = newNode;

    // 그렇지 않은경우
    } else {
        LQ->rear->link = newNode;
        LQ->rear = newNode;
    }
}

element deQueue(LinkedQueueType * LQ) {
    if(isEmpty(LQ)) {
        return 0;
    }
    // 제거할 노드를 가리킬 임시포인터 old
    QueueNode * old;
    // 제거할 노드의 data를 return 시킬 변수
    element dequeueData;
    // old 가 front 를 가리킴
    old = LQ->front;
    // old 의 data 를 dequeueData 에 할당
    dequeueData = old->data;
    // front 가 그 다음 노드를 가리키도록 함
    LQ->front = LQ->front->link;
    // 이동된 front 가 NULL 이라면 공백이니 rear도 NULL 로 만들어줌
    if(!(LQ->front)) {
        LQ->rear = NULL;
    }
    // 노드 제거
    free(old);
    return dequeueData;
}

/*** Queue 구현 종료 ***/

void radixSort(int a[], int n) {
  int i, bucket, d, factor = 1;
  LinkedQueueType *Q[RADIX];
  for(bucket = 0; bucket < RADIX; bucket++) {
    Q[bucket] = createQueue();
  }
  for(d = 0; d < DIGIT; d++) {
    for(i = 0; i < n; i++) {
      enQueue(Q[(a[i] / factor) % 10], a[i]);
    }
    for(bucket = 0, i = 0; bucket < RADIX; bucket++) {
      while(!isEmpty(Q[bucket])) {
        a[i++] = deQueue(Q[bucket]);
      }
    }
    printf("\n\n %d 단계 : \n\t", d + 1);
    for(i = 0; i < n; i++) {
      printf(" %d", a[i]);
    }

    factor *= 10;
  }
}

int main(void) {
  int list[LIST_SIZE] = {5, 3, 7, 8, 9, 2, 1, 54, 23, 99};
  printf(" <<<< 기수 정렬 수행 >>>>> ");
  radixSort(list, LIST_SIZE);
  return 0;
}
