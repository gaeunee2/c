#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 3

typedef struct element {
	char gender;
	char name[10];
}element;

typedef struct {
	element queue[MAX_QUEUE_SIZE];
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

void enqueue(QueueType* q, element item)
{
	if (is_full(q)) {
		printf("����ڰ� ��á���� ���� ��ȸ�� �̿��ϼ���.\n");
		return;
	}
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->queue[q->rear] = item;
}

element dequeue(QueueType* q)
{
	if (is_empty(q))
		error("ť�� ��������Դϴ�");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->queue[q->front];
}

element peek(QueueType* q)
{
	if (is_empty(q))
		error("ť�� ��������Դϴ�");
	return q->queue[(q->front + 1) % MAX_QUEUE_SIZE];
}

int get_count(QueueType* q)
{
	if (q->rear >= q->front)
		return q->rear - q->front;
	else
		return MAX_QUEUE_SIZE - (q->front - q->rear);
}

void print_queue(QueueType* q)
{
	int i;

	for (i = (q->front + 1) % MAX_QUEUE_SIZE; i != (q->rear + 1) % MAX_QUEUE_SIZE; i = (i + 1) % MAX_QUEUE_SIZE)
		printf("%s ", q->queue[i].name);
}

int main(void)
{
	QueueType maleQ, femaleQ;
	element newPerson;
	int i;
	char option;

	init(&maleQ);
	init(&femaleQ);

	printf("���� �ּ� ���α׷��Դϴ�.\n");
	printf("i<nsert, ���Է�>, c<heck, ����� üũ>, q<uit>: ");
	scanf(" %c", &option);

	while (option != 'q') {
		switch (option) {
		case 'i':
			printf("�̸��� �Է�: ");
			scanf("%s", newPerson.name);
			getchar();
			printf("������ �Է�<m or f>: ");
			scanf("%c", &newPerson.gender);
			
			if (newPerson.gender == 'm') {
				enqueue(&maleQ, newPerson);
				if (get_count(&femaleQ) == 0)
					printf("���� ����ڰ� �����ϴ�. ��ٷ��ֽʽÿ�.\n");
				else
					printf("Ŀ���� ź���߽��ϴ�! %s�� %s\n", dequeue(&maleQ).name, dequeue(&femaleQ).name);
			}
			else {
				enqueue(&femaleQ, newPerson);
				if (get_count(&maleQ) == 0)
					printf("���� ����ڰ� �����ϴ�. ��ٷ��ֽʽÿ�.\n");
				else
					printf("Ŀ���� ź���߽��ϴ�! %s�� %s\n", dequeue(&femaleQ).name, dequeue(&maleQ).name);
			}
			break;

		case 'c':
			printf("���� ����� %d��: ", get_count(&maleQ));
			print_queue(&maleQ);
			printf("\n���� ����� %d��: ", get_count(&femaleQ));
			print_queue(&femaleQ);
			printf("\n");
			break;
		}
		printf("i<nsert, ���Է�>, c<heck, ����� üũ>, q<uit>: ");
		scanf(" %c", &option);
	}
}