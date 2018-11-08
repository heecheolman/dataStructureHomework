#include <iostream>
#include <cstdlib>

typedef int element;
typedef struct DequeNode {
    element data;
    struct DequeNode * rlink;
    struct DequeNode * llink;
} DequeNode;

typedef struct {
    DequeNode * front;
    DequeNode * rear;
} DequeType;

// 덱을 생성 후 반환
DequeType * createDeque() {
    DequeType * deque = (DequeType *)malloc(sizeof(DequeType));
    deque->front = nullptr;
    deque->rear = nullptr;
    return deque;
}

// 덱이 공백인지 확인하는 함수
int isEmpty(DequeType * DQ) {
    return DQ->front ? 0 : 1;
}

// 덱의 front 부분으로 삽입
void insertFront(DequeType * DQ, element data) {
    DequeNode * newNode = (DequeNode *)malloc(sizeof(DequeNode));
    newNode->data = data;
    newNode->llink = nullptr;
    newNode->rlink = nullptr;
    // 공백덱일 경우 front와 rear 둘 다 새로운 노드를 가리킴
    if(!(DQ->front)) {
        DQ->front = newNode;
        DQ->rear = newNode;
    // 공백덱이 아닐경우 연결
    } else {
        DQ->front->llink = newNode;
        newNode->rlink = DQ->front;
        DQ->front = newNode;
    }
}

// 덱의 rear 부분으로 삽입
void insertRear(DequeType * DQ, element data) {
    DequeNode * newNode = (DequeNode *)malloc(sizeof(DequeNode));
    newNode->data = data;
    newNode->llink = nullptr;
    newNode->rlink = nullptr;
    // 공백덱일 경우 front와 rear 둘 다 새로운 노드를 가리킴
    if(!(DQ->rear)) {
        DQ->front = newNode;
        DQ->rear = newNode;
    // 공백덱이 아닐경우 연결
    } else {
        DQ->rear->rlink = newNode;
        newNode->llink = DQ->rear;
        DQ->rear = newNode;
    }
}

// 덱의 front 부분 삭제
element deleteFront(DequeType * DQ) {
    // 공백덱이라면 함수 종료
    if(isEmpty(DQ)) {
        return 0;
    }
    // 제거시킬 노드를 가리킬 임시 포인터 변수
    DequeNode * old;
    // 제거시킬 노드의 data를 담을 변수
    element frontData;
    // old가 덱의 front를 참조
    old = DQ->front;
    // frontData 에 삭제하려는 노드의 데이터를 담음
    frontData = old->data;
    // 만약 front의 오른쪽이 nullptr이라면, 다시말해 해당노드를 지우면 공백덱이 될 경우
    if(!(DQ->front->rlink)) {
        DQ->front = nullptr;
        DQ->rear = nullptr;
    // 그렇지 않을 경우 front 를 오른쪽의 노드로 이동
    } else {
        DQ->front = DQ->front->rlink;
        DQ->front->llink = nullptr;
    }
    // 이후 삭제
    free(old);
    return frontData;
}

// 덱의 rear 부분 삭제
element deleteRear(DequeType * DQ) {
    if(isEmpty(DQ)) {
        return 0;
    }
    // 제거시킬 노드를 가리킬 임시 포인터 변수
    DequeNode * old;
    // 제거시킬 노드의 data를 담을 변수
    element rearData;
    // old 가 덱의 rear 를 참조
    old = DQ->rear;
    // rearData 에 삭제하려는 노드의 데이터를 담음
    rearData = old->data;
    // 만약 rear의 왼쪽이 nullptr 이라면, 다시말해 해당노드를 지우면 공백덱이 될 경우
    if(!(DQ->rear->llink)) {
        DQ->front = nullptr;
        DQ->rear = nullptr;
    // 그렇지 않을 경우 rear 를 왼쪽의 노드로 이동
    } else {
        DQ->rear = DQ->rear->llink;
        DQ->rear->rlink = nullptr;
    }
    // 이후 삭제
    free(old);
    return rearData;
}

// 덱의 front 를 삭제후 성공여부를 반환 나머지는 deleteFront와 유사
int removeFront(DequeType * DQ) {
    // 데크가 비어있다면 종료
    if(isEmpty(DQ)) {
        return 0;
    }
    // 삭제할 노드를 저장할 old 포인터
    DequeNode * old;
    // 데크의 프론트를 old 포인터가 가르키게 함
    old = DQ->front;
    // 데크의 front의 오른쪽 노드가 nullptr
    // 즉, 노드가 하나라면 전부 nullptr 로 만들어줌
    if(!(DQ->front->rlink)) {
        DQ->front = nullptr;
        DQ->rear = nullptr;
    // 그렇지 않은 경우라면 front 는 다시 front 의 오른쪽 노드를 가리키게 하고
    // 이동한 front 의 왼쪽 링크는 nullptr 로 초기화
    } else {
        DQ->front = DQ->front->rlink;
        DQ->front->llink = nullptr;
    }
    // 메모리 해제
    free(old);
    return 1;
}

// 덱의 front 를 삭제후 성공여부를 반환 나머지는 deleteRear와 유사
int removeRear(DequeType * DQ) {
    if(isEmpty(DQ)) {
        return 0;
    }
    DequeNode * old;
    old = DQ->rear;
    if(!(DQ->rear->llink)) {
        DQ->front = nullptr;
        DQ->rear = nullptr;
    } else {
        DQ->rear = DQ->rear->llink;
        DQ->rear->rlink = nullptr;
    }
    free(old);
    return 1;
}

// 덱의 front 가 참조하는 노드의 데이터 반환
element peekFront(DequeType * DQ) {
    if(isEmpty(DQ)) {
        return 0;
    }
    return DQ->front->data;
}

// 덱의 rear 가 참조하는 노드의 데이터 반환
element peekRear(DequeType * DQ) {
    if(isEmpty(DQ)) {
        return 0;
    }
    return DQ->rear->data;
}

// 덱 내부의 데이터 전부 출력, front 에서 rear 방향으로 출력
void printDeque(DequeType * DQ) {
    printf("Deque [ ");
    // 순회를 위한 포인터변수 target
    DequeNode * target;
    // target 을 front에 위치시킴
    target = DQ->front;
    // target이 NULL 일때까지 반복
    while(target) {
        printf("%d ", target->data);
        target = target->rlink;
    }
    printf("]\n");
}

int main(void) {
    DequeType * DQ = createDeque();
    element data;

    while(true) {
      // removeMenu : 삽입할껀지 삭제할껀지 결정
      // frontMenu : front 아니면 rear 에 연산을 할껀지 결고
      int removeMenu;
      int frontMenu;
      std::cout << "1. 삽입   2. 삭제   3. 종료 --->";
      std::cin >> removeMenu;
      switch(removeMenu) {
        case 1: // 삽입
          std::cout << "\n1. Front   2. Rear   --->";
          std::cin >> frontMenu;
          std::cout << "\n추가할 데이터 입력 (정수) --->";
          std::cin >> data;
          std::cout << std::endl;
          frontMenu == 1
            ? insertFront(DQ, data)
            : insertRear(DQ, data);
          break;
        case 2: // 삭제
          std::cout << "\n1. Front   2. Rear   --->";
          std::cin >> frontMenu;
          frontMenu == 1
            ? deleteFront(DQ)
            : deleteRear(DQ);
          break;
        case 3:
          std::cout << "결과" << std::endl;
          printDeque(DQ);
          return 0;
      }
      printDeque(DQ);
    }
}
