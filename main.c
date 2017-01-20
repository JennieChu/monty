#include "monty.h"

int value;
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

/*	stack_t *head; */

	check_argc(argc);
/*	head = NULL; */
	path = argv[1];
	tok_line[0] = "push\0";
	tok_line[1] = "2\0";

	check_if_push(tok_line);
	printf("%d\n", value);
	printf("%s\n", path);
/*	free_stack(&head); */
	return (1);
}
