#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int i, num, userAnswer, rightAnswer, count = 0;

	printf("�� ���� �����Ͻðڽ��ϱ�?: ");
	scanf("%d", &num);

	for (i = 1; i < 10; i++) {
		rightAnswer = num * i;

		printf("%d * %d = ", num, i);
		scanf("%d", &userAnswer);

		if (userAnswer == rightAnswer)
			count += 1;
	}
	printf("%d���� �����ܿ��� %d���� �¾ҽ��ϴ�\n", num, count);

	return 0;
}