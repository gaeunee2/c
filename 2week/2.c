#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
long long calculateReverse(long long n);

int main()
{
	long long n;
	int count = 0;

	scanf("%lld", &n);

	while (n != calculateReverse(n)) {
		if (n < 0 || calculateReverse(n) < 0) {
			printf("Overflow\n");
			return 0;
		}
		n += calculateReverse(n);
		count += 1;
	}
	printf("%d %d\n", count, n);

	return 0;
}

long long calculateReverse(long long n)
{
	long long reverse = 0;

	while (n != 0) {
		reverse *= 10;
		reverse += n % 10;
		n /= 10;
	}
	return reverse;
}