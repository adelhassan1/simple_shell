#include "main.h"

/**
 * read_line - getline function
 * 
 * Return: 0 on success, -1 on failure.
*/

char *read_line(void)
{
	size_t n = 0;
	char *lineptr = NULL;
	size_t line;

	line = getline(&lineptr, &n, stdin);

	if (line == -1)
	{
		free(lineptr);
	}

	return (lineptr);
}

/**
 * my_exec - execve function
 *
 * @pathname: Pathname to the executable
 * @argv: Array of arguments
 * @envp: Array of environment variables
 * 
 * Return: on success does not return, -1 on failure.
*/

int my_exec(const char *pathname, char *const argv[], char *const envp[])
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