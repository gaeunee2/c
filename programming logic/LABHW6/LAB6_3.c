#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	char grade;
	int score;

	printf("Enter your grade: ");
	scanf("%c", &grade);
	
	if (grade == 'A') {
		printf("Enter your score: ");
		scanf("%d", &score);
		printf("%d점이면 A를 받는 군요.\n", score);
	}

	return 0;
}