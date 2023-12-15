#include "shell.h"

/**
 * read_line - Reads a line of input from the user.
 * @i_eof: Pointer to an integer to indicate EOF.
 * Return: A pointer to the input string.
 */
char *read_line(int *i_eof)
{
	char *input = NULL;
	size_t bufsize = 0;

	*i_eof = getline(&input, &bufsize, stdin);

	return (input);
}
