#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void save(int money);

int main(void)
{
	int money;

	printf("저금할 금액(-1 for exit):");
	scanf("%d", &money);
	while (money != -1)
	{
		save(money);
		printf("저금할 금액(-1 for exit):");
		scanf("%d", &money);
	}

	printf("입금 완료 \n");
	return 0;
}

void save(int money)
{
	static int acc = 0;
	acc += money;
	printf("현재까지의 입금액 %d \n", acc);
}