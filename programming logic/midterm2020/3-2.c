#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int i, j, n, sum;

	scanf("%d", &n);

	if (n < 5) {
		sum = 0;
		for (i = 1; i <= n; i++)
			sum += i;
		printf("1 - %d까지 합 = %d\n", n, sum);
	}
	else if (n % 5 == 0) {
		for (i = 5; i <= n; i += 5) {
			sum = 0;
			for (j = i - 4; j <= i; j++)
				sum += j;
			printf("%d - %d까지 합 = %d\n", i - 4, i, sum);
		}
	}
	else {
		for (i = 5; i <= n; i += 5) {
			sum = 0;
			for (j = i - 4; j <= i; j++)
				sum += j;
			printf("%d - %d까지 합 = %d\n", i - 4, i, sum);
		}
		sum = 0;
		for (j = i - 4; j <= n; j++)
			sum += j;
		printf("%d - %d까지 합 = %d\n", i - 4, n, sum);
	}

	return 0;
}