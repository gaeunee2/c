#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode { 	// 노드 타입
	element data;
	struct ListNode* link;
} ListNode;


ListNode* insert_last(ListNode* head, int value) // 변경하지 말라
{

	ListNode* temp = head;
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));	//(1)
	p->data = value;
	p->link = NULL;

	// (2)
	if (head == NULL) // 공백 리스트이면
		head = p;
	else {
		while (temp->link != 0)
			temp = temp->link;

		temp->link = p;
	}
	return head;
}

void print_list(ListNode* head) // 변경하지 말라
{
	for (ListNode* p = head; p != NULL; p = p->link)
		printf("%d->", p->data);
	printf("NULL \n");
}

ListNode* copyList(ListNode* head) // 이 함수를 재귀적으로 작성
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

void check(ListNode* head, ListNode* head2) { // 변경하지 말라
	ListNode* p = head;
	ListNode* pp;
	while (p != NULL) {
		pp = p;
		p = p->link;
		free(pp);
	}
	print_list(head2);
}
// 테스트 프로그램
int main(void) // 변경하지 말라
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