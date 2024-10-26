#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode { 	// 노드 타입
	element data;
	struct ListNode* link;
} ListNode;

ListNode* insert_last(ListNode* head, element data) // 변경하지 말라
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
	return head;	// 변경된 헤드 포인터를 반환한다. 
}

// 리스트의 항목 출력
void print_list(ListNode* head) // 이 함수를 작성하라
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

// 원형 연결 리스트 테스트 프로그램
int main(void) // 변경하지 말라
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