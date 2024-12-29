#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 50

typedef struct GraphType
{
	int n;
	int adj_mat[MAX_VERTICES][MAX_VERTICES];
} GraphType;

void graph_init(GraphType* g)
{
	int r, c;
	g->n = 0;
	for (r = 0; r < MAX_VERTICES; r++)
		for (c = 0; c < MAX_VERTICES; c++)
			g->adj_mat[r][c] = 0;
}

void insert_vertex(GraphType* g, int v)
{
	if (((g->n) + 1) > MAX_VERTICES) {
		fprintf(stderr, "그래프: 정점의 개수 초과");
		return;
	}
	g->n++;
}

void insert_edge(GraphType* g, int start, int end)
{
	if (start >= g->n || end >= g->n) {
		fprintf(stderr, "그래프: 정점 번호 오류");
		return;
	}

	g->adj_mat[start][end] = 1;
	g->adj_mat[end][start] = 1;
}

int visited[MAX_VERTICES] = { FALSE };

void read_graph(GraphType* g, char* filename)
{
	int number, u, v;
	FILE* fp;
	fp = fopen(filename, "rt");
	if (fp == NULL)
	{
		printf("file %s open error!\n", filename);
		return;
	}

	fscanf(fp, "%d", &(g->n));

	while ((number = fgetc(fp)) != '(')
	{
		fscanf(fp, "%d %d", &u, &v);
		insert_edge(g, u, v);
	}
	fclose(fp);
}

void bfs_mat(GraphType* g, int v)
{
	int w;
	QueueType q;
	init(&q);
	visited[v] = TRUE;
	enqueue(&q, v);

	while (!is_empty(&q))
	{
		v = dequeue(&q);
		for (w = 0; w < g->n; w++)
			if (g->adj_mat[v][w] == 1 && !visited[w])
			{
				printf("(%d %d)\n", v, w);
				visited[w] = TRUE;
				enqueue(&q, w);
			}
	}
}

int main(void)
{
	GraphType graph;
	int u, v;

	graph_init(&graph);
	read_graph(&graph, "infile.txt");

	printf("Enter 정점:");
	scanf("%d", &v);

	bfs_mat(&graph, v);
}