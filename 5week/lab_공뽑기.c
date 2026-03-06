#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
void pick(int* items, int itemSize, int* bucket, int bucketSize, int k);

int main()
{
	char items[7] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G' };
	int bucket[3];

	pick(items, 7, bucket, 3, 3);

	return 0;
}

void pick(char* items, int itemSize, int* bucket, int bucketSize, int k)
{
	int i, lastIndex, smallest, item;

	if (k == 0) {
		for (i = 0; i < bucketSize; i++)
			printf("%c ", items[bucket[i]]);
		printf("\n");
		return;
	}

	lastIndex = bucketSize - k - 1;
	if (bucketSize == k)
		smallest = 0;
	else
		smallest = bucket[lastIndex] + 1;

	for (item = smallest; item < itemSize; item++) {
		bucket[lastIndex + 1] = item;
		pick(items, itemSize, bucket, bucketSize, k - 1);
	}
}