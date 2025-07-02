#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int i, num = 0;
	int answer = 0;
	char str[100];

	printf("Enter a word: ");
	scanf("%s", str);

	for (i = 0; str[i] != '\0'; i++) {
		if (str[i] >= '0' && str[i] <= '9')
			num = num * 10 + (str[i] - '0');

		else {
			answer += num;
			num = 0;
		}
	}
	answer += num;

	printf("글자 안의 수의 합은 %d\n", answer);

	return 0;
}