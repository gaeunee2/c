#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
typedef struct person {
    int age;
    char name[101];
}PERSON;

#define MAX_SIZE 100001
PERSON sorted[MAX_SIZE];

void merge(PERSON list[], int left, int mid, int right) {
    int i = left, j = mid + 1, k = left;

    while (i <= mid && j <= right) {
        if (list[i].age <= list[j].age)
            sorted[k++] = list[i++];
        else
            sorted[k++] = list[j++];
    }

    while (i <= mid)
        sorted[k++] = list[i++];
    while (j <= right)
        sorted[k++] = list[j++];

    for (i = left; i <= right; i++)
        list[i] = sorted[i];
}

void merge_sort(PERSON list[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        merge_sort(list, left, mid);
        merge_sort(list, mid + 1, right);
        merge(list, left, mid, right);
    }
}

int main(void)
{
    int i, n;
    PERSON s[MAX_SIZE];

    scanf("%d", &n);

    for (i = 0; i < n; i++)
        scanf("%d %s", &s[i].age, s[i].name);

    merge_sort(s, 0, n - 1);

    for (i = 0; i < n; i++)
        printf("%d %s\n", s[i].age, s[i].name);

    return 0;
}