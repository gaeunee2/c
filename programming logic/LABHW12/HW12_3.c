#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int incomes[7];
	int i;
	int best = -1, bestDay;
	int total = 0;
	double avg;

	for (i = 0; i < 7; i++) {
		printf("Enter the income of day %d: ", i + 1);
		scanf("%d", &incomes[i]);

		if (best < incomes[i]) {
			best = incomes[i];
			bestDay = i + 1;
		}
		total += incomes[i];
	}
	avg = (double)total / 7;

	printf("----------------------------------\n");
	printf("The best income: %d in day %d\n", best, bestDay);
	printf("----------------------------------\n");

	printf("The total is %d\n", total);
	printf("The average is %.1f\n", avg);
	printf("The good days and their incomes are\n");

	for (i = 0; i < 7; i++)
		if (incomes[i] > avg)
			printf("day %d: %d\n", i + 1, incomes[i]);

	return 0;
}