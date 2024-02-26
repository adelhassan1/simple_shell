#include "shell.h"

/**
 * execute_args - map if command is a builtin or a process
 * @args: command and its flags
 *
 * Return: 1 on sucess, 0 otherwise
 */

int execute_args(char **args)
{
	char *builtin_func_list[] = {
		"cd",
		"env",
		"help",
		"exit",
	};
	int (*builtin_func[])(char **) = {
		&own_cd,
		&own_env,
		&own_help,
		&own_exit
	};
	unsigned long int i;

	if (!args[0])
		return (-1);
	for (; i < sizeof(builtin_func_list) / sizeof(char *); i++)
	{
		if (_strcmp(args[0], builtin_func_list[i]) == 0)
			return ((*builtin_func[i])(args));
	}
	return (new_process(args));
}
