#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int total, h, m;

	printf("Enter hour: ");
	scanf("%d", &h);
	printf("Enter minute: ");
	scanf("%d", &m);

	total = h * 60 + m;

	printf("Total %d minutes\n", total);

	return 0;
}