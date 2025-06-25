#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int isPrime(int num);
int main(void)
{
	int i, num;

	printf("Enter a number<-1 for exit>: ");
	scanf("%d", &num);

	while (num != -1) {
		if (isPrime(num))
			printf("소수입니다\n");
		else
			printf("소수가 아닙니다\n");

		printf("Enter a number<-1 for exit>: ");
		scanf("%d", &num);
	}

	return 0;
}

int isPrime(int num)
{
	int i;

	for (i = 2; i < num; i++)
		if (num % i == 0)
			return 0;
	return 1;
}
