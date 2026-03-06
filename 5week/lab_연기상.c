#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
void pick(char items[][7], int itemSize, int* bucket, int bucketSize, int k);

int main()
{
	int i, n, *bucket;
	char actor[5][7] = { "공유", "김수현", "송중기", "지성", "현빈" };

	printf("상의 종류는? ");
	scanf("%d", &n);

	for (i = 0; i < n; i++)
		printf("\t상 %d", (i + 1));
	printf("\n");

	bucket = (int*)malloc(n * sizeof(int));

	pick(actor, 5, bucket, n, n);
	free(bucket);

	return 0;
}

void pick(char items[][7], int itemSize, int* bucket, int bucketSize, int k)
{
	int i, j, lastIndex, smallest;

	if (k == 0) {
		for (i = 0; i < bucketSize; i++)
			printf("%10s", items[bucket[i]]);
		printf("\n");
		return;
	}

	lastIndex = bucketSize - k - 1;
	smallest = 0;

	for (i = smallest; i < itemSize; i++) {
		int flag = 0;
		for (j = 0; j <= lastIndex; j++) {
			if (bucket[j] == i) {
				flag = 1;
				break;
			}
		}
		if (flag == 1)
			continue;

		bucket[lastIndex + 1] = i;
		pick(items, itemSize, bucket, bucketSize, k - 1);
	}
}