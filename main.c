#include "shell.h"

/**
 * main - executing shell
 *
 * Return: 0.
*/

int main(void)
{
	if (isatty(STDIN_FILENO) == 1)
	{
		shell_interactive();
	} else
	{
	shell_no_interactive();
	}
	return (0);
}
