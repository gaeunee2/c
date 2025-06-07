#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int i, j, n, sum;

	scanf("%d", &n);

	for (i = 5; i <= n; i += 5) {
		sum = 0;
		for (j = i - 4; j <= i; j++)
			sum += j;
		printf("%d - %d±îÁö ÇÕ = %d\n", i - 4, i, sum);
	}

	return 0;
}