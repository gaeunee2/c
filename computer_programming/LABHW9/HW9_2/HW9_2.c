#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <string.h> 
#include <conio.h>
#include <ctype.h>

int main(void)
{
	char num[14];
	char year[4];
	int average = 0;

	printf("�ֹε�Ϲ�ȣ �Է�<'-'����>:");
	fgets(num, sizeof(num), stdin);
	
	strncpy(year, num, 2);
	printf("����� 19%d�⵵ ���̱���\n", atoi(year));

	if (num[7] == '1') {
		printf("���ں��̽ñ���.\n");
		average = 77;
	}
	else {
		printf("���ں��̽ñ���.\n");
		average = 84;
	}

	printf("��� ���� %d�� ���ϸ� %d���� ��ٰ� ���˴ϴ�.\n", average, average + 1900 + atoi(year));
}