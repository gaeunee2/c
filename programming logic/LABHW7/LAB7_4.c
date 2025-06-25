#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int num, i;

	printf("Enter a number: ");
	scanf("%d", &num);

	i = 3;
	while (i <= num) {
		if (i % 3 == 0 || i % 5 == 0)
			printf("%d ", i);
		i++;
	}
	printf("\n");

	return 0;
}