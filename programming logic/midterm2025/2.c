#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int i, n, score;
	int count = 0;

	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		scanf("%d", &score);

		if (score >= 50)
			count += 1;
	}
	printf("%.1f", count / (double)n * 100);

	return 0;
}