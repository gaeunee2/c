#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 10

typedef struct GraphNode
{
	int vertex;
	struct GraphNode* link;
} GraphNode;

typedef struct GraphType {
	int n;	// ������ ����
	GraphNode* adj_list[MAX_VERTICES];
} GraphType;

// �׷��� �ʱ�ȭ 
void graph_init(GraphType* g) // �������� ����
{
	int v;
	g->n = 0;
	for (v = 0; v < MAX_VERTICES; v++)
		g->adj_list[v] = NULL;
}

// ���� ���� ����, v�� u�� ���� ����Ʈ�� �����Ѵ�.(�ߺ� ó��)
void insert_edge(GraphType* g, int u, int v) // �� �Լ��� �ۼ�(������ �Լ� ����)
{
	// �Ʒ��� �־��� �ڵ�� ���翡�� �־��� ������ 
	// �̸� �ߺ��� ó���� ���ְ� �����Ѵ�
	GraphNode* node;
	if (u >= g->n || v >= g->n) {
		fprintf(stderr, "�׷���: ���� ��ȣ ����");
		return;
	}

	GraphNode* t = g->adj_list[u];
	while (t != NULL) {
		if (t->vertex == v)
			return;
		t = t->link;
	}

	node = (GraphNode*)malloc(sizeof(GraphNode));
	node->vertex = v;
	node->link = g->adj_list[u];
	g->adj_list[u] = node;

	/* ���� �׷����̹Ƿ� �Ʒ��� �ڵ带 �ּ�ó����
	node = (GraphNode*)malloc(sizeof(GraphNode));
	node->vertex = u;
	node->link = g->adj_list[v];
	g->adj_list[v] = node;
	*/
}

void printCheck(GraphType* g) // �� �Լ��� �ۼ�
{
	for (int i = 0; i < g->n; i++) {
		printf("%d|", i);
		while (g->adj_list[i] != NULL) {
			if (g->adj_list[i]->link == NULL)
				printf("->%d", g->adj_list[i]->vertex);
			else
				printf("->%d", g->adj_list[i]->vertex);
			g->adj_list[i] = g->adj_list[i]->link;
		}
		printf("\n");
	}
}

int main(void)  // �������� ����
{
	GraphType g;
	int num;
	int u, v;

	graph_init(&g);

	scanf("%d", &num); // ������ ����
	g.n = num;
	scanf("%d %d", &u, &v);
	while (u != -1 && v != -1) {
		insert_edge(&g, u, v);
		scanf("%d %d", &u, &v);
	}

	printCheck(&g);
}