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

element delete_max_heap(HeapType* h) {
	int parent, child;
	element item, temp;

	item = h->heap[1];
	temp = h->heap[(h->heap_size)--];
	parent = 1;
	child = 2;

	while (child <= h->heap_size) {
		if ((child < h->heap_size) && (h->heap[child].key < h->heap[child + 1].key))
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
void read_heap(HeapType* h, char* filename){	FILE* file = fopen(filename, "r");
	if (file == NULL) {
		printf("파일을 열 수 없습니다: %s\n", filename);
		return;
	}

	int key;
	while (fscanf(file, "%d", &key) != EOF) {
		element item = { key };
		insert_max_heap(h, item);
	}

	fclose(file);
	printf("읽기완료 %s\n", filename);}void write_heap_array(HeapType* h, char* filename){	FILE* file = fopen(filename, "w");
	if (file == NULL) {
		printf("파일을 열 수 없습니다: %s\n", filename);
		return;
	}

	for (int i = 1; i <= h->heap_size; i++) {
		fprintf(file, "%d ", h->heap[i].key);
	}
	fprintf(file, "\n");
	fclose(file);
	printf("저장완료 %s\n", filename);}void write_descending_order(HeapType* h, char* filename){	FILE* file = fopen(filename, "w");
	if (file == NULL) {
		printf("파일을 열 수 없습니다: %s\n", filename);
		return;
	}

	HeapType tempHeap = *h;
	while (tempHeap.heap_size > 0) {
		element e = delete_max_heap(&tempHeap);
		fprintf(file, "%d ", e.key);
	}
	fprintf(file, "\n");
	fclose(file);
	printf("내림차순 저장완료 %s\n", filename);}int main(void)
{
	HeapType heap;
	element e1 = { 20 }, e2 = { 40 };
	init(&heap);
	read_heap(&heap, "input.txt");
	insert_max_heap(&heap, e1);
	insert_max_heap(&heap, e2);

	write_heap_array(&heap, "heapArray.txt");
	write_descending_order(&heap, "sorted.txt");

	return 0;
}