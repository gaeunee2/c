#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int number, square, cube;

	printf("Enter a number: ");
	scanf("%d", &number);

	square = number * number;
	cube = number * number * number;

	printf("The square number of %d is %d\n", number, square);
	printf("The cube number of %d is %d\n", number, cube);

	return 0;
}