#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int compare(const void* a, const void* b) {
	const char* c1 = (const char*)a;
	const char* c2 = (const char*)b;

	int len1 = strlen(c1);
	int len2 = strlen(c2);

	if (len1 != len2)
		return len1 - len2;
	return strcmp(c1, c2);
}

int main(void)
{
	int i, n;
	char arr[20001][51];

	scanf("%d", &n);

	for (i = 0; i < n; i++)
		scanf("%s", arr[i]);
	qsort(arr, n, sizeof(arr[0]), compare);

	for (i = 0; i < n; i++)
		if (strcmp(arr[i], arr[i - 1]) != 0)
			printf("%s\n", arr[i]);

	return 0;
}