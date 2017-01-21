#include "monty.h"

/**
 * stk_push - pushes a value to the stack
 * @stack: the head of the stack
 * @ln: line number where the opcode is located
 */

void stk_push(stack_t **stack, unsigned int ln)
{
	int result;

	result = add_to_stack(stack, value);
	if (result != 0)
	{
		printf("L<%d>: usage: push integer\n", ln);
		exit(EXIT_FAILURE);
	}
}

/**
 * stk_pall - prints all values of the stack
 * @stack: the head of the stack
 * @ln: line number where the opcode is located
 */

void stk_pall(stack_t **stack, unsigned int ln)
{
	int result;
	(void) ln;

	result = print_stack(stack);
	if (result != 0)
	{
		;
	}
}

/**
 * stk_pop - removes the top element of the stack
 * @stack: the head of the stack
 * @ln: line number where the opcode is located
 */

void stk_pop(stack_t **stack, unsigned int ln)
{
	int result;

	result = delete_stack_head(stack);
	if (result != 1)
	{
		printf("L<%d>: usage: pop\n", ln);
		exit(EXIT_FAILURE);
	}
}

/**
 * stk_add - adds the top two elements together
 * @stack: the ehad of the stack
 * @ln: line number
 */

void stk_add(stack_t **stack, unsigned int ln)
{
	stack_t *temp;
	stack_t *temp2;

	temp = (*stack);
	temp2 = temp->next;
	if (temp->next == NULL)
	{
		printf("L<%d>: can't add, stack too short\n", ln);
		exit(EXIT_FAILURE);
	}
	temp->n = temp->next->n + temp->n;
	temp->next = temp2->next;
	if (temp2->next != NULL)
		temp2->next->prev = temp;
	else
		temp->next = NULL;
	free(temp2);

}
