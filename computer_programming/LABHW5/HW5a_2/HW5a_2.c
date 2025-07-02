#include <stdio.h>

void printSubstitute(int arr[][4], int size)
{
	int i, j;
	int num = 1;

	for (i = 0; i < size; i++) {
		for (j = 0; j < 4; j++) {
			arr[i][j] = num;
			num++;

			printf("%4d", arr[i][j]);
			if (j == 3)
				printf("\n");
		}
	}
}

void printRotateArray(int a1[][4], int a2[][4], int size)
{
	int i, j;

	for (int k = 0; k < 4; k++) {
		for (i = 0; i < size; i++)
			for (j = 0; j < 4; j++)
				a2[j][3 - i] = a1[i][j];

		for (i = 0; i < size; i++) {
			for (j = 0; j < 4; j++) {
				printf("%4d", a2[i][j]);
				if (j == 3)
					printf("\n");
			}
		}
		printf("\n\n");

		for (i = 0; i < size; i++)
			for (j = 0; j < 4; j++)
				a1[i][j] = a2[i][j];
	}
}

int main(void)
{
	int arr1[4][4] = { 0 };
	int arr2[4][4] = { 0 };

	printSubstitute(arr1, 4);
	printf("\n");
	printRotateArray(arr1, arr2, 4);

	return 0;
}