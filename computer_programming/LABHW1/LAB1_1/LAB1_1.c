#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int printLine(int);
int main(void)
{
	int i, num[5], total = 0;

	for (i = 0; i < 5; i++)
	{
		printf("Enter %dth number : ", i + 1);
		scanf("%d", &num[i]);
		
		total += num[i];
	}

	printLine(38);
	printf("ÃÑÇÕÀº %d\n", total);
	printf("Æò±ÕÀº %d\n", total / 5);
	printLine(38);

	for (i = 0; i < 5; i++)
		printf("array[%d] : %d\n", i, num[i]);

	return 0;
}

int printLine(int n)
{
	for (int j = 0; j < n; j++)
		printf("-");
	printf("\n");
}