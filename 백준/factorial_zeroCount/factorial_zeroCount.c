#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	int i, j, n;
	int num;
	int fiveCount = 0;
	int twoCount = 0;
	int zeroCount;

	scanf("%d", &n);

	for (i = n; i > 1; i--) {
		if (i % 5 == 0 || i % 2 == 0) {
			num = i;
			while (num % 5 == 0 || num % 2 == 0) {
				if (num % 5 == 0) {
					fiveCount += 1;
					num /= 5;
				}
				if (num % 2 == 0) {
					twoCount += 1;
					num /= 2;
				}
			}
		}
	}
	zeroCount = twoCount > fiveCount ? fiveCount : twoCount;
	printf("%d\n", zeroCount);

	return 0;
}