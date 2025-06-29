#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	int i, k;
	int sum = 0;
	int a[100001];
	int num;
	int index = 0;

	scanf("%d", &k);

	for (i = 0; i < k; i++) {
		scanf("%d", &num);

		if (num == 0 && index > 0)
			sum -= a[--index];
		else if (num != 0) {
			a[index++] = num;
			sum += num;
		}
	}
	printf("%d\n", sum);

	return 0;
}