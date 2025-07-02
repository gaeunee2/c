#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int is_word_in_word(char w1[], int start, char w2[])
{
	int i;

	if (w1[start] == w2[0]) {
		for (i = 1; w2[i] != '\0'; i++)
			if (w1[start + i] != w2[i])
				return 0;
		return 1;
	}
	else
		return 0;
}

int main(void)
{
	char s1[20], s2[20];
	int i, j;

	scanf("%s", s1);
	scanf("%s", s2);

	for (i = 0; s1[i] != '\0'; i++)
		printf("%d", is_word_in_word(s1, i, s2));
}