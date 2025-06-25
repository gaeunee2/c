#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
    char s[100];
    int max = -1;
    int i = 0, sum = 0, num = 0, in_number = 0;
-
    scanf("%s", s);

    while (s[i] != '\0') {
        if (s[i] >= '0' && s[i] <= '9') {
            num = num * 10 + (s[i] - '0');
            in_number = 1;
        }
        else {
            if (in_number) {
                if (num > max)
                    max = num;
                num = 0;
                in_number = 0;
            }
        }
        i++;
    }
    if (in_number)
        if (num > max)
            max = num;

    if (max == -1)
        printf("0\n");
    else
        printf("%d\n", max);

    return 0;
}