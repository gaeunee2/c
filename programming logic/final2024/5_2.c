#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h> 
int decodeStr(char s[], char s2[])
{
	int i, j, count, index = 0;
	int ci;

	for (i = 0; s[i] != '\0'; i++) {
		if (s[i] >= '1' && s[i] <= '9') {
			ci = i;
			count = 0;
			while (s[ci] >= '1' && s[ci] <= '9') {
				count *= 10;
				count += s[ci] - '1' + 1;
				ci++;
				i++;
			}
			for (j = 0; j < count; j++)
				s2[index++] = s[i];
		}
		else
			s2[index++] = s[i];
	}
	s2[index] = '\0';

	return index;
}

int main(void)
{
	char s[30], s2[300];

	scanf("%s", s);

	printf("%d ", decodeStr(s, s2));
	printf("%s\n", s2);
}