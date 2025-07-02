#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10
void selectionSort(int list[], int size)
{
	int i, j, temp, minIndex;

	for (i = 0; i < size - 1; i++) {
		int min = list[i];
		minIndex = i;

		for (j = i + 1; j < SIZE; j++) {
			if (list[j] < min) {
				minIndex = j;
				min = list[minIndex];
			}
		}

		temp = list[i];
		list[i] = list[minIndex];
		list[minIndex] = temp;
	}
}

int main(void)
{
	srand(time(NULL));

	int i, random[SIZE];

	printf("�߻��� ����:\t");
	for (i = 0; i < SIZE; i++)
	{
		random[i] = rand() % 100;
		printf("%d ", random[i]);
	}

	printf("\n���� ��:\t");
	selectionSort(random, SIZE);

	for (i = 0; i < SIZE; i++)
		printf("%d ", random[i]);
	printf("\n");

	return 0;
}