#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int get_cycle_number(int num);
int main(void)
{
	int n;

	printf("Enter a number<exit -1>: ");
	scanf("%d", &n);

	while (n != -1) {
		printf("±æÀÌ´Â %d\n", get_cycle_number(n));

		printf("Enter a number<exit -1>: ");
		scanf("%d", &n);
	}

	return 0;
}

int get_cycle_number(int num)
{
	int len = 1;

	while (num != 1) {
		printf("%d ", num);
		len += 1;

		if (num % 2 == 0)
			num /= 2;
		else
			num = num * 3 + 1;
	}
	printf("1\n");

	return len;
}