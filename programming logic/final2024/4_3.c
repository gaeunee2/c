#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h> 
int maxIncreasing2(int a[], int n)
{
	int i, j, len;
	int max = 1;
	int maxIndex = 0;

	for (i = 0; i < n; i++) {
		if (a[i] <= a[i + 1]) {
			j = i;
			len = 1;
			while (a[j] <= a[j + 1]) {
				len += 1;
				j++;
				i++;
			}
			if (len > max) {
				max = len;
				maxIndex = i - len + 1;
			}
		}
	}
	
	for (i = 0; i < max; i++)
		printf("%d ", a[maxIndex++]);
	printf("\n");

	return max;
}

int main(void)
{
	int a[40];
	int i, n;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);

	printf("%d\n", maxIncreasing2(a, n));
}
