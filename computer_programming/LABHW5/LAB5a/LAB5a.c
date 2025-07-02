#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void matrixAdd(int a[][3], int b[][3], int c[][3], int size)
{
	int i, j;

	for (i = 0; i < size; i++)
		for (j = 0; j < 3; j++)
			c[i][j] = a[i][j] + b[i][j];
}

void printMatrix(int a[][3], int size)
{
	int i, j;

	for (i = 0; i < size; i++) {
		for (j = 0; j < 3; j++) {
			printf("%6d", a[i][j]);
			if (j == 2)
				printf("\n");
		}
	}
}

void readMatrix(int a[][3], int size)
{
	int i, j;

	for (i = 0; i < size; i++)
		for (j = 0; j < 3; j++)
			scanf("%d", &a[i][j]);
}

int main(void)
{
	int A[4][3], B[4][3], C[4][3];

	printf("(4 x 3) 행렬 A 입력:\n");
	readMatrix(A, 4);
	printf("(4 x 3) 행렬 B 입력:\n");
	readMatrix(B, 4);

	matrixAdd(A, B, C, 4);

	printf("행렬합:\n"); printMatrix(C, 4);
	printf("\n");
}