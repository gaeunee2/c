#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
void pick(char items[][7], int itemSize, int* bucket, int bucketSize, int k);

int main()
{
	int n, *bucket;
	char actor[5][7] = { "공유", "김수현", "송중기", "지성", "현빈" };

	printf("인기상 몇명? ");
	scanf("%d", &n);
	bucket = (int*)malloc(n * sizeof(int));

	pick(actor, 5, bucket, n, n);
	free(bucket);

	return 0;
}

void pick(char items[][7], int itemSize, int* bucket, int bucketSize, int k)
{
	int i, lastIndex, smallest;
	
	if (k == 0) {
		for (i = 0; i < bucketSize; i++)
			printf("%10s ", items[bucket[i]]);
		printf("\n");
		return;
	}

	lastIndex = bucketSize - k - 1;

	if (bucketSize == k)
		smallest = 0;
	else
		smallest = bucket[lastIndex] + 1;

	for (i = smallest; i < itemSize; i++) {
		bucket[lastIndex + 1] = i;
		pick(items, itemSize, bucket, bucketSize, k - 1);
	}
}