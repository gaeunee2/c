#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(void)
{
	char sentence[50]; // �� 49������ ���ڵ�� ���� ����
	char delimiters[] = " ,\n\0"; // �� ���� �и� ���ڵ�(����,�޸�,�ٹٲ�,�ι���) �����Ѵ� 

	fgets(sentence, sizeof(sentence), stdin); // ������ ������ ������ �Է�, �ܾ���� ��� ���ڷ� �Ǿ��ٰ� ����

	int sum = 0;
	char* token;

	token = strtok(sentence, delimiters);
	
	while (token != NULL) {
		sum += atoi(token);
		token = strtok(NULL, delimiters);
	}

	printf("%d\n", sum); // ����1
}