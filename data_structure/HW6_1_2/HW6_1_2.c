#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 50

typedef int element;

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
    if (((g->n) + 1) > MAX_VERTICES)
    {
        fprintf(stderr, "�׷���: ������ ���� �ʰ�");
        return;
    }
    g->n++;
}

void insert_edge(GraphType* g, int u, int v)
{
    GraphNode* node_u, * node_v;
    if (u >= g->n || v >= g->n) {
        fprintf(stderr, "�׷���: ���� ��ȣ ����");
        return;
    }
    GraphNode* node = (GraphNode*)malloc(sizeof(GraphNode));
    if (node == NULL) {
        fprintf(stderr, "�޸� �Ҵ� ����!\n");
        return;
    }
    node->vertex = v;
    node->link = g->adj_list[u];
    g->adj_list[u] = node;

    node = (GraphNode*)malloc(sizeof(GraphNode));
    if (node == NULL) {
        fprintf(stderr, "�޸� �Ҵ� ����!\n");
        return;
    }
    node->vertex = u;
    node->link = g->adj_list[v];
    g->adj_list[v] = node;
}

void remove_node(GraphNode* head, element item) { 
    GraphNode* p, * prevp;

    if (head == NULL)
        printf("����Ʈ�� ����ֽ��ϴ�.\n");
    else if (head->vertex == item) {
        p = head;
        head = head->link;
        free(p);
    }
    else {
        p = head;
        do {
            prevp = p;
            p = p->link;
        } while (p != NULL && p->vertex != item);
        if (p != NULL) {
            prevp->link = p->link;
            free(p);
        }
        else
            printf("%d�� ����Ʈ�� ����\n", item);
    }
    return head;
}

void delete_edge(GraphType* g, int u, int v)
{
    if (u >= g->n || v >= g->n) {
        fprintf(stderr, "�׷���: ���� ��ȣ ����");
        return;
    }
    remove_node(g->adj_list[u], v);
    remove_node(g->adj_list[v], u);
}

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

void write_graph(GraphType* g, char* filename)
{
    int u;
    FILE* fp;
    GraphNode* ptr;

    if (filename == NULL) 
        fp = stdout;
    else {
        fp = fopen(filename, "w");
        if (fp == NULL)
        {
            printf("file %s open error!\n", filename);
            return;
        }
    }
    
    fprintf(fp, "%d\n", g->n);
    for (u = 0; u < g->n; u++)
        for (ptr = g->adj_list[u]; ptr != NULL; ptr = ptr->link)
            if (u < ptr->vertex)
                fprintf(fp, "%d %d\n", u, ptr->vertex);
    fprintf(fp, "(EOF)\n");

    if (filename != NULL) 
        fclose(fp);
}

int main(void)
{
    GraphType g;
    graph_init(&g);

    read_graph(&g, "input.txt");
    write_graph(&g, NULL);

    insert_edge(&g, 1, 3);
    write_graph(&g, NULL);

    delete_edge(&g, 2, 0);
    write_graph(&g, NULL);

    write_graph(&g, "output.txt");
}