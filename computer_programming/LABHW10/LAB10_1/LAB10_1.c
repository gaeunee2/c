struct customer {
	char name[40];
	int age;
};

#include <stdio.h> 
#include <string.h> 
int main(void)
{
	struct customer aCustomer = { "박수희", 36 };
	struct customer cArray[2] = { {"장동건", 38}, {"고소영", 38} };
	int i;

	printf("Name = %s, Age = %d\n", aCustomer.name, aCustomer.age);

	for (i = 0; i < 2; i++)
		printf("Name = %s, Age = %d\n", &cArray[i].name, cArray[i].age);
}