#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int base, height, area, width, perimeter;

	printf("�غ��� ���̸� �Է��ϼ���: ");
	scanf("%d %d", &base, &height);

	area = base * height / 2;

	printf("�غ��� ���̰� ���� %d�� %d��", base, height);
	printf(" �ﰢ���� ���̴� %d�̴�\n", area);

	printf("���簢���� ���ο� ���̸� �Է��ϼ���: ");
	scanf("%d %d", &width, &height);

	perimeter = width * 2 + height * 2;
	area = width * height;

	printf("���ο� ���̰� ���� %d�� %d��", width, height);
	printf(" ���簢���� �ѷ��� ���̴� %d�� %d�̴�\n", perimeter, area);

	return 0;
}