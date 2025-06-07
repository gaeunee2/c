#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int num, digit, newNum;
	int count = 0;

	scanf("%d", &num);
	scanf("%d", &digit);

	newNum = num * 3;

	while (newNum != 0) {
		if (newNum % 10 == digit)
			count++;
		newNum /= 10;
	}
	printf("%d\n", count);

	return 0;
}