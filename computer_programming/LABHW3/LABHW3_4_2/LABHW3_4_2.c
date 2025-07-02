#define _CRT_SECURE_NO_WARNINGS
#define SIZE 5
#include <stdio.h>
int hasElement(int s[], int size, int num)
{
	for (int i = 0; i < size; i++)
		if (s[i] == num)
			return 1;
	return 0;
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

int main(void)
{
	int i, j, element[SIZE];

	for (i = 0; i < SIZE; i++) {
		printf("집합에 추가할 원소: ");
		scanf("%d", &element[i]);
		
		if (hasElement(element, i, element[i])) {
			printf("%d는 이미 집합에 있음\n", element[i]);
			i--;
		}

		printSet(element, i + 1);
		printf("\n");
	}
}