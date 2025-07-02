#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

char firstDigit(char* p1)
{
	int i;
	for (i = 0; *p1 != '\0'; i++) {
		if (*p1 == '1' || *p1 == '2' || *p1 == '3' || *p1 == '4' || *p1 == '5' || *p1 == '6' || *p1 == '7' || *p1 == '8' || *p1 == '9' || *p1 == '0')
			return *p1;
		p1++;
	}
	return 'x';
}

int main(void) // 변경하지 말라
{
	char str[20];
	char numStr[20];

	scanf("%s", str);
	printf("%c\n", firstDigit(str)); // 문제-1)
}