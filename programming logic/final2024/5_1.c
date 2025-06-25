#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h> 
int decodeStr(char s[], char s2[])
{
	int i, j, count, index = 0;

	for (i = 0; s[i] != '\0'; i++) {
		if (s[i] >= '1' && s[i] <= '9') {
			count = s[i] - '1' + 1;
			for (j = 0; j < count; j++)
				s2[index++] = s[i + 1];
			i += 1;
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