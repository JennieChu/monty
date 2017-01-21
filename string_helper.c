#include "monty.h"

/**
 * tokenize_line - Tokenize command and any arguments
 * @s: line to parse
 * Return: array with commands
 */
void tokenize_line(char *s, char *tokens[])
{
	int i;
	char *token, *hold;

	token = strtok_r(s, " \t\n", &hold);
	for (i = 0; token && i < 2; i++)
	{
		tokens[i] = token;

		token = strtok_r(NULL, " \t\n", &hold);
	}
}

/**
 * clear_strings - Reset strings in an array
 * @tokens: array of strings
 */
void clear_strings(char *tokens[])
{
	int i;

	for (i = 0; tokens[i]; i++)
		tokens[i][0] = '\0';
}

/**
 * check_empty - Checks if a string is empty
 * @s: string to check
 * Return: 1 if empty, 0 otherwise
 */
int check_empty(const char *s)
{
	while (*s != '\0')
	{
		if (!isspace((unsigned char)*s))
			return (0);
		s++;
	}
	return (1);
}
