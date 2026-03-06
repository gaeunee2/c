#define _CRT_SECURE_NO_WARNINGS
#define WIDTH 10
#define HEIGHT 10
#include <stdio.h>
#include <stdlib.h>
int screen[HEIGHT][WIDTH] = { -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
							  -1,-1, 0, 0,-1,-1,-1, 0,-1,-1,
							  -1,-1,-1, 0, 0, 0, 0, 0,-1,-1,
							  -1,-1,-1, 0,-1,-1,-1,-1,-1,-1,
							  -1,-1,-1, 0, 0, 0, 0, 0,-1,-1,
							  -1,-1,-1, 0,-1, 0,-1,-1,-1,-1,
							  -1,-1,-1, 0,-1, 0,-1,-1,-1,-1,
							  -1,-1,-1, 0,-1, 0, 0, 0,-1,-1,
							  -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
							  -1,-1,-1,-1,-1,-1,-1,-1,-1,-1
};

void display(int s[][WIDTH]);

void flood_fill(int x, int y)
{
	int num;
	if (screen[x][y] == 0)
	{
		screen[x][y] = 9;
		flood_fill(x - 1, y);
		flood_fill(x + 1, y);
		flood_fill(x, y - 1);
		flood_fill(x, y + 1);
	}
}

int main()
{
	flood_fill(4, 3);
	display(screen);
}

void display(int s[][WIDTH])
{
	int i, j;
	for (i = 0; i < HEIGHT; i++) {
		for (j = 0; j < WIDTH; j++)
			printf("%d ", s[i][j]);
		printf("\n");
	}
}