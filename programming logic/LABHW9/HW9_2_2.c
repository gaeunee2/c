#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
int main(void)
{
	int score, best;
	int total = 0, count = 0;

	while (1) {
		printf("Enter a score(-1 for exit): ");
		scanf("%d", &score);

		if (score == -1)
			break;
		if (count == 0)
			best = score;
		else if (score > best)
			best = score;

		total += score;
		count++;
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