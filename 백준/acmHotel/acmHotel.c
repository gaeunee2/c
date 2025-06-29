#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int i, t;
    int h, w, n;
    int rslt;

    scanf("%d", &t);

    for (i = 0; i < t; i++) {
        rslt = 0;
        scanf("%d %d %d", &h, &w, &n);

        if (n % h == 0) {
            rslt += h * 100;
            rslt += n / h;
        }
        else {
            rslt += n % h * 100;
            rslt += n / h + 1;
        }

        printf("%d\n", rslt);
    }

    return 0;
}