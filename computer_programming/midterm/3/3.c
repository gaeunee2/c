#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define X_VALUE 5
#define Y_VALUE 5

void readGridInfo(char grid[][Y_VALUE + 1]) // 변경하지 말라
{
	int i;
	// grid 및 지뢰 정보 입력 
	//printf("Input Grid\n");
	for (i = 0; i < X_VALUE; i++)
		scanf("%s", grid[i]);
}

void countGrid(char grid[][Y_VALUE + 1], int nB[][Y_VALUE])
{
	int i, j;
	int temp;
	int newG[5][5];
	for (i = 0; i < X_VALUE; i++)
		for (j = 0; j < Y_VALUE; j++) {
			if (grid[i][j] == '0')
				grid[i][j] = grid[i][j] - 48;
			else
				grid[i][j] = grid[i][j] - 48;
		}
	for (i = 0; i < X_VALUE; i++)
		for (j = 0; j < Y_VALUE; j++)
			newG[i][j] = grid[i][j];
			
	for (i = 0; i < X_VALUE; i++)
		for (j = 0; j < Y_VALUE; j++) {
			if (j == 0)
				nB[i][j] = grid[i][1] + grid[i][2];
			else if (j == 1)
				nB[i][j] = grid[i][0] + grid[i][2] + grid[i][3];
			else if (j == 2)
				nB[i][j] = grid[i][0] + grid[i][1] + grid[i][3] + grid[i][4];
			else if (j == 3)
				nB[i][j] = grid[i][1] + grid[i][2] + grid[i][4];
			else
				nB[i][j] = grid[i][2] + grid[i][3];
		}
}

void display_nB(int nB[][Y_VALUE]) // 변경하지 말라 
{
	int i, j;
	for (i = 0; i < X_VALUE; i++) {
		for (j = 0; j < Y_VALUE; j++)
			printf("%d ", nB[i][j]);
		printf("\n");
	}
}

int main(void) // 변경하지 말라
{
	char grid[X_VALUE][Y_VALUE + 1]; // 문자열 마지막 \0 값 때문에 5*6 배열

	int nB[X_VALUE][Y_VALUE] = { 0 };

	readGridInfo(grid);
	countGrid(grid, nB);
	display_nB(nB);
}