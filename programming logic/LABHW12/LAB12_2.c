#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void)
{
	int i, num[10];
	int total = 0;

	srand(time(NULL));
	for (i = 0; i < 10; i++)
		num[i] = rand() % 100;

	for (i = 0; i < 10; i++)
		total += num[i];

	printf("Æò±ÕÀº %d\n", total / 10);

	for (i = 0; i < 10; i++)
		printf("%d ", num[i]);
	printf("\n");

	return 0;
}