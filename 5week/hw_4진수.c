#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
void pick(int* items, int itemSize, int* bucket, int bucketSize, int k);

int main()
{
	int i, n, *bucket;
	int items[4] = { 0, 1, 2, 3 };

	printf("ют╥б: ");
	scanf("%d", &n);
	bucket = (int*)malloc(n * sizeof(int));
	for (i = 0; i < n; i++)
		bucket[i] = 0;

	pick(items, 4, bucket, n, n);
	free(bucket);

	return 0;
}

void pick(int item[], int itemSize, int bucket[], int bucketSize, int toPick) 
{
	int i, lastIndex;

	if (toPick == 0) {
		for (i = 0; i < bucketSize; i++)
			printf("%d ", item[bucket[i]]);
		printf("\n");
		return;
	}

	lastIndex = bucketSize - toPick - 1;
	for (i = 0; i < itemSize; i++) {
		bucket[lastIndex + 1] = i;
		pick(item, itemSize, bucket, bucketSize, toPick - 1);
	}
}