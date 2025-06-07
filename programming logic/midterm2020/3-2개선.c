#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
    int i, n, sum;

    scanf("%d", &n);

    if (n < 5) {
        sum = n * (n + 1) / 2;
        printf("1 - %d까지 합 = %d\n", n, sum);
    }
    else {
        for (i = 5; i <= n; i += 5) {
            sum = (i * (i + 1) / 2) - ((i - 5) * (i - 4) / 2);
            printf("%d - %d까지 합 = %d\n", i - 4, i, sum);
        }
        if (n % 5 != 0) {
            sum = (n * (n + 1) / 2) - ((i - 5) * (i - 4) / 2);
            printf("%d - %d까지 합 = %d\n", i - 4, n, sum);
        }
    }

    return 0;
}