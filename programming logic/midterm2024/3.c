#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int i, j, n, m, count = 0;

	scanf("%d %d", &n, &m);

	for (i = n; i <= m; i++) {
		for (j = 2; j < i; j++)
			if (i % j == 0)
				break;
		if (j != i)
			count += 1;
	}
	printf("%d\n", count);

	return 0;
}