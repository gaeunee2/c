#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int n, l;
	int i, j, k;
	int sum;

	scanf("%d %d", &n, &l);

	for (i = 0; i < 31; i++) {
		sum = 0;
		for (j = i; sum <= n; j++) {
			if (sum == n && j - i >= l) {
				for (k = i; k < j; k++)
					printf("%d ", k);
				printf("\n");
				return 0;
			}
			if (j > 30 + i)
				break;
			sum += j;
		}
	}
	printf("-1\n");

	return 0;
}