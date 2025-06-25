#define _CRT_SECURE_NO_WARNINGS
#define MAX_STRING 81 
#include <stdio.h>
int main(void)
{
    char str[MAX_STRING];
    int countA = 0, countE = 0, countI = 0, countO = 0, countU = 0;
    int i;

    printf("문자열 입력 (문자수 %d 이하): ", MAX_STRING);
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
    printf("a or A: %d 개\n", countA);
    printf("e or E: %d 개\n", countE);
    printf("i or I: %d 개\n", countI);
    printf("o or O: %d 개\n", countO);
    printf("u or U: %d 개\n", countU);
    
    return 0;
}