#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h> 
#include <stdio.h> 
#include <time.h> 
#define NUM_OF_MEMBERS 5 

void print_links(int data[][NUM_OF_MEMBERS]);
void matrix_multiplication(int data[][NUM_OF_MEMBERS], int result[][NUM_OF_MEMBERS]);

int main(void)
{
	int link_data[NUM_OF_MEMBERS][NUM_OF_MEMBERS] = { 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 1, 1, 0, 1, 1, 1, 1 };
	int link_result[NUM_OF_MEMBERS][NUM_OF_MEMBERS] = { 0 };

	printf("=================================================================\n");
	printf("Friends matrix\n");
	printf("=================================================================\n");
	print_links(link_data);

	matrix_multiplication(link_data, link_result);
	printf("=================================================================\n");
	printf("Friends of friends matrix\n");
	printf("=================================================================\n");

	print_links(link_result);
}

void print_links(int data[][NUM_OF_MEMBERS])
{
	int i, j;

	for (i = 0; i < NUM_OF_MEMBERS; i++)
		for (j = 0; j < NUM_OF_MEMBERS; j++) {
			printf("%d ", data[i][j]);
			if (j == NUM_OF_MEMBERS - 1)
				printf("\n");
		}
}

void matrix_multiplication(int data[][NUM_OF_MEMBERS], int result[][NUM_OF_MEMBERS])
{
	int i, j, k;

	for (i = 0; i < NUM_OF_MEMBERS; i++)
		for (j = 0; j < NUM_OF_MEMBERS; j++) {
			result[i][j] = .0;
			for (k = 0; k < NUM_OF_MEMBERS; k++) {
				if (result[i][j] == 1)
					break;
				result[i][j] += data[i][k] * data[k][j];
			}
		}
}