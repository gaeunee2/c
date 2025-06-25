#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
void print_divisor(int num);

int main(void)
{
	int i, n;

	printf("Enter a number: ");
	scanf("%d", &n);

	print_divisor(n);

	return 0;
}

void print_divisor(int num)
{
	int i;

	for (i = 1; i <= num; i++)
		if (num % i == 0)
			printf("%d\n", i);

	return;
}