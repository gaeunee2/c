#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int scores[21], low[21], high[21];
	int i, n, standard;
	
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &scores[i]);
	scanf("\n%d", &standard);

	int x = 0;
	int y = 0;
	for (i = 0; i < n; i++) {
		if (scores[i] < standard)
			low[x++] = scores[i];
		else
			high[y++] = scores[i];
	}
	for (i = 0; i < x; i++)
		printf("%d ", low[i]);
	printf("\n");
	for (i = 0; i < y; i++)
		printf("%d ", high[i]);
	printf("\n");

	return 0;
}