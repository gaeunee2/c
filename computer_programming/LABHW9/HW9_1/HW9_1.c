#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <string.h> 
#include <conio.h>
#include <ctype.h>

int main(void)
{
	int i, alphaIndex = 0, digitIndex = 0;
	char string[50]; // �ԷµǴ� ���ڿ��� ����
	char alphaString1[50]; // �Է¹��ڿ����� ���ĺ��� ����
	char alphaString2[50]; // ��ҹ��ڸ� �ٲ�
	char digitString[50];
	char convertedString[50]; // ���ڵ�� ���ڵ�� ��迭�� ���ڿ�

	printf("���ڿ��� �Է��ϼ���:");
	fgets(string, sizeof(string), stdin);
	
	for (i = 0; string[i] != '\0'; i++) {
		if (isalpha(string[i]) != 0)
			alphaString1[alphaIndex++] = string[i];
		else if (isdigit(string[i]) != 0)
			digitString[digitIndex++] = string[i];
	}
	alphaString1[alphaIndex] = '\0';
	digitString[digitIndex] = '\0';

	printf("���ڵ��� %s\n", alphaString1);
	printf("���ڵ��� %s\n", digitString);

	alphaIndex = 0;
	for (i = 0; alphaString1[i] != '\0'; i++) {
		if (isupper(alphaString1[i]))
			alphaString2[alphaIndex++] = tolower(alphaString1[i]);
		else
			alphaString2[alphaIndex++] = toupper(alphaString1[i]);
	}
	alphaString2[alphaIndex] = '\0';

	strcpy(convertedString, alphaString1);
	strcat(convertedString, digitString);

	printf("��ҹ��ڸ� �ٲ� ���ڵ��� %s\n", alphaString2);
	printf("���ڵ�� ���ڵ�� ��迭�� ���ڿ��� %s\n", convertedString);
}