#include <stdio.h>
int main(void)
{
	int test[4][3] = { {8, 7}, {6, 5}, {1, 2}, {3, 4} };
	int i, j, total, max, sum;
	double average;

	printf("배열 test의 엘리먼트를 출력합니다.\n");
	for (i = 0; i < 4; i++)
	{
		printf("\n%d번째 row: ", i + 1);
		for (j = 0; j < 3; j++)
			printf("%d ", test[i][j]);
	}

	printf("\n\n다>");
	printf("배열 test의 엘리먼트를 출력합니다.\n");
	for (i = 0; i < 4; i++)
		test[i][2] = -1;
	for (i = 0; i < 4; i++)
	{
		printf("\n%d번째 row: ", i + 1);
		for (j = 0; j < 3; j++)
			printf("%d ", test[i][j]);
	}

	printf("\n\n라>");
	total = 0;
	for (i = 0; i < 4; i++)
		for (j = 0; j < 3; j++)
			total += test[i][j];
	printf("Total is %d\n", total);
	average = (double)total / 12;
	printf("Average is %.2f", average);

	printf("\n\n마>");
	sum = 0;
	for (i = 0; i < 4; i++) {
		max = -1;
		printf("\n%d번째 row에서의 최대값: ", i + 1);
		for (j = 0; j < 3; j++)
			if (max < test[i][j])
				max = test[i][j];
		sum += max;
		printf("%d", max);
	}
	printf("\n최대값의 합: %d\n", sum);
}