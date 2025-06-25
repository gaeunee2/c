#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int n, i;

	printf("Enter a number: ");
	scanf("%d", &n);

	i = 1;
	while (i <= n) {
		printf("%d\n", i * i * i);
		i++;
	}

	return 0;
}