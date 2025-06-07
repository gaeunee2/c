#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int i, n;
	int count = 0;

	scanf("%d", &n);

	for (i = 1; i <= n; i++) {
		int num = i;
		while (num != 0) {
			count += 1;
			num /= 10;
		}
	}
	printf("%d\n", count);

	return 0;
}