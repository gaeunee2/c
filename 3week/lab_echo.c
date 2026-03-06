#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void echo1() // 반복
{
	int ch;
	while ((ch = getchar()) != '\n')
		putchar(ch);
}

void echo2() // 순환
{
	int ch;
	if ((ch = getchar()) != '\n') {
		putchar(ch);
		echo2();
	}
}

void reverse()
{
	int ch;
	if ((ch = getchar()) != '\n') {
		reverse();
		putchar(ch);
	}
}

int main()
{
	printf("Enter a string and press enter:");
	echo1();

	printf("\nEnter a string and press enter:");
	echo2();

	printf("\nEnter a string and press enter:");
	reverse();
	printf("\n");
}