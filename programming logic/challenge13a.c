#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
    char word1[11], word2[11];
    int i, j, flag = 0;

    printf("Enter the first word: ");
    scanf("%s", word1);
    printf("Enter the second word: ");
    scanf("%s", word2);

    for (i = 0; word1[i] != '\0'; i++);
    for (j = 0; word2[j] != '\0'; j++);

    if (i != j) {
        printf("�� ���� �ٸ���\n");
        return 0;
    }
    
    for (i = 0; word1[i] != '\0'; i++) {
        if (word1[i] != word2[i]) {
            flag = 1;
            break;
        }
    }
    if (flag == 1)
        printf("�� ���� �ٸ���\n");
    else
        printf("�� ���� ����\n");

    return 0;
}