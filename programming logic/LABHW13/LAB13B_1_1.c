#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
    char s[80];
    int i, len;

    printf("Enter a string: ");
    scanf("%s", s);

    for (i = 0; s[i] != '\0'; i++);
    len = i;

    printf("±æÀÌ´Â %d\n", len);

    for (i = len - 1; i >= 0; i--)
        printf("%c\n", s[i]);

    return 0;
}