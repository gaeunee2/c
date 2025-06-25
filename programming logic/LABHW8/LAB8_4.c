#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int i, score, best = 0;

	for (i = 0; i < 5; i++) {
		printf("Enter a score: ");
		scanf("%d", &score);

		if (score > best)
			best = score;
	}
	printf("The best score is %d.\n", best);

	return 0;
}