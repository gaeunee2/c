#define _CRT_SECURE_NO_WARNINGS
#define SIZE 5
#include <stdio.h>
void printSet(int s[], int size);

int main(void)
{
	int i, element[SIZE];

	for (i = 0; i < SIZE; i++) {
		printf("다중집합에 추가할 원소: ");
		scanf("%d", &element[i]);
		printSet(element, i + 1);
		printf("\n");
	}
}

void printSet(int s[], int size)
{
	int i;
	if (size <= 1)
		for (i = 0; i < size; i++)
			printf("{ %d }", s[i]);
	else {
		printf("{ ");
		for (i = 0; i < size - 1; i++)
			printf("%d, ", s[i]);
		printf("%d", s[size - 1]);
		printf(" }");
	}
}