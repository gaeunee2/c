#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
    int k, temp, div;
    int count = 0;
    int num = 1;

    scanf("%d", &k);

    while (1) {
        temp = num;
        div = 1;

        while (temp / div >= 10) {
            div *= 10;
        }

        while (div > 0) {
            int digit = (temp / div) % 10;
            count++;
            if (count == k) {
                printf("%d\n", digit);
                return 0;
            }
            div /= 10;
        }
        num++;
    }

    return 0;
}