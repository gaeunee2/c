#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int i, n, m;
	int count = 0, sum = 0;

	scanf("%d", &n);
	scanf("%d", &m);

	while (count != m) {
		for (i = 2; i < n; i++)
			if (n % i == 0)
				break;
		if (i == n) {
			count++;
			sum += n;
		}
		n++;
	}
	printf("%d\n", sum);

	return 0;
}