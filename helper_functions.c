#include "main.h"
#include <stdio.h>

/**
 * write_base - prints characters
 * @s: string to be printed
 */
void write_base(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
		_put_char(s[i]);
}

/**
 * base_len - calculates length
 * @num: the number for which the length is calculated
 * @base: the base to be calculated by
 * Return: an integer representing length
 */
unsigned int base_len(unsigned int num, int base)
{
	unsigned int i;

	for (i = 0; num > 0; i++)
	{
		num = num / base;
	}
	return (i);
}

/**
 * _memcpy - copies memory area
 * @dest: destination for copying
 * @src: where to copy from
 * @n: number of bytes to copy
 * Return: pointer to dest
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}

/**
 * rev_string - reverses a string
 * @s: the string to reverse
 *
 * Return: pointer to character
 */
char *rev_string(char *s)
{
	int len;
	int head;
	char tmp;
	char *dest;

	for (len = 0; s[len] != '\0'; len++)
	{}

	dest = malloc(sizeof(char) * (len + 1));
	if (dest == NULL)
		return (NULL);

	_memcpy(dest, s, len);
	for (head = 0; head < len; head++, len--)
	{
		tmp = dest[len - 1];
		dest[len - 1] = dest[head];
		dest[head] = tmp;
	}
	return (dest);
}
