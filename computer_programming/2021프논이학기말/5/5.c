#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int isHiddenPassword(char passwd[], char input[]);
int main(void)
{
	char pass[20], in[20];
	int i;

	scanf("%s", pass);
	for (i = 0; i < 3; i++) {
		scanf("%s", in);
		if (isHiddenPassword(pass, in))
			printf("1");
		else
			printf("0");
	}
	printf("\n");
}

int isHiddenPassword(char passwd[], char input[])
{
	int i = 0;
	int j = 0;

	while (passwd[i] != '\0' && input[j] != '\0') {
		if (passwd[i] == input[j])
			i++;
		j++;
	}
	if (passwd[i] == '\0')
		return 1;
	else
		return 0;
}