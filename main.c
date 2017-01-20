#include "monty.h"

/**
 * main - Interpreter of the Monty Language
 * @argc: argument count
 * @argv: the list of arguments
 * Return: 1 if passed
 */

int main(int argc, char *argv[])
{
	char *path;
	char *tok_line[2];
	int value;
/*	stack_t *head; */

	check_argc(argc);
/*	head = NULL; */
	path = argv[1];
	tok_line[0] = "push";
	tok_line[1] = "2";
	if (strcmp(tok_line[0],"push") == 0)
	{
		/* check if tok_line[1] is digit */
		value = atoi(tok_line[1]);
	}
	printf("%d\n", value);
	printf("%s\n", path);
/*	free_stack(&head); */
	return (1);
}
