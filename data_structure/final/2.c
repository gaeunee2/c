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
	int n;	// 정점의 개수
	GraphNode* adj_list[MAX_VERTICES];
} GraphType;

// 그래프 초기화 
void graph_init(GraphType* g) // 변경하지 말라
{
	int v;
	g->n = 0;
	for (v = 0; v < MAX_VERTICES; v++)
		g->adj_list[v] = NULL;
}

// 간선 삽입 연산, v를 u의 인접 리스트에 삽입한다.(중복 처리)
void insert_edge(GraphType* g, int u, int v) // 이 함수를 작성(교재의 함수 수정)
{
	// 아래에 주어진 코드는 교재에서 주어진 것으로 
	// 이를 중복을 처리할 수있게 수정한다
	GraphNode* node;
	if (u >= g->n || v >= g->n) {
		fprintf(stderr, "그래프: 정점 번호 오류");
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

	/* 방향 그래프이므로 아래의 코드를 주석처리함
	node = (GraphNode*)malloc(sizeof(GraphNode));
	node->vertex = u;
	node->link = g->adj_list[v];
	g->adj_list[v] = node;
	*/
}

void printCheck(GraphType* g) // 이 함수를 작성
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

int main(void)  // 변경하지 말라
{
	GraphType g;
	int num;
	int u, v;

	graph_init(&g);

	scanf("%d", &num); // 정점의 개수
	g.n = num;
	scanf("%d %d", &u, &v);
	while (u != -1 && v != -1) {
		insert_edge(&g, u, v);
		scanf("%d %d", &u, &v);
	}

	printCheck(&g);
}