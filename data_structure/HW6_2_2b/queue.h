#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef int element;
typedef struct QueueNode {
	element item;
	struct QueueNode* link;
} QueueNode;

typedef struct {
	QueueNode* front, * rear;
} QueueType;

void error(const char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}
void init(QueueType* q)
{
	q->front = q->rear = NULL;
}

int is_empty(QueueType* q)
{
	return q->front == NULL;
}

int is_full(QueueType* q)
{
	return 0;
}

void enqueue(QueueType* q, element item)
{
	QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode));
	if (temp == NULL)
		error("메모리를 할당할 수 없습니다");

	else {
		temp->item = item;
		temp->link = NULL;
		if (is_empty(q)) {
			q->front = temp;
			q->rear = temp;
		}
		else { //큐 공백X
			q->rear->link = temp;
			q->rear = temp;
		}
	}
}

element dequeue(QueueType* q)
{
	QueueNode* removed = q->front;
	element rslt;
	if (is_empty(q))
		error("큐가 비어있음");
	else {
		rslt = removed->item;
		q->front = removed->link;
		if (q->front == NULL) //node 1개
			q->rear = NULL;
		free(removed);
		return rslt;
	}
}

void print_queue(QueueType* q)
{
	for (QueueNode* p = q->front; p; p = p->link)
		printf("%d ", p->item);
}