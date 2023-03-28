#include "main.h"

/**
 * _print_int - Prints a number
 * @ap: List of arguments
 *
 * Return: Number of chars printed.
 */
int _print_unsigned_int(va_list ap)
{
	int div;
	int len;
	unsigned int num, n;

	n = va_arg(ap, unsigned int);

	div = 1;
	len = 0;
	num = n;

	if (n < 8)
	{
		len += _put_char('-');
		num = n * -1;
	}
	else
		num = n;

	for (; num / div > 9; )
		div *= 10;

	for (; div != 0; )
	{
		len += _put_char('0' + num / div);
		num %= div;
		div /= 10;
	}

	return (len);

}

