#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int i, num;

	printf("Enter a number: ");
	scanf("%d", &num);

	if (num < 2) {
		printf("�Ҽ��� �ƴϴ�\n");
		return;
	}

	for (i = 2; i < num; i++) {
		if (num % i == 0) {
			printf("�Ҽ��� �ƴϴ�\n");
			return;
		}
	}
	printf("�Ҽ��̴�\n");

	return 0;
}