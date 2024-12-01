#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 200

typedef struct {
	int key;
} element;

typedef struct {
	element heap[MAX_ELEMENT];
	int heap_size;
}HeapType;

void init(HeapType* h)
{
	h->heap_size = 0;
}

void insert_max_heap(HeapType* h, element item)
{
	int i;
	i = ++(h->heap_size);

	while ((i != 1) && (item.key > h->heap[i / 2].key)) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = item;
}

element delete_max_heap(HeapType* h)
{
	int parent, child;
	element item, temp;

	item = h->heap[1];
	temp = h->heap[(h->heap_size)--];
	parent = 1;
	child = 2;

	while (child <= h->heap_size) {
		if ((child < h->heap_size) &&
			(h->heap[child].key < h->heap[child + 1].key))
			child++;
		if (temp.key >= h->heap[child].key)
			break;

		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;
	return item;
}

void preorder(HeapType* h, int root)
{
	if (root > h->heap_size) return;
	printf("%d ", h->heap[root].key);
	preorder(h, root * 2);
	preorder(h, root * 2 + 1);
}

void print_heap(HeapType* h)
{
	int i;
	int level = 1;
	for (i = 1; i <= h->heap_size; i++) {
		printf("%d ", h->heap[i].key);
		if (i == level) {
			printf("\n");
			level = level * 2 + 1;
		}
	}
	printf("\n");
} 
int find(HeapType* h, int root, int key)
{
	if (root > h->heap_size) 
		return 0;
	if (h->heap[root].key == key) 
		return root;

	int left = find(h, root * 2, key);
	if (left != 0) return left;

	return find(h, root * 2 + 1, key);
}

void print_sorted_value(HeapType* h)
{
	HeapType tempHeap = *h;
	while (tempHeap.heap_size > 0) {
		element e = delete_max_heap(&tempHeap);
		printf("%d ", e.key);
	}
	printf("\n");
}

HeapType* modify_priority(HeapType* h, int old, int new)
{
	for (int i = 1; i <= h->heap_size; i++) {
		if (h->heap[i].key == old) {
			h->heap[i].key = new;

			if (new > old) {
				element temp = delete_max_heap(h);
				insert_max_heap(h, temp);
			}
			else {
				element item = h->heap[i];
				h->heap[i] = h->heap[h->heap_size--];
				insert_max_heap(h, item);
			}
			return;
		}
	}
}

int main(void)
{
	element e1 = { 10 }, e2 = { 5 }, e3 = { 30 }, eA = { 9 }, eB = { 19 }, eC = { 39 };
	element e4, e5, e6;
	int index;
	int key, oldKey, newKey;
	HeapType heap; // ���� ����
	init(&heap); // �ʱ�ȭ

	printf("Step1: ���Ե� 10, 5, 30 �� �߰������� 9, 19, 39 �� <����> �Ѵ�");
	insert_max_heap(&heap, e1);
	insert_max_heap(&heap, e2);
	insert_max_heap(&heap, e3);
	insert_max_heap(&heap, eA);
	insert_max_heap(&heap, eB);
	insert_max_heap(&heap, eC);

	printf("\nStep2: preorder, print_heap �Լ� �׽�Ʈ\n");
	preorder(&heap, 1);
	printf("\n\n");
	print_heap(&heap);

	e4 = delete_max_heap(&heap);
	printf("\n ����: ��Ʈ�� ������\n", e4.key);
	print_heap(&heap);
	printf("\nStep3: find �Լ� �׽�Ʈ\n");
	printf("ã�� key �Է�(-1 for exit):");
	scanf("%d", &key);
	while (key != -1) {
		if ((index = find(&heap, 1, key)) == 0)
			printf("%d �� ����\n", key);
		else
			printf("%d �� [%d]�� ����\n", key, index);
		printf("ã�� key �Է�(-1 for exit):");
		scanf("%d", &key);
	}
	printf("\nStep4: print_sorted_value �Լ� �׽�Ʈ\n");
	print_sorted_value(&heap);

	printf("\nStep5: modify_priority �Լ� �׽�Ʈ\n");
	printf("�ٲ� key �Է�(-1 for exit):");
	scanf("%d", &oldKey);
	while (oldKey != -1) {
		printf("�� key �Է�:");
		scanf("%d", &newKey);
		modify_priority(&heap, oldKey, newKey);
		print_heap(&heap);
		printf("�ٲ� key �Է�(-1 for exit):");
		scanf("%d", &oldKey);
	}
	return 0;
}