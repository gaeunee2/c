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
//data before �����ʿ� ����
void dinsert(DListNode* before, element data)
{
	DListNode* newnode = (DListNode*)malloc(sizeof(DListNode));
	newnode->data = data;
	newnode->llink = before;
	newnode->rlink = before->rlink;
	before->rlink->llink = newnode;
	before->rlink = newnode;
}
//removed ��� ����
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

	printf("�߰� �ܰ�\n");
	//�� �� ��� ����
	dinsert(head, 10);
	print_dlist(head);
	dinsert(head, 20);
	print_dlist(head);
	dinsert(head, 30);
	print_dlist(head);
	//�� �� ��� ����
	dinsert(head->llink, 99);
	print_dlist(head);

	printf("\n���� �ܰ�\n");
	//�� �� ��� ����
	ddelete(head, head->rlink);
	print_dlist(head);
	//�� �� ��� ����
	ddelete(head, head->llink);
	print_dlist(head);

	printf("\n���� ���\n");
	print_reverse_dlist(head);

	printf("\n10 Ž�� ����\n");
	node = search(head, 10);
	if (node == NULL)
		printf("Ž�� ����\n");
	else
		printf("%d Ž�� ����\n", node->data);
	print_dlist(head);

	printf("\n30 Ž�� ����\n");
	node = search(head, 30);
	if (node == NULL)
		printf("Ž�� ����\n");
	else
		printf("%d Ž�� ����\n", node->data);
	print_dlist(head);

	free(head);
	return 0;
}