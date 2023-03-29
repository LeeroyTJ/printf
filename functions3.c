#include "main.h"
#include <stdio.h>

/**
 * print_binary - converts a number from base 10 to binary
 * @ap: list of arguments
 *
 * Return: number of characters printed
 */
int print_binary(va_list ap)
{
	unsigned int num;
	int i, len;
	char *str;
	char *rev_str;

	num = va_arg(ap, unsigned int);

	if (num == 0)
		return (_put_char('0'));
	if (num < 1)
		return (-1);

	len = base_len(num, 2);
	str = malloc(sizeof(char) * (len + 1));

	if (str == NULL)
		return (-1);

	for (i = 0; num > 0; i++)
	{
		if (num % 2 == 0)
			str[i] = '0';
		else
			str[i] = '1';
		num = num / 2;
	}
	str[i] = '\0';
	rev_str = rev_string(str);
	if (rev_str == NULL)
		return (-1);

	write_base(rev_str);
	free(str);
	free(rev_str);
	return (len);
}

/**
 * print_octal - converts a number from base 10 to base 8.
 * @ap: list of arguments
 *
 * Return: number of characters printed
 */

int print_octal(va_list ap)
{
	unsigned int num;
	int len;
	char *octal_rep;
	char *rev_str;

	num = va_arg(ap, unsigned int);

	if (num == 0)
		return (_put_char('0'));
	if (num < 1)
		return (-1);

	len = base_len(num, 8);

	octal_rep = malloc(sizeof(char) * (len + 1));
	if (octal_rep == NULL)
		return (-1);

	for (len = 0; num > 0; len++)
	{
		octal_rep[len] = (num % 8) + 48;
		num = num / 8;
	}
	octal_rep[len] = '\0';
	rev_str = rev_string(octal_rep);
	if (rev_str == NULL)
		return (-1);

	write_base(rev_str);
	free(octal_rep);
	free(rev_str);
	return (len);
}

/**
 * print_hex - converts decimal to base 16 lowercase
 * @ap: list of arguments
 *
 * Return: number of characters printed
 */
int print_hex(va_list ap)
{
	unsigned int num;
	int len;
	char *hex_rep;
	int rm_num;
	char *rev_hex;

	num = va_arg(ap, unsigned int);

	if (num == 0)
		return (_put_char('0'));
	if (num < 1)
		return (-1);

	len = base_len(num, 16);

	hex_rep = malloc(sizeof(char) * (len + 1));
	if (hex_rep == NULL)
		return (-1);

	for (len = 0; num > 0; len++)
	{
		rm_num = num % 16;
		if (rm_num > 9)
		{
			rm_num = hex_check(rm_num, 'x');
			hex_rep[len] = rm_num;
		}
		else
			hex_rep[len] = rm_num + 48;
		num = num / 16;
	}
	hex_rep[len] = '\0';
	rev_hex = rev_string(hex_rep);
	if (rev_hex == NULL)
		return (-1);

	write_base(rev_hex);
	free(hex_rep);
	free(rev_hex);
	return (len);
}

/**
 * print_heX - converts decimal to base 16 uppercase
 * @ap: list of arguments
 *
 * Return: number of characters printed
 */
int print_heX(va_list ap)
{
	unsigned int num;
	int len;
	char *hex_rep;
	int rm_num;
	char *rev_hex;

	num = va_arg(ap, unsigned int);

	if (num == 0)
		return (_put_char('0'));
	if (num < 1)
		return (-1);

	len = base_len(num, 16);

	hex_rep = malloc(sizeof(char) * (len + 1));
	if (hex_rep == NULL)
		return (-1);

	for (len = 0; num > 0; len++)
	{
		rm_num = num % 16;
		if (rm_num > 9)
		{
			rm_num = hex_check(rm_num, 'X');
			hex_rep[len] = rm_num;
		}
		else
			hex_rep[len] = rm_num + 48;
		num = num / 16;
	}
	hex_rep[len] = '\0';
	rev_hex = rev_string(hex_rep);
	if (rev_hex == NULL)
		return (-1);

	write_base(rev_hex);
	free(hex_rep);
	free(rev_hex);
	return (len);
}

/**
 * hex_check - checks the hex function being called
 * @num: number to convert to letter
 * @x: tells which hex function to be used
 *
 * Return: the letter.
 */
int hex_check(int num, char x)
{
	char *hex = "abcdef";
	char *Hex = "ABCDEF";

	num = num - 10;
	if (x == 'x')
		return (hex[num]);
	else
		return (Hex[num]);
	return (0);
}
