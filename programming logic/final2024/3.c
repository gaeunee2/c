#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h> 
int isPassword(char s1[], char s2[])
{
	int i, j, len;

	for (i = 0; s2[i] != '\0'; i++);
	len = i;

	j = 3;
	for (i = len - 1; i > len - 5; i--) {
		if (s2[i] != s1[j])
			return 0;
		j--;
	}
	return 1;
}

int main(void)
{
	char password[5];
	char inputPassword[20];

	scanf("%s", password);

	for (int i = 0; i < 4; i++) {
		scanf("%s", inputPassword);
		printf("%d\n", isPassword(password, inputPassword));
	}
}