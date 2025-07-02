#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int solution(char* s)
{
	char ss[1001];
	int i, j = 0, num = 1;
	for (i = 0; s[i] != '\0'; i++) {
		if (s[i] == s[i + 1]) {
			num += 1;
		}
		else {
			if (num > 1) {
				printf("%d%c", num, s[i]);
				ss[j++] = num;
				ss[j++] = s[i];
			}
			else {
				printf("%c", s[i]);
				s[j++] = s[i];
			}
			num = 1;
		}
	}
	return j;
}

int main(void)
{
	char s[1001];
	scanf("%s", s);
	printf("\n%d\n", solution(s)); // ¹®Á¦-1)
}