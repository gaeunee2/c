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

	printf("주민등록번호 입력<'-'포함>:");
	fgets(num, sizeof(num), stdin);
	
	strncpy(year, num, 2);
	printf("당신은 19%d년도 생이군요\n", atoi(year));

	if (num[7] == '1') {
		printf("남자분이시군요.\n");
		average = 77;
	}
	else {
		printf("여자분이시군요.\n");
		average = 84;
	}

	printf("평균 수명 %d를 더하면 %d까지 산다고 계산됩니다.\n", average, average + 1900 + atoi(year));
}