#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	char gen;
	int age;
	double height;

	printf("Enter your gender: ");
	scanf("%c", &gen);
	printf("Enter your age: ");
	scanf("%d", &age);
	printf("Enter your height: ");
	scanf("%lf", &height);

	printf("����\t����\tŰ\n");
	printf("%c\t%d\t%f\n", gen, age, height);

	return 0;
}