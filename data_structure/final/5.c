#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 50

// ===== ���� �ڵ��� ���� ===== 
#define MAX_STACK_SIZE 100

typedef int element;

typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
} StackType;

typedef struct {
	int w;
	int prevW;
} element2;
typedef struct {
	element2 data[MAX_STACK_SIZE];
	int top;
} StackType2;

// ���� �ʱ�ȭ �Լ�
void init_stack(StackType* s) // �������� ����
{
	s->top = -1;
}

// ���� ���� ���� �Լ�
int is_empty(StackType* s) // �������� ����
{
	return (s->top == -1);
}
// ��ȭ ���� ���� �Լ�
int is_full(StackType* s) // �������� ����
{
	return (s->top == (MAX_STACK_SIZE - 1));
}
// �����Լ�
void push(StackType* s, element item) // �������� ����
{
	if (is_full(s)) {
		fprintf(stderr, "���� ��ȭ ����\n");
		return;
	}
	else s->data[++(s->top)] = item;
}

// �����Լ�
element pop(StackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else return s->data[(s->top)--];
}

// ��ũ�Լ�
element peek(StackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else return s->data[s->top];
}
// ===== ���� �ڵ��� �� ===== 

int visited[MAX_VERTICES];
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
void init(GraphType* g) // �������� ����
{
	int v;
	g->n = 0;
	for (v = 0; v < MAX_VERTICES; v++)
		g->adj_list[v] = NULL;
}

// ���� ���� ����
void insert_vertex(GraphType* g, int v) // �������� ����
{
	if (((g->n) + 1) > MAX_VERTICES) {
		fprintf(stderr, "�׷���: ������ ���� �ʰ�");
		return;
	}
	g->n++;
}

// ���� ���� ����, (u, v)�� ���� ����Ʈ�� �����Ѵ�.
void insert_edge(GraphType* g, int u, int v) // �������� ����
{
	GraphNode* node;
	if (u >= g->n || v >= g->n) {
		fprintf(stderr, "�׷���: ���� ��ȣ ����");
		return;
	}
	node = (GraphNode*)malloc(sizeof(GraphNode));
	node->vertex = v;
	node->link = g->adj_list[u];
	g->adj_list[u] = node;

	node = (GraphNode*)malloc(sizeof(GraphNode));
	node->vertex = u;
	node->link = g->adj_list[v];
	g->adj_list[v] = node;
}

/*
* DFS-iterative(G, v):
���� S�� �����Ѵ�.
S.push(v)
while (not is_empty(S)) do
   v = S.pop()
   if (v�� �湮���� �ʾ�����)
	 v�� �湮�Ǿ��ٰ� ǥ��
	 for all u �� (v�� ������ ����) do
	   if (u�� ���� �湮���� �ʾ�����)
		S.push(u)
*/
void dfs_list_iterative(GraphType* g, int v) // �� �Լ��� �ۼ�
{
	StackType s;
	init_stack(&s);
	push(&s, v);

	while (!is_empty(&s)) {
		int current = pop(&s);
		if (!visited[current]) {
			printf("%d ", current);
			visited[current] = 1;

			GraphNode* t = g->adj_list[current];
			while (t != NULL) {
				if (!visited[t->vertex])
					push(&s, t->vertex);
				t = t->link;
			}
		}
	}
}

int main(void)  // �������� ����
{
	GraphType* g;
	g = (GraphType*)malloc(sizeof(GraphType));
	init(g);

	int n;
	int s, e; // ������ ���� ����
	scanf("%d", &n); // ������ ����
	for (int i = 0; i < n; i++)
		insert_vertex(g, i);

	scanf("%d %d", &s, &e);
	while (s != -1) {
		insert_edge(g, s, e);

		scanf("%d %d", &s, &e);
	}

	int start;
	scanf("%d", &start);

	for (int i = 0; i < n; i++)
		visited[i] = 0;
	dfs_list_iterative(g, start);

	free(g);
	return 0;
}