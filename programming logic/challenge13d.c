#define _CRT_SECURE_NO_WARNINGS
#define MAX_STRING 81 
#define BOOL int 
#define TRUE 1 
#define FALSE 0 
#include <stdio.h>
BOOL isPalindrome(char str[]);
int main(void)
{
	char str[MAX_STRING];

	printf("* Palindrome üũ\n\n");
	printf("���ڿ� �Է�(���ڼ� %d ����): ", MAX_STRING);
	scanf("%s", str);

	if (isPalindrome(str))
		printf("\"%s\" is a Palindrome\n\n", str);
	else
		printf("\"%s\" isn't a Palindrome\n\n", str);

	return 0;
}

BOOL isPalindrome(char s[])
{
    int i, start = 0, end;

    for (i = 0; s[i] != '\0'; i++);
    end = i - 1;

    while (start < end) {
        if (s[start] != s[end])
            return FALSE;
        start++;
        end--;
    }

    return TRUE;
}