#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int best(int a, int b, int c)
{
	int best = a;

	if (b > best)
		best = b;
	if (c > best)
		best = c;

	return best;
}

int main(void)
{
	int a, b, c;

	scanf("%d %d %d", &a, &b, &c);
	while (a != 0 && b != 0 && c != 0) {
		if (best(a, b, c) == a && b * b + c * c == a * a)
			printf("right\n");
		else if (best(a, b, c) == b && a * a + c * c == b * b)
			printf("right\n");
		else if (best(a, b, c) == c && a * a + b * b == c * c)
			printf("right\n");
		else
			printf("wrong\n");

		scanf("%d %d %d", &a, &b, &c);
	}

	return 0;
}