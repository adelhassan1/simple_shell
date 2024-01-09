#include "shell.h"

/**
 * own_exit - couses normal process termination
 * @args: empty args
 *
 * Return: 0 to terminate the process
 */

int own_exit(char **args)
{
    if (args[1])
    {
        return (_atoi(args[1]));
    } else
    {
        return (0);
    }
}