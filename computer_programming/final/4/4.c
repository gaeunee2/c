#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(void)
{
	char sentence[50]; // �� 49������ ���ڵ�� ���� ����
	char newSentence[50];
	char delimiters[] = " ,\n\0"; // �� ���� �и� ���ڵ�(����,�޸�,�ٹٲ�,�ι���) �����Ѵ� 

	fgets(sentence, sizeof(sentence), stdin); // ������ ������ ������ �Է�, �ܾ���� ��� ���ڷ� �Ǿ��ٰ� ����

	int len = 0;
	char* token;

	token = strtok(sentence, delimiters);
	strcpy(newSentence, token);
	len += strlen(token);
	token = strtok(NULL, delimiters);
	while (token != NULL) {
		len += strlen(token);
		strcat(newSentence, token);
		token = strtok(NULL, delimiters);
	}

	printf("%d\n", atoi(newSentence) * len);
}