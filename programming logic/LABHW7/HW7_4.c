#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int num, i, score;
	int total = 0;
	double avg;

	printf("Enter a student number: ");
	scanf("%d", &num);

	i = 1;
	while (i <= num) {
		printf("Enter a score: ");
		scanf("%d", &score);
		total += score;
		i++;
	}
	if (num == 0)
		avg = 0;
	else
		avg = (double)total / num;

	printf("The total is %d\n", total);
	printf("The average is %.1f\n", avg);

	return 0;
}