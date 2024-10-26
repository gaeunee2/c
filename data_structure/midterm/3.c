#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode { 	// ��� Ÿ��
	element data;
	struct ListNode* link;
} ListNode;


ListNode* insert_last(ListNode* head, int value) // �������� ����
{

	ListNode* temp = head;
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));	//(1)
	p->data = value;
	p->link = NULL;

	// (2)
	if (head == NULL) // ���� ����Ʈ�̸�
		head = p;
	else {
		while (temp->link != 0)
			temp = temp->link;

		temp->link = p;
	}
	return head;
}

void print_list(ListNode* head) // �������� ����
{
	for (ListNode* p = head; p != NULL; p = p->link)
		printf("%d->", p->data);
	printf("NULL \n");
}

ListNode* copyList(ListNode* head) // �� �Լ��� ��������� �ۼ�
{
	ListNode* copyList(ListNode * head)
	{
		if (head == NULL)
			return NULL;

		ListNode* clone = (ListNode*)malloc(sizeof(ListNode));
		clone->data = head->data;
		clone->link = copyList(head->link);
		return clone;
	}
}

void check(ListNode* head, ListNode* head2) { // �������� ����
	ListNode* p = head;
	ListNode* pp;
	while (p != NULL) {
		pp = p;
		p = p->link;
		free(pp);
	}
	print_list(head2);
}
// �׽�Ʈ ���α׷�
int main(void) // �������� ����
{
	ListNode* list1 = NULL;
	ListNode* list2;

	int data;

	scanf("%d", &data);
	while (data != -1) {
		list1 = insert_last(list1, data);
		scanf("%d", &data);
	}
	list2 = copyList(list1);
	check(list1, list2);
	return 0;
}