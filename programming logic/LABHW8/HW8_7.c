#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int i, num;

	printf("Enter a number: ");
	scanf("%d", &num);

	for (i = 1; i <= num; i++)
		if (num % i == 0)
			printf("%d ", i);
	printf("\n");

	return 0;
}