#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	int n, count = 0;

	scanf("%d", &n);

	while (n != 0) {
		count++;
		n /= 10;
	}
	printf("%d\n", count);

	return 0;
}