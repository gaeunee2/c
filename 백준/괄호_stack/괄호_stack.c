#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 51

typedef struct StackType {
	char data[MAX_STACK_SIZE];
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

void push(StackType* s, char item)
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

int peek(StackType* s)
{
	if (is_empty(s))
		return -1;
	else
		return s->data[s->top];
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
	int i, j, t;
	char str[51];

	scanf("%d", &t);

	for (i = 0; i < t; i++) {
		scanf("%s", str);
		init(&s);

		for (j = 0; str[j] != '\0'; j++) {
			if (str[j] == '(')
				push(&s, '(');
			else {
			else {
			if (peek(&s) == -1 || peek(&s) == ')') {
				printf("NO\n");
				break;
			}
			else
				pop(&s);
			}
			}
			if (str[j] == '\0' && is_empty(&s))
				printf("YES\n");
			else if (str[j] == '\0')
				printf("NO\n");
		}

		return 0;
	}