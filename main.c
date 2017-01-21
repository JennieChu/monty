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
	char *path, *line, *tok_line[2];
	FILE *fp;
	void (*fptr)(stack_t **stack, unsigned int ln);
	stack_t *head;
	size_t len;
	ssize_t read;

	check_argc(argc);
	path = argv[1];
	head = NULL;
	line = NULL;

	fp = fopen(path, "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", path);
		exit(EXIT_FAILURE);
	}
	check_valid_file(path);

	while ((read = getline(&line, &len, fp)) != -1)
	{
		if (check_empty(line))
			continue;

		tokenize_line(line, tok_line);

		check_if_push(tok_line);
		fptr = get_opcode_func(tok_line[0]);
		(*fptr)(&head, 6);

		clear_strings(tok_line);
	}

	free(line);
	fclose(fp);
	free_stack(head);

	return (1);
}
