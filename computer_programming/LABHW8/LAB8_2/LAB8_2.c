#include <stdio.h>
int sumUp(int* pa, int size)
{
	int i, sum = 0;
	for (i = 0; i < size; i++)
		sum += *pa++;
	return sum;
}
int main(void)
{
	int arr[5] = { 10, 20, 30, 40, 50 };
	printf("arrÀÇ ÇÕÀº %d\n", sumUp(arr, 5));
}
