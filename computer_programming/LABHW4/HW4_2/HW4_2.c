#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int fibo(int n);
int main(void)
{
	int n, idx;

	printf("몇개의 피보나치 수열값을 출력할까요?(3보다 큰 정수): ");
	scanf("%d", &n);

	for (idx = 0; idx < n; idx++) {
		printf("%d ", fibo(idx));
		if ((idx + 1) % 5 == 0)
			printf("\n");
	}
	printf("\n");
}

int fibo(int n)
{
	int i, result = 0;
	int x = 1, y = 1;

	if (n == 0 || n == 1)
		result = 1;
	for (i = 2; i <= n; i++) {
		result = x + y;
		x = y;
		y = result;
	}
	return result;
}