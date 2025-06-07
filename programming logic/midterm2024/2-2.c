#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int i, n, sum = 0;

	scanf("%d", &n);
	while (n != -1) {
		if (n % 3 == 0 || n % 5 == 0)
			sum += n;
		scanf("%d", &n);
	}
	printf("%d\n", sum);

	return 0;
}