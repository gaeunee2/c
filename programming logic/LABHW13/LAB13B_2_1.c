#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
    char str[100];

    printf("Enter one word: ");
    scanf("%s", str);

    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] >= 'A' && str[i] <= 'Z')
            printf("%c\n", str[i]);

    return 0;
}