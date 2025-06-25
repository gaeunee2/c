#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	char gen;
	int height, weight;

	printf("Enter your gender(M/F): ");
	scanf("%c", &gen);

	if (gen == 'M')
		printf("Sorry, this fitness center is for women only.\n");
	else if (gen == 'F') {
		printf("Enter your height: ");
		scanf("%d", &height);
		printf("Enter your weight: ");
		scanf("%d", &weight);

		if (height <= weight + 110)
			printf("You NEED a diet. Try HARDER.\n");
		else
			printf("You do NOT need a diet. Keep exercising.\n");
	}
	else
		printf("Error! Choose only M/F.\n");

	return 0;
}