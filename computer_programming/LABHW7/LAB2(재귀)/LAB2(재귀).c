#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void to_binary(int n);

int main(void)
{
	int i, n;

	scanf("%d", &n);
	to_binary(n);
	printf("\n");
}

void to_binary(int n)
{
	if (n == 0)
		return 0;
	else {
		to_binary(n / 2);
		printf("%d", n % 2);
	}
}