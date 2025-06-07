#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int i, x, y;
	int num, count = 0, sum = 0;

	scanf("%d %d", &x, &y);

	for (i = 0; i < 10; i++) {
		scanf("%d", &num);

		if (num > x && num < y) {
			count++;
			sum += num;
		}
	}
	printf("%d\n", sum);
	printf("%d\n", count);

	return 0;
}