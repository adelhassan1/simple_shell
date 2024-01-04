#include "main.h"

/**
 * _prompt - getline function
 * 
 * @lineptr: pointer to the line.
 * @n: size of buffer.
 * 
 * Return: 0 on success, -1 on failure.
*/

int _pormpt(char *lineptr, size_t n)
{

	printf("#cisfun$ ");
	getline(&lineptr, &n, stdin);

	free(lineptr);
	return (0);
}
