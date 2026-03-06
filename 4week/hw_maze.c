#define _CRT_SECURE_NO_WARNINGS
#define WIDTH 10
#define HEIGHT 10
#include <stdio.h>
#include <stdlib.h>
int screen[HEIGHT][WIDTH] = { 0, 0, 0,-1,-1,-1,-1,-1,-1,-1,
							 -1,-1, 0,-1,-1,-1,-1,-1,-1,-1,
							 -1, 0, 0, 0, 0, 0, 0,-1,-1,-1,
							 -1,-1,-1,-1, 0,-1, 0,-1,-1,-1,
							 -1,-1,-1,-1, 0,-1, 0,-1,-1,-1,
							 -1,-1, 0, 0, 0,-1, 0, 0, 0,-1,
							 -1,-1,-1,-1, 0,-1, 0,-1,-1,-1,
							 -1,-1,-1,-1, 0,-1, 0,-1, 0,-1,
							 -1,-1,-1,-1, 0,-1,-1,-1, 0,-1,
							 -1,-1,-1,-1, 0, 0, 0, 0, 0, 0
};

void display(int s[][WIDTH]);

void flood_fill(int x, int y, int *count)
{
	if (x < 0 || x > HEIGHT - 1 || y < 0 || y > WIDTH - 1)
		return;

	if (screen[x][y] == 0)
	{
		screen[x][y] = (*count)++;
		flood_fill(x, y + 1, count);
		flood_fill(x + 1, y, count);
		flood_fill(x, y - 1, count);
		flood_fill(x - 1, y, count);
	}
}

int main()
{
	int count = 1;

	printf("미로:\n");
	display(screen);
	printf("\n시작점을 <0 0>으로 한 미로방문<순서표기>:\n");
	flood_fill(0, 0, &count);
	display(screen);

	return 0;
}

void display(int s[][WIDTH])
{
	int i, j;
	for (i = 0; i < HEIGHT; i++) {
		for (j = 0; j < WIDTH; j++)
			printf("%2d ", s[i][j]);
		printf("\n");
	}
}