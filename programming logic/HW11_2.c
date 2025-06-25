#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int pow(int a, int b);
int main(void)
{
	int i;

	for (i = 0; i <= 10; i++)
		printf("%d ^ %d == %d\n", 5, i, pow(5, i));

	return 0;
}

int pow(int a, int b)
{
	int i, rslt = 1;

	for (i = 0; i < b; i++)
		rslt *= a;

	return rslt;
}