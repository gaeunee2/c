#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
    int a, b;
    int temp, found;

    scanf("%d", &a);
    scanf("%d", &b);

    temp = a;
    found = 0;

    while (temp != 0) {
        if (temp % 10 == b % 10) {
            int na = temp;
            int nb = b;
            while (nb != 0 && na % 10 == nb % 10) {
                na /= 10;
                nb /= 10;
            }
            if (nb == 0) {
                found = 1;
                break;
            }
        }
        temp /= 10;
    }

    if (found)
        printf("%d\n", temp);
    else
        printf("0\n");

    return 0;
}