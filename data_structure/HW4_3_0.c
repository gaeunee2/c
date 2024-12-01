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

// ��ȯ���� Ž�� �Լ�
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
    // Ž���� ���� ���� 
    while (t != NULL) {
        if (data.id == t->data.id) return node;
        p = t;
        if (data.id < t->data.id) t = t->left;
        else t = t->right;
    }
    // key�� Ʈ�� �ȿ� �����Ƿ� ���� ����
    n = (TreeNode*)malloc(sizeof(TreeNode));
    if (n == NULL) return node;
    // ������ ����
    n->data.id = data.id;
    n->left = n->right = NULL;
    // �θ� ���� ��ũ ����
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

    // key�� ���� ��� t�� Ž��, p�� t�� �θ���
    p = NULL;
    t = root;
    // key�� ���� ��� t�� Ž���Ѵ�.
    while (t != NULL && t->data.id != key) {
        p = t;
        t = (key < t->data.id) ? t->left : t->right;
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
        t->data.id = succ->data.id;
        // ������ �ļ��� ����
        t = succ;
    }
    free(t);
    return root;
}

//�� �л� ���� ���
void print_data(element* e)
{
    printf("-----------------------------------\n");
    printf("�й�: %d\n", e->id);
    printf("�̸�: %s\n", e->name);
    printf("��ȭ��ȣ: %s\n", e->tel);
    printf("�а�: %s\n", e->dept);
}

// ���� ��ȸ
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
            printf("�й� �Է�:");
            scanf("%d", &id);
            getchar();
            printf("�̸� �Է�:");
            scanf("%s", name);;
            printf("��ȭ��ȣ �Է�:");
            scanf("%s", tel);;
            printf("�а� �Է�:");
            scanf("%s", dept);;

            data.id = id;
            strcpy(data.name, name);
            strcpy(data.tel, tel);
            strcpy(data.dept, dept);

            root = insert_node(root, data);
            break;
        case 'p':
            printf("�л� ���� �й� �� ���\n");
            inorder(root);
            printf("\n");
            break;
        case 'd':
            printf("������ �й� �Է�:");
            scanf("%d", &id);
            root = delete_node(root, id);
            break;
        case 's':
            printf("Ž���� �й� �Է�:");
            scanf("%d", &id);

            node = search(root, id);
            if (node != NULL)
                print_data(&(node->data));
            else
                printf("id�� %d�� �л��� �����ϴ�.\n", id);
            break;

        case 'c':
            printf("���� ����� �л��� �� ���� %d\n", get_node_count(root));
            break;
        }

        while (getchar() != '\n');

        printf("Enter i(nsert), d(elete), s(earch), p(rint), c(ount), q(uit):");
        scanf("%c", &choice);
    }
    return 0;
}