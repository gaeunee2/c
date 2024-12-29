#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "minheap.h"
#include "unionfind.h"

#define MAX_VERTICES 100
#define INF 9999

typedef struct GraphType {
	int n;					// ������ ����
	int adj_mat[MAX_VERTICES][MAX_VERTICES];
} GraphType;

void graph_init(GraphType* g)
{
	int r, c;
	g->n = 0;
	for (r = 0; r < MAX_VERTICES; r++)
		for (c = 0; c < MAX_VERTICES; c++)
			g->adj_mat[r][c] = INF;
}

void insert_heap_edge(HeapType* h, int u, int v, int weight)
{
	element e;
	e.u = u;
	e.v = v;
	e.key = weight;

	insert_min_heap(h, e);
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
			g->adj_mat[r][c] = g->adj_mat[c][r] = weight;
	fclose(fp);
}

void write_graph(GraphType* g, char* filename)
{
	int r, c;
	FILE* fp;
	int visited[MAX_VERTICES][MAX_VERTICES] = { 0 };

	if (filename == NULL)
		fp = stdout;
	else
		fp = fopen(filename, "wt");

	fprintf(fp, "%d\n", g->n);
	for (r = 0; r < g->n; r++)
		for (c = 0; c < g->n; c++)
			if (g->adj_mat[r][c] != INF && visited[r][c] == 0) {
				fprintf(fp, "%d %d %d\n", r, c, g->adj_mat[r][c]);
				visited[r][c] = visited[c][r] = 1;
			}
	if (filename != NULL)
		fclose(fp);
}

void insert_all_edges(HeapType* h, GraphType* g)
{
	int r, c;
	int visited[MAX_VERTICES][MAX_VERTICES] = { 0 };

	for (r = 0; r < g->n; r++)
		for (c = r + 1; c < g->n; c++)
			if (g->adj_mat[r][c] != INF && visited[r][c] == 0) {
				insert_heap_edge(h, r, c, g->adj_mat[r][c]);
				visited[r][c] = visited[c][r] = 1;
			}
}

void kruskal(GraphType* g, GraphType* t)
{
	int edge_accepted = 0; //������� ���õ� ���� ��
	HeapType h;
	int uset, vset; //���� u�� ���� v ���� ��ȣ
	element e;

	init(&h);
	insert_all_edges(&h, g);
	set_init(g->n);

	printf("���õ� ����<�������>:\n");
	while (edge_accepted < (g->n - 1)) {
		e = delete_min_heap(&h);
		uset = set_find(e.u);
		vset = set_find(e.v);
		if (uset != vset) {
			printf("<%d %d> %d\n", e.u, e.v, e.key);
			t->adj_mat[e.u][e.v] = t->adj_mat[e.v][e.u] = e.key;
			edge_accepted++;
			set_union(uset, vset);
		}
	}
}

int main(void)
{
	GraphType g, t;		// �Է� �׷���, ��� Ʈ��

	graph_init(&g);
	//read_graph(&g, "input1.txt");
	read_graph(&g, "input2.txt");

	graph_init(&t);
	t.n = g.n;

	kruskal(&g, &t);

	printf("\n���Ϸ� ���:\n");
	write_graph(&t, "output.txt");
	write_graph(&t, NULL);	// to stdout
}