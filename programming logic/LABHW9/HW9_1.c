#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <stdlib.h> 
int main(void)
{
    int n1, n2, opNum;
    int userAnswer, rightAnswer;
    char ch, op;

    do {
        srand(time(NULL));

        n1 = rand() % 100;
        n2 = rand() % 100;
        opNum = rand() % 4;

        switch (opNum) {
        case 0:
            op = '+';
            rightAnswer = n1 + n2;
            break;
        case 1:
            op = '-';
            rightAnswer = n1 - n2;
            break;
        case 2:
            op = '*';
            rightAnswer = n1 * n2;
            break;
        case 3:
            op = '/';
            rightAnswer = n1 / n2;
        default:
            break;
        }

        printf("%d %c %d = ", n1, op, n2);
        scanf("%d", &userAnswer);

        if (userAnswer == rightAnswer)
            printf("Your answer is right.\n");
        else {
            printf("Your answer is wrong.\n");
            printf("%d is the right answer\n", rightAnswer);
        }

        while (getchar() != '\n');
        printf("Do you want to continue(y/n)?");
        scanf("%c", &ch);
    } while (ch == 'y');

    return 0;
}
