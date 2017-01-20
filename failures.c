#include "monty.h"

/**
 * check_argc - Function to check whether correct # arguments are given
 * argc: argument count
 */

void check_argc(int argc)
{
	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
}
