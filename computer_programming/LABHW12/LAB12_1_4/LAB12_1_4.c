#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
int main(void)
{
	int state;
	FILE* fp;
	char ch;

	fp = fopen("hello.out", "wt");
	if (fp == NULL)
	{
		printf("file open error!\n");
		return 1;
	}

	fprintf(fp, "Hello\n");
	fprintf(fp, "World\n");

	fclose(fp);
	
	fopen("hello.out", "rt");

	while ((ch = getc(fp)) != EOF)
		putc(ch, stdout);

	fclose(fp);
}