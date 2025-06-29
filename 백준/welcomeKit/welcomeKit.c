#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void)
{
    int i, n;
    int shirt[7];
    int t, p;
    int tNum = 0, pNum1, pNum2;

    scanf("%d", &n);
    for (i = 0; i < 6; i++)
        scanf("%d", &shirt[i]);
    scanf("%d %d", &t, &p);

    for (i = 0; i < 6; i++) {
        if (shirt[i] != 0) {
            if (shirt[i] % t == 0)
                tNum += shirt[i] / t;
            else
                tNum += shirt[i] / t + 1;
        }
    }
    pNum1 = n / p;
    pNum2 = n % p;

    printf("%d\n%d %d\n", tNum, pNum1, pNum2);

    return 0;
}