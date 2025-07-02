#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void mergeString(char c[], char a[], char b[])
{
    int lenA, lenB;
    int i, j = 0, k = 0;

    for (i = 0; a[i] != '\0'; i++);
    lenA = i;
    for (i = 0; b[i] != '\0'; i++);
    lenB = i;

    i = 0;
    while (i < lenA && j < lenB)
        if (a[i] < b[j])
            c[k++] = a[i++];
        else
            c[k++] = b[j++];

    while (i < lenA)
        c[k++] = a[i++];

    while (j < lenB)
        c[k++] = b[j++];

    c[k] = '\0';
}

int main(void)
{
	char word1[10], word2[10];
	char mergedWord[20];

	scanf("%s", word1);
	scanf("%s", word2);
	mergeString(mergedWord, word1, word2);
	printf("%s\n", mergedWord);
}