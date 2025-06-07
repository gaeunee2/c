#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int n, num, newN = 0, count = 1;

	scanf("%d", &n);
	num = n;

	while (n != 0) {
		if (n % 10 % 2 == 0) {
			newN += n % 10 * count;
			count *= 10;
		}
		n /= 10;
	}
	printf("%d %d\n", newN * 9, num);

	return 0;
}