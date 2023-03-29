#include "main.h"

/**
 * _print_int - Prints a number
 * @ap: List of arguments
 *
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

	if (n < 0)
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

/**
 * _print_unsigned_int - prints integers that are positive
 * @ap: list of arguments
 *
 * Return: number of characters
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

/**
 * _print_addr - prints address
 * @ap: argument list
 *
 * Return:number of characters
 */
int _print_addr(va_list ap)
{
	int k;

	k = va_arg(ap, unsigned int);

	_put_char('0');
	_put_char('x');
	print_add(k);

	return (cal_hexa(k) + 2);
}

/**
 * cal_hexa - changes to base 16
 * @x: integer to convert
 *
 * Return: number of characters
 */
int cal_hexa(unsigned long int x)
{
	int div;

	div = 1;
	while (x >= 16)
	{
		div++;
		x = x / 16;
	}
	return (div);
}

/**
 * print_add - prints memory address
 * @k: integer
 *
 * Return: number of characters
 */
void print_add(unsigned long int k)
{
	if (k >= 16)
		print_add(k / 16);
	_put_char("0123456789abcdef"[k % 16]);
}
