#include <stdio.h>
int main(void)
{
	int data[5] = { 10, 20, 30, 40, 50 };
	int* p = data;
	printf("%d %u %p\n\n", p, p, p); //A)
	printf("%d %d\n", p, *p);
	printf("%d\n", *p++);
	printf("%d %d\n\n", p, *p);
	p = data; // �ٽ� ù ��° ��Ҹ� ����Ű�� �� ��
	printf("%d %d\n", p, *p);
	printf("%d\n", (*p)++);
	printf("%d %d\n", p, *p);
}