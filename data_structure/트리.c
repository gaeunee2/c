#define _CRT_SECURE_NO_WARNINGS
#define TRUE 1
#define FALSE 0
#define MAX_TREE_SIZE 20
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <limits.h>

typedef int element;
typedef struct TreeNode
{
	element data;
	struct TreeNode* left, * right;
} TreeNode;

int get_nonleaf_count(TreeNode* node)
{
	if (node == NULL)
		return 0;
	else if (node->left == NULL && node->right == NULL)
		return 0;
	else
		return 1 + get_nonleaf_count(node->left) + get_nonleaf_count(node->right);
}

int get_oneleaf_count(TreeNode* node)
{
	if (node == NULL)
		return 0;
	else if (node->left == NULL && node->right == NULL)
		return 0;
	else if (node->left == NULL)
		return 1 + get_oneleaf_count(node->right);
	else if (node->right == NULL)
		return 1 + get_oneleaf_count(node->left);
	else
		return get_oneleaf_count(node->left) + get_oneleaf_count(node->right);
}

int get_twoleaf_count(TreeNode* node)
{
	if (node == NULL)
		return 0;
	else if (node->left == NULL && node->right == NULL)
		return 0;
	else if (node->left == NULL)
		return get_twoleaf_count(node->right);
	else if (node->right == NULL)
		return get_twoleaf_count(node->left);
	else
		return 1 + get_twoleaf_count(node->left) + get_twoleaf_count(node->right);
}

int get_max(TreeNode* node)
{
	if (node == NULL)
		return INT_MIN;
	else
		return max(max(get_max(node->left), get_max(node->right)), node->data);
}

int get_min(TreeNode* node)
{
	if (node == NULL)
		return INT_MAX;
	else
		return min(min(get_min(node->left), get_min(node->right)), node->data);
}

int search(TreeNode* root, int key, TreeNode* result[])
{
	if (root == NULL)
		return 0;

	int count = 0;
	if (root->data == key)
		result[count++] = root;

	count += search(root->left, key, result + count);
	count += search(root->right, key, result + count);

	return count;
}

void node_increase(TreeNode* node)
{
	if (node == NULL)
		return;
	else
	{
		(node->data)++;
		node_increase(node->left);
		node_increase(node->right);
	}
}

int equal(TreeNode* root1, TreeNode* root2)
{
	if (root1 == NULL && root2 == NULL)
		return TRUE;
	else if (root1 == NULL || root2 == NULL)
		return FALSE;
	else
		if (root1->data != root2->data)
			return FALSE;
		else
			return equal(root1->left, root2->left) && equal(root1->right, root2->right);
}

TreeNode* copy(TreeNode* root)
{
	if (root == NULL)
		return NULL;
	else
	{
		TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
		node->data = root->data;
		node->left = copy(root->left);
		node->right = copy(root->right);
		return node;
	}
}

void preorder(TreeNode* node)
{
	if (node == NULL)
		return;
	else
	{
		printf("%d ", node->data);
		preorder(node->left);
		preorder(node->right);
	}
}

int main(void)
{
	TreeNode* root;
	TreeNode* result[MAX_TREE_SIZE] = { NULL };
	int i, num = 0;

	// 트리 구조 생성
	root = (TreeNode*)malloc(sizeof(TreeNode));
	root->data = 15;
	root->left = (TreeNode*)malloc(sizeof(TreeNode));
	root->left->data = 10;
	root->right = (TreeNode*)malloc(sizeof(TreeNode));
	root->right->data = 20;

	// 루트 트리에서 15 찾기
	printf("\n나)\n");
	num = search(root, 15, result);  // root에서 15를 찾음
	for (i = 0; i < num; i++)
		printf("(0x%p, %d) ", result[i], result[i]->data);
	printf("\n");

	return 0;
}