#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int base, height, area, width, perimeter;

	printf("밑변과 높이를 입력하세요: ");
	scanf("%d %d", &base, &height);

	area = base * height / 2;

	printf("밑변과 높이가 각각 %d와 %d인", base, height);
	printf(" 삼각형의 넓이는 %d이다\n", area);

	printf("직사각형의 가로와 높이를 입력하세요: ");
	scanf("%d %d", &width, &height);

	perimeter = width * 2 + height * 2;
	area = width * height;

	printf("가로와 높이가 각각 %d와 %d인", width, height);
	printf(" 직사각형의 둘레와 넓이는 %d와 %d이다\n", perimeter, area);

	return 0;
}