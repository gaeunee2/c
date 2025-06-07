#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int i, j, n;
	int count = 0;

	scanf("%d", &n);

	for (i = n; i > 1; i--) {
		for (j = 2; j < i; j++)
			if (i % j == 0)
				break;
		if (j == i) {
			printf("%d ", i);
			count += 1;
		}
	}
	printf("\n%d\n", count);

	return 0;
}