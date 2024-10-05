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
        error("��ġ ����");
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
        error("������ �׸��� ����");
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
        error("������ �׸��� ����");

    if (temp->link == NULL) { //node 1��
        removed = temp->link;
        temp->link = NULL;
        free(removed);
        return NULL;
    }
    else { //node 2�� �̻�
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
        error("������ �׸��� ����");
    else if (pos < 0 || pos >= get_length(head))
        error("��ġ ����");
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
        error("head�� �������");
    else if (pos < 0 || pos >= get_length(head))
        error("��ġ ����");
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
    printf("a: �ؽ�Ʈ ���� ���� �߰�\n");
    printf("i: ���� ��ȣ�� ���� �߰�\n");
    printf("d: ���� ��ȣ�� ���� ����\n");
    printf("v: ���� ��ȣ�� �ش� ���� ���\n");
    printf("p: ��ü �ؽ�Ʈ ���\n");
    printf("q: ��\n");

    printf("�޴� ����: ");
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
            printf("�ؽ�Ʈ ���� ������ ����: ");
            while (getchar() != '\n');
            fgets(newElement.line, MAX_CHAR_PER_LINE, stdin);
            newElement.line[strcspn(newElement.line, "\n")] = '\0';
            list = insert_last(list, newElement);
            display_te(list);
            break;

        case 'i':
            printf("������ ���� ��ȣ: ");
            scanf("%d", &lineNb);
            while (getchar() != '\n');
            printf("������ ����: ");
            fgets(newElement.line, MAX_CHAR_PER_LINE, stdin);
            newElement.line[strcspn(newElement.line, "\n")] = '\0';
            list = insert_pos(list, lineNb - 1, newElement);
            display_te(list);
            break;

        case 'd':
            printf("������ ���� ��ȣ: ");
            scanf("%d", &lineNb);
            list = delete_pos(list, lineNb - 1);
            display_te(list);
            break;

        case 'v':
            printf("����� ���� ��ȣ: ");
            scanf("%d", &lineNb);
            printf("----------text edited---------\n");
            printf("(%d) %s\n", lineNb, get_entry(list, lineNb - 1));
            break;

        case 'p':
            display_te(list);
        }
        while (getchar() != '\n'); //���� ���
    }
    return 0;
}