#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX 20
typedef struct {
	char name[20];
	int score;
	char grade;
} Student;

typedef struct cClass {
	int num;
	Student s[40];
} CClass;


void printStudent(Student* m)
{
	printf("%s %d %c\n", m->name, m->score, m->grade);
}

void readClass(CClass* cp)
{
	int i;
	for (i = 0; i < cp->num; i++) {
		scanf("%s %d", &cp->s[i].name, &cp->s[i].score);
	}
}

void calculateClassGrade(CClass* cp)
{
	int i;
	for (i = 0; i < cp->num; i++) {
		if (cp->s[i].score > 50)
			cp->s[i].grade = 'A';
		else
			cp->s[i].grade = 'F';
	}
}

Student calculateClassBest(CClass* cp)
{
	Student bestStudent = { "0", 0, 0 };
	int i;
	int best = -1;

	for (i = 0; i < cp->num; i++) {
		if (cp->s[i].score > best) {
			best = cp->s[i].score;
			strcpy(bestStudent.name, cp->s[i].name);
			bestStudent.score = cp->s[i].score;
			bestStudent.grade = cp->s[i].grade;
		}
	}
	return bestStudent;
}


int main(void) // 변경하지 말라. 
{
	CClass cp;
	Student bestStudent;

	scanf("%d", &cp.num);

	readClass(&cp);
	calculateClassGrade(&cp);
	bestStudent = calculateClassBest(&cp);

	printStudent(&bestStudent);
}