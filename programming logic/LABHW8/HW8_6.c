#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int i, j, num;
	long long factorial;

	printf("Enter a number: ");
	scanf("%d", &num);

	for (i = 1; i <= num; i++) {
		factorial = 1;
		for (j = 0; j < i; j++)
			factorial *= (i - j);
		printf("%d! = %lld\n", i, factorial);
	}

	return 0;
}