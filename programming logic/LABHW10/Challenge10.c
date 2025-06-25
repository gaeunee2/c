#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
void printFibo(int n);

int main(void)
{
	int num, i;

	printf("��� �Ǻ���ġ �������� ����ұ��?(3���� ū ����): ");
	scanf("%d", &num);

	for (i = 0; i < num; i++)
		printFibo(i);
	printf("\n");

	return 0;
}

void printFibo(int n)
{
	int i, a = 1, b = 1, temp;

	if (n == 0)
		printf("%d ", a);
	else if (n == 1)
		printf("%d ", b);
	else {
		for (i = 2; i <= n; i++) {
			temp = a + b;
			a = b;
			b = temp;
		}
		printf("%d ", b);
	}

	return;
}