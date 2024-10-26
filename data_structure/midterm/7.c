#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 200
typedef int element;
typedef struct {
	element tree[MAX_ELEMENT];
	int tree_size;
} TreeType;

TreeType* create() // �������� ����
{
	return (TreeType*)malloc(sizeof(TreeType));
}
// �ʱ�ȭ �Լ�
void init(TreeType* h)
{
	h->tree_size = 0;
}
// ���� ����� ������ tree_size�� ���� h�� item�� �����Ѵ�.
// ���� �Լ�
void make_tree(TreeType* h, element item) // �������� ����. ���� ����� �ʾ����� � ��Ģ���� Ʈ���� ��带 �����Ѵ�.
{
	int i;
	i = ++(h->tree_size);

	//  Ʈ���� �Ž��� �ö󰡸鼭 �θ� ���� ���ϴ� ����
	while ((i != 1) && (item > h->tree[i / 2])) {
		h->tree[i] = h->tree[i / 2];
		i /= 2;
	}
	h->tree[i] = item;     // ���ο� ��带 ����

}

void preorder_array(TreeType* h, int id) // �� �Լ��� �ۼ�(��ĭ �ֱ⹮���� ��ĭ�� �Ϻ� ���ܵ� ������)
{
	if (id > h->tree_size)
		return;

	printf("%d ", h->tree[id]);

	preorder_array(h, id * 2);
	preorder_array(h, id * 2 + 1);
}
int main(void) // �������� ����
{
	element e;
	int data;
	TreeType* pTree;

	pTree = create(); 	// Ʈ�� ����
	init(pTree);	// �ʱ�ȭ

	// A)
	scanf("%d", &data);
	while (data != -1) {
		make_tree(pTree, data);
		scanf("%d", &data);
	}

	preorder_array(pTree, 1);

	return 0;
}