#include "monty.h"

/**
 * stk_sub - subtracts the top element of stack from second element
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
	temp->n = temp2->n - temp->n;
	temp->next = temp2->next;
	if (temp2->next != NULL)
		temp2->next->prev = temp;
	else
		temp->next = NULL;
	free(temp2);
}
