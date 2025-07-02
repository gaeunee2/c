#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int i, j;
	char word[81], newWord[81];

	printf("Enter one word: ");
	scanf("%s", word);

	for (i = 0; word[i] != '\0'; i++);

	for (j = i - 1; j >= 0; j--)
		newWord[i - 1 - j] = word[j];
	newWord[i] = '\0';

	printf("The reversed word is %s\n", newWord);
}