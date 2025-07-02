#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 

int sumUpData(int*, int);
void printData(int*, int);
int maxData(int*, int);

void main()
{
    int k;
    int* p;
    int sum;
    int data[10];

    p = data; //혹은 p = &data[0]  
    srand(time(NULL));

    for (k = 0; k < 10; k++)
        *p++ = rand() % 100;

    sum = sumUpData(data, 10);
    printf("엘리먼트의 합은 %d\n", sum);

    printf("엘리먼트들은 ");
    printData(data, 10);

    printf("\n엘리먼트들 중 가장 큰수는 %d \n", maxData(data, 10));
}

int sumUpData(int* p, int size)
{
    int i, sum = 0;
    for (i = 0; i < size; i++)
        sum += *p++;
    return sum;
}

void printData(int* p, int size)
{
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", *p);
        p++;
    }
}

int maxData(int* p, int size)
{
    int i, max = *p;
    for (i = 1; i < size; i++) {
        if (max < *p)
            max = *p;
        p++;
    }
    return max;
}