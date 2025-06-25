#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int i, num;

	printf("Enter a number: ");
	scanf("%d", &num);

	for (i = 1; i < 10; i++)
		printf("%d * %d = %d\n", num, i, num * i);

	return 0;
}