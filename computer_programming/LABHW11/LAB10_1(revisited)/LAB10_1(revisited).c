#include <stdio.h> 
#include <string.h> 

struct customer {
	char name[40];
	int age;
};

int main(void)
{
	//��)
	struct customer aCustomer = { "�ڼ���", 36 };
	printf("Name = %s, Age = %d\n", aCustomer.name, aCustomer.age);

	//��)
	int i;
	struct customer cArray[2] = { {"�嵿��", 38}, {"��ҿ�", 38} };
	for (i = 0; i < 2; i++)
		printf("Name = %s, Age = %d\n", cArray[i].name, cArray[i].age);

	//��)
	struct customer *cp = &aCustomer;
	printf("Name = %s, Age = %d\n", cp->name, cp->age);

	//��)
	cp = &cArray;
	for (i = 0; i < 2; i++) {
		printf("Name = %s, Age = %d\n", cp->name, cp->age);
		cp++;
	}
}