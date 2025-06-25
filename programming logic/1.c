#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int isPrime(int num) // 변경하지 말라
{
	int i;
	for (i = 2; i < num; i++)
		if (num % i == 0)
			return 0;
	return 1;
}
int main(void) // 작성
{
	int n;
	int total = 0;

	scanf("%d", &n);

	while (n != -1) {
		if (isPrime(n))
			total += n;
		scanf("%d", &n);
	}

	printf("%d\n", total);
}