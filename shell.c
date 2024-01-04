#include "main.h"

/**
 * 
*/

int main(void)
{
    pid_t pid;
    int status;
    char *argv[] = {"/bin/ls", "-l", "/tmp", NULL};

    printf("cisfun$ ");
    read_line();
    pid = fork();

    if (pid == -1)
    {
        perror("Error");
        return (-1);
    }
    if (pid == 0)
    {
        my_exec(argv[0], argv, NULL);
    }
    else
    {
        wait(&status);
    }
    return (0);
}
