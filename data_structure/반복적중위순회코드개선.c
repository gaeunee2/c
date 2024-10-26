#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
}TreeNode;

typedef TreeNode* element;

typedef struct StackNode {
	element data;
	struct StackNode* link;
}StackNode;

typedef struct {
	StackNode * top;
}LinkedStackType;

void init(LinkedStackType* s)
{
	s->top = NULL;
}

int is_empty(LinkedStackType* s)
{
	return s->top == NULL;
}

int is_full(LinkedStackType* s)
{
	return 0;
}

void push(LinkedStackType *s, element item)
{
	StackNode* temp = (StackNode*)malloc(sizeof(StackNode));

	if (temp == NULL) {
		fprintf(stderr, "메모리 할당에러\n");
		return;
	}
	else {
		temp->data = item;
		temp->link = s->top;
		s->top = temp;
	}
}

element pop(LinkedStackType* s)
{
	if (is_empty(s))
		return NULL;
	else {
		StackNode* remove = s->top;
		element rslt = remove->data;
		s->top = remove->link;
		free(remove);
		return rslt;
	}
}

element peek(LinkedStackType* s)
{
	if (is_empty(s))
		return NULL;
	else
		return s->top->data;
}

void inorder_iter(TreeNode* root)
{
	LinkedStackType s;
	init(&s);

	while (1) {
		//Left 모두 push
		for (; root != NULL; root = root->left)
			push(&s, root);

		if (is_empty(&s)) 
			break;
		else {
			root = pop(&s); //젤 왼쪽 아래거 루트에
			printf("[%d] ", root->data);
			root = root->right;
		}
	}
}

int main(void)
{
	TreeNode n1 = { 1, NULL, NULL };
	TreeNode n2 = { 4, &n1, NULL };
	TreeNode n3 = { 16, NULL, NULL };
	TreeNode n4 = { 25, NULL, NULL };
	TreeNode n5 = { 20, &n3, &n4 };
	TreeNode n6 = { 15, &n2, &n5 };
	TreeNode* root = &n6;

	printf("중위 순회=");
	inorder_iter(root);
	printf("\n");

	return 0;
}