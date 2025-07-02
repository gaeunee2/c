#define _CRT_SECURE_NO_WARNINGS
#define MAX_SET_SIZE 10 
#define HAVE_ELEMENT 1 
#define DO_NOT_HAVE_ELEMENT 0 
#include <stdio.h>
#include <stdlib.h> 

int hasElement(int set[], int size, int element)
{
	int i;
	for (i = 0; i < size; i++)
		if (set[i] == element)
			return HAVE_ELEMENT;
	return DO_NOT_HAVE_ELEMENT;
}

void printSet(int set[], int size)
{
	int i;

	printf("{ ");
	for (i = 0; i < size; i++) {
		if (i == size - 1) {
			printf("%d ", set[i]);
			break;
		}
		printf("%d, ", set[i]);
	}
	printf("}\n");
}

int addOneElement(int set[], int size, int element)
{
	int i;

	if (hasElement(set, size, element))
		printf("It is redundant. Please retry.\n");
	else {
		set[size] = element;
		size++;
	}
	return size;
}

int setUnion(int set1[], int size1, int set2[], int size2, int setResult[])
{
	int i;
	int count = 0;

	for (i = 0; i < size1; i++)
		setResult[count++] = set1[i];

	for (i = 0; i < size2; i++)
		if (!hasElement(setResult, size1 + size2, set2[i]))
			setResult[count++] = set2[i];

	return count;
}

int setIntersecton(int set1[], int size1, int set2[], int size2, int setResult[])
{
	int i;
	int count = 0;

	for (i = 0; i < size2; i++)
		if(hasElement(set1, size1, set2[i]))
				setResult[count++] = set2[i];

	return count;
}

int setComplements(int set1[], int size1, int set2[], int size2, int setResult[])
{
	int i;
	int count = 0;

	for (i = 0; i < size1; i++) 
		if(!hasElement(set2, size2, set1[i]))
			setResult[count++] = set1[i];

	return count;
}

int main(int argc, char* argv[])
{
	int i;
	int setA[MAX_SET_SIZE];
	int setB[MAX_SET_SIZE];
	int setC[MAX_SET_SIZE * 2];

	int sizeA;
	int sizeB;
	int sizeC;

	printf("Enter the size of Set A:");
	scanf("%d", &sizeA);
	i = 0;
	while (i < sizeA) {
		printf("Enter the number for Set A (%d/%d):", i + 1, sizeA);
		scanf("%d", &setA[i]);
		i = addOneElement(setA, i, setA[i]);
	}

	printf("Enter the size of Set B:");
	scanf("%d", &sizeB);
	i = 0;
	while (i < sizeB)
	{
		printf("Enter the number for Set B (%d/%d):", i + 1, sizeB);
		scanf("%d", &setB[i]);
		i = addOneElement(setB, i, setB[i]);
	}

	printf("Set A: ");
	printSet(setA, sizeA);
	printf("Set B: ");
	printSet(setB, sizeB);

	sizeC = setUnion(setA, sizeA, setB, sizeB, setC);
	printf("Union of setA and setB: ");
	printSet(setC, sizeC);

	sizeC = setIntersecton(setA, sizeA, setB, sizeB, setC);
	printf("Intersection of setA and setB: ");
	printSet(setC, sizeC);

	sizeC = setComplements(setA, sizeA, setB, sizeB, setC);
	printf("Set-theoretic difference of setA and setB (setA - setB): ");
	printSet(setC, sizeC);

	return 0;
}