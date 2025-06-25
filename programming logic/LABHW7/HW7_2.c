#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	char operator;
	int operand1, operand2, userAnswer, rightAnswer;

	printf("Enter an operator: ");
	scanf("%c", &operator);
	printf("Enter the first operand: ");
	scanf("%d", &operand1);
	printf("Enter the second operand: ");
	scanf("%d", &operand2);

	switch (operator) {
	case '+':
		rightAnswer = operand1 + operand2;
		break;
	case '-':
		rightAnswer = operand1 - operand2;
		break;
	case '*':
		rightAnswer = operand1 * operand2;
		break;
	case '/':
		rightAnswer = operand1 / operand2;
	default:
		break;
	}

	printf("%d %c %d = ", operand1, operator, operand2);
	scanf("%d", &userAnswer);

	switch (userAnswer - rightAnswer) {
	case 0:
		printf("Right answer\n");
		break;
	default:
		printf("Wrong!\n%d is the right answer\n", rightAnswer);
		break;
	}

	return 0;
}