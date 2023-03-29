#include "main.h"

/**
 * print_rev - prints a string in reverse
 * @ap: argument list
 *
 * Return: number of characters printed
 */
int print_rev(va_list ap)
{
	int len;
	char *str;
	char *ptr;

	str = va_arg(ap, char *);
	if (str == NULL)
		return (-1);
	ptr = rev_string(str);
	if (ptr == NULL)
		return (-1);
	for (len = 0; ptr[len] != '\0'; len++)
		_put_char(ptr[len]);
	free(ptr);
	return (len);
}

/**
 * rot13 - converts string to rot13
 * @ap: argument list
 *
 * Return: converted string
 */
int rot13(va_list ap)
{
	int i;
	int x;
	char *str;
	char s[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char u[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(ap, char *);
	if (str == NULL)
		retunr (-1);
	for (i = 0; str[i] != '\0'; i++)
	{
		for (x = 0; x <= 52; x++)
		{
			_put_char(u[x]);
			break;
		}
		if (x == 53)
			_put_char(str[i]);
	}
	return (i);
}
