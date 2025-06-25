#include <stdio.h>
void print5Stars(void);

int main(void)
{
	int i;

	for (i = 0; i < 3; i++)
		print5Stars();

	return 0;
}

void print5Stars(void)
{
	int i, num = 5;
	for (i = 0; i < num; i++)
		printf("*");
	printf("\n");

	return;
}