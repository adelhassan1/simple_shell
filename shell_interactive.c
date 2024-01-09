#include "shell.h"

/**
 * shell_interactive - UNIX command line interpreter
 *
 * Return: void
 */

void shell_interactive(void)
{
    char *lineptr = NULL, **args = NULL;
    int status = -1;

    do
    {
        write(STDIN_FILENO, "($) ", 4);
        lineptr = read_line();
        args = parse_string(lineptr);
        status = execute_args(args);

        free(lineptr);
        free(args);

        if (status >= 0)
            exit(status);

    }while (status == -1);
    
}