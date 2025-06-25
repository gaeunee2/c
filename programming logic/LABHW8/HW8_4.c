#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int i, j;

	for (i = 1; i < 10; i++) {
		for (j = 2; j < 9; j += 2)
			printf("%d * %d = %d\t", i, j, i * j);
		printf("\n");
	}

	return 0;
}