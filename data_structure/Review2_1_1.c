#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <stdlib.h>

typedef struct Score {
	int midterm;
	int final;
}Score;

void printScore(Score* p)
{
	printf("중간고사 성적은 %d\n", p->midterm);
	printf("기말고사 성적은 %d\n", p->final);
}

Score* biggerScore(Score* p1, Score* p2)
{
	Score* bigger = malloc(sizeof(Score));

	if (p1->midterm > p2->midterm)
		bigger->midterm = p1->midterm;
	else
		bigger->midterm = p2->midterm;

	if (p1->final > p2->final)
		bigger->final = p1->final;
	else
		bigger->final = p2->final;

	return bigger;
}

Score* totalScore(Score* p1, Score* p2)
{
	Score* total = malloc(sizeof(Score));

	total->midterm = p1->midterm + p2->midterm;
	total->final = p1->final + p2->final;

	return total;
}

Score* createScore(int m, int f)
{
	Score* new = malloc(sizeof(Score));

	new->midterm = m;
	new->final = f;

	return new;
}

int main(void)
{
	Score* p1, * p2, * p3;
	p1 = (Score*)malloc(sizeof(Score));
	p2 = (Score*)malloc(sizeof(Score));

	p1->midterm = 50;
	p1->final = 100;
	p2->midterm = 70;
	p2->final = 70;

	printScore(p1);
	printScore(p2);

	printf("-----------------------------\n");
	printf("둘중 성적이 좋은 점수:\n");
	printScore(biggerScore(p1, p2));

	printf("-----------------------------\n");
	printf("두 성적의 총 합:\n");
	printScore(totalScore(p1, p2));

	printf("-----------------------------\n");
	p3 = createScore(100, 100);
	printScore(p3);

	free(p1);
	free(p2);
	free(p3);
	return 0;
}
