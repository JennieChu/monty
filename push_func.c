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
