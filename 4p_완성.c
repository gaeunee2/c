#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct student {
	char name[20];
	int midterm;
	int final;
}student;

int main(void)
{
	student* sp;
	sp = (student*)malloc(sizeof(student));

	printf("Enter student name: ");
	scanf("%s", sp->name);
	printf("Enter midterm and final score: ");
	scanf("%d %d", &sp->midterm, &sp->final);
	printf("\n�̸�\t�߰�\t�б⸻\n");
	printf("%s\t%d\t%d\n", sp->name, sp->midterm, sp->final);

	free(sp);
	return 0;
}