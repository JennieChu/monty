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
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
}
