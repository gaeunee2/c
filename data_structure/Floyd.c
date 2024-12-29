#include <stdio.h> 
#include <stdlib.h> 
#define TRUE 1 
#define FALSE 0 
#define MAX_VERTICES 100  
#define INF 1000000

typedef struct GraphType {
    int n;
    int weight[MAX_VERTICES][MAX_VERTICES];
} GraphType;

int A[MAX_VERTICES][MAX_VERTICES];

void printA(GraphType* g)
{
    int i, j;
    printf("===============================\n");
    for (i = 0; i < g->n; i++) {
        for (j = 0; j < g->n; j++) {
            if (A[i][j] == INF)
                printf("  * ");
            else printf("%3d ", A[i][j]);
        }
        printf("\n");
    }
    printf("===============================\n");
}

void floyd(GraphType* g)
{

    int i, j, k;
    for (i = 0; i < g->n; i++)
        for (j = 0; j < g->n; j++)
            A[i][j] = g->weight[i][j];
    printf("�ʱ� ����\n");
    printA(g);

    for (k = 0; k < g->n; k++) {
        for (i = 0; i < g->n; i++)
            for (j = 0; j < g->n; j++)
                if (A[i][k] + A[k][j] < A[i][j])
                    A[i][j] = A[i][k] + A[k][j];
        printf("%d�� �����ؼ� �ٽ� ���\n", k);
        printA(g);
    }
}

int main(void)
{
    GraphType g = { 7,
    {{0, 10, INF, 50, INF},
    {10, 0, 45, 30, 60},
    {INF, 45, 0, 5, 20},
    {50, 30, 5, 0, INF},
    {INF, 60, 20, INF, 0}}
    };
    floyd(&g);
    return 0;
}