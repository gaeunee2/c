#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int incomes[7];
	int i, best;

	for (i = 0; i < 7; i++) {
		printf("Enter the income: ");
		scanf("%d", &incomes[i]);
	}

	best = incomes[0];
	for (i = 1; i < 7; i++)
		if (best < incomes[i])
			best = incomes[i];

	printf("----------------------------------\n");
	printf("The best income is %d\n", best);
	printf("Incomes are\n");

	for (i = 0; i < 7; i++)
		printf("%d ", incomes[i]);
	printf("\n");

	return 0;
}