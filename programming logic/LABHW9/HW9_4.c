#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
int main(void)
{
	int i, prime = 2, count = 1;

	do {
		for (i = 2; i < prime; i++)
			if (prime % i == 0)
				break;
		if (i == prime) {
			printf("%d번째 소수는 %d\n", count, prime);
			count++;
		}
		prime++;
	} while (count <= 10);

	return 0;
}