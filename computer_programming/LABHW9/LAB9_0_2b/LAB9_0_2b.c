#define CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <ctype.h>
void main()
{
	char c;
	printf("Enter characters(^Z for exit):\n");

	while ((c = fgetc(stdin)) != EOF)
	{
		if (isupper(c))
			c = tolower(c);
		else
			c = toupper(c);
		fputc(c, stdout);
	}
}