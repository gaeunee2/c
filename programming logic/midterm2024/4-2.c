#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int i, n, k, sum = 0;
	int num = 1;

	scanf("%d", &n);
	scanf("%d", &k);

	for (i = 0; i < k; i++)
		num *= 10;

	while (n != 0) {
		sum += n % num;
		n /= num;
	}
	printf("%d\n", sum);

	return 0;
}