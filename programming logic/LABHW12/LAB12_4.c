#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int i, n, data[20];

	printf("Enter a number: ");
	scanf("%d", &n);

	for (i = 0; i < 20; i++)
		data[i] = n * (i + 1);

	for (i = 0; i < 20; i++) {
		printf("%5d ", data[i]);
		if (i % 5 == 4)
			printf("\n");
	}

	return 0;
}