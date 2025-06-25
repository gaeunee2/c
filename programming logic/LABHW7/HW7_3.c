#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int num, i;
	int fact = 1;

	printf("Enter a number: ");
	scanf("%d", &num);

	i = 1;
	while (i <= num) {
		fact *= i;
		i++;
	}
	printf("%dÀÇ Factorial °ªÀº %dÀÌ´Ù.\n", num, fact);

	return 0;
}
