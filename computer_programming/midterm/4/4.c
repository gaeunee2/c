#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	char a[20], b[20], c[20];
	int i, j, k;

	scanf("%s", a);
	scanf("%s", b);

	for (i = 0; a[i] != '\0'; i++);
	for (j = 0; b[j] != '\0'; j++);

	k = 0;
	if (i > j) {
		for (i = 0; b[i] != '\0'; i++) {
			if (a[i] < b[i])
				c[k++] = a[i];
			else
				c[k++] = b[i];
		}
		for (i = k; a[i] != '\0'; i++)
			c[k++] = a[i];
		c[k] = '\0';
	}
	else {
		for (i = 0; a[i] != '\0'; i++) {
			if (a[i] < b[i])
				c[k++] = a[i];
			else
				c[k++] = b[i];
		}
		for (i = k; b[i] != '\0'; i++)
			c[k++] = b[i];
		c[k] = '\0';
	}

	printf("%s\n", c); 
}