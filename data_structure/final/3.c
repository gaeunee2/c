#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

typedef int element;
typedef struct TreeNode {
	element data;
	struct TreeNode* left, * right;
} TreeNode;
// key�� ���� Ž�� Ʈ�� root�� �����Ѵ�. 
// key�� �̹� root�ȿ� ������ ���Ե��� �ʴ´�.

TreeNode* insert_node(TreeNode* root, element key) // �������� ����
{
	TreeNode* p, * t; // p�� �θ���, t�� ������ 
	TreeNode* n;	    // n�� ���ο� ���

	t = root;
	p = NULL;

	// Ž���� ���� ����, �ݺ��� �̿��ؼ� search(���� search�Լ� ����)
	while (t != NULL) { // �����尡 NULL�� �ɶ�����
		//if( key == t->key ) return root; // (A)-1: ���� ��� �Լ��� ������ �κ��� �ּ�ó����
		p = t; // �����带 �θ���� �ϰ�
		// �����带 ����
		if (key <= t->data) // (A)-2: ���� ��� �������� �̵�
			t = t->left;
		else
			t = t->right;
	}
	// key�� Ʈ�� �ȿ� �����Ƿ� ���� ����
	n = (TreeNode*)malloc(sizeof(TreeNode));
	if (n == NULL) exit(1);
	// ������ ����
	n->data = key;
	n->left = n->right = NULL;

	// �θ� ���� ��ũ ����
	if (p != NULL)
		if (key <= p->data)
			p->left = n;
		else
			p->right = n;
	else // ���ʿ� Ʈ���� ����־�����
		root = n;

	return root;
}

void inorder(TreeNode* root) { // �������� ����
	if (root) {
		inorder(root->left);	// ���ʼ���Ʈ�� ��ȸ
		printf("%d ", root->data); 	// ��� �湮
		inorder(root->right);	// �����ʼ���Ʈ�� ��ȸ
	}
}
// ���� ��ȸ
void preorder(TreeNode* root) { // �������� ����
	if (root) {
		printf("%d ", root->data); 	// ��� �湮
		preorder(root->left);	// ���ʼ���Ʈ�� ��ȸ
		preorder(root->right);	// �����ʼ���Ʈ�� ��ȸ
	}
}
void printCheck(TreeNode* node) // �������� ����
{
	preorder(node); printf("\n");
	inorder(node); printf("\n");
}

void doubleKeyValue(TreeNode* root, int key) // �� �Լ��� �ۼ�
{
	if (root == NULL)
		return;

	if (root->data == key)
		root->data *= 2;
	doubleKeyValue(root->left, key);
	doubleKeyValue(root->right, key);
}

int main(void) // �������� ����
{
	int n;
	int key;

	TreeNode* root = NULL;

	// (B) �Էºκ�
	scanf("%d", &n);
	while (n != -1) {
		root = insert_node(root, n);
		scanf("%d", &n);
	}

	scanf("%d", &key);
	doubleKeyValue(root, key); // Ʈ��-1)
	printCheck(root); // Ʈ��-1)
}