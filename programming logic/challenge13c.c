#define _CRT_SECURE_NO_WARNINGS
#define MAX_STRING 81 
#include <stdio.h>
int main(void)
{
    char str[MAX_STRING];
    int countA = 0, countE = 0, countI = 0, countO = 0, countU = 0;
    int i;

    printf("���ڿ� �Է� (���ڼ� %d ����): ", MAX_STRING);
    scanf("%s", str);

    for (i = 0; str[i] != '\0'; i++) {
        switch (str[i]) {
        case 'a':
        case 'A':
            countA += 1;
            break;
        case 'e':
        case 'E':
            countE += 1;
            break;
        case 'i':
        case 'I':
            countI += 1;
            break;
        case 'o':
        case 'O':
            countO += 1;
            break;
        case 'u':
        case 'U':
            countU += 1;
            break;
        default:
            break;
        }
    }
    printf("a or A: %d ��\n", countA);
    printf("e or E: %d ��\n", countE);
    printf("i or I: %d ��\n", countI);
    printf("o or O: %d ��\n", countO);
    printf("u or U: %d ��\n", countU);
    
    return 0;
}