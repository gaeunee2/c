#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 50

typedef struct GraphNode
{
	int vertex;
	struct GraphNode* link;
} GraphNode;

typedef struct GraphType {
	int n;
	GraphNode* adj_list[MAX_VERTICES];
} GraphType;

void graph_init(GraphType* g)
{
	int v;
	g->n = 0;
	for (v = 0; v < MAX_VERTICES; v++)
		g->adj_list[v] = NULL;
}

void insert_vertex(GraphType* g, int v)
{
	if (((g->n) + 1) > MAX_VERTICES) {
		fprintf(stderr, "그래프: 정점의 개수 초과");
		return;
	}
	g->n++;
}

void insert_edge(GraphType* g, int u, int v)
{
	GraphNode* node_u, * node_v;
	if (u >= g->n || v >= g->n) {
		fprintf(stderr, "그래프: 정점 번호 오류");
		return;
	}
	GraphNode* node = (GraphNode*)malloc(sizeof(GraphNode));
	if (node == NULL) {
		fprintf(stderr, "메모리 할당 에러!\n");
		return;
	}
	node->vertex = v;
	node->link = g->adj_list[u];
	g->adj_list[u] = node;

	node = (GraphNode*)malloc(sizeof(GraphNode));
	if (node == NULL) {
		fprintf(stderr, "메모리 할당 에러!\n");
		return;
	}
	node->vertex = u;
	node->link = g->adj_list[v];
	g->adj_list[v] = node;
}

int visited[MAX_VERTICES] = { FALSE };

void read_graph(GraphType* g, char* filename)
{
	int number, u, v;
	GraphNode* node;
	FILE* fp;
	fp = fopen(filename, "rt");
	if (fp == NULL)
	{
		printf("file open error!\n");
		return;
	}

	fscanf(fp, "%d", &(g->n));
	while (fscanf(fp, "%d %d", &u, &v) == 2)
		insert_edge(g, u, v);

	fclose(fp);
}

void bfs_list(GraphType* g, int v)
{
	GraphNode* w;
	QueueType q;
	init(&q);
	visited[v] = TRUE;
	enqueue(&q, v);

	while (!is_empty(&q)) {
		v = dequeue(&q);
		for (w = g->adj_list[v]; w; w = w->link)
			if (!visited[w->vertex]) {
				printf("<%d %d>\n", v, w->vertex);
				visited[w->vertex] = TRUE;
				enqueue(&q, w->vertex);
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

	bfs_list(&graph, v);
}