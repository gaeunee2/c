#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
void pick(int* items, int itemSize, int* bucket, int bucketSize, int k);

int main()
{
	int i, n, * bucket;
	char items[2] = { '+', '-' };

	printf("ют╥б: ");
	scanf("%d", &n);

	bucket = (int*)malloc(n * sizeof(int));

	pick(items, 2, bucket, n, n);

	free(bucket);

	return 0;
}

void pick(char* items, int itemSize, int* bucket, int bucketSize, int k)
{
	int i, lastIndex, sum;

	if (k == 0) {
		sum = 0;
		for (i = 0; i < bucketSize; i++) {
			printf("%c%d", items[bucket[i]], i + 1);
			if (items[bucket[i]] == '+')
				sum += (i + 1);
			else
				sum -= (i + 1);
		}
		printf(" = %d\n", sum);
		return;
	}
	lastIndex = bucketSize - k - 1;

	for(i = 0; i < itemSize; i++) {
		bucket[lastIndex + 1] = i;
		pick(items, itemSize, bucket, bucketSize, k - 1);
	}
}