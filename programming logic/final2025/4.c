#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) // 변경해도 된다.
{
	char s[100];
	int i, j, temp, minIndex, min, index = 0;

	scanf("%s", s);

	char alpha[100];

	for (i = 0; s[i] != '\0'; i++)
		if (s[i] >= 'a' && s[i] <= 'z')
			alpha[index++] = s[i];
	alpha[index] = '\0';

	if (index != 0) {
		for (i = 0; i < index - 1; i++) {
			min = alpha[i];
			minIndex = i;
			for (j = i + 1; j < index; j++)
				if (alpha[j] < min) {
					min = alpha[j];
					minIndex = j;
				}
			temp = alpha[i];
			alpha[i] = alpha[minIndex];
			alpha[minIndex] = temp;
		}
		printf("%s=\n", alpha);
	}
	else
		printf("=\n");
}