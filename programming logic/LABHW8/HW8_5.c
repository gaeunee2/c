#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int i, num, factorial = 1;

	printf("Enter a number (>=2): ");
	scanf("%d", &num);

	printf("%d! = ", num);
	for (i = 0; i < num - 1; i++) {
		printf("%d * ", num - i);
		factorial *= (num - i);
	}
	printf("1 = %d\n", factorial);

	return 0;
}