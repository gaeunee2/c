#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int i, num;

	printf("Enter a number: ");
	scanf("%d", &num);

	if (num < 2) {
		printf("소수가 아니다\n");
		return;
	}

	for (i = 2; i < num; i++) {
		if (num % i == 0) {
			printf("소수가 아니다\n");
			return;
		}
	}
	printf("소수이다\n");

	return 0;
}