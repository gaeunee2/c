#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int i, num, userAnswer, rightAnswer, count = 0;

	printf("몇 단을 연습하시겠습니까?: ");
	scanf("%d", &num);

	for (i = 1; i < 10; i++) {
		rightAnswer = num * i;

		printf("%d * %d = ", num, i);
		scanf("%d", &userAnswer);

		if (userAnswer == rightAnswer)
			count += 1;
	}
	printf("%d단의 구구단에서 %d개를 맞았습니다\n", num, count);

	return 0;
}
