#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX 20
typedef struct {
	char name[20];
	int score;
	char grade;
} Student;

void calculateGrade(Student* m, int size) // 이 함수를 작성: void calculateGrade(Student m[], int size)로 해도 된다
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

#define MAX 20
int main(void) // 변경하지 말라
{
	Student students[MAX];
	int i;
	int studentNum;

	scanf("%d", &studentNum);
	for (i = 0; i < studentNum; i++)
		scanf("%s %d", students[i].name, &students[i].score);

	calculateGrade(students, studentNum); // 학점을 부여한다

	for (i = 0; i < studentNum; i++)
		printf("%s %d %c\n", students[i].name, students[i].score, students[i].grade);
}