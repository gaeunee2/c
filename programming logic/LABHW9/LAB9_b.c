#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
int main(void)
{
    int n1, n2;
    int userAnswer, rightAnswer;

    srand(time(NULL));
    
    n1 = rand() % 100;
    n2 = rand() % 100;
    rightAnswer = n1 + n2;

    printf("%d + %d = ", n1, n2);
    scanf("%d", &userAnswer);

    if (userAnswer == rightAnswer)
        printf("Your answer is right.\n");
    else {
        printf("Your answer is wrong.\n");
        printf("%d is the right answer\n", rightAnswer);
    }

    return 0;
}