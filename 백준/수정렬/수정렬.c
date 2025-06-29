#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int compare(const void* a, const void* b) {
    int x = *(int*)a;
    int y = *(int*)b;

    return (x > y) - (x < y);
}

int main(void)
{
    int i, n;

    scanf("%d", &n);
    int* a = malloc(sizeof(int) * n);

    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    qsort(a, n, sizeof(a[0]), compare);

    printf("%d\n", a[0]);
    for (i = 1; i < n; i++)
        if (a[i] != a[i - 1])
            printf("%d\n", a[i]);

    free(a);
    return 0;
}