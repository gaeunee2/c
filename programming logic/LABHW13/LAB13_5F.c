#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
void printArray(int a[], int size);
void reverse(int a[], int size);

int main(void)
{
    int binary[8];
    int num;
    int bIndex = 0;

    printf("Enter ¾ç¼ö(<256):");
    scanf("%d", &num);

    while (num > 0) {
        binary[bIndex++] = num % 2;
        num /= 2;
    }

    reverse(binary, bIndex);
    printArray(binary, bIndex);

    return 0;
}

void printArray(int a[], int size)
{
    int i;

    for (i = 0; i < size; i++)
        printf("%d", a[i]);
    printf("\n");

    return;
}

void reverse(int a[], int size)
{
    int i, tmp;

    for (i = 0; i < size / 2; i++) {
        tmp = a[i];
        a[i] = a[size - i - 1];
        a[size - i - 1] = tmp;
    }

    return;
}