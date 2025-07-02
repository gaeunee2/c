#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int processEven(int* p, int size)
{
	int i, sum = 0;

	for (i = 0; i < size; i++) {
		if (*p % 2 == 0) {
			printf("%d ", *p);
			sum += *p;
		}
		p++;
	}
	printf("\n%d", sum);
}
int main(void)
{
	int i;
	int n;
	int data[20];
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &data[i]);
	printf("end\n%d\n", processEven(data, n));
}