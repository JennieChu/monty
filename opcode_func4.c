#include "monty.h"

/**
 * stk_sub - subtracts the top element of stack from the second element
 * @stack: head to the stack
 * @ln: line number where the opcode is located
 */

void stk_sub(stack_t **stack, unsigned int ln)
{
	stack_t *temp, *temp2;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		printf("L%d: can't sub, stack too short\n", ln);
		exit(EXIT_FAILURE);
	}
	temp = (*stack);
	temp2 = temp->next;
	temp->n = temp2->n - temp->n;
	temp->next = temp2->next;
	if (temp2->next != NULL)
		temp2->next->prev = temp;
	else
		temp->next = NULL;
	free(temp2);
}

/**
 * stk_div - divides the second top element of stack from the top element
 * @stack: head to the stack
 * @ln: line number where the opcode is located
 */

void stk_div(stack_t **stack, unsigned int ln)
{
	stack_t *temp, *temp2;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		printf("L%d: can't div, stack too short\n", ln);
		exit(EXIT_FAILURE);
	}
	temp = (*stack);
	temp2 = temp->next;
	if (temp->n == 0)
	{
		printf("L%d: division by zero\n", ln);
		exit(EXIT_FAILURE);
	}

	temp->n = (int)(temp2->n / temp->n);
	temp->next = temp2->next;
	if (temp2->next != NULL)
		temp2->next->prev = temp;
	else
		temp->next = NULL;
	free(temp2);
}

/**
 * stk_mul - multiplies the top two elements of the stack
 * @stack: head to the stack
 * @ln: line number where the opcode is located
 */

void stk_mul(stack_t **stack, unsigned int ln)
{
	stack_t *temp, *temp2;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		printf("L%d: can't mul, stack too short\n", ln);
		exit(EXIT_FAILURE);
	}
	temp = (*stack);
	temp2 = temp->next;
	temp->n = temp2->n * temp-> n;
	temp->next = temp2->next;
	if (temp2->next != NULL)
		temp2->next->prev = temp;
	else
		temp->next = NULL;
	free(temp2);
}

/**
 * stk_mod - divides second top element by top element and gets remainder
 * @stack: head to the stack
 * @ln: line number where the opcode is located
 */

void stk_mod(stack_t **stack, unsigned int ln)
{
	stack_t *temp, *temp2;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		printf("L%d: can't mod, stack too short\n", ln);
		exit(EXIT_FAILURE);
	}
	temp = (*stack);
	temp2 = temp->next;
	if (temp->n == 0)
	{
		printf("L%d: division by zero\n", ln);
		exit(EXIT_FAILURE);
	}
	temp->n = temp2->n % temp->n;
	temp->next = temp2->next;
	if (temp2->next != NULL)
		temp2->next->prev = temp;
	else
		temp->next = NULL;
	free(temp2);
}
