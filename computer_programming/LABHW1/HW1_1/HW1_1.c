#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int printLine(int);
int main(void)
{
	srand(time(NULL));
	int i, num, random[100], count[10];

	printf("Enter the number of random numbers:<<=100>: ");
	scanf("%d", &num);
	
	for (i = 0; i < 10; i++)
		count[i] = 0;

	for (i = 0; i < num; i++)
	{
		random[i] = rand() % 10;
		count[random[i]]++;
	}

	for (i = 0; i < 10; i++)
		printf("%d의 개수는 %d\n", i, count[i]);
	printLine(44);
	printf("발생된 난수는\n");
	for (i = 0; i < num; i++)
	{
		printf("%5d", random[i]);
		if ((i + 5) % 5 == 4)
			printf("\n");
	}
}

int printLine(int n)
{
	for (int j = 0; j < n; j++)
		printf("-");
	printf("\n");
}