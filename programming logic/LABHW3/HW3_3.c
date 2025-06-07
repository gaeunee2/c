#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int total, h, m, s;

	printf("Enter h m s: ");
	scanf("%d %d %d", &h, &m, &s);
	
	total = h * 3600 + m * 60 + s;

	printf("---Calculation Result---\n");
	printf("Total %d seconds\n", total);

	return 0;
}