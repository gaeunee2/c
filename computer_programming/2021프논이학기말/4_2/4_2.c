#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void changeToDigitEncode(char s[], char e[]);
int main(void)
{
	char words[20], encoded[40];

	scanf("%s", words);
	changeToDigitEncode(words, encoded);
	printf("%s\n", encoded);
}

void changeToDigitEncode(char s[], char e[])
{
	int i, j = 0;
	int score;

	for (i = 0; s[i] != '\0'; i++) {
		score = s[i] - 64;
		if (score >= 10) {
			e[j++] = score / 10 + 48;
			e[j++] = score % 10 + 48;
		}
		else
			e[j++] = score + 48;
	}
	e[j] = '\0';
}