#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char s[500001][21]; // 듣도 못한 사람
char l[500001][21]; // 보도 못한 사람
char b[500001][21]; // 듣보잡 저장
int bIndex = 0;

int compare(const void* a, const void* b) {
    return strcmp((char*)a, (char*)b);
}

int binary_search(int n, char target[]) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        int cmp = strcmp(s[mid], target);
        if (cmp == 0) return 1;
        else if (cmp < 0) left = mid + 1;
        else right = mid - 1;
    }
    return 0;
}

int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++)
        scanf("%s", s[i]);
    qsort(s, n, sizeof(s[0]), compare); // 정렬

    for (int i = 0; i < m; i++) {
        scanf("%s", l[i]);
        if (binary_search(n, l[i])) {
            strcpy(b[bIndex++], l[i]);
        }
    }

    qsort(b, bIndex, sizeof(b[0]), compare); // 듣보잡 정렬
    printf("%d\n", bIndex);
    for (int i = 0; i < bIndex; i++)
        printf("%s\n", b[i]);

    return 0;
}