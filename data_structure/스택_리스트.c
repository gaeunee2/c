#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef int element;
typedef struct StackNode
{
	element item;
	struct StackNode* link;
} StackNode;

typedef struct
{
	StackNode* top;
} LinkedStackType;

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

void push(LinkedStackType* s, element item)
{
	StackNode* temp = (StackNode*)malloc(sizeof(StackNode));
	if (temp == NULL) {
		fprintf(stderr, "메모리 할당에러\n");
		return;
	}
	else {
		temp->item = item;
		temp->link = s->top;
		s->top = temp;
	}
}

element pop(LinkedStackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "스택이 비어있음\n");
		exit(1);
	}
	else {
		StackNode* removed = s->top;
		element rslt = removed->item;
		s->top = removed->link;
		free(removed);
		return rslt;
	}
}

element peek(LinkedStackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "스택이 비어있음\n");
		exit(1);
	}
	else
		return s->top->item;
}

void print_stack(LinkedStackType* s)
{
	for (StackNode* p = s->top; p; p = p->link)
		printf("%d ", p->item);
}

int main(void)
{
	LinkedStackType s;

	init(&s);

	push(&s, 1);
	push(&s, 2);
	push(&s, 3);

	printf("%d\n", pop(&s));
	printf("%d\n", pop(&s));
	printf("%d\n", pop(&s));
	printf("%d\n", is_empty(&s));
}