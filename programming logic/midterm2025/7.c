#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int i, k, rslt;
	int count = 0;
	int j = 0;

	scanf("%d", &k);

	for (i = 1; count < k; i++) {
		int num = i;
		int n = num;
		j = 0;
		while (n != 0) {
			count += 1;
			if (k == count) {
				rslt = num;
				break;
			}
			n /= 10;
			j += 1;
		}
	}
	if (j == 0)
		while (rslt / 10 != 0)
			rslt /= 10;
	else if (j == 1) {
		while (rslt / 10 / 10 != 0)
			rslt /= 10;
		rslt = rslt % 10;
	}
		
	printf("%d\n", rslt);

	return 0;
}