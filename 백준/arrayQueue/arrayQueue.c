#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_QUEUE_SIZE 10001

typedef struct QueueType {
    int data[MAX_QUEUE_SIZE];
    int front;
    int back;
}QueueType;

void init(QueueType* q)
{
    q->front = 0;
    q->back = 0;
}

int is_empty(QueueType* q)
{
    return (q->front == q->back);
}

void push(QueueType* q, int item)
{
    q->data[q->back++] = item;
}

int pop(QueueType* q)
{
    if (is_empty(q))
        return -1;
    else
        return q->data[q->front++];
}

int size(QueueType* q)
{
    return q->back - q->front;
}

int front(QueueType* q)
{
    if (is_empty(q))
        return -1;
    else
        return q->data[q->front];
}

int back(QueueType* q)
{
    if (is_empty(q))
        return -1;
    else
        return q->data[q->back - 1];
}

int main(void)
{
    QueueType q;
    int i, n;
    char work[6];
    int num;

    init(&q);
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%s", work);

        if (strcmp(work, "push") == 0) {
            scanf("%d", &num);
            push(&q, num);
        }
        else if (strcmp(work, "pop") == 0)
            printf("%d\n", pop(&q));
        else if (strcmp(work, "size") == 0)
            printf("%d\n", size(&q));
        else if (strcmp(work, "empty") == 0)
            printf("%d\n", is_empty(&q));
        else if (strcmp(work, "front") == 0)
            printf("%d\n", front(&q));
        else
            printf("%d\n", back(&q));
    }

    return 0;
}