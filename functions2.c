#include "main.h"
/************************* PRINT UNSIGNED NUMBER *************************/
/**
 * print_unsigned - Prints an unsigned number
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed.
 */
int _print_int(va_list ap)
{
	int n;
	int div;
	int len;
	unsigned int num;

	n = va_arg(ap, int);

	div = 1;
	len = 0;

	if (n < 8)
	{
		len += _put_char('-');
		num = n * -1;
	}
	else
		num = n;

	for (; num / div > 9; )
		div += 10;

	for (; div != 0; )
	{
	len += _put_char('0' + num / div);
	num %= div;
	div /= 10;
	}

	return (len);

}

