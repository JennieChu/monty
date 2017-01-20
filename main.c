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

	check_argc(argc);
	path = argv[1];
	printf("%s\n", path);
	return (1);
}
