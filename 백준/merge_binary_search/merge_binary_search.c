#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 100001
int sorted[MAX_SIZE];
void merge(int* list, int left, int mid, int right) {
    int i, j, k, l;
    i = left;
    j = mid + 1;
    k = left;

    while (i <= mid && j <= right) {
        if (list[i] <= list[j])
            sorted[k++] = list[i++];
        else
            sorted[k++] = list[j++];
    }
    if (i > mid)
        for (l = j; l <= right; l++)
            sorted[k++] = list[l];
    else
        for (l = i; l <= mid; l++)
            sorted[k++] = list[l];

    for (l = left; l <= right; l++)
        list[l] = sorted[l];
}

void merge_sort(int* list, int left, int right) {
    int mid;

    if (left < right) {
        mid = (left + right) / 2;
        merge_sort(list, left, mid);
        merge_sort(list, mid + 1, right);
        merge(list, left, mid, right);
    }
}

int search_binary(int* list, int key, int low, int high) {
    int middle;
    if (low <= high) {
        middle = (low + high) / 2;
        if (key == list[middle])
            return middle;
        else if (key < list[middle])
            return search_binary(list, key, low, middle - 1);
        else
            return search_binary(list, key, middle + 1, high);
    }
    return -1;
}

int main(void)
{
    int i, n, m;
    int a[100001];
    int num;

    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    merge_sort(a, 0, n - 1);

    scanf("%d", &m);
    for (i = 0; i < m; i++) {
        scanf("%d", &num);

        if (search_binary(a, num, 0, n - 1) != -1)
            printf("1\n");
        else
            printf("0\n");
    }

    return 0;
}