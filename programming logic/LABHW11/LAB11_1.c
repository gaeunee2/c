#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int sum1ToN(int n);
int main(void)
{
	printf("1부터 %d까지의 합은 %d\n", 5, sum1ToN(5));
	printf("1부터 %d까지의 합은 %d\n", 7, sum1ToN(7));
	printf("1부터 %d까지의 합은 %d\n", 10, sum1ToN(10));

	return 0;
}

int sum1ToN(int n)
{
	int i, sum = 0;

	for (i = 1; i <= n; i++)
		sum += i;

	return sum;
}
