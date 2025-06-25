#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int i, j, r, c;

	printf("Enter the number of rows: ");
	scanf("%d", &r);
	printf("Enter the number of columns: ");
	scanf("%d", &c);

	for (i = 0; i < r; i++) {
		for (j = 0; j < c; j++)
			printf("*");
		printf("\n");
	}

	return 0;
}