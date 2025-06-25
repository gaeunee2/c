#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
    int incomes[12];
    int i, key, found = 0;

    for (i = 0; i < 12; i++) {
        if (i < 6)
            incomes[i] = 11 * (i + 1);
        else
            incomes[i] = 11 * (i - 5);
    }

    printf("탐색할 수입은? ");
    scanf("%d", &key);

    for (i = 0; i < 12; i++) {
        if (key == incomes[i]) {
            found = 1;
            break;
        }
    }

    if (found)
        printf("수입 %d를 갖는 첫번째 달은 %d월입니다\n", key, i + 1);
    else
        printf("수입 %d를 갖는 달은 없습니다\n", key);

    return 0;
}