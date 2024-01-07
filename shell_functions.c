#include "shell.h"

/**
 * read_line - getline function
 * 
 * Return: 0 on success, -1 on failure.
*/

char *read_line(void)
{
	size_t n = 0;
	char *lineptr = NULL;
	ssize_t line;

	line = getline(&lineptr, &n, stdin);

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
	if (execvp(pathname, argv) == -1)
	{
		perror("./shell");
		return (-1);
	}

    // if(execve(pathname, argv, envp) == -1)
    // {
	// 	perror("./shell");
    //     return (-1);
    // }
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


char **pars_args(char *str)
{
	char **tokens = malloc(MAX_TOKENS * sizeof(char *));
	if (tokens == NULL)
		return (NULL);

	int token_count = 0;
	char *token = strtok(str, " ");


	while (token && token_count < MAX_TOKENS)
	{
		tokens[token_count] = malloc((_strlen(token) + 1) * sizeof(char));
		if (tokens[token_count] == NULL)
			return (NULL);
	
		_strcpy(tokens[token_count], token);
		token_count++;
		token = strtok(NULL, " ");  
	}

	tokens[token_count] = NULL;
	return (tokens);

}