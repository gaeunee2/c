#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int radius;
	double area, circumference;
	const double PI = 3.141592;

	printf("Enter a radius: ");
	scanf("%d", &radius);

	area = radius * radius * PI;
	circumference = 2 * radius * PI;

	printf("The area of circle with %d: \t\t%lf\n", radius, area);
	printf("The circumference of a circle with %d: %lf\n", radius, circumference);

	return 0;
}