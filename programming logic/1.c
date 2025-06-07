#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int bloodSugar, result;

	scanf("%d", &bloodSugar);

	if (bloodSugar > 100)
		result = 1;
	else if (bloodSugar >= 90)
		result = 0;
	else
		result = -1;

	printf("%d\n", result);

	return 0;
}