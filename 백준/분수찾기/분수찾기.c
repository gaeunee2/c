#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 1001
int main(void)
{
	int i, x;
	int n1 = 1, n2 = 1;
	int count = 1;
	int flag = 1;

	scanf("%d", &x);
	for (i = 0; i < x - 1; i++) {
		if (flag == 1) {
			if (n2 == count) {
				flag = 0;
				n2 += 1;
				count += 1;
			}
			else {
				n1 -= 1;
				n2 += 1;
			}
		}
		else {
			if (n1 == count) {
				flag = 1;
				n1 += 1;
				count += 1;
			}
			else {
				n2 -= 1;
				n1 += 1;
			}
		}
	}
	printf("%d/%d\n", n1, n2);

	return 0;
}