#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h> 
int main(void)
{
	int a[20];
	int i, n;
	int best = -1;
	int worst = 101;
	int sum = 0;
	int bf = 1, wf = 1;

	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);

		if (a[i] > best)
			best = a[i];
		if (a[i] < worst)
			worst = a[i];
	}

	for (i = 0; i < n; i++) {
		if (a[i] == best && bf == 1)
			bf = 0;
		else if (a[i] == worst && wf == 1)
			wf = 0;
		else
			sum += a[i];
	}
	printf("%d\n", sum / (n - 2));

	return 0;
}