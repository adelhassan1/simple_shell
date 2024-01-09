#include "shell.h"

/**
 * main - executing shell
 * 
 * @argc: number of args.
 * @argv: array of args.
 * 
 * Return: 0.
*/

int main(void)
{
    if (isatty(STDIN_FILENO) == 1)
    {
        shell_interactive();
    }else
    {
        shell_no_interactive();
    }
    return (0);
}
