#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define MAX_STACK_SIZE 3

typedef struct {
	int num;
	char eng[10];
}element;

typedef struct StackType {
	element data[MAX_STACK_SIZE];
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

int is_full(StackType* s)
{
	return s->top == MAX_STACK_SIZE - 1;
}

void push(StackType* s, element item)
{
	if (is_full(s)) {
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	else
		s->data[++(s->top)] = item;
}

element pop(StackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else
		return s->data[s->top--];
}

element peek(StackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else
		return s->data[s->top];
}

void stack_print(StackType* s)
{
	int i;

	if (is_empty(s))
		printf("<empty>\n");
	else {
		printf("[%d, %s] <- top\n", peek(s).num, peek(s).eng);
		for (i = s->top - 1; i != -1; i--)
			printf("[%d, %s]\n", s->data[i].num, s->data[i].eng);
	}
	printf("--\n");
}

void push_loc(StackType* s, int num, const char* eng)
{
	element tmp;
	tmp.num = num;
	strcpy(tmp.eng, eng);
	push(s, tmp);
}

int main(void)
{
	StackType s;

	init(&s);
	stack_print(&s);
	push_loc(&s, 10, "ten");
	stack_print(&s);
	push_loc(&s, 20, "twenty");
	stack_print(&s);
	push_loc(&s, 30, "thirty");
	stack_print(&s);
	push_loc(&s, 40, "forty");
	stack_print(&s);
	pop(&s);
	stack_print(&s);
	push_loc(&s, 50, "fifty");
	stack_print(&s);
	pop(&s);
	stack_print(&s);
	pop(&s);
	stack_print(&s);
	pop(&s);
	stack_print(&s);

	return 0;
}