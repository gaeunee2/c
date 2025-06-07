#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int i, score;
	int student = 0;
	int count = 0;

	scanf("%d", &score);

	while (score != -1) {
		student += 1;
		if (score >= 50)
			count += 1;

		scanf("%d", &score);
	}
	printf("%.1f", count / (double)student * 100);

	return 0;
}