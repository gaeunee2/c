#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

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

// name이 배열 s에 있으면 그 인덱스를, 아니면 -1을 반환
int searchStudentByName(Student s[], int n, char name[])
{
	int i;
	for (i = 0; i < n; i++) {
		if (strcmp(s[i].name, name) == 0)
			return i;
	}
	return -1;
}

int main(void) // 변경하지 말라
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
	//printf("Enter 학생 이름: ");
	scanf("%s", name);
	for (i = 0; i < studentNum; i++)
		if ((indexSearched = searchStudentByName(students, studentNum, name)) != -1) {
			printStudent(&students[indexSearched]);
			break;
		}
	if (indexSearched == -1)
		printf("not found\n");
}