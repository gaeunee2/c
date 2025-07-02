#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <stdlib.h>
#include <time.h>

int main(void)
{
	srand(time(NULL));
	int i, state, random, sum = 0;
	FILE* fp1, * fp2;

	fp1 = fopen("random.txt", "wt");
	if (fp1 == NULL)
	{
		printf("file open error!\n");
		return 1;
	}

	for (i = 0; i < 10; i++) {
		fprintf(fp1, "%d\n", rand() % 100);
	}
	fclose(fp1);

	fp1 = fopen("random.txt", "rt");
	if (fp1 == NULL)
	{
		printf("file open error!\n");
		return 1;
	}

	fscanf(fp1, "%d", &random);
	while (!feof(fp1)) {
		fprintf(stdout, "%5d", random);
		fscanf(fp1, "%d", &random);
		sum += random;
	}
	fprintf(stdout, "\n합은 %d\n", sum);
	fclose(fp1);

	fp1 = fopen("random.txt", "rt");
	fp2 = fopen("output.txt", "wt");

	sum = 0;
	fscanf(fp1, "%d", &random);
	while (!feof(fp1)) {
		fprintf(fp2, "%d\n", random);
		fscanf(fp1, "%d", &random);
		sum += random;
	}
	fprintf(fp2, "합은 %d\n", sum);

	fclose(fp1);
	fclose(fp2);
}