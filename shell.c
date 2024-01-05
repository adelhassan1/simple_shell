#include "main.h"

/**
 * 
*/

int main(int argc, char *argv[])
{
    pid_t pid;
    int status;
    char *lineptr = NULL, **token = NULL;

    printf("cisfun$ ");

    lineptr = read_line();
    token = _strtok(lineptr);

    int num_tokens = 0;
    while (token[num_tokens])
        num_tokens++;
    
    char **args = malloc((num_tokens + 1) * sizeof(char *));
    if (args == NULL)
    {
        perror("Error allocation memory for args");
        exit(EXIT_FAILURE);
    }
    int i = 0;
    while (i <= num_tokens)
    {
        args[i] = token[i];
        i++;
    }
    args[i] = NULL;

    pid = fork();
    if (pid == -1)
    {
        perror("Error");
        return (-1);
    }
    if (pid == 0)
    {
        my_exec(args[0], args, NULL);
    }
    else
    {
        wait(&status);
    }

    free(args);
    return (0);
}
