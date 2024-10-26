#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
typedef int element;
typedef struct ListNode {
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

// �� �Լ�(��)�� �߰�
int is_prime(element num)
{
	if (num == 1)
		return 0;
	else if (num == 2)
		return 1;
	else {
		for (int i = 2; i < num; i++)
			if (num % i == 0)
				return 0;
		return 1;
	}
}

int count_prime_node(ListNode* l)
{
	int count = 0;

	while (l != NULL) {
		if (is_prime(l->data))
			count += 1;
		l = l->link;
	}
	return count;
}

int main(void) // �������� ����
{
	ListNode* list = NULL;
	int n;

	scanf("%d", &n);
	while (n != -1) {
		list = insert_last(list, n);
		scanf("%d", &n);
	}

	printf("%d\n", count_prime_node(list));
}