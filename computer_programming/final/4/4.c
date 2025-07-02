#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(void)
{
	char sentence[50]; // 총 49이하의 문자들로 문장 구성
	char newSentence[50];
	char delimiters[] = " ,\n\0"; // 네 개의 분리 문자들(공백,콤마,줄바꿈,널문자) 지정한다 

	fgets(sentence, sizeof(sentence), stdin); // 공백을 포함한 문장을 입력, 단어들은 모두 숫자로 되었다고 가정

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