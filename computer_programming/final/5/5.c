#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX 20
typedef struct {
	char name[20];
	int score;
	char grade;
} Student;

void calculateGrade(Student* m, int size) // �� �Լ��� �ۼ�: void calculateGrade(Student m[], int size)�� �ص� �ȴ�
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
int main(void) // �������� ����
{
	Student students[MAX];
	int i;
	int studentNum;

	scanf("%d", &studentNum);
	for (i = 0; i < studentNum; i++)
		scanf("%s %d", students[i].name, &students[i].score);

	calculateGrade(students, studentNum); // ������ �ο��Ѵ�

	for (i = 0; i < studentNum; i++)
		printf("%s %d %c\n", students[i].name, students[i].score, students[i].grade);
}