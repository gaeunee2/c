#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int number;

	printf("Enter a number: ");
	scanf("%d", &number);

	printf("The square number of %d is %d\n", number, number * number);
	printf("The cube number of %d is %d\n", number, number * number * number);

	return 0;
}