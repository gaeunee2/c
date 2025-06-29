#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 1001

typedef struct {
	int queue[MAX_QUEUE_SIZE];
	int front, rear;
}QueueType;

void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void init(QueueType* q)
{
	q->front = q->rear = 0;
}

int is_empty(QueueType* q)
{
	return q->front == q->rear;
}

int is_full(QueueType* q)
{
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

void enqueue(QueueType* q, int item)
{
	if (is_full(q)) {
		printf("full\n");
		return;
	}
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->queue[q->rear] = item;
}

int dequeue(QueueType* q)
{
	if (is_empty(q))
		error("empty\n");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->queue[q->front];
}

int peek(QueueType* q)
{
	if (is_empty(q))
		error("큐가 공백상태입니다");
	return q->queue[(q->front + 1) % MAX_QUEUE_SIZE];
}

int get_count(QueueType* q)
{
	if (q->rear >= q->front)
		return q->rear - q->front;
	else
		return MAX_QUEUE_SIZE - (q->front - q->rear);
}

int main(void)
{
	QueueType q;
	int i, n, k;
	init(&q);

	scanf("%d %d", &n, &k);

	for (i = 1; i <= n; i++)
		enqueue(&q, i);

	printf("<");
	while (!is_empty(&q)) {
		for (i = 0; i < k - 1; i++) {
			int temp = dequeue(&q);
			enqueue(&q, temp);
		}
		int out = dequeue(&q);
		printf("%d", out);
		if (!is_empty(&q))
			printf(", ");
	}
	printf(">\n");

	return 0;
}