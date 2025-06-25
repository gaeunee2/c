#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int n, l;
	int i, j, k;
	int sum;
	int arr[31];
	int length = 31;
	int flag = 0;

	scanf("%d %d", &n, &l);

	for (i = 0; i < 1000001; i++) {
		sum = 0;
		for (j = i; sum <= n; j++) {
			if (sum == n && j - i >= l && j - i < length) {
				for (k = 0; k < j - i; k++)
					arr[k] = i + k;
				flag = 1;
				length = j - i;
			}
			if (j > 30 + i)
				break;
			sum += j;
		}
	}
	if (flag) {
		for (i = 0; i < length; i++)
			printf("%d ", arr[i]);
		printf("\n");
	}
	else
		printf("-1\n");

	return 0;
}