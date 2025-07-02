#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int isPrime(int n)
{
	int i;
	for (i = 2; i < n; i++)
		if (n % i == 0)
			return 0;
	return 1;
}
int main(void)
{
	int num, total = 0;

	scanf("%d", &num);
	while (num != -1) {
		if (isPrime(num) == 1)
			total += num;
		scanf("%d", &num);
	}
	printf("%d\n", total);
}