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

/**
 * _strlen - lenght
 * @s: par
 * Return: lenght
 */

int _strlen(char *s)
{
	int len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

/**
 * _strcat - concatenate two strings
 * @dest: str1
 * @src: str2
 * Return: str1 + str2
 */

char *_strcat(char *dest, char *src)
{
	int i, l;

	i = 0;
	l = 0;
	while (dest[i++])
		l++;

	for (i = 0; src[i]; i++)
	{
		dest[l++] = src[i];
	}

	return (dest);
}

/**
 * _strcmp - compartion
 * @s1: str1
 * @s2: str2
 * Return: 0 or positive or negative
 */

int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}

	return (*s1 - *s2);
}