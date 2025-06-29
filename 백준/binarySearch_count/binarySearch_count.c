#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int compare(const void* a, const void* b) {
    int x = *(int*)a;
    int y = *(int*)b;

    return (x > y) - (x < y);
}

int lower_bound(int* arr, int size, int key) {
    int low = 0, high = size;
    while (low < high) {
        int mid = (low + high) / 2;
        if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid;
    }
    return low;
}

int upper_bound(int* arr, int size, int key) {
    int low = 0, high = size;
    while (low < high) {
        int mid = (low + high) / 2;
        if (arr[mid] <= key)
            low = mid + 1;
        else
            high = mid;
    }
    return low;
}

int main(void)
{
    int i, n, m, count;

    scanf("%d", &n);
    int* a = malloc(sizeof(int) * n);

    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    qsort(a, n, sizeof(a[0]), compare);

    scanf("%d", &m);
    int* b = malloc(sizeof(int) * m);

    for (i = 0; i < m; i++)
        scanf("%d", &b[i]);

    for (i = 0; i < m; i++) {
        int low = lower_bound(a, n, b[i]);
        int up = upper_bound(a, n, b[i]);
        printf("%d ", up - low);
    }
    printf("\n");

    free(a);
    free(b);
    return 0;
}