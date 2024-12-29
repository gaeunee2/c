#include <stdio.h> 
#include <stdlib.h> 
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
	g->n = 0;
	for (int i = 0; i < MAX_VERTICES; i++)
		g->adj_list[i] = NULL;
}

void insert_vertex(GraphType* g, int v) 
{
	if (g->n + 1 > MAX_VERTICES) {
		printf("그래프: 정점의 개수 초과\n");
		return;
	}
	g->n++;
}

void insert_edge(GraphType* g, int u, int v) 
{
	GraphNode* node = (GraphNode*)malloc(sizeof(GraphNode));
	node->vertex = v;
	node->link = g->adj_list[u];
	g->adj_list[u] = node;
}

#define MAX_STACK_SIZE 100 
typedef int element;

typedef struct {
	element stack[MAX_STACK_SIZE];
	int top;
} StackType;

void init(StackType* s) 
{
	s->top = -1;
}

int is_empty(StackType* s)
{
	return (s->top == -1);
}

int is_full(StackType* s) 
{
	return (s->top == (MAX_STACK_SIZE - 1));
}

void push(StackType* s, element item) 
{
	if (is_full(s)) {
		printf("스택 포화 상태\n");
		exit(1);
	}
	s->stack[++(s->top)] = item;
}

element pop(StackType* s) 
{
	if (is_empty(s)) {
		printf("스택 공백 상태\n");
		exit(1);
	}
	return s->stack[(s->top)--];
}

element peek(StackType* s)
{
	if (is_empty(s)) {
		printf("스택 공백 상태\n");
		exit(1);
	}
	return s->stack[s->top];
}

int topo_sort(GraphType* g)
{
	int i;
	StackType s;
	GraphNode* node;

	// 모든 정점의 진입 차수를 계산 
	int* in_degree = (int*)malloc(g->n * sizeof(int));
	for (i = 0; i < g->n; i++)   // 초기화 
		in_degree[i] = 0;

	for (i = 0; i < g->n; i++)
		for (node = g->adj_list[i]; node; node = node->link) //정점 i에서 나오는 간선들 
			in_degree[node->vertex]++;
	init(&s);
	for (i = 0; i < g->n; i++)
		if (in_degree[i] == 0) 
			push(&s, i);

	while (!is_empty(&s)) {
		int w;
		w = pop(&s);
		printf("%d ", w);
		for (node = g->adj_list[w]; node; node = node->link) { //각 정점의 진입 차수를 변경 
			int u = node->vertex;
			in_degree[u]--;   //진입 차수를 감소 
			if (in_degree[u] == 0) push(&s, u);
		}
	}
	free(in_degree);
}

int main(void)
{
	GraphType g;

	graph_init(&g);
	insert_vertex(&g, 0);
	insert_vertex(&g, 1);
	insert_vertex(&g, 2);
	insert_vertex(&g, 3);
	insert_vertex(&g, 4);
	insert_vertex(&g, 5);

	//정점 0의 인접 리스트 생성 
	insert_edge(&g, 0, 2);
	insert_edge(&g, 0, 3);
	//정점 1의 인접 리스트 생성 
	insert_edge(&g, 1, 3);
	insert_edge(&g, 1, 4);
	//정점 2의 인접 리스트 생성 
	insert_edge(&g, 2, 3);
	insert_edge(&g, 2, 5);
	//정점 3의 인접 리스트 생성 
	insert_edge(&g, 3, 5);
	//정점 4의 인접 리스트 생성 
	insert_edge(&g, 4, 5);
	//위상 정렬  
	topo_sort(&g);
}