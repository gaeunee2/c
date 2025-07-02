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

int isSetEqual(int set1[], int size1, int set2[], int size2)
{
	int i;

	if (size1 == size2)
		for (i = 0; i < size1; i++)
			if (hasElement(set2, size1, set1[i])) 
				return 1;
	else
		return 0;
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

int main(void)
{
	int setA[MAX_SET_SIZE] = { 1, 2, 3 };
	int setB[MAX_SET_SIZE] = { 3, 2, 1, 4 };
	int num;
	int sizeA = 3, sizeB = 4;

	printf("A:"); printSet(setA, sizeA);
	printf("B:"); printSet(setB, sizeB);
	if (isSetEqual(setA, sizeA, setB, sizeB))
		printf("집한 A 와 B는 같다\n");
	else
		printf("집한 A 와 B는 다르다\n\n");
	printf("A 에 3 을 추가하면\n");
	sizeA = addOneElement(setA, sizeA, 3);
	printf("집합 A:"); printSet(setA, sizeA);
	printf("A 에 4 를 추가하면\n");
	sizeA = addOneElement(setA, sizeA, 4);
	printf("집합 A:"); printSet(setA, sizeA);
	if (isSetEqual(setA, sizeA, setB, sizeB))
		printf("집한 A 와 B는 같다\n");
	else
		printf("집한 A 와 B는 다르다\n");
}