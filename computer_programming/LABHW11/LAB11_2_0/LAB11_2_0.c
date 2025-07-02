#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 

typedef struct student {
	char name[20];
	int midterm;
	int final;
	int average;
}Student;

void printStudent(Student *p)
{
	printf("%s\t", p->name);
	printf("%d\t%d\t%d\n", p->midterm, p->final, p->average);
}

int main(void)
{
	Student s[40];
	Student *sp = s;
	int num, i;

	printf("Enter a number of student:");
	scanf("%d", &num);

	for (i = 0; i < num; i++)
	{
		printf("Enter student name: "); //a) 
		scanf("%s", sp->name); //b) 
		printf("Enter midterm and final score: "); //c) 
		scanf("%d %d", &sp->midterm, &sp->final); //d)
		sp++;
	}

	sp = s;
	for (i = 0; i < num; i++) {
		sp->average = ((sp->midterm + sp->final) / 2); //e)
		sp++;
	}

	printf("\n이름\t중간\t학기말\t평균\n");
	sp = s;
	for (i = 0; i < num; i++) {
		printStudent(sp);
		sp++;
	}
}