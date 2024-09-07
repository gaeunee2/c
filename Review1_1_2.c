#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void reverse_string(char* str, int s, int e)
{
	char tmp;

	while (s < e) {
		tmp = str[s];
		str[s] = str[e];
		str[e] = tmp;

		s++;
		e--;
	}
}

int main()
{
	char str[100];

	printf("Enter any string: ");
	scanf("%s", str);

	reverse_string(str, 0, strlen(str) - 1);
	printf("\nReversed String is: %s", str);
	printf("\n");

	return 0;
}