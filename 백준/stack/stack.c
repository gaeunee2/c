#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define MAX_STACK_SIZE 10000

typedef struct StackType {
	int data[MAX_STACK_SIZE];
	int top;
}StackType;

void init(StackType* s)
{
	s->top = -1;
}

int is_empty(StackType* s)
{
	return s->top == -1;
}

void push(StackType* s, int item)
{
	s->data[++(s->top)] = item;
}

int pop(StackType* s)
{
	if (is_empty(s))
		return -1;
	else
		return s->data[s->top--];
}

int size(StackType* s)
{
	return s->top + 1;
}

int top(StackType* s)
{
	if (is_empty(s))
		return -1;
	else
		return s->data[s->top];
}

int main(void)
{
	StackType s;
	int i, n, num;
	char work[6];

	init(&s);
	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		scanf("%s", work);

		if (strcmp(work, "push") == 0) {
			scanf("%d", &num);
			push(&s, num);
		}
		else if (strcmp(work, "pop") == 0)
			printf("%d\n", pop(&s));
		else if (strcmp(work, "size") == 0)
			printf("%d\n", size(&s));
		else if (strcmp(work, "empty") == 0)
			printf("%d\n", is_empty(&s));
		else
			printf("%d\n", top(&s));
	}

	return 0;
}