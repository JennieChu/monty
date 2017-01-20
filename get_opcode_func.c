#include "monty.h"

/**
 * get_opcode_func - selects the correct function to perform the opcode
 * @s: opcode passed to the program
 * Return: a pointer to the function given the opcode or NULL if not found
 */

void (*get_opcode_func(char *s))(stack_t **stack, unsigned int ln)
{
/**
 *	int i;
 *	instruction_t stk[] = {
 *		{"push", stk_push},
 *		{"pall", stk_pall},
 *		{NULL, NULL}
 *	};
 *
 *	i = 0;
 *	while (i < 3)
 *	{
 *		if (*s == *(stk[i]).opcode)
 *			return (*(stk[i]).f);
 *	i++;
 *	}
 *	return (NULL);
 */
	printf("%s\n", s);
	return (NULL);
}
