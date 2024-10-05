#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_CHAR_PER_LINE 100 

typedef struct {
    char line[MAX_CHAR_PER_LINE];
} element;

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

void display_te(ListNode * head)
{
    printf("----------text edited---------\n");
    for (int i = 1; head != NULL; i++) {
        printf("(%d) %s\n", i, head->data.line);
        head = head->link;
    }
}

char askChoice(void)
{
    char choice;
    printf("------------------------------\n");
    printf("a: 텍스트 끝에 라인 추가\n");
    printf("i: 라인 번호로 라인 추가\n");
    printf("d: 라인 번호로 라인 삭제\n");
    printf("v: 라인 번호로 해당 라인 출력\n");
    printf("p: 전체 텍스트 출력\n");
    printf("q: 끝\n");

    printf("메뉴 선택: ");
    scanf("%c", &choice);
    return choice;
}

int main(void)
{
    ListNode* list = NULL;
    char choice;
    int lineNb;
    element newElement;

    while ((choice = askChoice()) != 'q') {
        switch (choice) {
        case 'a':
            printf("텍스트 끝에 삽입할 라인: ");
            while (getchar() != '\n');
            fgets(newElement.line, MAX_CHAR_PER_LINE, stdin);
            newElement.line[strcspn(newElement.line, "\n")] = '\0';
            list = insert_last(list, newElement);
            display_te(list);
            break;

        case 'i':
            printf("삽입할 라인 번호: ");
            scanf("%d", &lineNb);
            while (getchar() != '\n');
            printf("삽입할 라인: ");
            fgets(newElement.line, MAX_CHAR_PER_LINE, stdin);
            newElement.line[strcspn(newElement.line, "\n")] = '\0';
            list = insert_pos(list, lineNb - 1, newElement);
            display_te(list);
            break;

        case 'd':
            printf("삭제할 라인 번호: ");
            scanf("%d", &lineNb);
            list = delete_pos(list, lineNb - 1);
            display_te(list);
            break;

        case 'v':
            printf("출력할 라인 번호: ");
            scanf("%d", &lineNb);
            printf("----------text edited---------\n");
            printf("(%d) %s\n", lineNb, get_entry(list, lineNb - 1));
            break;

        case 'p':
            display_te(list);
        }
        while (getchar() != '\n'); //버퍼 비움
    }
    return 0;
}