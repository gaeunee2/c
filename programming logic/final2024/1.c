#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int isDecimal(int num);
int main(void)
{
	int a[100];
	int i, n;
	int count = 0;

	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		
		if (isDecimal(a[i]) == 1)
			count += 1;
	}

	printf("%d\n", count);
	for (i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");

	return 0;
}

int isDecimal(int num)
{
	int i;

	if (num <= 1)
		return 0;

	for (i = 2; i < num; i++)
		if (num % i == 0)
			return 0;
	return 1;
}
