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
	size_t len, lineno, status;
	ssize_t read;

	head = NULL;
	line = NULL;
	check_argc(argc);
	path = argv[1];
	check_valid_file(path);

	fp = fopen(path, "r");
	check_file_stream(fp, path);


	for (lineno = 1; (read = getline(&line, &len, fp)) != -1; lineno++)
	{
		if (check_empty(line))
			continue;

		status = tokenize_line(line, tok_line);
		if (status == 0)
			continue;
		/* check_arg 2 validity */

		check_if_push(tok_line, lineno);
		fptr = get_opcode_func(tok_line[0]);
		(*fptr)(&head, lineno);

		clear_strings(tok_line);
	}

	free(line);
	fclose(fp);
	free_stack(head);

	return (1);
}
