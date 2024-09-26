#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

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

ListNode* insert_first(ListNode* head, int value)
{
    ListNode* p = (ListNode*)malloc(sizeof(ListNode));
    p->data = value;
    p->link = head;
    head = p;

    return head;
}

ListNode* insert_last(ListNode* head, int value)
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

ListNode* delete_by_key(ListNode* head, int key)
{
    ListNode* pre = NULL;
    ListNode* removed = head;

    if (head == NULL)
        error("삭제할 항목이 없음");

    while (removed != NULL) {
        if (removed->data == key) {
            if (pre != NULL)
                pre->link = removed->link;
            free(removed);
            return head;
        }
        pre = removed;
        removed = removed->link;
    }
    error("key값 없음");
}

void print_list(ListNode* head)
{
    ListNode* p;
    for (p = head; p != NULL; p = p->link)
        printf("%d->", p->data);
    printf("NULL \n");
}

int is_in_list(ListNode* head, element item)
{
    while (head != NULL) {
        if (head->data == item)
            return 1;
        head = head->link;
    }
    return 0;
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

int get_total(ListNode* head)
{
    int total = 0;
    while (head != NULL) {
        total += head->data;
        head = head->link;
    }
    return total;
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

int main(void)
{
    ListNode* list1 = NULL, * list2 = NULL, * list3 = NULL;
    int i;

    list1 = insert_first(list1, 10);
    list1 = insert_first(list1, 20);
    list1 = insert_first(list1, 30);
    printf("list1 = ");
    print_list(list1);

    list1 = delete_first(list1);
    printf("list1 = ");
    print_list(list1);

    list2 = insert_last(list2, 11);
    list2 = insert_last(list2, 22);
    list2 = insert_last(list2, 33);
    list2 = insert_last(list2, 44);
    printf("list2 = ");
    print_list(list2);

    list2 = delete_last(list2);
    printf("list2 = ");
    print_list(list2);

    while (list2 != NULL) {
        list3 = insert_first(list3, list2->data);
        list2 = list2->link;
    }
    printf("list3 = ");
    print_list(list3);

    ListNode* temp = list1;
    while (temp->link != NULL)
        temp = temp->link;
    temp->link = list3;
    printf("list1 = ");
    print_list(list1);

    //item이 리스트에 있으면 1, 없으면 0 반환
    printf("list1에 50이 있으면 1, 없으면 0: ");
    printf("%d\n", is_in_list(list1, 50));

    //단순 연결 리스트에 존재하는 노드 수 반환
    printf("list1에 존재하는 노드 수: ");
    printf("%d\n", get_length(list1));

    //단순 연결 리스트의 모든 데이터 값 더한 합 반환
    printf("list1 모든 데이터 합: ");
    printf("%d\n", get_total(list1));

    //pos위치에 있는 노드 data 반환
    printf("3 index 노드 데이터: ");
    printf("%d\n", get_entry(list1, 3));

    delete_by_key(list1, 10);
    printf("key값 10 삭제 후: ");
    print_list(list1);

    insert_pos(list1, 2, 100); //pos위치에 value갖는 노드 추가
    printf("2위치에 100 노드 추가 후: ");
    print_list(list1);

    delete_pos(list1, 2); //pos 위치 노드 삭제
    printf("2위치 제거 후: ");
    print_list(list1);
}