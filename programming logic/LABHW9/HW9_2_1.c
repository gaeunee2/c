#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
int main(void)
{
	int score, best;
	int total = 0, count = 0;

	printf("Enter a score(-1 for exit): ");
	scanf("%d", &score);
	best = score;

	while (score != -1) {
		total += score;
		count++;

		if (score > best)
			best = score;
		printf("Enter a score(-1 for exit): ");
		scanf("%d", &score);
	}
	printf("You've entered %d students.\n", count);

	if (count == 0)
		printf("There is no data.\n");
	else {
		printf("The total is %d.\n", total);
		printf("The average is %.1f.\n", (double)total / count);
		printf("The best score is %d.\n", best);
	}

	return 0;
}