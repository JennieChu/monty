#include "monty.h"

/**
 * stk_sub - subtracts the top element of stack from the second element
 * @stack: head to the stack
 * @ln: line number where the opcode is located
 */

void stk_sub(stack_t **stack, unsigned int ln)
{
	stack_t *temp, *temp2;

	temp = (*stack);
	temp2 = temp->next;
	if (temp2 == NULL)
	{
		printf("L<%d>: can't sub, stack too short\n", ln);
		exit(EXIT_FAILURE);
	}
	temp2->n = temp2->n - temp->n;
	delete_stack_head(stack);
}

/**
 * stk_div - divides the second top element of stack from the top element
 * @stack: head to the stack
 * @ln: line number where the opcode is located
 */

void stk_div(stack_t **stack, unsigned int ln)
{
	stack_t *temp, *temp2;

	temp = (*stack);
	temp2 = temp->next;
	if (temp2 == NULL)
	{
		printf("L<%d>: can't div, stack too short\n", ln);
		exit(EXIT_FAILURE);
	}
	if (temp->n == 0)
	{
		printf("L<%d>: division by zero\n", ln);
		exit(EXIT_FAILURE);
	}
	temp2->n = (int)(temp2->n / temp->n);
	delete_stack_head(stack);
}

/**
 * stk_mul - multiplies the top two elements of the stack
 * @stack: head to the stack
 * @ln: line number where the opcode is located
 */

void stk_mul(stack_t **stack, unsigned int ln)
{
	stack_t *temp, *temp2;

	temp = (*stack);
	temp2 = temp->next;
	if (temp2 == NULL)
	{
		printf("L<%d>: can't mul, stack too short\n", ln);
		exit(EXIT_FAILURE);
	}
	temp2->n = temp2->n * temp->n;
	delete_stack_head(stack);
}

/**
 * stk_mod - divides second top element by top element and gets remainder
 * @stack: head to the stack
 * @ln: line number where the opcode is located
 */

void stk_mod(stack_t **stack, unsigned int ln)
{
	stack_t *temp, *temp2;

	temp = (*stack);
	temp2 = temp->next;
	if (temp2 == NULL)
	{
		printf("L<%d>: can't mod, stack too short\n", ln);
		exit(EXIT_FAILURE);
	}
	if (temp->n == 0)
	{
		printf("L<%d>: division by zero\n", ln);
		exit(EXIT_FAILURE);
	}
	temp2->n = temp2->n % temp->n;
	delete_stack_head(stack);
}
