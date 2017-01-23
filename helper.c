#include "monty.h"

/**
 * check_if_number - checks if a string is a number string
 * @str: string to check
 * Return: 1 if true or 0 if not a number string
 */

int check_if_number(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (!isdigit(str[i]))
			return (0);
	}
	return (1);
}

/**
 * check_if_push - checks if the opcode is str and sets value
 * @tok_line: line of opcode
 * Return: 1 if success and 0 if not push
 */

int check_if_push(char *tok_line[], int lineno)
{
	if (strcmp(tok_line[0], "push") == 0)
	{
		if (tok_line[1][0] != '\0' && check_if_number(tok_line[1]))
			value = atoi(tok_line[1]);
		else
		{
			printf("L<%d>: usage: push integer\n", lineno);
			exit(EXIT_FAILURE);
		}

		return (1);
	}
	return (0);
}

/**
 * is_ascii - checks if a character is a valid ascii
 * @c: character to check
 * Return: 0 if not and 1 if it is an ascii
 */

int is_ascii(int c)
{
	if (c < 0 || c > 127)
		return (0);
	return (1);
}
