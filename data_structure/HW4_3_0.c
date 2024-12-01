#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>
#define TRUE 1
#define FALSE 0
#define MAX_STRING 100

typedef struct {
    int id;
    char name[MAX_STRING];
    char tel[MAX_STRING];
    char dept[MAX_STRING];
} element;

typedef struct TreeNode {
    element data;
    struct TreeNode* left, * right;
} TreeNode;

// 순환적인 탐색 함수
TreeNode* search(TreeNode* node, int key)
{
    TreeNode* t = node;

    if (t == NULL)
        return NULL;
    while (t) {
        if (key == t->data.id)
            return t;
        else if (key < t->data.id)
            return search(t->left, key);
        else
            return search(t->right, key);
    }
    return 0;
}

TreeNode* newNode(element item)
{
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->data = item;
    node->left = node->right = NULL;
    return node;
}

TreeNode* insert_node(TreeNode* node, element data)
{
    TreeNode* p, * t;
    TreeNode* n;

    t = node;
    p = NULL;
    // 탐색을 먼저 수행 
    while (t != NULL) {
        if (data.id == t->data.id) return node;
        p = t;
        if (data.id < t->data.id) t = t->left;
        else t = t->right;
    }
    // key가 트리 안에 없으므로 삽입 가능
    n = (TreeNode*)malloc(sizeof(TreeNode));
    if (n == NULL) return node;
    // 데이터 복사
    n->data.id = data.id;
    n->left = n->right = NULL;
    // 부모 노드와 링크 연결
    if (p != NULL)
        if (data.id < p->data.id)
            p->left = n;
        else p->right = n;
    else node = n;
    return node;
}
TreeNode* min_value_node(TreeNode* node)
{
    TreeNode* current = node;

    while (current->left != NULL)
        current = current->left;

    return current;
}

TreeNode* delete_node(TreeNode* root, int key)
{
    TreeNode* p, * child, * succ, * succ_p, * t;

    // key를 갖는 노드 t를 탐색, p는 t의 부모노드
    p = NULL;
    t = root;
    // key를 갖는 노드 t를 탐색한다.
    while (t != NULL && t->data.id != key) {
        p = t;
        t = (key < t->data.id) ? t->left : t->right;
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
        t->data.id = succ->data.id;
        // 원래의 후속자 삭제
        t = succ;
    }
    free(t);
    return root;
}

//한 학생 정보 출력
void print_data(element* e)
{
    printf("-----------------------------------\n");
    printf("학번: %d\n", e->id);
    printf("이름: %s\n", e->name);
    printf("전화번호: %s\n", e->tel);
    printf("학과: %s\n", e->dept);
}

// 중위 순회
void inorder(TreeNode* root)
{
    if (root) {
        inorder(root->left);
        print_data(&root->data);
        inorder(root->right);
    }
}

int get_node_count(TreeNode* node)
{
    if (node == NULL)
        return 0;
    return 1 + get_node_count(node->left) + get_node_count(node->right);
}

int main(void)
{
    TreeNode* root = NULL;
    TreeNode* node;
    element data;

    char choice;
    int id;
    char name[MAX_STRING];
    char tel[MAX_STRING];
    char dept[MAX_STRING];

    printf("Enter i(nsert), d(elete), s(earch), p(rint), c(ount), q(uit):");
    scanf("%c", &choice);
    while (choice != 'q') {
        switch (choice) {
        case 'i':
            printf("학번 입력:");
            scanf("%d", &id);
            getchar();
            printf("이름 입력:");
            scanf("%s", name);;
            printf("전화번호 입력:");
            scanf("%s", tel);;
            printf("학과 입력:");
            scanf("%s", dept);;

            data.id = id;
            strcpy(data.name, name);
            strcpy(data.tel, tel);
            strcpy(data.dept, dept);

            root = insert_node(root, data);
            break;
        case 'p':
            printf("학생 정보 학번 순 출력\n");
            inorder(root);
            printf("\n");
            break;
        case 'd':
            printf("삭제할 학번 입력:");
            scanf("%d", &id);
            root = delete_node(root, id);
            break;
        case 's':
            printf("탐색할 학번 입력:");
            scanf("%d", &id);

            node = search(root, id);
            if (node != NULL)
                print_data(&(node->data));
            else
                printf("id가 %d인 학생은 없습니다.\n", id);
            break;

        case 'c':
            printf("현재 저장된 학생의 총 수는 %d\n", get_node_count(root));
            break;
        }

        while (getchar() != '\n');

        printf("Enter i(nsert), d(elete), s(earch), p(rint), c(ount), q(uit):");
        scanf("%c", &choice);
    }
    return 0;
}