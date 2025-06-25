#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
int main(void)
{
	int n;

	printf("Enter a number: ");
	scanf("%d", &n);

	while (n != 0) {
		printf("%d", n % 10);
		n /= 10;
	}
	printf("\n");

	return 0;
}