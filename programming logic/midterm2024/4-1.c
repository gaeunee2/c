#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int n, sum = 0;

	scanf("%d", &n);

	while (n != 0) {
		sum += n % 100;
		n /= 100;
	}
	printf("%d\n", sum);

	return 0;
}