#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char s[9];
    int i, index, num, nextNum;

    for (i = 0; i < 3; i++) {
        scanf("%s", s);

        if (strcmp(s, "FizzBuzz") != 0 &&
            strcmp(s, "Fizz") != 0 &&
            strcmp(s, "Buzz") != 0) {
            num = atoi(s);
            index = i;
        }
    }
    nextNum = 3 - index + num;

    if (nextNum % 3 == 0 && nextNum % 5 == 0)
        printf("FizzBuzz\n");
    else if (nextNum % 3 == 0)
        printf("Fizz\n");
    else if (nextNum % 5 == 0)
        printf("Buzz\n");
    else
        printf("%d\n", nextNum);

    return 0;
}