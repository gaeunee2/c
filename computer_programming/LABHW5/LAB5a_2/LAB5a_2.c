#include <stdio.h>

void substitute(int arr[4][4])
{
	int i, j;
	int num = 1;

	for (i = 0; i < 4; i++)
		for (j = 0; j < 4; j++) {
			arr[i][j] = num;
			num++;
		}
}

void printArray(int arr[4][4])
{
	int i, j;

	for (i = 0; i < 4; i++)
		for (j = 0; j < 4; j++) {
			printf("%4d", arr[i][j]);
			if (j == 3)
				printf("\n");
		}
}

void rotateArray(int arr[4][4])
{
	int i, j;
	int move[4][4];

	for (i = 0; i < 4; i++)
		for (j = 0; j < 4; j++)
			move[j][3 - i] = arr[i][j];

	for (i = 0; i < 4; i++)
		for (j = 0; j < 4; j++)
			arr[i][j] = move[i][j];
}

int main(void)
{
	int arr1[4][4] = { 0 };

	substitute(arr1);
	printArray(arr1);

	printf("\n\n");
	rotateArray(arr1);
	printArray(arr1);

	return 0;
}