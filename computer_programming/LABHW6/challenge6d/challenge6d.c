#define _CRT_SECURE_NO_WARNINGS
#define MAX_STRING 81
#define BOOL int 
#define TRUE 1 
#define FALSE 0 
#include <stdio.h>

int main(void)
{
	char str[MAX_STRING];

	printf("* Palindrome 체크\n\n");
	printf("문자열 입력<문자수 %d 이하>: ", MAX_STRING);
	scanf("%s", str);

	if (isPalindrome(str))
		printf("\"%s\" is a Palindrome\n\n", str);
	else
		printf("\"%s\" isn't a Palindrome\n\n", str);

	return 0;
}

BOOL isPalindrome(char s[])
{
	int i, j;
	for (i = 0; s[i] != '\0'; i++);

	for (j = 0; j < i / 2; j++)
		if (s[j] != s[i - 1 - j])
			return FALSE;
	return TRUE;
}