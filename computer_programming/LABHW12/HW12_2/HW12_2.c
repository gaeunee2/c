#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <string.h>
int main(void)
{
	int state;
	FILE* fp1, * fp2;
	char text;

	fp1 = fopen("input.txt", "rt");
	if (fp1 == NULL)
	{
		printf("file open error!\n");
		return 1;
	}

	fp2 = fopen("output.txt", "wt");
	if (fp2 == NULL)
	{
		printf("file open error!\n");
		return 1;
	}

	while ((text = getc(fp1)) != EOF)
		putc(toupper(text), fp2);
	fprintf(fp2, "\n");
	fseek(fp1, 0, SEEK_SET);

	while ((text = getc(fp1)) != EOF)
		putc(tolower(text), fp2);

	fclose(fp1);
	fclose(fp2);
}