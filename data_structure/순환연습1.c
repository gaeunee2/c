#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int factorial(int n)
{
	if (n == 0 || n == 1)
		return 1;
	else
		return n * factorial(n - 1);
}

int main(void)
{
	int n;

	printf("Enter a number: ");
	scanf("%d", &n);

	printf("%d! = %d\n", n, factorial(n));

	return 0;
}
