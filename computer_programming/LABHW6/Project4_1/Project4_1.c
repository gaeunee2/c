#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h> 
#include <stdio.h> 
#include <time.h>

#define NUM_OF_MEMBERS 15

void print_links(int data[][NUM_OF_MEMBERS]);
void matrix_multiplication(int data[][NUM_OF_MEMBERS], int result[][NUM_OF_MEMBERS]);

int main(void)
{
	int link_data[NUM_OF_MEMBERS][NUM_OF_MEMBERS] = { 0 };
	int link_result[NUM_OF_MEMBERS][NUM_OF_MEMBERS] = { 0 };
	int i = 0;
	int j = 0;
	int num_of_steps = 0;
	int ALL_ONES = 0;

	srand(100);
	//srand((unsigned int)time(NULL));

	// link_data 값 넣기: 자신은 모두 1촌이다 
	for (i = 0; i < NUM_OF_MEMBERS; i++)
		link_data[i][i] = 1;

	// link_data 값 넣기: random하게 수를 발생시켜서 1촌 친구를 설정한다.
	for (i = 0; i < NUM_OF_MEMBERS; i++) //각 user마다 대략 4명의 친구가 있다고 가정. 
	{
		j = 0;
		while (j < 2) //i가 두 개의 링크를 연결하고 i가 아닌 다른 user가 i와 연결 
		{
			int new_link = rand() % NUM_OF_MEMBERS;
			if (new_link != i)
			{
				link_data[i][new_link] = 1; //i와 new_link가 1촌이면 
				link_data[new_link][i] = 1; //new_linke와 i도 1촌. 
				j++;
			}
		}
	}
	printf("=================================================================\n");
	printf("Friends matrix\n");
	printf("=================================================================\n");
	print_links(link_data); //최초 1촌 관계 출력

	matrix_multiplication(link_data, link_result);

	printf("=================================================================\n");
	printf("Friends of friends matrix\n");
	printf("=================================================================\n");
	print_links(link_result); // 계산된 2촌까지의 관계 출력 
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
			result[i][j] = 0;
			for (k = 0; k < NUM_OF_MEMBERS; k++) {
				if (result[i][j] == 1)
					break;
				result[i][j] += data[i][k] * data[k][j];
			}
		}
}