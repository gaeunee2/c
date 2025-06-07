#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int i, j, m, n, sum = 0;

	scanf("%d %d", &m, &n);

	for (i = m; i <= n; i++) {
		for (j = 2; j < i; j++)
			if (i % j == 0)
				break;
		if (j == i)
			sum += i;
	}
	printf("%d\n", sum);

	return 0;
}