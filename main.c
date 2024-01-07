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

    while (1)
    { 
        write(STDIN_FILENO, "$ ", 3);

        lineptr = read_line();
        if (!lineptr)
        {
            if (feof(stdin))
            {
                exit(EXIT_SUCCESS);
            }else
            {
                perror("read_line");
                continue;
            }
        }

        token = pars_args(lineptr);
        if (!token)
        {
            free(lineptr);
            continue;
        }

        if (!token[0])
        {
            free(lineptr);
            continue;
        }

        if (token)
        {
            // Remove the newline character from each token
            for (i = 0; token[i]; i++)
            {
                size_t len = _strlen(token[0]);
                if (len > 0 && token[i][len - 1] == '\n')
                    token[i][len - 1] = '\0';
            }

            pid = fork();
            if (pid == -1)
            {
                perror("fork");
                free(lineptr);
                free(token);
                continue;
            }else if (pid == 0)
            {
                    my_exec(token[0], token, NULL);
            }else
            {
                do
                {
                    waitpid(pid, &status, WUNTRACED);
                } while (!WIFEXITED(status) && !WIFSIGNALED(status));
            }
        }
        free(lineptr);
            for (i = 0; token[i]; i++)
                free(token[i]);
            free(token);
    }
    return (0);
}
