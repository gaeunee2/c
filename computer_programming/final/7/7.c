#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MAX 20
// ����üŸ�� Student�� �ۼ�
typedef struct {
	char name[20];
	int score;
	char grade;
} Student;

void printStudent(Student* m)
{
	printf("%s %d %c\n", m->name, m->score, m->grade);
}

void readNewStudent(Student* m, int* snPtr)
{
	Student student;

	scanf("%s %d", &student.name, &student.score);
	m[*snPtr] = student;
	(*snPtr)++;
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

// name�� �迭 s�� ������ �� �ε�����, �ƴϸ� -1�� ��ȯ
int searchStudentByName(Student s[], int n, char name[])
{
	int i;
	for (i = 0; i < n; i++) {
		if (strcmp(s[i].name, name) == 0)
			return i;
	}
	return -1;
}

int main(void) // �������� ����
{
	Student students[MAX];
	int i;
	int studentNum;
	int choice;
	char name[20];

	studentNum = 0;
	scanf("%d", &choice);
	while (choice != -1) {
		readNewStudent(students, &studentNum);
		scanf("%d", &choice);
	}

	calculateGrade(students, studentNum);

	int indexSearched = -1;
	//printf("Enter �л� �̸�: ");
	scanf("%s", name);
	for (i = 0; i < studentNum; i++)
		if ((indexSearched = searchStudentByName(students, studentNum, name)) != -1) {
			printStudent(&students[indexSearched]);
			break;
		}
	if (indexSearched == -1)
		printf("not found\n");
}