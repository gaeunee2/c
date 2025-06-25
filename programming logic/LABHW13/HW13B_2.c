#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
    char word[81];
    int i, sum = 0;

    printf("Enter one word: ");
    scanf("%s", word);

    for (i = 0; word[i] != '\0'; i++)
        if (word[i] > '0' && word[i] <= '9')
            sum += word[i] - 48;

    printf("안에 있는 숫자들의 합은 %d\n", sum);

    return 0;
}