#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int multiply[8][9];
	int i, j, num, want;

	printf("--구구단 표는 다음과 같습니다.\n");
	num = 2;
	for (i = 0; i < 8; i++) {
		for (j = 0; j < 9; j++) {
			multiply[i][j] = num + j * num;
			printf("%4d", multiply[i][j]);
			if (j == 8) {
				printf("\n");
				num += 1;
			}
		}
	}
	printf("--원하는 구구단은? ");
	scanf("%d", &want);

	for (j = 0; j < 9; j++)
		printf("%4d", multiply[want - 2][j]);
	printf("\n");
}