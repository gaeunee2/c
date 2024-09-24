#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define MAX_STRING 20

typedef char element;

typedef struct StackType {
	element data[MAX_STRING];
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
	return s->top == MAX_STRING - 1;
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

int palindrome(char str[])
{
	StackType s; //연결리스트를 사용하면 LinkedStackType s; 
	int i, len = strlen(str);

	init(&s);
	
	for (i = 0; i < len; i++)
		push(&s, str[i]);

	for (i = 0; is_empty(&s) != 1; i++)
		if (pop(&s) != str[i])
			return 0;
	return 1;
}

int main(void)
{
	char word[MAX_STRING];

	printf("Enter a word to check palindrome: ");
	scanf("%s", word);

	if (palindrome(word))
		printf("palindrome입니다.\n");
	else
		printf("palindrome이 아닙니다.\n");
}