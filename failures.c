#include "monty.h"

/**
 * check_argc - Function to check whether correct # arguments are given
 * @argc: argument count
 */

void check_argc(int argc)
{
	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
}

/**
 * check_valid_file - Check if file given is valid
 * @filename: path to file
 */

void check_valid_file(char *filename)
{
	char *ext;

	ext = strrchr(filename, '.');
	if (ext == NULL)
		return;
	if (!(strcmp(".txt", ext) == 0 || strcmp(".m", ext) == 0))
	{
		printf("Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
}

/**
 * check_file_stream - Check if file stream is valid
 * @fp: file stream
 * @filename: name of file
 */

void check_file_stream(FILE *fp, char *filename)
{
	if (fp == NULL)
	{
		printf("Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
}

/**
 * check_opcode - Check if opcode function pointer is NULL
 * @opcode: opcode function pointer
 * @l: line number
 * @c: command given
 */

void check_opcode(void (*opcode)(), int lineno, char *cmd)
{
	if (opcode == NULL)
	{
		printf("L%d: unknown instruction %s\n", lineno, cmd);
		value[2] = 1;
		return;
	}
}

/**
 * check_fail - check if a fail has been raised. If so, free memory and exit
 * @line: buffer to free
 * @fp: file stream to close
 * @head: head of the stack
 * Return: return 1 if exit triggered, else 0 for false
 */

void check_fail(char *line, FILE *fp, stack_t *head)
{
	if (value[2] == 1)
	{
		free(line);
		fclose(fp);
		free_stack(head);
		exit(EXIT_FAILURE);
	}
}
