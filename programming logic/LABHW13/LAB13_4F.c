#define _CRT_SECURE_NO_WARNINGS
#define SIZE 10
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void selectionSort(int* arr)
{
    int i, j, tmp, minIndex, min;
    for (i = 0; i < SIZE - 1; i++) {
        min = arr[i];
        minIndex = i;
        for (j = i + 1; j < SIZE; j++) {
            if (arr[j] < min) {
                min = arr[j];
                minIndex = j;
            }
        }
        tmp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = tmp;
    }
}

int main(void)
{
    int arr[SIZE];
    int i;

    srand(time(NULL));
    for (i = 0; i < SIZE; i++)
        arr[i] = rand() % 100;

    selectionSort(arr);

    for (i = 0; i < SIZE; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}