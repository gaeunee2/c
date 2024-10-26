#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode { 	// ��� Ÿ��
	element data;
	struct ListNode* link;
} ListNode;

ListNode* insert_last(ListNode* head, element data) // �������� ����
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = data;
	if (head == NULL) {
		head = node;
		node->link = head;
	}
	else {
		node->link = head->link;	// (1)
		head->link = node;		// (2)
		head = node;		// (3)
	}
	return head;	// ����� ��� �����͸� ��ȯ�Ѵ�. 
}

// ����Ʈ�� �׸� ���
void print_list(ListNode* head) // �� �Լ��� �ۼ��϶�
{
	ListNode* p;

	if (head == NULL) {
		printf("NULL\n");
		return;
	}
	p = head->link;
	do {
		printf("%d->", p->data);
		p = p->link;
	} while (p != head->link);
	printf("NULL\n");
}

// ���� ���� ����Ʈ �׽�Ʈ ���α׷�
int main(void) // �������� ����
{
	ListNode* list = NULL;

	int data;

	scanf("%d", &data);
	while (data != -1) {
		list = insert_last(list, data);
		scanf("%d", &data);
	}

	print_list(list);

	return 0;
}