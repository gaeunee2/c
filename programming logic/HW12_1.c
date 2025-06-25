#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int i, j, n, scores[20];

	printf("Enter the number of scores<<= 20>: ");
	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		printf("Enter a score: ");
		scanf("%d", &scores[i]);
	}

	for (i = 0; i < n; i++) {
		printf("Student %3d: ", i + 1);
		for (j = 0; j < scores[i]; j++)
			printf("*");
		printf("\n");
	}

	return 0;
}