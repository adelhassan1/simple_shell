#include "main.h"

/**
 * _getline - getline function
 * 
 * @lineptr: pointer to the line.
 * @n: size of buffer.
 * 
 * Return: on success return the number of characters read,
 * -1 on failure.
*/

int _getline(char *lineptr, size_t n)
{

	printf("#cisfun$ ");
	getline(&lineptr, &n, stdin);

	free(lineptr);
	return (0);
}

/**
 * _exec - execve function
 *
 * @pathname: Pathname to the executable
 * @argv: Array of arguments
 * @envp: Array of environment variables
 * 
 * Return: on success does not return, -1 on failure.
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

/**
 * _strtok - spliting string with strtok
 * 
 * @str: string to be split.
 * @delim: the delimeter.
 * 
 * Return: a pointer to the next token,
 * or NULL if there are no more tokens.
*/
int _strtok(char *str, char *delim)
{
	char *token = strtok(str, delim);

	while (token)
	{
		printf("%s\n", token);
		token = strtok(NULL, delim);
	}
	
	return (0);

}