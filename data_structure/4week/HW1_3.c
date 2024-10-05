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

ListNode* insert_next(ListNode* head, ListNode* pre, element value)
{
    ListNode* p = (ListNode*)malloc(sizeof(ListNode));
    p->data = value;
    p->link = pre->link;
    pre->link = p;

    return head;
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

ListNode* insert_pos(ListNode* head, int pos, element value)
{
    ListNode* pre = NULL;
    ListNode* temp = head;
    ListNode* p = (ListNode*)malloc(sizeof(ListNode));
    p->data = value;
    p->link = NULL;

    if (head == NULL)
        head = p;
    else if (pos < 0 || pos >= get_length(head))
        error("위치 오류");
    else {
        for (int i = 0; i < pos; i++) {
            pre = temp;
            temp = temp->link;
        }
        p->link = temp;
        if (pre != NULL)
            pre->link = p;
    }
    return head;
}

ListNode* delete_next(ListNode* head, ListNode* pre)
{
    ListNode* removed;
    removed = pre->link;
    pre->link = removed->link;
    free(removed);

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

ListNode* delete_pos(ListNode* head, int pos)
{
    ListNode* pre = NULL;
    ListNode* removed = head;

    if (head == NULL)
        error("삭제할 항목이 없음");
    else if (pos < 0 || pos >= get_length(head))
        error("위치 오류");
    else if (pos == 0) {
        head = removed->link;
        free(removed);
    }
    else {
        for (int i = 0; i < pos; i++) {
            pre = removed;
            removed = removed->link;
        }
        if (pre != NULL)
            pre->link = removed->link;
        free(removed);
    }
    return head;
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

element get_entry(ListNode* head, int pos)
{
    if (head == NULL)
        error("head가 비어있음");
    else if (pos < 0 || pos >= get_length(head))
        error("위치 오류");
    else {
        for (int i = 0; i < pos; i++)
            head = head->link;
        return head->data;
    }
}

int searchPos(ListNode* head, element w)
{
    ListNode* temp = head;
    int pos = 0;

    do {
        if (temp->data == w)
            return pos;
        temp = temp->link;
        pos += 1;
    } while (temp != NULL);
    printf("아이템 %d는 보유하고 있지 않습니다.\n");
    return -1;
}

ListNode* add_item(ListNode* head, element w)
{
    int total = 0;
    ListNode* temp = head;

    while (temp != NULL) {
        total += temp->data;
        temp = temp->link;
    }
    if (total + w > MAX_WEIGHT)
        printf("최대 무게<%dkg> 초과로 아이템 %d를 추가할 수 없음\n", MAX_WEIGHT, w);
    else
        head = insert_first(head, w);
    return head;
}

void display(ListNode* head)
{
    ListNode* temp = head;
    if (head == NULL) {
        printf("비어있음\n");
        return;
    }

    printf("< ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->link;
    }
    printf(">\n");
}

int main(void)
{
    ListNode* list = NULL;
    char choice;
    element weight;
    int pos;

    do {
        printf("enter a<dd>, d<elete> or q<uit>: ");
        scanf("%c", &choice);

        switch (choice)
        {
        case 'a':
            printf("enter the weight of the item: ");
            scanf("%d", &weight);
            list = add_item(list, weight);
            display(list);
            break;
        case 'd':
            printf("enter the weight of the item: ");
            scanf("%d", &weight);
            pos = searchPos(list, weight);
            if (pos !=-1)
                list = delete_pos(list, pos);
            display(list);
            break;
        }
        while (getchar() != '\n'); //버퍼 비움

    } while (choice != 'q');

    return 0;
}
