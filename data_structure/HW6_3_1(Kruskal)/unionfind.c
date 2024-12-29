#include <stdio.h>
#include <stdlib.h>
#include "unionfind.h"

#define MAX_VERTICES 100

int parent[MAX_VERTICES];		// �θ� ����� index�� ����; ������ ��ǥ ���ҿ� ���ؼ��� -(�� ���տ� ���� ������ ����)�� �����Ѵ�.

void set_init(int n)
{
	int i;
	for (i = 0; i < n; i++)
		parent[i] = -1;
}

int set_find(int curr)
{
	if (parent[curr] == -1)
		return curr;
	while (parent[curr] != -1)
		curr = parent[curr];
	return curr;
}

void set_union(int s1, int s2)
{
	int root1 = set_find(s1);
	int root2 = set_find(s2);
	if (root1 != root2)
		parent[root1] = root2;
}