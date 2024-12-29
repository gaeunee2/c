#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_VERTICES 50

typedef struct GraphType {
    int n;
    int adj_mat[MAX_VERTICES][MAX_VERTICES];
} GraphType;

int visited[MAX_VERTICES] = { 0 };

void graph_init(GraphType* g)
{
    int r, c;
    g->n = 0;
    for (r = 0; r < MAX_VERTICES; r++)
        for (c = 0; c < MAX_VERTICES; c++)
            g->adj_mat[r][c] = 0;
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

void dfs_mat(GraphType* g, int v)
{
    int w;
    visited[v] = 1;
    for (w = 0; w < g->n; w++)
        if ((g->adj_mat[v][w] == 1) && (visited[w] == 0)) {
            printf("<%d %d>\n", v, w);
            dfs_mat(g, w);
        }
}

int main(void)
{
    GraphType graph;
    int u, v;

    graph_init(&graph);
    read_graph(&graph, "infile.txt");
    //read_graph(&graph, "infile2.txt");

    printf("Enter 정점:");
    scanf("%d", &v);

    dfs_mat(&graph, v);
}