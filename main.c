#include "shell.h"

/**
 * main - executing shell
 * 
 * @argc: number of args.
 * @argv: array of args.
 * 
 * Return: 0.
*/

int main(int argc, char *argv[])
{
    pid_t pid;
    int status, i;
    char *lineptr = NULL, **token = NULL;
    size_t len = _strlen(token[0]);

    write(STDIN_FILENO, "$ ", 3);

    lineptr = read_line();
    token = pars_args(lineptr);

    if (token && token[0])
    {
        // Remove the newline character from the last token
        if (len > 0 && token[0][len - 1] == '\n')
            token[0][len - 1] = '\0';

        pid = fork();
        if (pid == -1)
        {
            perror("Error");
            return (-1);
        }
        if (pid == 0)
        {
                my_exec(token[0], NULL, NULL);

        }
    }
    if (token)
    {
        for (i = 0; token[i]; i++)
            free(token[i]);
        free(token);
    }
    return (0);
}
