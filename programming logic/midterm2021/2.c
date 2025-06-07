#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int score;
	double bonus;

	scanf("%d", &score);

	if (score >= 100)
		bonus = score * 0.5;
	else if (score >= 50)
		bonus = score * 0.25;
	else if (score >= 10)
		bonus = score * 0.15;
	else
		bonus = 0;

	printf("%.2f\n", score + bonus);

	return 0;
}