#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void changeToDigitEncode(char s[], char e[]);
int main(void)
{
	char words[20], encoded[40];

	scanf("%s", words);
    changeToDigitEncode(words, encoded);
    printf("%s\n", encoded);

    return 0;
}

void changeToDigitEncode(char s[], char e[])
{
    int i;

    for(i = 0; s[i] != '\0'; i++)
        e[i] = s[i] - 16;
    e[i] = '\0';

    return 0;
}