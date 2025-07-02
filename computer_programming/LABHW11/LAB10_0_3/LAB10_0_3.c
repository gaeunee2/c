#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct student
{
	char name[20];
	int midterm;
	int final;
};

void main()
{
	struct student s[3];
	struct student *sp = s;
	int i;

	for (i = 0; i < 3; i++) {
		printf("Enter student name: ");
		scanf("%s", &(*sp).name);
		printf("Enter midturm and final score: ");
		scanf("%d %d", &(*sp).midterm, &(*sp).final);
		sp++;
	}

	printf("\n이름\t중간\t학기말\n");

	sp = s;
	for (i = 0; i < 3; i++) {
		printf("%s\t%d\t%d\n", (*sp).name, (*sp).midterm, (*sp).final);
		sp++;
	}
}