#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h> 
int isIncreasing(int a[], int n)
{
	int i;

	for (i = 1; i < n; i++)
		if (a[i] < a[i - 1])
			return 0;
	return 1;
}

int main(void)
{
	int a[40];
	int n;

	scanf("%d", &n);

	for (int k = 0; k < 4; k++) {
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		printf("%d\n", isIncreasing(a, n));
	}
}