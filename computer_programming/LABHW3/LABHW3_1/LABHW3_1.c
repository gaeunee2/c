#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int sumList(int arr[], int size)
{
	int i, total = 0;
	for (i = 0; i < size; i++)
		total += arr[i];
	return total;
}

int maxList(int arr[], int size)
{
	int i, j, max = -1;
	for (i = 0; i < size; i++)
	{
		if (arr[i] > max)
			max = arr[i];
	}
	return max;
}

int indexSearch(int arr[], int size, int key)
{
	int i, search = 0;
	for (i = 0; i < size; i++)
		if (arr[i] == key)
			return i;
	return -1;
}

int main(void)
{
	int list[10] = { 10,20,30,40,50,40,30,20,10,0 };
	int i, value, keyIndex;

	printf("합은 %d\n", sumList(list, 10));
	printf("가장 큰 수는 %d\n", maxList(list, 10));
	printf("탐색할 값은? ");
	scanf("%d", &value);

	if (indexSearch(list, 10, value) == -1)
		printf("값 %d를 갖는 값은 없습니다.\n", value);
	else
		printf("값 %d를 갖는 첫번째 값은 %d번째에 있습니다\n", value, indexSearch(list, 10, value) + 1);

	return 0;
}