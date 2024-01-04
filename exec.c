#include "main.h"

/**
 * _exec - execve function
 *
 * @pathname: Pathname to the executable
 * @argv: Array of arguments
 * @envp: Array of environment variables
 * 
 * Return: 0 on success, -1 on failure.
*/

int _exec(const char *pathname, char *const argv[], char *const envp[])
{
    if(execve(pathname, argv, envp) == -1)
    {
        perror("./shell:");
        return (-1);
    }
    return (0);

}