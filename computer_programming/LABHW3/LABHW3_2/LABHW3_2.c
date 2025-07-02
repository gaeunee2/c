#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void initArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		arr[i] = rand() % 100;
	return;
}

void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

void printMinMax(int arr[], int size)
{
	int min = INT_MAX;
	int max = INT_MIN;
	int i, minIndex = 0, maxIndex = 0;

	for (i = 0; i < size; i++) {
		if (arr[i] > max) {
			max = arr[i];
			maxIndex = i;
		}
		if (arr[i] < min) {
			min = arr[i];
			minIndex = i;
		}
	}
	printf("최대값: 인덱스 = %d, 값 = %d\n", maxIndex, max);
	printf("최소값: 인덱스 = %d, 값 = %d\n", minIndex, min);
}

int main(void)
{
	srand(time(NULL));
	int a[10];

	initArray(a, 10);
	printArray(a, 10);
	printMinMax(a, 10);

	return 0;
}