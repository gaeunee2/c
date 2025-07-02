#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX 20
// 구조체타입 Student를 작성
typedef struct {
	char name[20];
	int score;
	char grade;
} Student;

void printStudent(Student* m)
{
	printf("%s %d %c\n", m->name, m->score, m->grade);
}

void calculateGrade(Student* m, int size)
{
	int i;
	for (i = 0; i < size; i++) {
		if (m->score > 50)
			m->grade = 'A';
		else
			m->grade = 'F';
		m++;
	}
}

int bestStudent(Student* m, int size)
{
	int i;
	int best = 0;
	int bestIndex = 0;
	for (i = 0; i < size; i++) {
		if (m->score > best) {
			best = m->score;
			bestIndex = i;
		}
		m++;
	}
	return bestIndex;
}

int main(void) // 변경하지 말라. 
{

	Student students[MAX];
	int i;
	int studentNum;

	scanf("%d", &studentNum);
	for (i = 0; i < studentNum; i++)
		scanf("%s %d", students[i].name, &students[i].score);

	calculateGrade(students, studentNum);

	int bestId = bestStudent(students, studentNum);

	printStudent(&students[bestId]);
}