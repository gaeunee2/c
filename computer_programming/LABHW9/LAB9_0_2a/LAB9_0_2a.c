#define CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <ctype.h>
void main()
{
	char c;
	printf("Enter characters(^Z for exit):\n");
	c = getchar();

	while (c != EOF)
	{
		if (isupper(c))
			c = tolower(c);
		else
			c = toupper(c);
		putchar(c);

		c = getchar();
	}
}