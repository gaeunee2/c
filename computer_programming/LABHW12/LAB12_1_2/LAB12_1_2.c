#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
int main(void)
{
	int state;
	FILE* fp;
	char ch;

	fp = fopen("hello.in", "rt");
	if (fp == NULL)
	{
		printf("파일 오픈 에러입니다!!!\n");
		return 1;
	}

	ch = getc(fp);
	while (!feof(fp)) {
		putc(ch, stdout);
		ch = getc(fp);
	}

	fclose(fp);
	return 0;
}