#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int total, h, m, s;

	printf("Enter the total seconds: ");
	scanf("%d", &total);

	h = total / 60 / 60;
	m = total % 3600 / 60;
	s = total % 60;

	printf("---Calculation Result---\n");
	printf("%d seconds\n", total);
	printf("%dh %dm %ds\n", h, m, s);

	return 0;
}