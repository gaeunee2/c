#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
    char word[81];
    int i = 0, sum = 0, num = 0, in_number = 0;

    printf("Enter a word: ");
    scanf("%s", word);

    while (word[i] != '\0') {
        if (word[i] >= '0' && word[i] <= '9') {
            num = num * 10 + (word[i] - '0');
            in_number = 1;
        }
        else {
            if (in_number) {
                sum += num;
                num = 0;
                in_number = 0;
            }
        }
        i++;
    }
    if (in_number)
        sum += num;

    printf("글자 안의 수의 합은 %d\n", sum);

    return 0;
}