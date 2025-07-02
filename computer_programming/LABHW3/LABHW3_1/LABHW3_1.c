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

	printf("���� %d\n", sumList(list, 10));
	printf("���� ū ���� %d\n", maxList(list, 10));
	printf("Ž���� ����? ");
	scanf("%d", &value);

	if (indexSearch(list, 10, value) == -1)
		printf("�� %d�� ���� ���� �����ϴ�.\n", value);
	else
		printf("�� %d�� ���� ù��° ���� %d��°�� �ֽ��ϴ�\n", value, indexSearch(list, 10, value) + 1);

	return 0;
}