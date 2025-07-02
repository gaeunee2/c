#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <stdlib.h>
#include <time.h>

int main(void)
{
	srand(time(NULL));
	int i, state, random, max = -1, sum = 0;
	FILE* fp1, * fp2;

	fp1 = fopen("random.txt", "wt");

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

	while (fscanf(fp1, "%d", &random) != EOF) {
		fprintf(stdout, "%5d", random);
		fprintf(fp1, "%d\n", random);
		sum += random;
		if (random > max)
			max = random;
	}
	fprintf(stdout, "\n합은 %d\n", sum);
	fprintf(stdout, "max값 %d\n", max);
	fclose(fp1);

	fp1 = fopen("random.txt", "rt");
	if (fp1 == NULL)
	{
		printf("file open error!\n");
		return 1;
	}
	fp2 = fopen("output.txt", "wt");

	sum = 0;
	max = -1;
	
	fscanf(fp1, "%d", &random);
	while (!feof(fp1)) {
		fprintf(fp2, "%d\n", random);
		fscanf(fp1, "%d", &random);
		sum += random;

		if (random > max)
			max = random;
	}
	fprintf(fp2, "합은 %d\n", sum);
	fprintf(fp2, "max값 %d\n", max);

	fclose(fp1);
	fclose(fp2);
}