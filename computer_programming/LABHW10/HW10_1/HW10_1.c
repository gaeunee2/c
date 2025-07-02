struct student {
	char name[20];
	int midterm;
	int final;
	int average;
	char grade;
};

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <string.h> 
int main(void)
{
	struct student s[3];
	int i;
	int midSum = 0;
	int finalSum = 0;

	for (i = 0; i < 3; i++) {
		printf("Enter student name: ");
		scanf("%s", s[i].name);
		printf("Enter midturm and final score: ");
		scanf("%d %d", &s[i].midterm, &s[i].final);

		midSum += s[i].midterm;
		finalSum += s[i].final;

		s[i].average = (s[i].midterm + s[i].final) / 2;
		if (s[i].average >= 80)
			s[i].grade = 'A';
		else if (s[i].average >= 50)
			s[i].grade = 'B';
		else
			s[i].grade = 'F';
	}
	
	printf("\n�̸�\t�߰�\t�б⸻\t���\n");
	for (i = 0; i < 3; i++)
		printf("%s\t%d\t%d\t%d\n", s[i].name, s[i].midterm, s[i].final, s[i].average);

	printf("\n�̸�\t����\n");
	for (i = 0; i < 3; i++)
		printf("%s\t%c\n", s[i].name, s[i].grade);

	printf("\n�߰������ �� = %d\n", midSum / 3);
	printf("�б⸻����� ��� = %d\n", finalSum / 3);
}