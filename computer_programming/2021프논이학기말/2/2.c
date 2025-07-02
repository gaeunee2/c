#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int searchKey(char s[20], char key)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
		if (s[i] == key)
			break;

	if (s[i] == '\0')
		return -1;
	else
		return i + 1;
}
int main(void)
{
	char key, s[20];
	int i;

	scanf("%s %c", s, &key);
	printf("%d\n", searchKey(s, key));
}