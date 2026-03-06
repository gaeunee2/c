#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int n1, n2, count, carry;

	count = 0;
	carry = 0;

	scanf("%d %d", &n1, &n2);
	
	while (n1 != 0 || n2 != 0) {
		int sum;
		sum = n1 % 10 + n2 % 10 + carry;

		if (sum >= 10) {
			count++;
			carry = 1;
		}
		else
			carry = 0;

		n1 /= 10;
		n2 /= 10;
	}
	printf("%d\n", count);

	return 0;
}