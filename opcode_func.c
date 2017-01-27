#include "monty.h"

/**
 * stk_push - pushes a value to the stack
 * @stack: the head of the stack
 * @ln: line number where the opcode is located
 */

void stk_push(stack_t **stack, unsigned int ln)
{
	int result;

	if (value[1] == 0)
		result = add_to_stack(stack, value[0]);
	else
		result = add_to_queue(stack, value[0]);
	if (result < 0)
	{
		printf("L%d: usage: push integer\n", ln);
		value[2] = 1;
		return;
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
		printf("L%d: can't pop an empty stack\n", ln);
		value[2] = 1;
		return;
	}
}

/**
 * stk_add - adds the top two elements of the stack
 * @stack: head to the stack
 * @ln: line number where the opcode is located
 */

void stk_add(stack_t **stack, unsigned int ln)
{
	stack_t *temp;
	stack_t *temp2;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		printf("L%d: can't add, stack too short\n", ln);
		value[2] = 1;
		return;
	}
	temp = (*stack);
	temp2 = temp->next;
	temp->n = temp->next->n + temp->n;
	temp->next = temp2->next;
	if (temp2->next != NULL)
		temp2->next->prev = temp;
	else
		temp->next = NULL;
	free(temp2);
}

/**
 * stk_pint - print value at top of stack followed by new line
 * @stack: head to the stack
 * @ln: line number where the opcode is located
 */

void stk_pint(stack_t **stack, unsigned int ln)
{
	stack_t *head;

	head = *stack;
	if (head == NULL)
	{
		printf("L%d: can't pint, stack empty\n", ln);
		value[2] = 1;
		return;
	}

	printf("%d\n", head->n);
}
