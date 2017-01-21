#include "monty.h"

/**
 * main - Interpreter of the Monty Language
 * @argc: argument count
 * @argv: the list of arguments
 * Return: 1 if passed
 */

int main(int argc, char *argv[])
{
	char *path, *line, *tokens[2];
	FILE *fp;
	size_t len, i, j;
	ssize_t read;

	check_argc(argc);
	path = argv[1];
	printf("%s\n", path);

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

		tokenize_line(line, tokens);

		for (j = 0; tokens[j]; j++)
			printf("token> %s\n", tokens[j]);

		clear_strings(tokens);
	}
	free(line);

	fclose(fp);
	return (1);
}
