#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	int num, i, result;

	printf("Enter a number: ");
	scanf("%d", &num);

	i = 2 * num;
	while (i <= 2 * num) {
		i /= 2;
		if (i % 2 == 0)
			result = 0;
		else
			result = 1;
		if (i == 0)
			break;
		printf("%d", result);
	}
	printf("\n");

	return 0;
}