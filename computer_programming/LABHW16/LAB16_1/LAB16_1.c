#include <stdio.h>
int main(void)
{
	int table[5][3] = { 0 };
	int i, j, sum, total;

	printf("°¡>\n");
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 3; j++)
			printf("%d ", table[i][j]);
		printf("\n");
	}

	printf("³ª>\n");
	sum = 0;
	for (i = 0; i < 5; i++) {
		for (j = 0; j < 3; j++) {
			sum = i + j;
			table[i][j] = sum;
		}
	}
	i = 0;
	while (i < 5) {
		j = 0;
		while (j < 3) {
			printf("%d ", table[i][j]);
			j++;
		}
		i++;
		printf("\n");
	}

	printf("´Ù>\n");
	total = 0;
	for (i = 0; i < 5; i++) {
		for (j = 0; j < 3; j++)
			total += table[i][j];
	}
	printf("Total is %d\n", total);
}