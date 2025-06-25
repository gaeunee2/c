#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
long long pow(int a, int b)
{
	int i;
	long long rslt = 1;

	for (i = 0; i < b; i++)
		rslt *= a;

	return rslt;
}

int isPrime(long long num)
{
	int i;

	for (i = 2; i < num; i++)
		if (num % i == 0)
			return 0;
	return 1;
}

int main(void)
{
	int i, num;

	printf("Enter a number: ");
	scanf("%d", &num);

	for (i = 2; i <= num; i++)
		if (isPrime(pow(2, i) - 1))
			printf("(2^%d - 1) = %lld은 메르센 소수이다\n", i, pow(2, i) - 1);

	return 0;
}