#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int radius;
	double area;
	const double PI = 3.141592;

	printf("Enter a radius: ");
	scanf("%d", &radius);

	area = radius * radius * PI;

	printf("The area of circle with %d: \t%lf.\n", radius, area);

	return 0;
}