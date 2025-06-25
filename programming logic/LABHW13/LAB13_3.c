#define _CRT_SECURE_NO_WARNINGS
#define SIZE 10
#include <stdio.h>
void selectionSort(int* arr, int size)
{
    int i, j, tmp, minIndex, min;

    for (i = 0; i < size - 1; i++) {
        min = arr[i];
        minIndex = i;
        for (j = i + 1; j < size; j++) {
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
    int odd[SIZE], even[SIZE];
    int num;
    int i, oddIndex = 0, evenIndex = 0;

    for (i = 0; i < SIZE; i++) {
        printf("Enter a number: ");
        scanf("%d", &num);

        if (num % 2 == 0)
            even[evenIndex++] = num;
        else
            odd[oddIndex++] = num;
    }

    selectionSort(odd, oddIndex);
    printf("\nÈ¦¼ö Ãâ·Â: ");
    for (i = 0; i < oddIndex; i++)
        printf("%d ", odd[i]);

    selectionSort(even, evenIndex);
    printf("\nÂ¦¼ö Ãâ·Â: ");
    for (i = 0; i < evenIndex; i++)
        printf("%d ", even[i]);
    printf("\n");

    return 0;
}