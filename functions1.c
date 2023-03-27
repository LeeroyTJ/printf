#include "main.h"

/**
 * _printchar - prints a character
 * @ap: list of arguments
 *
 * Return: characters
 */
int _printchar(va_list ap)
{
	_put_char(va_arg(ap, int));
	return (1);
}

/**
 * _printstr - prints a string
 * @ap: list of arguments
 *
 * Return: a string
 */
int _printstr(va_list ap)
{
	int i;
	char *str;

	str = va_arg(ap, char *);

	if (str == NULL)
		str = "(nil)";

	for (i = 0; str[i] != '\0'; i++)
		_put_char(str[i]);

	return (i);
}

/**
 * _printpercent - prints percent sign
 * @ap: list of arguments
 *
 * Return: Always 0.
 */
int _printpercent(__attribute__((unused))va_list ap)
{
	_put_char('%');
	return (1);
}
