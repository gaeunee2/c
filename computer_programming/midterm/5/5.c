#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int maxIncreasing(char s[])
{
	int i, j;
	int length = 0, l = 0;

	for (i = 0; s[i] != '\0'; i++) {
		if (s[i] <= s[i + 1]) {
			length += 1;
		}
		else {
			if (length >= l)
				l = length;
			length = 0;
		}
	}
	return l + 1;
}

int main(void) // 변경하지 마라
{
	char s[50];

	scanf("%s", s);
	printf("%d\n", maxIncreasing(s));
}