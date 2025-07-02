#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <string.h> 

struct student {
	char name[20];
	int midterm;
	int final;
	int average;
	char grade;
};

int main(void)
{
	struct student s[3];
	struct student* sp = s;
	int i;
	int midSum = 0;
	int finalSum = 0;

	for (i = 0; i < 3; i++) {
		printf("Enter student name: ");
		scanf("%s", sp->name);
		printf("Enter midturm and final score: ");
		scanf("%d %d", &sp->midterm, &sp->final);

		midSum += sp->midterm;
		finalSum += sp->final;

		sp->average = (sp->midterm + sp->final) / 2;
		if (sp->average >= 80)
			sp->grade = 'A';
		else if (sp->average >= 50)
			sp->grade = 'B';
		else
			sp->grade = 'F';
		sp++;
	}

	sp = s;
	printf("\n이름\t중간\t학기말\t평균\n");
	for (i = 0; i < 3; i++) {
		printf("%s\t%d\t%d\t%d\n", sp->name, sp->midterm, sp->final, sp->average);
		sp++;
	}

	sp = s;
	printf("\n이름\t학점\n");
	for (i = 0; i < 3; i++) {
		printf("%s\t%c\n", sp->name, sp->grade);
		sp++;
	}

	printf("\n중간고사의 평군 = %d\n", midSum / 3);
	printf("학기말고사의 평균 = %d\n", finalSum / 3);
}