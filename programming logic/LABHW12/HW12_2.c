#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void)
{
	int i, n, num[100];
	int total = 0;

	printf("Enter the number of random numbers<<= 100>: ");
	scanf("%d", &n);

	srand(time(NULL));
	for (i = 0; i < n; i++) {
		num[i] = rand() % 100;
		total += num[i];
	}
	printf("������ ����� %d\n", total / n);
	printf("�߻��� ������\n");

	for (i = 0; i < n; i++) {
		printf("%5d", num[i]);
		if (i % 5 == 4)
			printf("\n");
	}

	return 0;
}