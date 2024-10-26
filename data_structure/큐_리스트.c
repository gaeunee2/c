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
} LinkedQueuType;

void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void init(LinkedQueuType* q)
{
	q->front = q->rear = NULL;
}

int is_empty(LinkedQueuType* q)
{
	return q->front == NULL;
}

int is_full(LinkedQueuType* q)
{
	return 0;
}

void enqueue(LinkedQueuType* q, element item)
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

element dequeue(LinkedQueuType* q)
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

void print_queue(LinkedQueuType* q)
{
	for (QueueNode* p = q->front; p; p = p->link)
		printf("%d ", p->item);
}

int main(void)
{
	QueueNode q;

	init(&q);
	enqueue(&q, 1);
	enqueue(&q, 2);
	enqueue(&q, 3);
	printf("dequeue()=%d\n", dequeue(&q));
	printf("dequeue()=%d\n", dequeue(&q));
	printf("dequeue()=%d\n", dequeue(&q));
}