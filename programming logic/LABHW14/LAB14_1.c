#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 

void generateData(int[], int);
void printData(int[], int);
int averageData(int[], int);
int maxData(int[], int);

int main(void)
{
    int data[10]; 

    srand(time(NULL)); 
    generateData(data, 10);

    printf("엘리먼트들은 ");
    printData(data, 10);

    printf("엘리먼트의 평균은 %d\n", averageData(data, 10));

    printf("엘리먼트들 중 가장 큰수는 %d\n", maxData(data, 10));

    return 0;
}

void generateData(int a0[], int size)
{
    int i;

    for (i = 0; i < size; i++)
        a0[i] = rand(time(NULL)) % 100;

    return;
}

void printData(int a2[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", a2[i]);
    printf("\n");

    return;
}

int averageData(int a1[], int size)
{
    int i, sum = 0;

    for (i = 0; i < size; i++)
        sum += a1[i];

    return sum / (size - 1);
}

int maxData(int a3[], int size)
{
    int i, best = a3[0];

    for (i = 0; i < size; i++)
        if (best < a3[i])
            best = a3[i];

    return best;
}