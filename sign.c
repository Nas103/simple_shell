#include "shell.h"

/**
 * get_sigint - Handles the SIGINT signal (Ctrl+C).
 * @sig: The signal number.
 */
void get_sigint(int sig)
{
	(void)sig;
    write(STDOUT_FILENO, "\n^-^ ", 5);
}
