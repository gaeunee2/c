#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 100
#define INF 100000

typedef struct GraphType {
	int n;
	int weight[MAX_VERTICES][MAX_VERTICES];
} GraphType;

int distance[MAX_VERTICES];
int found[MAX_VERTICES];
int previous[MAX_VERTICES] = { 0, };

void graph_init(GraphType* g)
{
	int r, c;
	g->n = 0;
	for (r = 0; r < MAX_VERTICES; r++)
		for (c = 0; c < MAX_VERTICES; c++)
			g->weight[r][c] = INF;
}

void read_graph(GraphType* g, char* filename)
{
	int r, c, weight;
	FILE* fp = fopen(filename, "rt");

	if (fp == NULL) {
		printf("file %s open error!\n", filename);
		return;
	}

	fscanf(fp, "%d", &(g->n));
	while (fscanf(fp, "%d %d %d", &r, &c, &weight) == 3)
		g->weight[r][c] = g->weight[c][r] = weight;
	fclose(fp);
}

int choose(int distance[], int n, int found[])
{
	int i, min, minpos;
	min = INT_MAX;
	minpos = -1;

	for(i=0; i<n; i++)
		if (distance[i] < min && !found[i]) {
			min = distance[i];
			minpos = i;
		}
	return minpos;
}

void print_status(GraphType* g)
{
	static int step = 1;
	printf("STEP %d: ", step++);
	printf("distance: ");
	for (int i = 0; i < g->n; i++)
		if (distance[i] == INF)
			printf(" * ");
		else
			printf("%2d ", distance[i]);
	printf("\n");
	printf("found: ");
	for (int i = 0; i < g->n; i++)
		printf("%2d ", found[i]);
	printf("\n\n");
}

void print_path(int start, int end)
{
	static int recursion_end = 0;
	if (start == end)
	{
		printf("%d -> ", start);
		return;
	}
	recursion_end++;
	print_path(start, previous[end]);
	recursion_end--;
	if (recursion_end == 0)
		printf("%d <%d>\n", end, distance[end]);
	else
		printf("%d -> ", end);
}

void shortest_path(GraphType* g, int start)
{
	int i, u, w;
	for (i = 0; i < g->n; i++) //ÃÊ±âÈ­
	{
		distance[i] = g->weight[start][i];
		if (distance[i] != INF)
			previous[i] = start;
		found[i] = FALSE;
	}

	found[start] = TRUE;
	distance[start] = 0;

	for (i = 0; i < g->n - 1; i++) {
		u = choose(distance, g->n, found);
		found[u] = TRUE;
		print_path(start, u);
		for (w = 0; w < g->n; w++)
			if (!found[w])
				if (distance[u] + g->weight[u][w] < distance[w]) {
					distance[w] = distance[u] + g->weight[u][w];
					previous[w] = u;
				}
	}
}

int main(void)
{
	GraphType g;

	graph_init(&g);
	read_graph(&g, "input.txt");
	shortest_path(&g, 4);

	return 0;
}