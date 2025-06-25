#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int isGenerousPassword(char passwd[], char wd[]) // 이 함수를 작성
{
	int i, j;
	int index = 0;
	int pre = -1;

	for (i = 0; passwd[i] != '\0'; i++) {
		for (j = pre + 1; wd[j] != '\0'; j++) {
			if (wd[j] == passwd[i]) {
				if (j > pre) {
					pre = j;
					break;
				}
				else
					return 0;
			}
		}
		if (wd[j] == '\0')
			return 0;
	}
	return 1;
}

int main(void) // 변경하지 말라
{
	char passwd[20], wd[20];

	scanf("%s", passwd);
	for (int i = 0; i < 4; i++) {
		scanf("%s", wd);
		printf("%d\n", isGenerousPassword(passwd, wd));
	}
}