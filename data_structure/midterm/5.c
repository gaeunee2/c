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

ListNode* insert_sorted(ListNode* head, element key) // �� �Լ��� �ۼ�
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = key;

	if (head == NULL) {
		head = node;
		node->link = head;
	}
	else {
		while (1) {
			if (head->link->data >= key || head->data <= key) {
				node->link = head->link;
				head->link = node;
				return head;
			}
			if (head->link->data <= key && head->link->link->data >= key) {
				node->link = head->link->link;
				head->link->link = node;
				return head;
			}
			head = head->link;
		}
	}
}

// ����Ʈ�� �׸� ���
void print_list(ListNode* head)
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

	int data, key;

	scanf("%d", &data);
	while (data != -1) {
		list = insert_last(list, data);
		scanf("%d", &data);
	}

	scanf("%d", &key);

	list = insert_sorted(list, key);
	print_list(list);

	return 0;
}