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

    printf("Ž���� ������? ");
    scanf("%d", &key);

    for (i = 0; i < 12; i++) {
        if (key == incomes[i]) {
            found = 1;
            break;
        }
    }

    if (found)
        printf("���� %d�� ���� ù��° ���� %d���Դϴ�\n", key, i + 1);
    else
        printf("���� %d�� ���� ���� �����ϴ�\n", key);

    return 0;
}