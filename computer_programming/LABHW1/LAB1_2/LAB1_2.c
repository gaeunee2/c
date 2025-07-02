#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int printLine(int);
int main(void)
{
	srand(time(NULL));
	int i, num, random[50], best = -1;

	printf("Enter the number of random numbers:<<=50>: ");
	scanf("%d", &num);

	for (i = 0; i < num; i++)
	{
		random[i] = rand() % 100;
		
		if (best < random[i])
			best = random[i];
	}

	printf("최대값은 %d\n", best);
	printLine(44);
	printf("발생된 난수는\n");

	for (i = 0; i < num; i++)
	{
		printf("%5d", random[i]);
		if ((i + 5) % 5 == 4)
			printf("\n");
	}

	return 0;
}

int printLine(int n)
{
	for (int j = 0; j < n; j++)
		printf("-");
	printf("\n");
}