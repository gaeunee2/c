#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int f(int n)
{
	int i, a = n, length = 0;
	if (n > 100) {
		printf("");
	}
	else {
		printf("%d ", n);
		f(n * 2);
	}

	for (i = 0; i < 100; i++) {
		a *= 2;
		length += 1;
		if (a > 100)
			break;
	}
	return length;
}

int main(void)
{
	int n;
	scanf("%d", &n);
	printf("end\n%d\n", f(n));
}