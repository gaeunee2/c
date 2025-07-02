#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 

typedef struct student {
	char name[20];
	int midterm;
	int final;
	int average;
}Student;

void printStudent(Student* p)
{
	printf("%s\t", p->name);
	printf("%d\t%d\t%d\n", p->midterm, p->final, p->average);
}

Student readStudentScore(Student* p, int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf("Enter student name: "); //a) 
		scanf("%s", p->name); //b) 
		printf("Enter midterm and final score: "); //c) 
		scanf("%d %d", &p->midterm, &p->final); //d)
		p++;
	}
	return *p;
}

Student calculateStudentAverage(Student* p, int n)
{
	int i;
	for (i = 0; i < n; i++) {
		p->average = ((p->midterm + p->final) / 2); //e)
		p++;
	}
	return *p;
}

int main(void)
{
	Student s[40];
	Student* sp = s;
	int i, num;

	printf("Enter a number of student:");
	scanf("%d", &num);

	readStudentScore(sp, num);

	sp = s;
	calculateStudentAverage(sp, num);

	printf("\n이름\t중간\t학기말\t평균\n");
	sp = s;
	for (i = 0; i < num; i++) {
		printStudent(sp);
		sp++;
	}
}