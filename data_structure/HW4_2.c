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

// key�� ���� Ž�� Ʈ�� root�� �����Ѵ�. 
// key�� �̹� root�ȿ� ������ ���Ե��� �ʴ´�.
TreeNode* insert_node(TreeNode* root, int key)
{
    TreeNode* p, * t; // p�� �θ���, t�� ������ 
    TreeNode* n;	    // n�� ���ο� ���

    t = root;
    p = NULL;
    // Ž���� ���� ���� 
    while (t != NULL) {
        if (key == t->key) return root;
        p = t;
        if (key < t->key) t = t->left;
        else t = t->right;
    }
    // key�� Ʈ�� �ȿ� �����Ƿ� ���� ����
    n = (TreeNode*)malloc(sizeof(TreeNode));
    if (n == NULL) return root;
    // ������ ����
    n->key = key;
    n->left = n->right = NULL;
    // �θ� ���� ��ũ ����
    if (p != NULL)
        if (key < p->key)
            p->left = n;
        else p->right = n;
    else root = n;
    return root;
}

// ���� �Լ�
TreeNode* delete_node(TreeNode* root, int key)
{
    TreeNode* p, * child, * succ, * succ_p, * t;

    // key�� ���� ��� t�� Ž��, p�� t�� �θ���
    p = NULL;
    t = root;
    // key�� ���� ��� t�� Ž���Ѵ�.
    while (t != NULL && t->key != key) {
        p = t;
        t = (key < t->key) ? t->left : t->right;
    }
    // Ž���� ����� ������ t�� NULL�̸� Ʈ���ȿ� key�� ����
    if (t == NULL) { 	// Ž��Ʈ���� ���� Ű
        printf("key is not in the tree");
        return root;
    }
    // ù��° ���: �ܸ������ ���
    if ((t->left == NULL) && (t->right == NULL)) {
        if (p != NULL) {
            // �θ����� �ڽ��ʵ带 NULL�� �����.
            if (p->left == t)
                p->left = NULL;
            else   p->right = NULL;
        }
        else	// ���� �θ��尡 NULL�̸� �����Ǵ� ��尡 ��Ʈ
            root = NULL;
    }
    // �ι�° ���: �ϳ��� �ڽĸ� ������ ���
    else if ((t->left == NULL) || (t->right == NULL)) {
        child = (t->left != NULL) ? t->left : t->right;
        if (p != NULL) {
            if (p->left == t)	// �θ� �ڽİ� ���� 
                p->left = child;
            else p->right = child;
        }
        else   // ���� �θ��尡 NULL�̸� �����Ǵ� ��尡 ��Ʈ
            root = child;
    }
    // ����° ���: �ΰ��� �ڽ��� ������ ���
    else {
        // ������ ����Ʈ������ �İ��ڸ� ã�´�.
        succ_p = t;
        succ = t->right;
        // �İ��ڸ� ã�Ƽ� ��� �������� �̵��Ѵ�.
        while (succ->left != NULL) {
            succ_p = succ;
            succ = succ->left;
        }
        // �ļ����� �θ�� �ڽ��� ���� 
        if (succ_p->left == succ)
            succ_p->left = succ->right;
        else
            succ_p->right = succ->right;
        // �ļ��ڰ� ���� Ű���� ���� ��忡 ����
        t->key = succ->key;
        // ������ �ļ��� ����
        t = succ;
    }
    free(t);
    return root;
}
//��ȸ
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

// ���� ���ϱ�
int get_height(TreeNode* node)
{
    if (node == NULL)
        return 0;

    int left_height = get_height(node->left);
    int right_height = get_height(node->right);
    return (left_height > right_height ? left_height : right_height) + 1;
}

//����� ����
int get_node_count(TreeNode* node)
{
    if (node == NULL)
        return 0;
    return 1 + get_node_count(node->left) + get_node_count(node->right);
}

// �ִ밪
int get_maximum(TreeNode* node)
{
    TreeNode* t = node;
    
    while (t->right != NULL)
        t = node->right;
    return t->key;
}
// �ּҰ�
int get_minimum(TreeNode* node)
{
    TreeNode* t = node;

    while (t->left != NULL)
        t = node->left;
    return t->key;
}
// ���� ���
void preorder(TreeNode* root) // p271 �ڵ� ����
{
    if (root) {
        printf("%d ", root->key);
        preorder(root->left);
        preorder(root->right);
    }
}

// ��ü ��� ����
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
            printf("������ key�� �Է�:");
            scanf("%d", &key);
            root = insert_node(root, key);
            break;
        case 'p':
            preorder(root);
            printf("\n");
            break;
        case 'd':
            printf("������ key�� �Է�:");
            scanf("%d", &key);
            root = delete_node(root, key);
            break;
        case 's':
            printf("Ž���� key�� �Է�:");
            scanf("%d", &key);

            if (search(root, key) == NULL)
                printf("����\n");
            else
                printf("����\n");
            break;
        case 'h':
            printf("Ʈ���� ���̴� %d\n", get_height(root));
            break;
        case 'c':
            printf("����� ������ %d\n", get_node_count(root));
            break;
        case 'm':
            printf("���� ū ���� %d\n", get_maximum(root));
            break;
        case 'n':
            printf("���� ���� ���� %d\n", get_minimum(root));
            break;
        }
        fflush(stdin);
        printf("Enter i(nsert),d(elete),s(earch),p(rint),h(eight),c(ount),m(ax),n(min),q(uit):");
        scanf(" %c", &choice);
    }
    return 0;
}