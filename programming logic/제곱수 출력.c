#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
int main(void)
{
	int n1, n2, num;

	printf("Enter two numbers: ");
	scanf("%d %d", &n1, &n2);
	num = n1;

	printf("1 ");
	while (n1 <= n2) {
		printf("%d ", n1);
		n1 *= num;
	}
	printf("\n");

	return 0;
}