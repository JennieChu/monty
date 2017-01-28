#include "monty.h"

/**
 * stk_rotl - rotates the top element of the stack to the bottom
 * @stack: head of the stack
 * @ln: line number
 */

void stk_rotl(stack_t **stack, unsigned int ln)
{
	stack_t *temp, *temp2;

	(void) ln;
	temp = (*stack);
	if (temp == NULL)
		return;
	temp2 = temp;
	if (temp->next == NULL)
		;
	else
	{
		(*stack) = (*stack)->next;
		while (temp2->next != NULL)
			temp2 = temp2->next;
		temp2->next = temp;
		temp->prev = temp2;
		temp->next->prev = NULL;
		temp->next = NULL;
	}
}

/**
 * stk_rotr - rotates the last element of the stack to the top
 * @stack: head of the stack
 * @ln: line number
 */

void stk_rotr(stack_t **stack, unsigned int ln)
{
	stack_t *temp, *temp2;

	(void) ln;
	temp = (*stack);
	temp2 = temp;
	if (temp->next == NULL)
		;
	else
	{
		while (temp2->next != NULL)
			temp2 = temp2->next;
		temp2->prev->next = NULL;
		temp2->prev = NULL;
		temp2->next = temp;
		temp->prev = temp2;
		(*stack) = temp2;
	}
}

/**
 * stk_stack - sets the format of the data to a stack
 * @stack: head of the stack
 * @ln: line number
 */


void stk_stack(stack_t **stack, unsigned int ln)
{
	(void) stack;
	(void) ln;
}

/**
 * stk_queue - sets teh format of the data to a queue
 * @stack: head of the stack
 * @ln: line number of the opcode
 */

void stk_queue(stack_t **stack, unsigned int ln)
{
	(void) stack;
	(void) ln;
}
