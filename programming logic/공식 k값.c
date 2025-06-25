#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	int i, n;
	int count = 0;

	printf("Enter a number: ");
	scanf("%d", &n);

	for (i = 2; i <= n; i *= 2)
		count++;
	printf("%d\n", count);

	return 0;
}