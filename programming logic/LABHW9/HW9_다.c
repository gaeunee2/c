#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void get_cycle_number(int num);
int main(void)
{
	int n;

	printf("Enter a number:");
	scanf("%d", &n);

	get_cycle_number(n);

	return 0;
}

void get_cycle_number(int num)
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
	printf("±æÀÌ´Â %d\n", len);
}