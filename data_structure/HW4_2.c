#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#define TRUE 1
#define FALSE 0

typedef struct TreeNode {
    int key;
    struct TreeNode* left, * right;
} TreeNode;

// key를 이진 탐색 트리 root에 삽입한다. 
// key가 이미 root안에 있으면 삽입되지 않는다.
TreeNode* insert_node(TreeNode* root, int key)
{
    TreeNode* p, * t; // p는 부모노드, t는 현재노드 
    TreeNode* n;	    // n은 새로운 노드

    t = root;
    p = NULL;
    // 탐색을 먼저 수행 
    while (t != NULL) {
        if (key == t->key) return root;
        p = t;
        if (key < t->key) t = t->left;
        else t = t->right;
    }
    // key가 트리 안에 없으므로 삽입 가능
    n = (TreeNode*)malloc(sizeof(TreeNode));
    if (n == NULL) return root;
    // 데이터 복사
    n->key = key;
    n->left = n->right = NULL;
    // 부모 노드와 링크 연결
    if (p != NULL)
        if (key < p->key)
            p->left = n;
        else p->right = n;
    else root = n;
    return root;
}

// 삭제 함수
TreeNode* delete_node(TreeNode* root, int key)
{
    TreeNode* p, * child, * succ, * succ_p, * t;

    // key를 갖는 노드 t를 탐색, p는 t의 부모노드
    p = NULL;
    t = root;
    // key를 갖는 노드 t를 탐색한다.
    while (t != NULL && t->key != key) {
        p = t;
        t = (key < t->key) ? t->left : t->right;
    }
    // 탐색이 종료된 시점에 t가 NULL이면 트리안에 key가 없음
    if (t == NULL) { 	// 탐색트리에 없는 키
        printf("key is not in the tree");
        return root;
    }
    // 첫번째 경우: 단말노드인 경우
    if ((t->left == NULL) && (t->right == NULL)) {
        if (p != NULL) {
            // 부모노드의 자식필드를 NULL로 만든다.
            if (p->left == t)
                p->left = NULL;
            else   p->right = NULL;
        }
        else	// 만약 부모노드가 NULL이면 삭제되는 노드가 루트
            root = NULL;
    }
    // 두번째 경우: 하나의 자식만 가지는 경우
    else if ((t->left == NULL) || (t->right == NULL)) {
        child = (t->left != NULL) ? t->left : t->right;
        if (p != NULL) {
            if (p->left == t)	// 부모를 자식과 연결 
                p->left = child;
            else p->right = child;
        }
        else   // 만약 부모노드가 NULL이면 삭제되는 노드가 루트
            root = child;
    }
    // 세번째 경우: 두개의 자식을 가지는 경우
    else {
        // 오른쪽 서브트리에서 후계자를 찾는다.
        succ_p = t;
        succ = t->right;
        // 후계자를 찾아서 계속 왼쪽으로 이동한다.
        while (succ->left != NULL) {
            succ_p = succ;
            succ = succ->left;
        }
        // 후속자의 부모와 자식을 연결 
        if (succ_p->left == succ)
            succ_p->left = succ->right;
        else
            succ_p->right = succ->right;
        // 후속자가 가진 키값을 현재 노드에 복사
        t->key = succ->key;
        // 원래의 후속자 삭제
        t = succ;
    }
    free(t);
    return root;
}
//순회
TreeNode* search(TreeNode* node, int key)
{
    TreeNode* t = node;

    if (t == NULL)
        return NULL;
    while (t) {
        if (key == t->key)
            return t;
        else if (key < t->key)
            return search(t->left, key);
        else
            return search(t->right, key);
    }
    return 0;
}

// 높이 구하기
int get_height(TreeNode* node)
{
    if (node == NULL)
        return 0;

    int left_height = get_height(node->left);
    int right_height = get_height(node->right);
    return (left_height > right_height ? left_height : right_height) + 1;
}

//노드의 개수
int get_node_count(TreeNode* node)
{
    if (node == NULL)
        return 0;
    return 1 + get_node_count(node->left) + get_node_count(node->right);
}

// 최대값
int get_maximum(TreeNode* node)
{
    TreeNode* t = node;
    
    while (t->right != NULL)
        t = node->right;
    return t->key;
}
// 최소값
int get_minimum(TreeNode* node)
{
    TreeNode* t = node;

    while (t->left != NULL)
        t = node->left;
    return t->key;
}
// 전위 출력
void preorder(TreeNode* root) // p271 코드 복사
{
    if (root) {
        printf("%d ", root->key);
        preorder(root->left);
        preorder(root->right);
    }
}

// 전체 노드 삭제
/*void delete_all(TreeNode *root)
{
     if (root != NULL) {
          delete_all(root->left);
          delete_all(root->right);
          free(root);
     }
}*/

int main(void)
{
    TreeNode* root = NULL;
    char choice;
    int key;

    printf("Enter i(nsert),d(elete),s(earch),p(rint),h(eight),c(ount),m(ax),n(min),q(uit):");
    scanf("%c", &choice);
    while (choice != 'q') {
        switch (choice) {
        case 'i':
            printf("삽입할 key값 입력:");
            scanf("%d", &key);
            root = insert_node(root, key);
            break;
        case 'p':
            preorder(root);
            printf("\n");
            break;
        case 'd':
            printf("삭제할 key값 입력:");
            scanf("%d", &key);
            root = delete_node(root, key);
            break;
        case 's':
            printf("탐색할 key값 입력:");
            scanf("%d", &key);

            if (search(root, key) == NULL)
                printf("없음\n");
            else
                printf("있음\n");
            break;
        case 'h':
            printf("트리의 높이는 %d\n", get_height(root));
            break;
        case 'c':
            printf("노드의 개수는 %d\n", get_node_count(root));
            break;
        case 'm':
            printf("가장 큰 값은 %d\n", get_maximum(root));
            break;
        case 'n':
            printf("가장 작은 값은 %d\n", get_minimum(root));
            break;
        }
        fflush(stdin);
        printf("Enter i(nsert),d(elete),s(earch),p(rint),h(eight),c(ount),m(ax),n(min),q(uit):");
        scanf(" %c", &choice);
    }
    return 0;
}