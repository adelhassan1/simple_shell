#include "shell.h"

/**
 * own_cd - changes the working dir of the current shell executon env
 * @args: target directory
 *
 * Return: 1 one success, 0 otherwise.
 */
int own_cd(char **args)
{
	if (args[1] == NULL)
	{
		fprintf(stderr, "expected argument to \"cd\"\n");
	}
	else
	{
		if (chdir(args[1]) != 0)
		{
			perror("error in own_cd.c: changing dir\n");
		}
	}
	return (-1);
}

/**
 * own_env - function that prints enviroment variables
 * @args: arguments
 *
 * Return: 1 on success, 0 otherwise
 */
int own_env(char **args)
{
	int i = 0;
	(void)(**args);

	while (environ[i])
	{
		write(STDOUT_FILENO, environ[i], strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
	return (-1);
}

/**
 * own_help - print help
 * @args: arguments
 *
 * Return: 1 on success, 0 otherwise
 */
int own_help(char **args)
{
	char *builtin_func_list[] = {
		"cd",
		"env",
		"help",
		"exit"
	};
	long unsigned int i = 0;
	(void)(**args);

	printf("\n---help simple_shell---\n");
	printf("Type a command and its arguments, then hit enter\n");
	printf("Built-in commands:\n");
	for (; i < sizeof(builtin_func_list) / sizeof(char *); i++)
	{
		printf("  -> %s\n", builtin_func_list[i]);
	}
	printf("Use the man command for information on other programs.\n\n");
	return (-1);
}
/**
 * own_exit - Exit the shell
 * @args: Command and its flags
 *
 * Return: 1 on success, 0 otherwise
 */

int own_exit(char **args)
{
	if (args[1])
	{
		return (_atoi(args[1]));
	}
	else
	{
		return (0);
	}
}

