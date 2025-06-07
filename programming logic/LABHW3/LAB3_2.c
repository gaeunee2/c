#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int total, h, m;

	printf("Enter the total minutes: ");
	scanf("%d", &total);

	h = total / 60;
	m = total % 60;

	printf("%d minutes\n%dh %dm\n", total, h, m);

	return 0;
}