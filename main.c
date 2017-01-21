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
	void (*fptr)(stack_t **stack, unsigned int ln);
	stack_t *head;

	check_argc(argc);
	head = NULL;
	path = argv[1];

	tok_line[0] = "push\0";
	tok_line[1] = "1\0";
	check_if_push(tok_line);
	fptr = get_opcode_func(tok_line[0]);
	(*fptr)(&head, 3);

	tok_line[0] = "push\0";
	tok_line[1] = "2\0";
	check_if_push(tok_line);
	fptr = get_opcode_func(tok_line[0]);
	(*fptr)(&head, 3);

	tok_line[0] = "push\0";
	tok_line[1] = "3\0";
	check_if_push(tok_line);
	fptr = get_opcode_func(tok_line[0]);
	(*fptr)(&head, 3);

	tok_line[0] = "pall\0";
	check_if_push(tok_line);
	fptr = get_opcode_func(tok_line[0]);
	(*fptr)(&head, 3);

	tok_line[0] = "swap\0";
	check_if_push(tok_line);
	fptr = get_opcode_func(tok_line[0]);
	(*fptr)(&head, 3);

	tok_line[0] = "pall\0";
	fptr = get_opcode_func(tok_line[0]);
	(*fptr)(&head, 3);

	tok_line[0] = "pop\0";
	check_if_push(tok_line);
	fptr = get_opcode_func(tok_line[0]);
	(*fptr)(&head, 3);

	printf("%s\n", path);
	free_stack(head);
	return (1);
}
