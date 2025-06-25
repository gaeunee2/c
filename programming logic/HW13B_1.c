#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
    char word[81], newWord[81];
    int i, j = 0;

    printf("Enter one word: ");
    scanf("%s", word);

    for (i = 0; word[i] != '\0'; i++) {
        if (word[i] >= 'A' && word[i] < 'a')
            newWord[j++] = word[i] + 32;
        else if (word[i] >= 'a' && word[i] <= 'z')
            newWord[j++] = word[i] - 32;
        else
            newWord[j++] = word[i];
    }
    newWord[j] = '\0';

    printf("word given: %s\n", word);
    printf("new word: %s\n", newWord);

    return 0;
}