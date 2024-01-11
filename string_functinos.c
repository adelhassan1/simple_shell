#include "shell.h"
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
 * _atoi - function that convert a char to int
 *
 * @str: pointer to string
 *
 * Return: nomber of the converted char
 */

int _atoi(const char *str)
{
	int num = 0, sign = 1, i = 0;

	while (str[i] == ' ')
		i++;

	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
	{
		i++;
	}

	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}

	return (num * sign);
}
