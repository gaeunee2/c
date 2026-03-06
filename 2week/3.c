#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int i, n, c = 1;

	scanf("%d", &n);

	for (i = 1; ; i++) {
		if (c % n == 0)
			break;

		c = c * 10 + 1;
	}
	printf("%d\n", i);

	return 0;
}