#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int i, n, sum = 0;

	scanf("%d", &n);

	for (i = 1; i <= n; i++)
		if (i % 3 == 0 || i % 5 == 0)
			sum += i;
	printf("%d\n", sum);

	return 0;
}