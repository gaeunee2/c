#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	char operator;
	int operand1, operand2, answer;

	printf("Enter an operator: ");
	scanf("%c", &operator);
	printf("Enter the first operand: ");
	scanf("%d", &operand1);
	printf("Enter the second operand: ");
	scanf("%d", &operand2);

	switch (operator) {
	case '+':
		answer = operand1 + operand2;
		break;
	case '-':
		answer = operand1 - operand2;
		break;
	case '*':
		answer = operand1 * operand2;
		break;
	case '/':
		answer = operand1 / operand2;
	default:
		break;
	}

	printf("%d %c %d = %d\n", operand1, operator, operand2, answer);

	return 0;
}