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
			printf("%d��° �Ҽ��� %d\n", count, prime);
			count++;
		}
		prime++;
	} while (count <= 10);

	return 0;
}