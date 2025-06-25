#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int scores[40];
	int i, n, avg;
	int total = 0;

	printf("Enter the number of scores(0 < number <= 40): ");
	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		printf("Enter a score: ");
		scanf("%d", &scores[i]);
	}
	for (i = 0; i < n; i++)
		total += scores[i];
	avg = total / n;

	printf("----------------------------------\n");
	printf("Total: %d\n", total);
	printf("Average: %d\n", avg);

	for (i = 0; i < n; i++)
		printf("%d ", scores[i]);
	printf("\n");

	return 0;
}