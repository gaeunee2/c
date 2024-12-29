#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 50

// ===== 스택 코드의 시작 ===== 
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

// 스택 초기화 함수
void init_stack(StackType* s) // 변경하지 말라
{
	s->top = -1;
}

// 공백 상태 검출 함수
int is_empty(StackType* s) // 변경하지 말라
{
	return (s->top == -1);
}
// 포화 상태 검출 함수
int is_full(StackType* s) // 변경하지 말라
{
	return (s->top == (MAX_STACK_SIZE - 1));
}
// 삽입함수
void push(StackType* s, element item) // 변경하지 말라
{
	if (is_full(s)) {
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	else s->data[++(s->top)] = item;
}

// 삭제함수
element pop(StackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return s->data[(s->top)--];
}

// 피크함수
element peek(StackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return s->data[s->top];
}
// ===== 스택 코드의 끝 ===== 

int visited[MAX_VERTICES];
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
void init(GraphType* g) // 변경하지 말라
{
	int v;
	g->n = 0;
	for (v = 0; v < MAX_VERTICES; v++)
		g->adj_list[v] = NULL;
}

// 정점 삽입 연산
void insert_vertex(GraphType* g, int v) // 변경하지 말라
{
	if (((g->n) + 1) > MAX_VERTICES) {
		fprintf(stderr, "그래프: 정점의 개수 초과");
		return;
	}
	g->n++;
}

// 간선 삽입 연산, (u, v)를 인접 리스트에 삽입한다.
void insert_edge(GraphType* g, int u, int v) // 변경하지 말라
{
	GraphNode* node;
	if (u >= g->n || v >= g->n) {
		fprintf(stderr, "그래프: 정점 번호 오류");
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
스택 S를 생성한다.
S.push(v)
while (not is_empty(S)) do
   v = S.pop()
   if (v가 방문되지 않았으면)
	 v를 방문되었다고 표시
	 for all u ∈ (v에 인접한 정점) do
	   if (u가 아직 방문되지 않았으면)
		S.push(u)
*/
void dfs_list_iterative(GraphType* g, int v) // 이 함수를 작성
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

int main(void)  // 변경하지 말라
{
	GraphType* g;
	g = (GraphType*)malloc(sizeof(GraphType));
	init(g);

	int n;
	int s, e; // 간선의 양쪽 정점
	scanf("%d", &n); // 정점의 개수
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