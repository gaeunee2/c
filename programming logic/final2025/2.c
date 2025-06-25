#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int searchKey(char s[], char key) // 이 함수를 작성
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
		if (s[i] == key)
			return i;
	return -1;
}
int main(void) // 변경하지 말라
{
	char str[30];
	char key;
	int keyIndex;
	scanf("%s %c", str, &key);

	if ((keyIndex = searchKey(str, key)) == -1)
		printf("%d\n", -1);
	else
		printf("%d\n", keyIndex + 1);
}