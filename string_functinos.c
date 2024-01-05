#include "main.h"
/**
 * _strcpy - copy
 * @dest: par 1
 * @src: par 2
 * Return: str
 */

char *_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (i >= 0)
	{
		if (src[i] == '\0')
		{
			dest[i] = src[i];
			break;
		}
		dest[i] = src[i];
		i++;
	}
	return (dest);
}
