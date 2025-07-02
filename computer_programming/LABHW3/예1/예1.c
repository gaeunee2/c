#include <stdio.h>
#define SIZE 6
int main(void)
{
	int a[SIZE] = { 5, 3, 8, 1, 2, 7 };
	int i, j, temp, minIndex;
	for (i = 0; i < SIZE - 1; i++) 
	{
		int min = a[i];
		minIndex = i;

		for (j = i + 1; j < SIZE; j++)
		{
			if (a[j] < min) 
			{
				minIndex = j;
				min = a[minIndex];
			}
		}

		temp = a[i];
		a[i] = a[minIndex];
		a[minIndex] = temp;
	}
	for (i = 0; i < SIZE; i++)
		printf("%d ", a[i]);
	printf("\n");
	return 0;
}