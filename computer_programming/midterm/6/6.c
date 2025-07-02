#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int maxIncreasing2(char s[])
{
	int i, j, k = 0;
	int length = 0, l = 0, g = 0;
	char w[20] = { 0 };

	for (i = 0; s[i] != '\0'; i++) {
		if (s[i] <= s[i + 1]) {
			w[k++] = s[i];
			length += 1;
		}
		else {
			w[k] = '\0';
			if (length >= l)
				l = length;
			length = 0;
			if (k > g)
				g = k;
			k = 0;
			for (j = 0; w[j] != '\0'; j++)
				w[j] = 0;
		}
	}
	for (i = 0; w[i] != '\0'; i++)
		printf("%c", w[i]);
	return l + 1;
}

int main(void) //변경하지 말라
{
	char s[50];

	scanf("%s", s);
	printf("%d\n", maxIncreasing2(s));
}