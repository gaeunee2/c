#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int compare(const void* a, const void* b)
{
	int num1 = *(int*)a;
	int num2 = *(int*)b;
	return (num1 > num2) - (num1 < num2);
}

int main(void)
{
	int i, n, k;

	scanf("%d %d", &n, &k);
	int* score = (int*)malloc(sizeof(int) * n);

	for (i = 0; i < n; i++)
		scanf("%d", &score[i]);
	qsort(score, n, sizeof(int), compare);
	printf("%d\n", score[n - k]);

	free(score);
	return 0;
}