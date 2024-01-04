#include "main.h"


/**
 * _strtok - spliting string with strtok
 * 
 * Return: 0.
*/
int _strtok(void)
{
	char str[] = "This is the way.";
	char d[] = " ";
	char *token = strtok(str, d);

	while (token)
	{
		printf("%s\n", token);
		token = strtok(NULL, d);
	}
	
	return (0);

}
