#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct DataType {
	int x;
	int y;
}DataType;

int compare(const void* a, const void* b) {
	DataType* d1 = (DataType*)a;
	DataType* d2 = (DataType*)b;

	if (d1->x != d2->x)
		return d1->x - d2->x;
	else
		return d1->y - d2->y;
}

int main(void)
{
	int i, n;

	scanf("%d", &n);
	DataType* arr = (DataType*)malloc(sizeof(DataType) * n);

	for (i = 0; i < n; i++)
		scanf("%d %d", &arr[i].x, &arr[i].y);
	qsort(arr, n, sizeof(DataType), compare);

	for (i = 0; i < n; i++)
		printf("%d %d\n", arr[i].x, arr[i].y);

	free(arr);
	return 0;
}