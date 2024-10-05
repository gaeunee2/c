#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct DListNode {
	element data;
	struct DListNode* llink;
	struct DListNode* rlink;
} DListNode;

void init(DListNode* phead)
{
	phead->llink = phead;
	phead->rlink = phead;
}

void print_dlist(DListNode* phead)
{
	DListNode* p;
	for (p = phead->rlink; p != phead; p = p->rlink)
		printf("<-| |%d| |-> ", p->data);
	printf("\n");
}
//data before 오른쪽에 삽입
void dinsert(DListNode* before, element data)
{
	DListNode* newnode = (DListNode*)malloc(sizeof(DListNode));
	newnode->data = data;
	newnode->llink = before;
	newnode->rlink = before->rlink;
	before->rlink->llink = newnode;
	before->rlink = newnode;
}
//removed 노드 삭제
void ddelete(DListNode* head, DListNode* removed)
{
	if (removed == head) 
		return;
	removed->llink->rlink = removed->rlink;
	removed->rlink->llink = removed->llink;
	free(removed);
}

void print_reverse_dlist(DListNode* head)
{
	DListNode* p = head->llink;
	do {
		printf("<-| |%d| |-> ", p->data);
		p = p->llink;
	} while (p != head);
	printf("\n");
}

DListNode* search(DListNode* head, element data)
{
	DListNode* temp = head;
	do {
		if (temp->data == data)
			return temp;
		temp = temp->rlink;
	} while (temp != head);
	return NULL;
}

int main(void)
{
	DListNode* head = (DListNode*)malloc(sizeof(DListNode));
	DListNode* node = (DListNode*)malloc(sizeof(DListNode));
	init(head);

	printf("추가 단계\n");
	//맨 앞 노드 삽입
	dinsert(head, 10);
	print_dlist(head);
	dinsert(head, 20);
	print_dlist(head);
	dinsert(head, 30);
	print_dlist(head);
	//맨 뒤 노드 삽입
	dinsert(head->llink, 99);
	print_dlist(head);

	printf("\n삭제 단계\n");
	//맨 앞 노드 삭제
	ddelete(head, head->rlink);
	print_dlist(head);
	//맨 뒤 노드 삭제
	ddelete(head, head->llink);
	print_dlist(head);

	printf("\n역순 출력\n");
	print_reverse_dlist(head);

	printf("\n10 탐색 시작\n");
	node = search(head, 10);
	if (node == NULL)
		printf("탐색 실패\n");
	else
		printf("%d 탐색 성공\n", node->data);
	print_dlist(head);

	printf("\n30 탐색 시작\n");
	node = search(head, 30);
	if (node == NULL)
		printf("탐색 실패\n");
	else
		printf("%d 탐색 성공\n", node->data);
	print_dlist(head);

	free(head);
	return 0;
}