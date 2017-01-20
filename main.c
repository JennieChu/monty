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
/*	stack_t *head; */

	check_argc(argc);
/*	head = NULL; */
	path = argv[1];
	printf("%s\n", path);
/*	free_stack(&head); */
	return (1);
}
