#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int month, days;

	scanf("%d", &month);

	if (month < 1 || month>12) {
		printf("invalid month\n");
		return 0;
	}
	else {
		switch (month) {
		case 2:
			days = 28;
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			days = 30;
			break;
		default:
			days = 31;
			break;
		}
	}
	printf("%d\n", days);

	return 0;
}