#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int bp;

	scanf("%d", &bp);

	if (bp >= 80 && bp <= 120)
		printf("1\n");
	else
		printf("0\n");

	return 0;
}
