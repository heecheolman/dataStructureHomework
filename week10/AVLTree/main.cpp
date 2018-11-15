#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#define MAX(a, b) (a > b ? a : b)

// int 타입 element
typedef int element;

// 트리노드의 구조체
typedef struct TreeNode {
    element data; // 노드의 data 필드타입
    struct TreeNode * left; // 왼쪽 자식노드에대한 링크
    struct TreeNode * right; // 오른쪽 자식노드에대한 링크
} TreeNode;

// 균형이 무너진 상태로 우회전 한번
TreeNode* LLrotate(TreeNode *parent) {
  TreeNode *child = parent->left;
  parent->left = child->right;
  child->right = parent;
  return child;
}

// 균형이 무너진 상태로 좌회전 한번
TreeNode* RRrotate(TreeNode *parent) {
  TreeNode *child = parent->right;
  parent->right = child->left;
  child->left = parent;
  return child;
}

// 우회전한번 -> 좌회전 한번
TreeNode* LRrotate(TreeNode *parent) {
  TreeNode *child = parent->left;
  parent->left = RRrotate(child);
  return LLrotate(parent);
}

// 좌회전 한번 -> 우회전한번
TreeNode* RLrotate(TreeNode *parent) {
  TreeNode *child = parent->right;
  parent->right = LLrotate(child);
  return RRrotate(parent);
}

// 서브트리의 높이를 구하는 연산
// recursive 로 구하는 방식
int getHeight(TreeNode *forest) {
  int height = 0;
  if(forest) {
    height = MAX(getHeight(forest->left), getHeight(forest->right)) + 1;
  }
  return height;
}

// 서브트리의 높이를 이용해 균형 인수 BF 를 구하는 연산
// recursive
int getBF(TreeNode *forest) {
  if(!forest) {
    return 0;
  }
  return getHeight(forest->left) - getHeight(forest->right);
}

// BF 를 검사하여 불균형이 발생한경우, 회전 연산 호출
TreeNode* reBalance(TreeNode** forest) {
  int BF = getBF(*forest);
  if(BF > 1) {
    if(getBF((*forest)->left) > 0) {
      *forest = LLrotate(*forest);
    } else {
      *forest = LRrotate(*forest);
    }
  } else if (BF < -1) {
    if(getBF((*forest)->right) < 0) {
      *forest = RRrotate(*forest);
    } else {
      *forest = RLrotate(*forest);
    }
  }
  return *forest;
}

// AVL 트리에 노드를 삽입하는 연산 : 이진 탐색 연산처럼 삽입한 후에, reBalance() 호출
TreeNode* insertAVLNode(TreeNode **root, element data) {
  // NULL 일경우 노드를 새로 동적할당
  if(!(*root)) {
    *root = (TreeNode*)malloc(sizeof(TreeNode));
    (*root)->data = data;
    (*root)->left = NULL;
    (*root)->right = NULL;
  // 들어온 데이터가 root의 데이터보다 작으면 왼쪽에 넣어줌
  // 넣어준 후 재배치
  } else if(data < (*root)->data) {
    (*root)->left = insertAVLNode(&((*root)->left), data);
    *root = reBalance(root);
  // 들어온 데이터가 root의 데이터보다 크면 오른쪽에 넣어줌
  // 넣어준 후 재배치
  } else if(data > (*root)->data) {
    (*root)->right = insertAVLNode(&((*root)->right), data);
    *root = reBalance(root);
  // 모든경우가 아니라면 같은 데이터가 있는 경우임
  } else {
    printf("\n 이미 같은 데이터가 있습니다!\n");
    exit(1);
  }
  return *root;
}

// 일반적인 BinarySearchTree 구현
TreeNode* insertBSTNode(TreeNode *forest, element data) {
  TreeNode *newNode;
  if(!forest) {
    newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
  } else if(data < forest->data) {
    forest->left = insertBSTNode(forest->left, data);
  } else if(data > forest->data) {
    forest->right = insertBSTNode(forest->right, data);
  } else {
    printf("\n 이미 같은 데이터가 있습니다!\n");
  }
  return forest;
}

//이진 탐색트리와 AVL트리에서 데이터값 data를 탐색하는 연산
TreeNode* searchTree(TreeNode* root, element data) {
  TreeNode *forest;
  int count = 0;
  forest = root;
  // forest 가 데이터를 찾을때까지 반복
  while(forest) {
    count++;
    if(data < forest->data) {
      forest = forest->left;
    } else if(data == forest->data) {
      printf("%3d번째에 탐색 성공", count);
      return forest;
    } else {
      forest = forest->right;
    }
  }
  // 여기를 온 경우면 탐색을 실패한 경우임
  count++;
  printf("%3d번째에 탐색 실패! 찾는 데이터가 없습니다", count);
  return forest;
}

// 중위순회 : recursive
// 왼쪽 ->방문 -> 오른쪽
void displayInorder(TreeNode *root) {
  if(root) {
    displayInorder(root->left);
    printf("_%d ", root->data);
    displayInorder(root->right);
  }
}

int main() {
  TreeNode* rootAVL = NULL;
  TreeNode* rootBST = NULL;

  // AVL 트리 만들기
  rootAVL = insertAVLNode(&rootAVL, 50);
  insertAVLNode(&rootAVL, 60);
  insertAVLNode(&rootAVL, 70);
  insertAVLNode(&rootAVL, 90);
  insertAVLNode(&rootAVL, 80);
  insertAVLNode(&rootAVL, 75);
  insertAVLNode(&rootAVL, 73);
  insertAVLNode(&rootAVL, 72);
  insertAVLNode(&rootAVL, 78);

  printf("\n ******** AVL 트리 출력 ********* \n\n");
  displayInorder(rootAVL);

  printf("\n\n AVL 트리에서 70탐색 \n\n");
  searchTree(rootAVL, 70);

  printf("\n\n AVL 트리에서 72탐색 \n\n");
  searchTree(rootAVL, 72);

  printf("\n\n AVL 트리에서 76탐색 \n\n");
  searchTree(rootAVL, 76);

  // 일반적인 이진탐색트리 만들기
  rootBST = insertBSTNode(rootBST, 50);
  insertBSTNode(rootBST, 60);
  insertBSTNode(rootBST, 70);
  insertBSTNode(rootBST, 90);
  insertBSTNode(rootBST, 80);
  insertBSTNode(rootBST, 75);
  insertBSTNode(rootBST, 73);
  insertBSTNode(rootBST, 72);
  insertBSTNode(rootBST, 78);

  printf("\n ******** BST 출력 ********* \n\n");
  displayInorder(rootAVL);

  printf("\n\n BST에서 70탐색 : ");
  searchTree(rootBST, 70);

  printf("\n\n BST에서 72탐색 : ");
  searchTree(rootBST, 72);

  printf("\n\n BST에서 76탐색 : ");
  searchTree(rootBST, 76);

  getchar();
}
