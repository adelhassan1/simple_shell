#include "shell.h"

/**
 * own_exit - Exit the shell
 * @args: Command and its flags
 *
 * Return: 1 on success, 0 otherwise
 */

int own_exit(char **args)
{
	if (args[1])
	{
		return (_atoi(args[1]));
	}
	else
	{
		return (0);
	}
}

