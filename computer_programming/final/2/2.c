#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void extractDigits(char* p1, char* p2)
{
	int i;
	for (i = 1; *p1 != '\0'; i++) {
		if (*p1 == '1' || *p1 == '2' || *p1 == '3' || *p1 == '4' || *p1 == '5' || *p1 == '6' || *p1 == '7' || *p1 == '8' || *p1 == '9' || *p1 == '0') {
			*p2 = *p1;
			p2++;
		}
		p1++;
	}
	*p2 = '\0';
}
int main(void) // 변경하지 말라
{
	char str[20], numStr[20];

	scanf("%s", str);

	extractDigits(str, numStr);
	printf("%send\n", numStr);
}