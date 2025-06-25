#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int i, num, integer, evenInteger = 0;

	printf("Enter the # of integers: ");
	scanf("%d", &num);

	for (i = 0; i < num; i++) {
		printf("Enter an integer: ");
		scanf("%d", &integer);

		if (integer % 2 == 0)
			evenInteger += 1;
	}
	printf("The number of even numbers is %d.\n", evenInteger);

	return 0;
}