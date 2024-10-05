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
		printf("대기자가 꽉찼으니 다음 기회를 이용하세요.\n");
		return;
	}
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->queue[q->rear] = item;
}

element dequeue(QueueType* q)
{
	if (is_empty(q))
		error("큐가 공백상태입니다");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->queue[q->front];
}

element peek(QueueType* q)
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

	printf("미팅 주선 프로그램입니다.\n");
	printf("i<nsert, 고객입력>, c<heck, 대기자 체크>, q<uit>: ");
	scanf(" %c", &option);

	while (option != 'q') {
		switch (option) {
		case 'i':
			printf("이름을 입력: ");
			scanf("%s", newPerson.name);
			getchar();
			printf("성별을 입력<m or f>: ");
			scanf("%c", &newPerson.gender);
			
			if (newPerson.gender == 'm') {
				enqueue(&maleQ, newPerson);
				if (get_count(&femaleQ) == 0)
					printf("아직 대상자가 없습니다. 기다려주십시오.\n");
				else
					printf("커플이 탄생했습니다! %s와 %s\n", dequeue(&maleQ).name, dequeue(&femaleQ).name);
			}
			else {
				enqueue(&femaleQ, newPerson);
				if (get_count(&maleQ) == 0)
					printf("아직 대상자가 없습니다. 기다려주십시오.\n");
				else
					printf("커플이 탄생했습니다! %s와 %s\n", dequeue(&femaleQ).name, dequeue(&maleQ).name);
			}
			break;

		case 'c':
			printf("남성 대기자 %d명: ", get_count(&maleQ));
			print_queue(&maleQ);
			printf("\n여성 대기자 %d명: ", get_count(&femaleQ));
			print_queue(&femaleQ);
			printf("\n");
			break;
		}
		printf("i<nsert, 고객입력>, c<heck, 대기자 체크>, q<uit>: ");
		scanf(" %c", &option);
	}
}
