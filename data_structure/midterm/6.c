#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

typedef struct TreeNode {
	int key;
	struct TreeNode* left, * right;
} TreeNode;

TreeNode* insert_node(TreeNode* root, int key)  // �������� ����. ���� ����� �ʾ����� � ��Ģ���� Ʈ���� ��带 �����Ѵ�.
{
	TreeNode* p, * t; // p�� �θ���, t�� ������ 
	TreeNode* n;	    // n�� ���ο� ���

	t = root;
	p = NULL;

	// Ž���� ���� ����, �ݺ��� �̿��ؼ� search(���� search�Լ� ����)
	while (t != NULL) { // �����尡 NULL�� �ɶ�����
		 //if( key == t->key ) return;
		p = t; // �����带 �θ���� �ϰ�
			// �����带 ����
		if (key < t->key)
			t = t->left;
		else
			t = t->right;
	}
	// key�� Ʈ�� �ȿ� �����Ƿ� ���� ����
	n = (TreeNode*)malloc(sizeof(TreeNode));
	//if (n == NULL) return;
	// ������ ����
	n->key = key;
	n->left = n->right = NULL;

	// �θ� ���� ��ũ ����
	if (p != NULL)
		if (key < p->key)
			p->left = n;
		else
			p->right = n;
	else // ���ʿ� Ʈ���� ����־�����
		root = n;
	return root;
}

int count_even_non_leaf(TreeNode* node) // �� �Լ��� *���������* �ۼ�
{
	if (node == NULL)
		return 0;
	else if ((node->right == NULL) && (node->left == NULL))
		return 0;
	else if (node->key % 2 == 0)
		return 1 + count_even_non_leaf(node->left) + count_even_non_leaf(node->right);
	else
		return count_even_non_leaf(node->left) + count_even_non_leaf(node->right);
}

int main(void) // main�� �������� ����. 
{
	int n;

	TreeNode* root;

	// �Ʒ��� 7���� Ʈ���� ����� �κ����� �����ð��� �ٷ��� �ʾ����Ƿ� �Ű澲�� �ʾƵ� �ȴ�.
	root = NULL;
	// A)
	scanf("%d", &n);
	while (n != -1) {
		root = insert_node(root, n);
		scanf("%d", &n);
	}

	printf("%d\n", count_even_non_leaf(root));
}