#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 200
typedef int element;
typedef struct {
	element tree[MAX_ELEMENT];
	int tree_size;
} TreeType;

TreeType* create() // 변경하지 말라
{
	return (TreeType*)malloc(sizeof(TreeType));
}
// 초기화 함수
void init(TreeType* h)
{
	h->tree_size = 0;
}
// 현재 요소의 개수가 tree_size인 히프 h에 item을 삽입한다.
// 삽입 함수
void make_tree(TreeType* h, element item) // 변경하지 말라. 아직 배우지 않았으나 어떤 규칙으로 트리에 노드를 삽입한다.
{
	int i;
	i = ++(h->tree_size);

	//  트리를 거슬러 올라가면서 부모 노드와 비교하는 과정
	while ((i != 1) && (item > h->tree[i / 2])) {
		h->tree[i] = h->tree[i / 2];
		i /= 2;
	}
	h->tree[i] = item;     // 새로운 노드를 삽입

}

void preorder_array(TreeType* h, int id) // 이 함수를 작성(빈칸 넣기문제로 빈칸을 일부 남겨도 괜찮다)
{
	if (id > h->tree_size)
		return;

	printf("%d ", h->tree[id]);

	preorder_array(h, id * 2);
	preorder_array(h, id * 2 + 1);
}
int main(void) // 변경하지 말라
{
	element e;
	int data;
	TreeType* pTree;

	pTree = create(); 	// 트리 생성
	init(pTree);	// 초기화

	// A)
	scanf("%d", &data);
	while (data != -1) {
		make_tree(pTree, data);
		scanf("%d", &data);
	}

	preorder_array(pTree, 1);

	return 0;
}