#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int i, num, score;
	int best, worst;

	printf("Enter the number of scores: ");
	scanf("%d", &num);

	if (num == 0) {
		printf("no data.\n");

		return;
	}

	for (i = 0; i < num; i++) {
		printf("Enter a score: ");
		scanf("%d", &score);

		if (i == 0) {
			best = score;
			worst = score;
		}

		if (score > best)
			best = score;
		if (score < worst)
			worst = score;
	}
	printf("The best score is %d\n", best);
	printf("The worst score is %d\n", worst);

	return 0;
}