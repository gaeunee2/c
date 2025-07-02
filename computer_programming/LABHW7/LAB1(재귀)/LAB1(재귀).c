#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int sum(int n);

int main(void) 
{
	int i, n;

	scanf("%d", &n);

	for (i = 1; i < n + 1; i++)
		printf("%d ", 10 * i + 2);
	printf("\n%d\n", sum(n));
}

int sum(int n) 
{
	if (n == 1)
		return 12;
	else
		return 10 * n + 2 + sum(n - 1);
}