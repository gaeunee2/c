#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int isASeries(int a[], int size) // �� �Լ��� �ۼ�
{
	int i;

	for (i = 0; i < size - 1; i++)
		if (a[i] == a[i + 1])
			return 0;
	return 1;
}

int main(void) { // �������� ����
	int M;
	int a[100];
	scanf("%d", &M);
	for (int k = 0; k < 4; k++) {
		for (int i = 0; i < M; i++)
			scanf("%d", &a[i]);
		printf("%d\n", isASeries(a, M));
	}
	return 0;
}