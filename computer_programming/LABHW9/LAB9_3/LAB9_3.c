#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 
int main(void)
{
	char str1[15] = "ABCDED";
	char str2[15] = "abcde";
	char str3[15] = "1234";
	char str4[15];
	int n;

	char s[] = "Life is short, but art is long";
	char delimiters[] = " ,\n\0"; // 네 개의 분리 문자들(공백,콤마,줄바꿈,널문자) 지정한다
	char* token;

	printf("가)str1 의 길이 = %d\n", strlen(str1));
	printf(" str2 의 길이 = %d\n", strlen(str2));

	strcpy(str1, str2);
	printf("나)str1 = %s\t\tstr2 = %s\n", str1, str2);

	strncpy(str4, str3, 2); // strncpy는자동으로 ‘\0’을넣지않음에주의하자!
	str4[2] = '\0';
	printf("다)str4 = %s\t\tstr3 = %s\n", str4, str3);

	strcat(str1, str2);
	printf("라)str1 = %s\tstr2 = %s\n", str1, str2);

	strncat(str1, str3, 2); // strncat 는 ‘\0’을 자동으로 넣는다! 
	printf("마)str1 = %s\tstr3 = %s\n", str1, str3);

	printf("바)%d %d %d\n", strcmp("aaa", "abc"), strcmp("aaa", "aaa"), strcmp("ddd", "ccc", str3));
	strcpy(str1, "111");
	n = atoi(str1) * 7;
	printf("사)str1 를 7 배 한 값은 %d\n", n);

	printf("아)\n"); // 중요!! 
	n = 1;
	token = strtok(s, delimiters);
	while (token != NULL)
	{
		printf("%d 번째 토큰은 %s\n", n++, token);
		token = strtok(NULL, delimiters);
	}
}