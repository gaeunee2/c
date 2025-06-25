#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
    int i, j, num, arr[10];

    scanf("%d", &num);
    num *= 9;

    i = 0;
    while (num != 0) {
        arr[i++] = num % 10;
        num /= 10;
    }

    for (j = i - 1; j >= 0; j--)
        printf("%d ", arr[j]);
    printf("\n");
    
    return 0;
}