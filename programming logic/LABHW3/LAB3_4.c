#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int base, height, area;

	printf("�غ��� ���̸� �Է��ϼ���: ");
	scanf("%d %d", &base, &height);
	
	area = base * height / 2;

	printf("�غ��� ���̰� ���� %d�� %d�� �ﰢ���� ���̴� %d�̴�\n", base, height, area);

	return 0;
}