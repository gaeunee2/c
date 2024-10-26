#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_WEIGHT 100

typedef int element;

typedef struct ListNode {
    element data;
    struct ListNode* link;
} ListNode;

void error(char* message)
{
    fprintf(stderr, "%s\n", message);
    exit(1);
}

ListNode* insert_first(ListNode* head, element value)
{
    ListNode* p = (ListNode*)malloc(sizeof(ListNode));
    p->data = value;
    p->link = head;
    head = p;

    return head;
}

ListNode* insert_last(ListNode* head, element value)
{
    ListNode* temp = head;
    ListNode* p = (ListNode*)malloc(sizeof(ListNode));
    p->data = value;
    p->link = NULL;

    if (head == NULL)
        head = p;
    else {
        while (temp->link != NULL)
            temp = temp->link;
        temp->link = p;
    }
    return head;
}

ListNode* delete_first(ListNode* head)
{
    ListNode* removed;
    if (head == NULL)
        error("삭제할 항목이 없음");
    removed = head;
    head = removed->link;
    free(removed);

    return head;
}

ListNode* delete_last(ListNode* head)
{
    ListNode* temp = head;
    ListNode* prevTemp = NULL;
    ListNode* removed;

    if (head == NULL)
        error("삭제할 항목이 없음");

    if (temp->link == NULL) { //node 1개
        removed = temp->link;
        temp->link = NULL;
        free(removed);
        return NULL;
    }
    else { //node 2개 이상
        while (temp->link != NULL) {
            prevTemp = temp;
            temp = temp->link;
        }
        removed = temp;
        prevTemp->link = NULL;
        free(removed);
        return head;
    }
}

int get_length(ListNode* head)
{
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->link;
    }
    return count;
}

int main(void)
{
    int n;
    ListNode* list = NULL;

    scanf("%d", &n);

    for (int i = n; i >= 1; i--)
        list = insert_first(list, i);
    while (get_length(list) != 2) {
        list = delete_first(list);
        list = insert_last(list, list->data);
        list = delete_first(list);
    }
    list = delete_first(list);
    printf("%d\n", list->data);
}