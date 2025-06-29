#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_QUEUE_SIZE 10001

typedef struct {
    int queue[MAX_QUEUE_SIZE];
    int front, rear;
} QueueType;

void init(QueueType* q) {
    q->front = q->rear = 0;
}

int is_empty(QueueType* q) {
    return q->front == q->rear;
}

int is_full(QueueType* q) {
    return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

void enqueue(QueueType* q, int item) {
    if (is_full(q)) return;
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->queue[q->rear] = item;
}

int dequeue(QueueType* q) {
    if (is_empty(q))
        return -1;
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return q->queue[q->front];
}

int front_val(QueueType* q) {
    if (is_empty(q))
        return -1;
    return q->queue[(q->front + 1) % MAX_QUEUE_SIZE];
}

int back_val(QueueType* q) {
    if (is_empty(q))
        return -1;
    return q->queue[q->rear];
}

int size(QueueType* q) {
    return (q->rear - q->front + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
}

int main(void) {
    int i, n, num;
    char cmd[10];
    QueueType q;

    init(&q);
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%s", cmd);
        if (strcmp(cmd, "push") == 0) {
            scanf("%d", &num);
            enqueue(&q, num);
        }
        else if (strcmp(cmd, "pop") == 0)
            printf("%d\n", dequeue(&q));
        else if (strcmp(cmd, "size") == 0)
            printf("%d\n", size(&q));
        else if (strcmp(cmd, "empty") == 0)
            printf("%d\n", is_empty(&q));
        else if (strcmp(cmd, "front") == 0)
            printf("%d\n", front_val(&q));
        else if (strcmp(cmd, "back") == 0)
            printf("%d\n", back_val(&q));
    }

    return 0;
}