#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct ListNode {
    element data;
    struct ListNode* link;
} ListNode;

void print_list(ListNode* head)
{
    ListNode* p;

    if (head == NULL) 
        return;
    p = head->link;
    do {
        printf("%d->", p->data);
        p = p->link;
    } while (p != head->link);
    printf("����Ʈ�� ��\n");
}

ListNode* insert_first(ListNode* head, element data)
{
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    node->data = data;
    if (head == NULL) {
        head = node;
        node->link = head;
    }
    else {
        node->link = head->link;
        head->link = node;
    }
    return head;
}

ListNode* insert_last(ListNode* head, element data)
{
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    node->data = data;
    if (head == NULL) {
        head = node;
        node->link = head;
    }
    else {
        node->link = head->link;
        head->link = node;
        head = node;
    }
    return head;
}

ListNode* delete_first(ListNode* head)
{
    ListNode* temp;
    if (head == NULL) {
        printf("����Ʈ�� ��� ������ ����\n");
        return NULL;
    }
    else if (head == head->link) { //��� �ϳ� ������ ��
        temp = head;
        head = NULL;
        free(temp);
    }
    else {
        temp = head->link;
        head->link = temp->link;
        free(temp);
    }
    return head;
}

ListNode* delete_last(ListNode* head)
{
    ListNode* temp;
    ListNode* pre;
    if (head == NULL) {
        printf("����Ʈ�� ����־� ������ ����\n");
        return NULL;
    }
    else if (head==head->link) { //��� �ϳ� ������ ��
        temp = head;
        head = NULL;
        free(temp);
    }
    else {
        pre = head;
        while (pre->link != head)
            pre = pre->link;
        temp = head;
        pre->link = head->link;
        head = pre;
        free(temp);
    }
    return head;
}

ListNode* search(ListNode* head, element data)
{
    ListNode* node = head;
    if (head == NULL) {
        printf("����Ʈ�� �������\n");
        return NULL;
    }
    do {
        if (node->data == data)
            return node;
        node = node->link;
    } while (node != head);
    return NULL;
}

int get_size(ListNode* head)
{
    int size = 0;
    ListNode* temp = head;

    if (head == NULL)
        return 0;
    do {
        size += 1;
        temp = temp->link;
    } while (temp != head);

    return size;
}

int main(void)
{
    ListNode* head = NULL;
    ListNode* temp = (ListNode*)malloc(sizeof(ListNode));
    temp = delete_last(head);

    head = insert_last(head, 20);
    print_list(head);

    head = insert_last(head, 30);
    print_list(head);
    head = insert_last(head, 40);
    print_list(head);
    head = insert_first(head, 10);
    print_list(head);

    printf("���� ����Ʈ�� ����: %d\n", get_size(head));

    temp = search(head, 10);
    if (temp == NULL)
        printf("Ž�� ����\n");
    else
        printf("%d Ž�� ����\n", temp->data);

    head = delete_first(head);
    print_list(head);

    return 0;
}