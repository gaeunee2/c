#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int i, num = 0;
	char str[100];

	printf("Enter one word: ");
	scanf("%s", str);

	for (i = 0; str[i] != '\0'; i++) {
		if (str[i] >= '0' && str[i] <= '9')
			num += str[i] - 48;
	}

	printf("�ȿ� �ִ� ���ڵ��� ���� %d\n", num);

	return 0;
}