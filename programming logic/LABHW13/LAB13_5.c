#define _CRT_SECURE_NO_WARNINGS
#define SIZE 8
#include <stdio.h>
int main(void)
{
    int i, j, num;
    int binary[SIZE];

    printf("Enter ¾ç¼ö<<256>: ");
    scanf("%d", &num);

    if (num == 0) {
        printf("0\n");
        return 0;
    }

    i = 0;
    while (num > 0) {
        binary[i] = num % 2;
        num /= 2;
        i++;
    }

    for (j = i - 1; j >= 0; j--)
        printf("%d", binary[j]);
    printf("\n");

    return 0;
}