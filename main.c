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
	int i;

	check_argc(argc);
	head = NULL;
	path = argv[1];
	line = NULL;
	len = 0;

	fp = fopen(path, "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", path);
		exit(EXIT_FAILURE);
	}

	while ((read = getline(&line, &len, fp)) != -1)
	{
		if (check_empty(line))
			continue;

		tokenize_line(line, tok_line);

		/* tok_line[0] is the command */
		/* tok_line[1] is optional parameters */
/*		printf("tok_line[0]: %s\n", tok_line[0]);
		printf("tok_line[1]: %s\n", tok_line[1]);*/

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
