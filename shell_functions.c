#include "shell.h"

/**
 * read_line - getline function
 * 
 * Return: 0 on success, -1 on failure.
*/

char *read_line(void)
{
	size_t bufsize = 0;
	char *lineptr = NULL;

	if ((getline(&lineptr, &bufsize, stdin)) == -1)
	{
		if (feof(stdin))
		{
			free(lineptr);
			exit(EXIT_SUCCESS);
		}else
		{
			perror("error while reading the line from stdin");
			exit(EXIT_FAILURE);
		}
	}
	return (lineptr);
}

/**
 * read_stream - read a line from the stream
 *
 * Return: pointer that points the the read line
 */

char *read_stream(void)
{
    int bufsize = 1024;
    int i, character;
    char *line = malloc((bufsize + 1) * sizeof(char));

    if (!line)
    {
        perror("error in allocation");
        exit(EXIT_FAILURE);
    }

    while(1)
    {
        character = getchar();
        if (character == EOF)
        {
            free(line);
            exit(EXIT_SUCCESS);
        }else if (character == '\n')
        {
            line[i] = '\0';
            return (line);
        }else
        {
            line[i] = character;
        }
        i++;
        if (i >= bufsize)
        {
            bufsize += bufsize;
			line = realloc(line, bufsize);
			if (line == NULL)
			{
				perror("reallocation error in read_stream");
				exit(EXIT_FAILURE);
        	}
		}
    }
}

/**
 * new_process - create a new process.
 * 
 * @args: array of strings that contains the command and its flags
 *
 * Return: 1 if success, 0 otherwise.
*/



int new_process(char **args)
{
	pid_t pid;
    int status;
	pid = fork();
	if (pid == 0)
	{
		if(execve(args[0], args, NULL) == -1)
		{
			perror("error in new_process: child process");
		}
		exit(EXIT_FAILURE);
	}else if (pid < 0)
	{
		perror("error in new_process: fork");
	}else
	{
		do
		{
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}

    return (-1);

}

/**
 * parse_string - spliting string with strtok
 * 
 * @line: string from read_line to be split.
 * 
 * Return: a pointer to the next token,
 * or NULL if there are no more tokens.
*/


char **parse_string(char *line)
{
	int token_count = 0;
	int bufsize = 64;
	char **tokens = malloc(bufsize * sizeof(char *));
	char *token;

	if (tokens == NULL)
	{
		perror("error while spliting line");
		exit(EXIT_FAILURE);
	}
	token = strtok(line, DELIM);

	while (token)
	{
		if (token[0] == '#')
			break;
		tokens[token_count] = token;
		token_count++;
		if (token_count >= bufsize)
		{
			bufsize += bufsize;
			tokens = realloc(tokens, bufsize * sizeof(char *));
			if (!tokens)
			{
				perror("reallocation error in split_line: tokens");
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, DELIM);  
	}


	tokens[token_count] = NULL;
	return (tokens);

}