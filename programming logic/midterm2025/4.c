#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int i, j, n;

	scanf("%d", &n);

	for (i = 1; i <= n; i++) {
		int num = n;
		for (j = 0; j < i; j++) {
			printf("%d", num);
			num -= 1;
		}
		printf("\n");
	}

	return 0;
}